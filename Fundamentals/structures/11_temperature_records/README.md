# The Coldest and Hottest City
A C program demonstrating struct-based records, interactive per-field input with validation, and separate linear-scan functions to find the temperature extremes among a set of cities.
## Description
This program prompts the user to enter a name and temperature for 5 cities, storing each as a `struct TempRecord` in an array. It then scans the records using two separate functions — `find_hottest` and `find_coldest` — to determine the highest and lowest temperatures, and prints both cities alongside their temperatures.
## Features
- Struct-based storage (`struct TempRecord`) for city name and temperature.
- Interactive per-field console input prompts and validation.
- Bounded city name input (`%29s`) to prevent buffer overflow.
- Separate linear-scan functions to independently determine the hottest and coldest cities.
- Error handling for invalid city name or temperature inputs.
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
./coldest_hottest
```
## Usage Examples
**Coldest and Hottest Example:**
```text


The Coldest and Hottest City


Enter name for 1th city: Cairo

Enter temperature for 1th city: 38.5

Enter name for 2th city: Oslo

Enter temperature for 2th city: -5.2

Enter name for 3th city: Dubai

Enter temperature for 3th city: 42.1

Enter name for 4th city: Moscow

Enter temperature for 4th city: -10.0

Enter name for 5th city: Tokyo

Enter temperature for 5th city: 22.3

Hottest: 42.10, CityName: Dubai
Coldest: -10.00, CityName: Moscow
```
**Invalid Temperature Error Example:**
```text


The Coldest and Hottest City


Enter name for 1th city: Cairo

Enter temperature for 1th city: x
[ERROR] Invalid temperature!
```