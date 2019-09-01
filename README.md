# WorkerManagement
1 Description  
----

Design a virtual base class Staff, including number, name and age protection data members and related member functions;Salesman, derived from Staff, contains sales protection data members and related member functions;Then, the Manager class is derived from Staff.The SalesManager class is then derived from the Salesman and Manager classes.  
Design a file processing method to achieve the company's personnel (including sales, managers and sales managers) management, with the addition of data, update data, query data, delete data and reorganization of the file function.(delete data in the record to make delete mark, reorganization file refers to the physical deletion of records with delete mark.)In addition, the number of employees in these three categories and the total number of employees are required.  

2 Principal Method  
---- 

First, define a virtual base class Staffy (employee) that contains Numbers, names, and age-protected data members, as well as related member functions.Salesman, derived from Staff, contains sales protection data members and related member functions;Then, the Manager class is derived from Staff, which includes data members protected by the Manager's department and related member functions.The SalesManager class is then derived from the Salesman and Manager classes.Salesman, Manager, and SalesManager respectively define an operation class named Salesman_operation, Manage_operationr, and SalesManager_operation. In these three classes, functions such as addinfo(), deleteinfo(), modifyinfo(), searchinfo() are implemented for adding data, updating data, queryingdata, deleting data, and reorganizing files.In terms of implementation, I mainly achieved through the operation of linked lists and files.For counting people, I use count in the constructor for each operaton class.  
