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
2. Search for a specific record via employee ID, name, age or role.
3. Display the list of all employees with job status (currently working or fired).
4. Edit the details of a current employee.
5. Fire an employee, update this status in the record of all employees.
6. Search for all employees with salary greater than a specific entered record.

## Building and Running the Program
We have made using the program a rather simple task for anyone with a Unix-based terminal. Just follow the following instructions, and execute these commands in order. However, you are required to have [git](https://www.atlassian.com/git/tutorials/install-git), [g++ compiler](https://www.cs.odu.edu/~zeil/cs250PreTest/latest/Public/installingACompiler/), and [make](https://www.gnu.org/software/make/) installed.

Clone this github repo.

`git clone https://github.com/janvisharma/project_1340.git`

Go into the project root directory.

`cd project_1340`

Build the main program using make. *Our makefile defaults to compiling main.cpp*

`make`

Start running the program.

`./main`

## Our Data Structure
### The Employee Class
