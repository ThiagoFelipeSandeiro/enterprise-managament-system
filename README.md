# Setup
1. Install XAMPP.
2. Start Apache.
3. Start MySQL.
4. Open shell.
5. Run this command ```mysql.exe –h localhost –u root -p```.
6. Continue with no password.
7. Run this code in the shell. 
```
CREATE DATABASE go_to_gro_ems;

USE go_to_gro_ems;

CREATE TABLE Employee(
  employeeID SERIAL PRIMARY KEY,
  password VARCHAR(255) NOT NULL,
  employeeName VARCHAR(32) NOT NULL,
  address VARCHAR(64),
  email VARCHAR(32) NOT NULL);

CREATE TABLE Product(
  productID SERIAL PRIMARY KEY,
  productName VARCHAR(64) NOT NULL,
  description VARCHAR(255),
  unitCost DOUBLE(5,2) NOT NULL,
  qualityOnHand INTEGER(64) NOT NULL,
  supplier VARCHAR(64) NOT NULL);

CREATE TABLE `Purchace Details`(
  productID SERIAL PRIMARY KEY,
  purchaseID VARCHAR(8) NOT NULL,
  quantity INTEGER(64) NOT NULL,
  unitCost DOUBLE(5,2) NOT NULL,
  subTotal DOUBLE(5,2) NOT NULL,
  FOREIGN KEY (productID) REFERENCES Product(productID) );

CREATE TABLE Member (
  memberID SERIAL PRIMARY KEY,
  memberName VARCHAR(32) NOT NULL,
  address VARCHAR(64),
  email VARCHAR(32) NOT NULL);

CREATE TABLE Purchace (
  purchaseID SERIAL PRIMARY KEY,
  dateCreated DATETIME(0) NOT NULL,
  memberID VARCHAR(8) NOT NULL,
  status ENUM("pending", "ready", "complete"),
  FOREIGN KEY (memberID) REFERENCES Member(memberID) );

INSERT INTO Employee(password, employeeName, address, email) VALUES ('P@ssw0rd', 'Bobby', 'Melbourne', 'bobby@swin.edu.au');
INSERT INTO Employee(password, employeeName, address, email) VALUES ('P@ssw0rd', 'Poppy', 'Melbourne', 'poppy@swin.edu.au');
```
8. Clone repo into htdocs folder in xampp dir.

# Homepage
```
http://localhost/index.php
```
