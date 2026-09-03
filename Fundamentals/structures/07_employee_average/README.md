# Employees DataBase
A C program demonstrating struct-based records, nested per-field input validation, average computation with overflow-safe summing, and a linear scan to find the highest-average employee.
## Description
This program prompts the user to enter a name and 6 salary values for 3 employees, storing each as a `struct Employee` record in an array. Input is validated at every step, and the whole read stops immediately if any field is invalid. Once input succeeds, the program computes each employee's average salary (summing into an `unsigned long long` to avoid overflow before dividing), scans for the employee with the highest average, and prints that employee's full record.
## Features
- Struct-based storage (`struct Employee`) for name, salaries, and average.
- Interactive per-field console input prompts with validation.
- Status-returning input function so the caller can detect and stop on failure instead of continuing with incomplete data.
- Bounded name input (`%49s`) to prevent buffer overflow.
- Overflow-safe summing (`unsigned long long`) before computing the integer average.
- Linear scan (`largest_average_counting`) to determine the highest-average employee.
- Error handling for invalid name or salary inputs.
- Standard C17 compliant code.
## Requirements
- C Compiler (`gcc` or `clang`)
- `make` utility
## Building
To compile the project, run:
```bash
make
```
To clean up built binaries:
```bash
make clean
```
## Running
Run the compiled executable:
```bash
./employees_db
```
## Usage Examples
**Highest Average Example:**
```text


Employees DataBase

Info input

Enter 1th Employee's name: Alice
Enter 1th Employee's 1 salary: 3000
Enter 1th Employee's 2 salary: 3200
Enter 1th Employee's 3 salary: 3100
Enter 1th Employee's 4 salary: 3300
Enter 1th Employee's 5 salary: 3400
Enter 1th Employee's 6 salary: 3500

Enter 2th Employee's name: Bob
Enter 2th Employee's 1 salary: 2500
Enter 2th Employee's 2 salary: 2600
Enter 2th Employee's 3 salary: 2400
Enter 2th Employee's 4 salary: 2700
Enter 2th Employee's 5 salary: 2500
Enter 2th Employee's 6 salary: 2600

Enter 3th Employee's name: Carl
Enter 3th Employee's 1 salary: 4000
Enter 3th Employee's 2 salary: 4100
Enter 3th Employee's 3 salary: 3900
Enter 3th Employee's 4 salary: 4200
Enter 3th Employee's 5 salary: 4300
Enter 3th Employee's 6 salary: 4400


Employee information

Name: Carl
1th Salary: 4000
2th Salary: 4100
3th Salary: 3900
4th Salary: 4200
5th Salary: 4300
6th Salary: 4400
Average: 4150
```
**Invalid Input Error Example:**
```text


Employees DataBase

Info input

Enter 1th Employee's name: Alice
Enter 1th Employee's 1 salary: 3000
Enter 1th Employee's 2 salary: 3200
Enter 1th Employee's 3 salary: 3100
Enter 1th Employee's 4 salary: 3300
Enter 1th Employee's 5 salary: 3400
Enter 1th Employee's 6 salary: 3500

Enter 2th Employee's name: Bob
Enter 2th Employee's 1 salary: x
[ERROR] Invalid salary for employee 2.
```