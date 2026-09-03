# Vehicle
A C program demonstrating struct-based state, pointer-modifying functions to simulate filling a fuel tank and driving, and validation across multiple input stages.
## Description
This program prompts the user to enter a vehicle's brand, year, and starting fuel level, then an amount of fuel to add and a distance to drive, all via standard input (`stdin`), storing the vehicle as a `struct Vehicle`. It fills the tank via a pointer-modifying `fill_tank` function (rejecting negative amounts or overfilling past 60 units), simulates driving via a `driver` function that consumes 0.08 fuel per kilometer and stops early if fuel runs out, and finally prints the remaining fuel.
## Features
- Struct-based state (`struct Vehicle`) for brand, year, and fuel level.
- Pointer-modifying functions (`fill_tank`, `driver`) that mutate the vehicle in place.
- Validation of initial fuel (0–60), fill amount (non-negative, capped at 60 total), and distance (non-negative).
- Per-kilometer fuel consumption simulation that stops early and reports when fuel runs out.
- Error handling at every input stage, and for invalid fill or drive conditions.
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
./vehicle
```
## Usage Examples
**Vehicle Example:**
```text


Vehicle


Entering vehicle info

Enter your Vehicle brand: Toyota

Enter your Vehicle year: 2020

Enter your Vehicle fuel: 20

Enter amount to fill your fuel: 10

Enter distance: 100

Fuel left: 22.00
```
**Too Much Fuel Error Example:**
```text


Vehicle


Entering vehicle info

Enter your Vehicle brand: Toyota

Enter your Vehicle year: 2020

Enter your Vehicle fuel: 50

Enter amount to fill your fuel: 20

[ERROR] Too much fuel!

Enter distance: 10

Fuel left: 49.20
```
**Out of Fuel While Driving Example:**
```text


Vehicle


Entering vehicle info

Enter your Vehicle brand: Toyota

Enter your Vehicle year: 2020

Enter your Vehicle fuel: 1

Enter amount to fill your fuel: 0

Enter distance: 1000

[ERROR] No fuel!

Fuel left: 0.04
```
**Failed Input Error Example:**
```text


Vehicle


Entering vehicle info

Enter your Vehicle brand: [ERROR] Failed to read vehicle brand!
```