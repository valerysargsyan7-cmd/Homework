# Best Film
A C program demonstrating struct-based records, nested per-field input validation with range checking, average computation, and a linear scan to find the highest-rated movie.
## Description
This program prompts the user to enter a title and 5 individual ratings (0–10) for 5 movies, storing each as a `struct Movie` record in an array. Input is validated at every step — including a range check on ratings — and the whole read stops immediately if any field is invalid. Once input succeeds, the program computes each movie's average rating, scans for the movie with the highest average, and prints that movie's full record.
## Features
- Struct-based storage (`struct Movie`) for title, ratings, and average.
- Interactive per-field console input prompts with validation.
- Range validation rejecting ratings outside 0–10.
- Status-returning input function so the caller can detect and stop on failure instead of continuing with incomplete data.
- Bounded title input (`%49s`) to prevent buffer overflow.
- Linear scan (`highest_rating_film`) to determine the highest-rated movie.
- Error handling for invalid title, rating, or out-of-range rating inputs.
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
./best_film
```
## Usage Examples
**Best Movie Example:**
```text


Best film

Info input

Enter 1th movie title: Matrix
Enter 1th rating for 1th movie: 9
Enter 2th rating for 1th movie: 8
Enter 3th rating for 1th movie: 9
Enter 4th rating for 1th movie: 10
Enter 5th rating for 1th movie: 9

Enter 2th movie title: Cars
Enter 1th rating for 2th movie: 7
Enter 2th rating for 2th movie: 6
Enter 3th rating for 2th movie: 7
Enter 4th rating for 2th movie: 8
Enter 5th rating for 2th movie: 7

Enter 3th movie title: Inception
Enter 1th rating for 3th movie: 10
Enter 2th rating for 3th movie: 9
Enter 3th rating for 3th movie: 10
Enter 4th rating for 3th movie: 10
Enter 5th rating for 3th movie: 9

Enter 4th movie title: Dune
Enter 1th rating for 4th movie: 8
Enter 2th rating for 4th movie: 8
Enter 3th rating for 4th movie: 9
Enter 4th rating for 4th movie: 9
Enter 5th rating for 4th movie: 8

Enter 5th movie title: Tenet
Enter 1th rating for 5th movie: 6
Enter 2th rating for 5th movie: 7
Enter 3th rating for 5th movie: 6
Enter 4th rating for 5th movie: 5
Enter 5th rating for 5th movie: 6


Best movie

Movie title: Matrix
1th Rating: 9
2th Rating: 8
3th Rating: 9
4th Rating: 10
5th Rating: 9
Average: 9
```
**Rating Out of Range Error Example:**
```text


Best film

Info input

Enter 1th movie title: Matrix
Enter 1th rating for 1th movie: 9
Enter 2th rating for 1th movie: 8
Enter 3th rating for 1th movie: 9
Enter 4th rating for 1th movie: 10
Enter 5th rating for 1th movie: 15
[ERROR] Rating must be between 0 and 10.
```
**Invalid Input Error Example:**
```text


Best film

Info input

Enter 1th movie title: Matrix
Enter 1th rating for 1th movie: x
[ERROR] Invalid rating for movie 1.
```