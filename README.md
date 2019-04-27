# 2018/19 Semester 2 ENGG1340 Course Project (Group 9)

#### Group members
- Janvi Sharma (3035552894)
- Sean Chok (3035551644)

## Introduction
### Problem Statement
Janvi is a startup CEO, who is running Nord Etoile, a personal care & fragrance store. Like any other startup (which is always short on cash), Nord Etoile faces deep troubles with its human resources department; that is, its HR manager and software / hardware developer, Sean always has headaches recording, finding, editing, and removing employee information because he has STML. Clearly, something must be done to provide a remedy. This is where a comprehensive employee management system (written in C++) comes in.

### Problem Setting
Some problems faced by Sean are:
1. How to easily maintain a record of all employees?
2. How to look for a specific record of an employee?
3. How to know whether an employee is a current employee or has been fired?
4. How to effectively edit the details of the employee?

### Program Features
The program will be menu driven, and it will contain the following features:
1. Create record of a new employee with details such as ID, name, age, role & salary. Adding this record to the current record of employees.
2. Search for employee records based on certain criteria.
3. Display the list of all employees with job status (currently working or fired).
4. Sort the employee records.
5. Edit the details of a current employee.
6. Fire an employee, update this status in the record of all employees.
7. Delete employee records, completely removing it from the employee data file.

