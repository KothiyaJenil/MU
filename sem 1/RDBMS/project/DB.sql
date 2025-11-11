CREATE TABLE bus (
    bus_id NUMBER(5) GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    bus_number VARCHAR2(20) UNIQUE NOT NULL,
    bus_type VARCHAR2(20) CHECK (bus_type IN ('AC', 'Non-AC', 'Sleeper', 'Seater')),
    total_seats NUMBER(3) CHECK (total_seats > 0),
    fare_per_km NUMBER(6,2) CHECK (fare_per_km > 0)
);


CREATE TABLE driver (
    driver_id NUMBER(5) GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    driver_name VARCHAR2(50) NOT NULL,
    license_number VARCHAR2(20) UNIQUE NOT NULL,
    phone VARCHAR2(15),
    address VARCHAR2(100)
);


CREATE TABLE route (
    route_id NUMBER(5) GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    source VARCHAR2(50) NOT NULL,
    destination VARCHAR2(50) NOT NULL,
    distance_km NUMBER(6,2) CHECK (distance_km > 0)
);


CREATE TABLE schedule (
    schedule_id NUMBER(5) GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    bus_id NUMBER(5) NOT NULL,
    driver_id NUMBER(5) NOT NULL,
    route_id NUMBER(5) NOT NULL,
    travel_date DATE NOT NULL,
    departure_time VARCHAR2(10) NOT NULL,
    arrival_time VARCHAR2(10),
    available_seats NUMBER(3),
    total_duration VARCHAR2(20),
    FOREIGN KEY (bus_id) REFERENCES bus(bus_id) ON DELETE CASCADE,
    FOREIGN KEY (driver_id) REFERENCES driver(driver_id) ON DELETE CASCADE,
    FOREIGN KEY (route_id) REFERENCES route(route_id) ON DELETE CASCADE
);


CREATE TABLE passenger (
    passenger_id NUMBER(5) GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    passenger_name VARCHAR2(50) NOT NULL,
    gender CHAR(1) CHECK (gender IN ('M', 'F')),
    phone VARCHAR2(15) UNIQUE,
    email VARCHAR2(50) UNIQUE
);


CREATE TABLE booking (
    booking_id NUMBER(6) GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    passenger_id NUMBER(5) NOT NULL,
    schedule_id NUMBER(5) NOT NULL,
    seat_number NUMBER(3) NOT NULL,
    booking_date DATE DEFAULT SYSDATE,
    amount_paid NUMBER(8,2) CHECK (amount_paid >= 0),
    payment_status VARCHAR2(10) CHECK (payment_status IN ('Paid', 'Pending')),
    FOREIGN KEY (passenger_id) REFERENCES passenger(passenger_id) ON DELETE CASCADE,
    FOREIGN KEY (schedule_id) REFERENCES schedule(schedule_id) ON DELETE CASCADE
);


CREATE TABLE payment (
    payment_id NUMBER(6) GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    booking_id NUMBER(6) NOT NULL,
    payment_mode VARCHAR2(15) CHECK (payment_mode IN ('UPI','Card','Cash')),
    payment_date DATE DEFAULT SYSDATE,
    transaction_id VARCHAR2(30) UNIQUE NOT NULL,
    amount NUMBER(8,2),
    FOREIGN KEY (booking_id) REFERENCES booking(booking_id) ON DELETE CASCADE
);



CREATE TABLE maintenance (
    bus_id NUMBER(5) NOT NULL,
    maintenance_id NUMBER(5) NOT NULL,
    maintenance_date DATE DEFAULT SYSDATE,
    description VARCHAR2(100),
    cost NUMBER(8,2) CHECK (cost >= 0),
    performed_by VARCHAR2(50),
    FOREIGN KEY (bus_id) REFERENCES bus(bus_id) ON DELETE CASCADE
);
