--, 1) A simple PL/SQL block that displays all buses with their type and fare.

DECLARE
    CURSOR bus_cur IS SELECT bus_number, bus_type, fare_per_km FROM bus;
    v_number bus.bus_number%TYPE;
    v_type bus.bus_type%TYPE;
    v_fare bus.fare_per_km%TYPE;
BEGIN
    DBMS_OUTPUT.PUT_LINE('--- BUS DETAILS ---');
    OPEN bus_cur;
    LOOP
        FETCH bus_cur INTO v_number, v_type, v_fare;
        EXIT WHEN bus_cur%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE('Bus: ' || v_number || ', Type: ' || v_type || ', Fare: ' || v_fare);
    END LOOP;
    CLOSE bus_cur;
END;
/

-------------------------------------------------------------------------------------------------------------------------

--, 2) Takes input using variables and inserts a new record into bus.

DECLARE
    v_bus_number VARCHAR2(20) := 'GJ09KL1122';
    v_type VARCHAR2(20) := 'Seater';
    v_seats NUMBER := 40;
    v_fare NUMBER := 3.00;
BEGIN
    INSERT INTO bus (bus_number, bus_type, total_seats, fare_per_km)
    VALUES (v_bus_number, v_type, v_seats, v_fare);
    DBMS_OUTPUT.PUT_LINE('New bus inserted successfully.');
END;
/

-------------------------------------------------------------------------------------------------------------------------

--, 3) Calculates the average fare per km across all buses.

DECLARE
    v_avg NUMBER(6,2);
BEGIN
    SELECT AVG(fare_per_km) INTO v_avg FROM bus;
    DBMS_OUTPUT.PUT_LINE('Average Fare per KM: ' || v_avg);
END;
/

-------------------------------------------------------------------------------------------------------------------------

--, 4) Calculates and displays the total amount received from all payments.

DECLARE
    v_total NUMBER(8,2);
BEGIN
    SELECT SUM(amount) INTO v_total FROM payment;
    DBMS_OUTPUT.PUT_LINE('Total Amount Collected: ' || v_total);
END;
/

-------------------------------------------------------------------------------------------------------------------------

--, 5) Updates a passenger’s phone number using their name.

DECLARE
    v_name VARCHAR2(50) := 'Amit Joshi';
BEGIN
    UPDATE passenger SET phone = '9998887776' WHERE passenger_name = v_name;
    DBMS_OUTPUT.PUT_LINE('Phone number updated for ' || v_name);
END;
/

-------------------------------------------------------------------------------------------------------------------------

--, 6) Displays buses that are either ‘AC’ or ‘Sleeper’.

DECLARE
    v_type VARCHAR2(20) := 'AC';
    v_count NUMBER;
BEGIN
    SELECT COUNT(*) INTO v_count FROM bus WHERE bus_type = v_type;
    IF v_count > 0 THEN
        DBMS_OUTPUT.PUT_LINE(v_type || ' buses available: ' || v_count);
    ELSE
        DBMS_OUTPUT.PUT_LINE('No ' || v_type || ' buses found.');
    END IF;
END;
/

-------------------------------------------------------------------------------------------------------------------------

--, 7) A function that calculates total fare for a booking given distance and fare per km.

CREATE OR REPLACE FUNCTION calc_fare(p_distance NUMBER, p_fare NUMBER)
RETURN NUMBER IS
BEGIN
    RETURN p_distance * p_fare;
END;
/

-- calling function

DECLARE
    v_total NUMBER;
BEGIN
    v_total := calc_fare(215, 3.5);
    DBMS_OUTPUT.PUT_LINE('Total Fare: ' || v_total);
END;
/

-------------------------------------------------------------------------------------------------------------------------

--, 8) Displays driver details based on driver ID.

CREATE OR REPLACE PROCEDURE show_driver(p_driver_id NUMBER) AS
    v_name driver.driver_name%TYPE;
    v_phone driver.phone%TYPE;
    v_addr driver.address%TYPE;
BEGIN
    SELECT driver_name, phone, address
    INTO v_name, v_phone, v_addr
    FROM driver
    WHERE driver_id = p_driver_id;
    
    DBMS_OUTPUT.PUT_LINE('Driver: ' || v_name || ', Phone: ' || v_phone || ', Address: ' || v_addr);
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('No driver found with ID ' || p_driver_id);
END;
/

