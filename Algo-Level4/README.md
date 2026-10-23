# Algo-Level4: Bank System with Login + Dates Library

Part of Dr. Mohammad Abo Hadhoud's C++ roadmap. This level extends the Level 3 bank console app with a **login system** and **user management**, and adds a standalone **dates library**.

> **Platform:** Windows only (uses `Windows.h`, `conio.h`, and `system("cls")`).

## What's New Compared to Level 3

- Login screen that authenticates against `Users.txt`
- "Manage Users" menu (list users implemented; add, delete, update and find are still stubs)
- "Logout" returns to the login flow
- New `Algo.h` dates library (see below)

## Project Structure

| File | Description |
|------|-------------|
| `Bank2.h` | UI layer: login, main menu, transactions menu, manage users menu |
| `Algo1.h` | Bank logic (`Client`, `Bank` and `StringMan` namespaces, file I/O, user listing) |
| `Algo.h` | Dates library (`Date`, `Period`, and the namespaces below) |
| `Users.txt` | User accounts file |

## Main Features

**Clients** (same as Level 3)
- List, add, delete, update and find clients
- Deposit, withdraw and total balances

**Users**
- Login with username and password
- List users
- Add / delete / update / find users (menu entries exist, not implemented yet)

## Data Storage

Clients are stored in `clients.txt` and users in `Users.txt`, one record per line, fields separated by `###`.

Users format:

```
Username###Password###Permissions
```

Default account:

```
Admin###1234###-1
```

## Dates Library (`Algo.h`)

| Namespace | Contents |
|-----------|----------|
| `StringManip` | Replace a word in a string |
| `Dates` | Leap year, days/hours/minutes/seconds in a month or year, day name and order, month and year calendars, date comparison, difference in days, age in days, date validation, number to text |
| `IncreaseDates` | Add days, weeks, months, years, decades, century, millennium |
| `DecreaseDates` | Subtract days, weeks, months, years, decades, century, millennium |
| `DateDetails` | Weekend and business day checks, days until end of week/month/year, vacation days and return date |
| `Periods` | Read a period, overlap check, period length, date in period, overlap days count |

## Build & Run

Requirements: Windows, a C++17 compiler (MSVC / Visual Studio recommended).

Create a `main` that includes `Bank2.h` and starts with the login screen:

```cpp
#include "Bank2.h"

int main() {
	printLoginScreen();
}
```

Build as a Console Application in Visual Studio / Rider, or with MSVC:

```
cl /EHsc /std:c++17 main.cpp /Fe:bank.exe
```

Keep `Users.txt` in the working directory.

## Known Limitations

- Windows-specific APIs.
- Passwords are stored in plain text.
- Manage Users options 2 to 5 are not implemented yet.
- Screens navigate by calling each other recursively instead of returning to a loop.
- Minimal input validation.