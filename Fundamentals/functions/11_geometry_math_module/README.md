# Static Geometry Math Module
A modular C library project providing geometric formulas (rectangle surface area, circle perimeter) structured as a static utility module with separate header and implementation files.
## Description
This project demonstrates modular mathematical function structuring:
1. **Geometry Library (`geometry.h` / `geometry.c`)**:
   - `rectangle_surface(float length, float width)`: Computes rectangle surface area (\(S = L \times W\)) with dimension positivity checks.
   - `circle_perimeter(float radius)`: Computes circle perimeter/circumference (\(P = 2 \pi r\)).
2. **Driver (`main.c`)**: Captures user dimensions, invokes geometric module routines, and displays formatted floating-point results.
## Project Structure
```text
11_geometry_math_module/
├── geometry.c
├── geometry.h
├── main.c
├── Makefile
└── README.md
```
## Features
- Multi-file modular architecture.
- Floating-point arithmetic and dimension validation.
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
./geometry_math_module
```
## Usage Examples
**Geometry Math Module Output Example:**
```text


Static Geometry Math Module

Enter length of rectangle: 5.5
Enter width of rectangle: 4.0

Enter radius of circle: 3.0

--- Calculation Results ---
Surface of Rectangle (5.50 x 4.00) = 22.00
Perimeter of Circle (r = 3.00)       = 18.85

Program status: DONE
```
