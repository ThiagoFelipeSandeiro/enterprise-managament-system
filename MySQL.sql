CREATE DATABASE go_to_gro_ems;

USE go_to_gro_ems;

CREATE TABLE Employee(
  employeeID SERIAL PRIMARY KEY,
  password VARCHAR(32) NOT NULL,
  loginStatus BOOLEAN,
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

INSERT INTO Employee(password, loginStatus, employeeName, address, email) VALUES ('P@ssw0rd', 'FALSE', 'Bobby', 'Melbourne 3000', 'bobby@swin.edu.au');
INSERT INTO Employee(password, loginStatus, employeeName, address, email) VALUES ('P@ssw0rd', 'FALSE', 'Poppy', 'Melbourne 3000', 'poppy@swin.edu.au');