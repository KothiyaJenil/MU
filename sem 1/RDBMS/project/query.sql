---------------------------------------------
-- 1. Basic SQL Queries (INSERT, UPDATE, DELETE, SELECT)
----------------------------------------------------------

-- 1️⃣ Insert a new passenger record
INSERT INTO passenger (passenger_name, gender, phone, email)
VALUES ('Nisha Patel', 'F', '9898123456', 'nisha.patel@gmail.com');

-- 2️⃣ Update fare of all Non-AC buses
UPDATE bus SET fare_per_km = fare_per_km + 0.25 WHERE bus_type = 'Non-AC';

-- 3️⃣ Delete a booking with Pending payment
DELETE FROM booking WHERE payment_status = 'Pending';

-- 4️⃣ Select all details of routes
SELECT * FROM route;

-- 5️⃣ Select specific columns from bus table
SELECT bus_number, bus_type, total_seats FROM bus;

---------------------------------------------
-- 2. Operators in SQL*Plus (WHERE, BETWEEN, IN, LIKE, AND/OR, NOT)
----------------------------------------------------------

-- 6️⃣ Display buses with fare between 3 and 4 rupees per km
SELECT bus_number, fare_per_km FROM bus
WHERE fare_per_km BETWEEN 3 AND 4;

-- 7️⃣ Show passengers whose name starts with 'P'
SELECT passenger_name FROM passenger
WHERE passenger_name LIKE 'P%';

-- 8️⃣ Find drivers from Surat or Rajkot
SELECT driver_name, address FROM driver
WHERE address IN ('Surat', 'Rajkot');

-- 9️⃣ Find buses which are not AC
SELECT bus_number, bus_type FROM bus
WHERE NOT bus_type = 'AC';

-- 🔟 Show schedules with available seats greater than 35 and type = AC
SELECT s.schedule_id, b.bus_number, s.available_seats
FROM schedule s
JOIN bus b ON s.bus_id = b.bus_id
WHERE s.available_seats > 35 AND b.bus_type = 'AC';

---------------------------------------------
-- 3. DISTINCT, ORDER BY, GROUP BY, HAVING
----------------------------------------------------------

-- 11️⃣ Show distinct bus types
SELECT DISTINCT bus_type FROM bus;

-- 12️⃣ Display all drivers ordered by name
SELECT driver_name, address FROM driver ORDER BY driver_name ASC;

-- 13️⃣ Find total buses of each type
SELECT bus_type, COUNT(*) AS total_buses
FROM bus
GROUP BY bus_type;

-- 14️⃣ Find routes with total distance more than 200 km (using HAVING)
SELECT source, destination, distance_km
FROM route
GROUP BY source, destination, distance_km
HAVING distance_km > 200;

-- 15️⃣ Count number of bookings per payment status
SELECT payment_status, COUNT(*) AS total_bookings
FROM booking
GROUP BY payment_status;

---------------------------------------------
-- 4. Aggregate & Built-in Functions
----------------------------------------------------------

-- 16️⃣ Find average fare per km
SELECT ROUND(AVG(fare_per_km),2) AS avg_fare FROM bus;

-- 17️⃣ Find maximum and minimum fare
SELECT MAX(fare_per_km) AS max_fare, MIN(fare_per_km) AS min_fare FROM bus;

-- 18️⃣ Find total maintenance cost for all buses
SELECT SUM(cost) AS total_maintenance_cost FROM maintenance;

-- 19️⃣ Display passenger names in uppercase
SELECT UPPER(passenger_name) AS passenger_name_upper FROM passenger;

-- 20️⃣ Show driver names in lowercase
SELECT LOWER(driver_name) AS driver_name_lower FROM driver;

---------------------------------------------
-- 5. JOINS (INNER, LEFT, RIGHT, MULTI-TABLE)
----------------------------------------------------------

-- 21️⃣ Show passenger with their booked bus and travel date
SELECT p.passenger_name, b.bus_number, s.travel_date
FROM passenger p
JOIN booking bk ON p.passenger_id = bk.passenger_id
JOIN schedule s ON bk.schedule_id = s.schedule_id
JOIN bus b ON s.bus_id = b.bus_id;

-- 22️⃣ Show route with bus details
SELECT r.source, r.destination, b.bus_number, b.bus_type
FROM route r
JOIN schedule s ON r.route_id = s.route_id
JOIN bus b ON s.bus_id = b.bus_id;

-- 23️⃣ Show payment with passenger details
SELECT p.passenger_name, pay.payment_mode, pay.amount
FROM payment pay
JOIN booking b ON pay.booking_id = b.booking_id
JOIN passenger p ON b.passenger_id = p.passenger_id;

-- 24️⃣ LEFT JOIN – show all schedules, even if no booking
SELECT s.schedule_id, b.bus_number, bk.booking_id
FROM schedule s
LEFT JOIN booking bk ON s.schedule_id = bk.schedule_id
JOIN bus b ON s.bus_id = b.bus_id;

-- 25️⃣ Show driver name with bus and route they are assigned to
SELECT d.driver_name, b.bus_number, r.source, r.destination
FROM driver d
JOIN schedule s ON d.driver_id = s.driver_id
JOIN bus b ON s.bus_id = b.bus_id
JOIN route r ON s.route_id = r.route_id;

---------------------------------------------
-- 6. Subqueries (Single Row, Multi Row, Correlated)
----------------------------------------------------------

-- 26️⃣ Find buses with fare higher than the average fare
SELECT bus_number, fare_per_km FROM bus
WHERE fare_per_km > (SELECT AVG(fare_per_km) FROM bus);

-- 27️⃣ Show passengers who made a payment using UPI
SELECT passenger_name FROM passenger
WHERE passenger_id IN (
    SELECT b.passenger_id FROM booking b
    JOIN payment p ON b.booking_id = p.booking_id
    WHERE p.payment_mode = 'UPI'
);

-- 28️⃣ Show bus details for schedule with the most available seats
SELECT * FROM bus WHERE bus_id = (
    SELECT bus_id FROM schedule
    WHERE available_seats = (SELECT MAX(available_seats) FROM schedule)
);

-- 29️⃣ Find passengers who have not made any booking
SELECT passenger_name FROM passenger
WHERE passenger_id NOT IN (SELECT passenger_id FROM booking);

-- 30️⃣ Find total number of schedules per bus using subquery in FROM
SELECT b.bus_number, COUNT(s.schedule_id) AS total_schedules
FROM bus b
JOIN schedule s ON b.bus_id = s.bus_id
GROUP BY b.bus_number;

---------------------------------------------
-- 7. Set Operators (UNION, INTERSECT, MINUS)
----------------------------------------------------------

-- 31️⃣ UNION – list of all source and destination cities
SELECT source AS city FROM route
UNION
SELECT destination FROM route;

-- 32️⃣ INTERSECT – cities that are both source and destination
SELECT source AS city FROM route
INTERSECT
SELECT destination FROM route;

-- 33️⃣ MINUS – cities that are only sources, not destinations
SELECT source AS city FROM route
MINUS
SELECT destination FROM route;

---------------------------------------------
-- 8. Extra Advanced or Useful Queries (34–35)
----------------------------------------------------------

-- 34️⃣ Show total revenue collected from all payments
SELECT SUM(amount) AS total_revenue FROM payment;

-- 35️⃣ Show average cost of maintenance per bus
SELECT b.bus_number, ROUND(AVG(m.cost),2) AS avg_maintenance_cost
FROM maintenance m
JOIN bus b ON m.bus_id = b.bus_id
GROUP BY b.bus_number;
