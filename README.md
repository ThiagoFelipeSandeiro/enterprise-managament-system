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

CREATE TABLE employee(
  employeeID INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
  password VARCHAR(255) NOT NULL,
  employeeName VARCHAR(32) NOT NULL,
  address VARCHAR(64),
  email VARCHAR(32) NOT NULL
);

CREATE TABLE product(
  productID INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
  productName VARCHAR(64) NOT NULL,
  productDescription VARCHAR(255),
  productUnitCost DOUBLE(5,2) NOT NULL,
  productQuantityOnHand INTEGER(64) NOT NULL,
  productSupplier VARCHAR(64) NOT NULL
);

CREATE TABLE member (
  memberID INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
  memberName VARCHAR(32) NOT NULL,
  address VARCHAR(64) NOT NULL,
  email VARCHAR(32) NOT NULL
);

CREATE TABLE purchase (
  purchaseID INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
  date DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,
  memberID INT NOT NULL,
  CONSTRAINT memberID_constraint FOREIGN KEY memberID_fk(memberID) REFERENCES member(memberID)
);

CREATE TABLE purchased_products(
  purchaseID INT NOT NULL,
  productID INT NOT NULL,
  quantity INTEGER(64) NOT NULL,
  subTotal DOUBLE(7,2) NOT NULL,
  CONSTRAINT purchaseID_constraint FOREIGN KEY purchaseID_fk(purchaseID) REFERENCES purchase(purchaseID),
  CONSTRAINT productID_constraint FOREIGN KEY productID_fk(productID) REFERENCES product(productID),
  PRIMARY KEY (purchaseID, productID)
);

--employee insert
INSERT INTO employee(password, employeeName, address, email) VALUES ('$2y$10$RXW65hPF.vDa63tPta2.1..JJCITyo7R5qUewJNmkf8y1c3AoC/fG', 'Bobby', 'Melbourne', 'bobby@swin.edu.au');
INSERT INTO employee(password, employeeName, address, email) VALUES ('$2y$10$RXW65hPF.vDa63tPta2.1..JJCITyo7R5qUewJNmkf8y1c3AoC/fG', 'Poppy', 'Melbourne', 'poppy@swin.edu.au');
--product insert
INSERT INTO product(productName, productDescription, productUnitCost, productQuantityOnHand, productSupplier) VALUES ('Carrot', 'Ohakune Carrots', 1.50, 150, 'Kim Young & Sons');
INSERT INTO product(productName, productDescription, productUnitCost, productQuantityOnHand, productSupplier) VALUES ('Acai', 'Acai berry from the Brazilian Amazon', 2.50, 1500, 'Tropical Brazil');
--member insert
INSERT INTO member(memberName, address, email) VALUES ('Jeff Bezos', 'USA', 'jeff@amazon.com');
--purchase insert
INSERT INTO purchase(memberID) VALUES (1);
--purchased_products insert
INSERT INTO purchased_products(purchaseID, productID, quantity, subTotal) VALUES (1, 1, 100, 150.00);
INSERT INTO purchased_products(purchaseID, productID, quantity, subTotal) VALUES (1, 2, 100, 250.00);

--employee select
SELECT * FROM employee;
--product select
SELECT * FROM product;
--member select
SELECT * FROM member;
--purchase select
SELECT * FROM purchase;
--purchased_products select
SELECT * FROM purchased_products;

--purchased_products and product join
SELECT * FROM purchased_products AS pp JOIN product AS p ON pp.productID = p.productID;

--purchased_products, product, and purchase join
SELECT * FROM purchased_products AS pd JOIN product AS pro ON pd.productID = pro.productID JOIN purchase AS pur ON pd.purchaseID = pur.purchaseID;

--purchased_products, product, purchase, and member join
SELECT * FROM purchased_products AS pp JOIN product AS pro ON pp.productID = pro.productID JOIN purchase AS pur ON pp.purchaseID = pur.purchaseID JOIN member AS m ON pur.memberID = m.memberID;

--sale details
SELECT pur.purchaseID, pur.date, pur.memberID, m.memberName, pp.productID, pp.quantity, pro.productUnitCost, pp.quantity*pro.productUnitCost AS 'Total Sale' FROM purchased_products AS pp JOIN product AS pro ON pp.productID = pro.productID JOIN purchase AS pur ON pp.purchaseID = pur.purchaseID JOIN member AS m ON pur.memberID = m.memberID;

--sale grand total
SELECT pur.purchaseID, pur.date, pur.memberID, m.memberName, COUNT(pp.productID) AS 'Total Products', SUM(pp.subTotal) AS 'Grand Total' FROM purchased_products AS pp JOIN product AS pro ON pp.productID = pro.productID JOIN purchase AS pur ON pp.purchaseID = pur.purchaseID JOIN member AS m ON pur.memberID = m.memberID;
```
8. Clone repo into htdocs folder in xampp dir.

# Homepage
```
http://localhost/index.php
```
