# Library
A C program demonstrating enum-tagged union storage, struct composition, per-type input branching, and multiple linear-scan helper functions to manage a small library catalog.
## Description
This program prompts the user to enter a media type (Book, Magazine, or DVD) and type-specific details for 4 library items, storing each as a `struct LibraryItem`. A `union MediaInfo`, tagged by an `enum MediaType`, holds either a page count, an issue number, or a duration depending on the item's type. Input is validated at every step, and the whole read stops immediately if any field is invalid. Once input succeeds, the program prints all items, computes the total price, and reports the cheapest item.
## Features
- Enum-tagged union storage (`union MediaInfo` + `enum MediaType`) for type-specific fields sharing one memory slot.
- Struct-based storage (`struct LibraryItem`) combining title, type, info, and price.
- Per-type input and display branching via `switch` statements.
- Status-returning input function so the caller can detect and stop on failure instead of continuing with incomplete data.
- Bounded title input (`%49s`) to prevent buffer overflow.
- Separate helper functions to compute total price and find the cheapest item.
- Variable-length array (`items[n]`) sized from a runtime value.
- Error handling for invalid or unknown media type, and for invalid type-specific fields.
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
./library
```
## Usage Examples
**Library Example:**
```text


Library


Inputing information

Enter type of object 0-BOOK, 1-MAGAZINE, 2-DVD: 0

Enter title of book: Dune

Enter pages of book: 400

Enter price of book: 15.99

Enter type of object 0-BOOK, 1-MAGAZINE, 2-DVD: 1

Enter title of magazine: Time

Enter issue number: 12

Enter price of magazine: 3.99

Enter type of object 0-BOOK, 1-MAGAZINE, 2-DVD: 2

Enter title of film: Matrix

Enter duration of film min: 136

Enter price of film: 9.99

Enter type of object 0-BOOK, 1-MAGAZINE, 2-DVD: 0

Enter title of book: Hobbit

Enter pages of book: 300

Enter price of book: 12.50

------ -----

Name: Dune
Pages: 400
Price: 15.99

Name: Time
Issue number: 12
Price: 3.99

Name: Matrix
Duration: 136
Price: 9.99

Name: Hobbit
Pages: 300
Price: 12.50

------ ------

Total: 42.47

--Cheapest--

Name: Time
Issue number: 12
Price: 3.99
```
**Invalid Input Error Example:**
```text


Library


Inputing information

Enter type of object 0-BOOK, 1-MAGAZINE, 2-DVD: 0

Enter title of book: Dune

Enter pages of book: 400

Enter price of book: 15.99

Enter type of object 0-BOOK, 1-MAGAZINE, 2-DVD: 1

Enter title of magazine: Time

Enter issue number: x
[ERROR] Invalid issue number!
```