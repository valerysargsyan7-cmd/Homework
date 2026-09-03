# Soccer Team DataBase
A C program demonstrating struct-based records, nested per-field input validation, an aggregation helper function, and a linear scan to find the top-scoring player.
## Description
This program prompts the user to enter a name and 5 game-by-game goal counts for 3 players, storing each as a `struct Player` record in an array. Input is validated at every step, and the whole read stops immediately if any field is invalid or a goal count is negative. Once input succeeds, the program sums each player's goals via a helper function, scans for the player with the highest total, and prints that player's full record.
## Features
- Struct-based storage (`struct Player`) for name, per-game goals, and total goals.
- Interactive per-field console input prompts with validation, including a rejection of negative goal counts.
- Status-returning input function so the caller can detect and stop on failure instead of continuing with incomplete data.
- Bounded name input (`%49s`) to prevent buffer overflow.
- Separate aggregation function (`summing_goals`) to compute each player's total.
- Linear scan (`best_index_return`) to determine the top-scoring player.
- Error handling for invalid name, goal, or negative-goal inputs.
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
./soccer_team_db
```
## Usage Examples
**Best Player Example:**
```text


Soccer Team DataBase

Inputing info

Enter 1th player name: Alice
Enter goals for 1th player, game 1: 1
Enter goals for 1th player, game 2: 2
Enter goals for 1th player, game 3: 0
Enter goals for 1th player, game 4: 3
Enter goals for 1th player, game 5: 1

Enter 2th player name: Bob
Enter goals for 2th player, game 1: 0
Enter goals for 2th player, game 2: 1
Enter goals for 2th player, game 3: 1
Enter goals for 2th player, game 4: 0
Enter goals for 2th player, game 5: 0

Enter 3th player name: Carl
Enter goals for 3th player, game 1: 2
Enter goals for 3th player, game 2: 2
Enter goals for 3th player, game 3: 2
Enter goals for 3th player, game 4: 2
Enter goals for 3th player, game 5: 2


Best player

Name: Carl
Game 1 goals: 2
Game 2 goals: 2
Game 3 goals: 2
Game 4 goals: 2
Game 5 goals: 2
Total Goals: 10
```
**Invalid Input Error Example:**
```text


Soccer Team DataBase

Inputing info

Enter 1th player name: Alice
Enter goals for 1th player, game 1: 1
Enter goals for 1th player, game 2: 2
Enter goals for 1th player, game 3: 0
Enter goals for 1th player, game 4: 3
Enter goals for 1th player, game 5: 1

Enter 2th player name: Bob
Enter goals for 2th player, game 1: 0
Enter goals for 2th player, game 2: x
[ERROR] Invalid goals value for player 2.
```
**Negative Goals Error Example:**
```text


Soccer Team DataBase

Inputing info

Enter 1th player name: Alice
Enter goals for 1th player, game 1: 1
Enter goals for 1th player, game 2: 2
Enter goals for 1th player, game 3: 0
Enter goals for 1th player, game 4: 3
Enter goals for 1th player, game 5: -1
[ERROR] Goals cannot be negative.
```