## Building and Running the Program
We have made using the program a rather simple task for anyone with a Unix-based terminal. Just follow the following instructions, and execute these commands in order. However, you are required to have [git](https://www.atlassian.com/git/tutorials/install-git), [g++ compiler](https://www.cs.odu.edu/~zeil/cs250PreTest/latest/Public/installingACompiler/), and [make](https://www.gnu.org/software/make/) installed.

Clone this github repo.

`git clone https://github.com/janvisharma/project_1340.git`

Go into the project root directory.

`cd project_1340`

Build the main program using make. *Our makefile defaults to compiling main.cpp.*

`make`

Start running the program.

`./main`

To remove all `.o` and `main` files.

`make clean`


## Our Data Structure
### Level 1: The Employee Class
An `Employee` class has been implemented for the use of the entire program. It stores `Employee` attributes as private information. The attributes are:
```
string firstName;
string lastName;
string employeeId;
int age;
string role;
double salary;
string address;
string phoneNumber;
string dateOfBirth;
bool isAnEmployee;
```
It has all of the setter and getter functions for each attribute, it also contains additional functions such as `getNumberOfEmployeeAttributes`, that are essential for many other parts of the program.

### Level 2: Dynamic Array (C++ Vectors) of Employee(s)
We have considered using either dynamic arrays (C++ vector library) or linked lists to store the employee records, and evaluated the pros and cons of each approach. We found out that arrays are more suitable for our application due to a couple of reasons:
- arrays take up less memory space than linked list, and our application may have to deal with a very big number of employees
- a company does not hire / fire employees at a very high rate such that the ability of linked lists to quickly insert / delete employee records would be underused
- the application user is likely to be more interested in quickly looking up an employee record, and updating it; this means, a 'random access' approach using arrays would be better

Hence, a dynamic array using C++ vectors has been implemented.

## Using the Program
### File I/O
When the program user runs the `main` program, he / she is first asked to either **create a new employee data record file**, or **load an existing file**. The file extension must be `.txt`, and it has to conform to the following rules:
1. Header line
```
First Name | Last Name | Employee ID | Age | Role | Salary | Address | Phone Number | Date of Birth | Employee Status |
```
2. Data line
Example:
```
Jon | Snow | 1 | 22 | Rightful King of 7 Kingdoms | 9999999 | Winterfell | No number | 283 AC | True |
```

When the user loads an existing file (an example file called `employee_data.txt` has been provided), the employee records are read, and a vector of Employee's is created using `vector <Employee> employeesArray` (we have kept the vector name consistent throughout our program). Functions such as searching and sorting are done using `employeesArray`.

When the user exits the program, the file loaded at the start is be overwritten using the `employeesArray` at the end of program run time. Essentially, each `Employee`'s data is recorded in the file using the aforementioned rules.

### Navigating the Menu
Our program contains the following features in a menu-based navigation:
```
0: Exit the program, and record changes to your employee data in the file you loaded.
1: Create a new employee record.
2: Search employees.
3: Display list of employees.
4: Sort employee records.
5: Modify record of an employee.
6: Fire employees.
7. Delete employee records.
```

#### Exit the program
```
0: Exit the program, and record changes to your employee data in the file you loaded.
```
The user exits the program, and an output filestream is invoked to store `employeesArray` data into the file.

#### Create a new employee record
```
1: Create a new employee record.
```
The user is prompted a series of employee attributes such as first name, last name, etc to create a new employee. Furthermore, our program asks the user for necessary modifications (just in case he / she has typed incorrect values) before letting the user confirm the employee creation.

#### Search employees
```
2: Search employees.
```
The user is asked to search for employees based on the selection of 1 employee attribute. However, the `address` attribute is disabled because it is to our knowledge that searching based on long string values such as `address` is not meaningful. The allowed employee attributes for searching are as follows:
```
1: First Name
2: Last Name
3: Employee ID
4: Age
5: Role
6: Salary
7: Phone Number
8: Date of Birth
9: Employee Status
```
`employeesArray` is filtered based on the attribute selected, and the data of the employees found is displayed sparingly.

#### Display list of employees
```
3: Display list of employees.
```
A list of employees is displayed, but with 5 attributes only; the attributes include `First Name`, `Last Name`, `Employee ID`, `Salary`, and `Employee Status`. An index for each employee is also provided at the beginning of each `cout` line. The user is then given an option to go back to the navigation menu, or look further into a specific employee. If the user chooses the latter, an employee index is prompted, and the complete record of the relevant employee is displayed.

#### Sort employee records
```
4: Sort employee records.
```
A list of attributes is shown to let the user choose some attributes based on a decreasing order of sorting importance. `employeesArray` is sorted based on that order.

#### Modify record of an employee
```
5: Modify record of an employee.
```
A list of employees is shown. An index of the employee that the user wants to modify is asked. Then, a list of all employee attributes (except for `Employee Status`) is displayed; subsequently, the user is asked to select 1 attribute, and enter a new value for that attribute. The user is then asked to confirm the changes.

#### Fire employees
```
6: Fire employees.
```
Technically, we could have asked the user to simply use **feature #5** to modify an employee's `Employee Status` attribute to `False`. However, we want to provide a faster way for the user to modify that attribute quickly without having to go through the process of choosing it.

A list of employees is shown. The user is asked to input a line that contains the index of the employees to be fired. Then, the user is also asked to make confirmation.

**Firing an employee is not equivalent to completely removing the entire employee record, instead it updates the `Employee Status` attribute to `False`.**

#### Delete employee records
```
7. Delete employee records.
```
A list of employees is shown. The user is asked to input a line that contains the index of the employees to be deleted. Then the user is also asked to make confirmation.

**The data of the `Employee`'s chosen is deleted from memory, and the subsequent output file does not contain the deleted data.**


## Problems and Possible Further Improvements
### 1. Employee Attributes
Our implementation of the `Employee` class can be greatly improved. Currently, the number of attributes is fixed at 10, and there is no way that the program user is allowed to create more attributes. In our view, one of the ways to dynamically manage attributes is by using a `struct` to store each attribute. The proposed implementation is as follows:
```
struct Attribute {
  string key; // attribute name such as "First Name"
  string type; // attribute type such as "string"
  string value; // attribute value such as "Janvi"
}
```
Then, the `Employee` class will store a vector of `Attributes`, and it will also contain setter and getter functions.

### 2. Code Modularity
As our `Employee` class implementation is rather rigid, it has been quite difficult to call functions in a more DRY way, so we ended up with a lot of WET code. For example, we have separate functions for `getFirstName` and `getLastName`, in which both deal with the `string` data type. Hence, we have used a great deal of switches to handle each `Employee` attribute differently.

Therefore, the first thing to do is to solve **Problem 1**, and use the greatly improved `Employee` class to make the code base more modular.

### 3. File I/O
For the purpose of this project, our file i/o methods are also quite rigid in the sense that file formats must conform to those rules aforementioned. There is considerable room for improvement in this area.
