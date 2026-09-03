# Students DataBase
A C program demonstrating struct-based record storage, interactive console input with validation across multiple fields, and linear scanning to find the highest-graded record.
## Description
This program prompts the user to enter a name, age, and grade for 3 students, storing each as a `struct StudentInfo` record in an array (`student[3]`) while validating every input. It then scans the array to find the student with the highest grade and prints that student's full record.
## Features
- Struct-based storage (`struct StudentInfo`) for name, age, and grade fields.
- Interactive per-field console input prompts and validation.
- Bounded name input (`%19s`) to prevent buffer overflow.
- Linear scan to determine the highest-graded student.
- Error handling for invalid name, age, or grade inputs.
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
./students_database
```
## Usage Examples
**Highest Grade Example:**
```text


Students DataBase

Enter name for student 1: Alice
Enter age for student 1: 20
Enter grade for student 1: 8.5
Enter name for student 2: Bob
Enter age for student 2: 22
Enter grade for student 2: 9.2
Enter name for student 3: Carl
Enter age for student 3: 19
Enter grade for student 3: 7.8

Student with highest grade:
Name: Bob
Age: 22
Grade: 9.20
```
**Invalid Input Error Example:**
```text


Students DataBase

Enter name for student 1: Alice
Enter age for student 1: x
Error: Invalid age input.
```