-------------------------------------------------------------------------------------------------------------------------

--, 9) Counts how many bookings exist in the system.

CREATE OR REPLACE PROCEDURE total_bookings IS
    v_count NUMBER;
BEGIN
    SELECT COUNT(*) INTO v_count FROM booking;
    DBMS_OUTPUT.PUT_LINE('Total Bookings: ' || v_count);
END;
/

-------------------------------------------------------------------------------------------------------------------------

--, 10) Uses a cursor to display all schedules with bus and route details.

DECLARE
    CURSOR sched_cur IS
        SELECT s.schedule_id, b.bus_number, r.source, r.destination
        FROM schedule s
        JOIN bus b ON s.bus_id = b.bus_id
        JOIN route r ON s.route_id = r.route_id;
    v_id NUMBER;
    v_bus VARCHAR2(20);
    v_src VARCHAR2(50);
    v_dest VARCHAR2(50);
BEGIN
    OPEN sched_cur;
    LOOP
        FETCH sched_cur INTO v_id, v_bus, v_src, v_dest;
        EXIT WHEN sched_cur%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE('Schedule ' || v_id || ': ' || v_bus || ' - ' || v_src || ' to ' || v_dest);
    END LOOP;
    CLOSE sched_cur;
END;
/

-------------------------------------------------------------------------------------------------------------------------

--, 11) Handles the case where a passenger ID doesn’t exist.

DECLARE
    v_name passenger.passenger_name%TYPE;
BEGIN
    SELECT passenger_name INTO v_name FROM passenger WHERE passenger_id = 99;
    DBMS_OUTPUT.PUT_LINE('Passenger Name: ' || v_name);
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Passenger not found!');
END;
/


-------------------------------------------------------------------------------------------------------------------------

--, 12) Simple demonstration of loop logic.

DECLARE
    -- Cursor to get passenger details with their bookings
    CURSOR passenger_bookings IS
        SELECT p.passenger_name, b.booking_id, b.seat_number, s.schedule_id
        FROM passenger p
        JOIN booking b ON p.passenger_id = b.passenger_id
        JOIN schedule s ON b.schedule_id = s.schedule_id
        ORDER BY p.passenger_name;

BEGIN
    DBMS_OUTPUT.PUT_LINE('--- PASSENGER BOOKING DETAILS ---');
    
    -- Loop through each booking record
    FOR rec IN passenger_bookings LOOP
        DBMS_OUTPUT.PUT_LINE('Passenger: ' || rec.passenger_name || ' | Booking ID: ' || rec.booking_id || ' | Seat: ' || rec.seat_number || ' | Schedule ID: ' || .schedule_id);
    END LOOP;

END;
/


-------------------------------------------------------------------------------------------------------------------------

--, 13) Automatically decreases available seats when a booking is added.

CREATE OR REPLACE TRIGGER trg_update_seats
AFTER INSERT ON booking
FOR EACH ROW
BEGIN
    UPDATE schedule
    SET available_seats = available_seats - 1
    WHERE schedule_id = :NEW.schedule_id;
END;
/

-------------------------------------------------------------------------------------------------------------------------

--, 14) Displays message whenever maintenance record is added.

CREATE OR REPLACE TRIGGER trg_log_maintenance
AFTER INSERT ON maintenance
FOR EACH ROW
BEGIN
    DBMS_OUTPUT.PUT_LINE('New maintenance added for bus ID: ' || :NEW.bus_id);
END;
/

-------------------------------------------------------------------------------------------------------------------------

--, 15) Returns the total maintenance cost for a given bus ID.

CREATE OR REPLACE FUNCTION get_maintenance_cost(p_bus_id NUMBER)
RETURN NUMBER IS
    v_cost NUMBER := 0;
BEGIN
    SELECT SUM(cost) INTO v_cost FROM maintenance WHERE bus_id = p_bus_id;
    RETURN NVL(v_cost, 0);
END;
/

-- calling function

DECLARE
    v_total NUMBER;
BEGIN
    v_total := get_maintenance_cost(1);
    DBMS_OUTPUT.PUT_LINE('Total maintenance cost for Bus 1: ' || v_total);
END;
/
