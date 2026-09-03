# Shop Discounts

A simple C program demonstrating standard input processing, input validation, range checking, and percentage calculations for grocery item pricing using integer arithmetic.

## Description

This program prompts the user to enter prices for three items (tomatoes, potatoes, and bananas) and a discount percentage between 0 and 100 from standard input (`stdin`). It validates all inputs to ensure non-negative prices and a valid discount percentage range, computes the discounted price for each item using standard integer arithmetic, and displays the final price breakdown.

## Features

- Interactive command-line prompts for item prices and discount percentage.
- Comprehensive input validation catching non-numeric values.
- Bounds checking ensuring non-negative prices and discount values between 0% and 100%.
- Integer arithmetic percentage calculations using `long long` integers.
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
./shop_discounts
```

## Usage Examples

**Valid Input Example:**

```text
Shop discounts

Enter tomato price: 100
Enter potato price: 50
Enter banana price: 200
Enter discount percent (0 - 100): 10

Tomato price with 10% discount: 90
Potato price with 10% discount: 45
Banana price with 10% discount: 180
```

**Negative Price Error Example:**

```text
Shop discounts

Enter tomato price: -10
Error: Prices cannot be negative.
```

**Invalid Discount Percentage Example:**

```text
Shop discounts

Enter tomato price: 100
Enter potato price: 50
Enter banana price: 200
Enter discount percent (0 - 100): 150
Error: Discount must be between 0 and 100.
```

**Invalid Input Example:**

```text
Shop discounts

Enter tomato price: free
Error: Invalid input. Please enter a valid price.
```