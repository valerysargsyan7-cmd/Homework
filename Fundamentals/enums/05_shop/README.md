A C program demonstrating enum-based categorization, struct-based product records, input validation with retry-on-invalid-choice, and per-category filtering and display.
## Description
This program prompts the user to enter a category (FOOD, ELECTRONICS, or CLOTHING), name, and price for 5 products, storing each as a `struct Product` record in an array (`products[5]`). Invalid category numbers are rejected and re-prompted for the same product slot without consuming it. After all products are entered, the program prints the products grouped by category: Electronics, Food, then Clothing.
## Features
- Enum-based category representation (`enum Category`: FOOD, ELECTRONICS, CLOTHING).
- Struct-based storage (`struct Product`) for name, price, and category fields.
- Interactive per-field console input prompts and validation.
- Retry-on-invalid-category logic that re-prompts without skipping a product slot.
- Bounded product name input (`%19s`) to prevent buffer overflow.
- Per-category filtering and display of stored products.
- Error handling for invalid category, name, or price inputs.
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
./shop
```
## Usage Examples
**Shop Example:**
```text


Shop

Enter category 0 - FOOD, 1 - ELECTRONICS, 2 - CLOTHING: 0
Enter product name: Bread
Enter product price: 2.5
Enter category 0 - FOOD, 1 - ELECTRONICS, 2 - CLOTHING: 1
Enter product name: Phone
Enter product price: 599.99
Enter category 0 - FOOD, 1 - ELECTRONICS, 2 - CLOTHING: 9
[ERROR] Invalid category. Please enter 0, 1 or 2.
Enter category 0 - FOOD, 1 - ELECTRONICS, 2 - CLOTHING: 2
Enter product name: Shirt
Enter product price: 19.99
Enter category 0 - FOOD, 1 - ELECTRONICS, 2 - CLOTHING: 2
Enter product name: Jeans
Enter product price: 39.99
Enter category 0 - FOOD, 1 - ELECTRONICS, 2 - CLOTHING: 0
Enter product name: Milk
Enter product price: 1.5

Electronics products:
Phone - 599.99

Food products:
Bread - 2.50
Milk - 1.50

Clothing products:
Shirt - 19.99
Jeans - 39.99
```
**Invalid Price Error Example:**
```text


Shop

Enter category 0 - FOOD, 1 - ELECTRONICS, 2 - CLOTHING: 0
Enter product name: Bread
Enter product price: x
[ERROR] Invalid product price. Please enter a number.
```