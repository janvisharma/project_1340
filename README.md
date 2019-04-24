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
5. How to find out which employees earn more than a specific employee?


### Program Features
The program will be menu driven, and it will contain the following features:
1. Create record of a new employee with details such as ID, name, age, role & salary. Adding this record to the current record of employees.
2. Search for employee records based on certain criteria.
3. Display the list of all employees with job status (currently working or fired).
4. Sort the employee records.
5. Edit the details of a current employee.
6. Fire an employee, update this status in the record of all employees.

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

## Our Data Structure
### Level 1: The Employee Class


### Level 2: Dynamic Array (C++ Vectors) of Employee(s)
We have considered using either dynamic arrays (C++ vector library) or linked lists to store the employee records, and evaluated the pros and cons of each approach. We found out that arrays are more suitable for our application due to a couple of reasons:
- arrays take up less memory space than linked list, and our application may have to deal with a very big number of employees
- a company does not hire / fire employees at a very high rate such that the ability of linked lists to quickly insert / delete employee records would be underused
- the application user is likely to be more interested in quickly looking up an employee record, and updating it; this means, a 'random access' approach using arrays would be better

Hence, a dynamic array using C++ vectors has been implemented.

## Using the Program


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

### 2. Handle User Input
To a certain degree, user inputs are being processed before they influence the program flow. For example, when the user is asked to enter a salary (data type double), the module `handle_user_input` would check if the input can be converted into a double; otherwise, the user will be prompted for a valid input. However, as our `Employee` class implementation is rather rigid, it has been quite difficult to call these functions in a more DRY way, so we eneded up with a lot of WET code.

One of the more acute problems is our handling of user input while creating a new employee (`createNewEmployee` in `navigation`). When asking the user for the new employee's attributes, inputs are being taken using `getline(cin, attribute)`, and converted directly to `string`, `int`, `double` and `boolean` type without any program fallbacks. In other words, if the user enters something that cannot be converted to a double for the `salary` attribute, the program will crash.

Therefore, the first thing to do is to solve **Problem 1**, and use the greatly improved `Employee` class to handle user input.
