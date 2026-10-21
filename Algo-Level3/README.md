# Bank Management System (C++ Console App)

A console-based bank client management system written in C++. It stores client records in a plain text file and provides a menu-driven interface for managing clients and performing transactions.

> **Platform:** Windows only (uses `Windows.h`, `conio.h`, and `system("cls")`).

## Features

**Client Management**
- Show client list (formatted table)
- Add new client (with duplicate account number check)
- Delete a client (with confirmation)
- Update client info (with confirmation)
- Find a client by account number

**Transactions**
- Deposit
- Withdraw (rejects amounts exceeding the balance)
- Total balances report

## Project Structure

| File | Description |
|------|-------------|
| `Algo-Level3.cpp` | Entry point (`main`), launches the main menu |
| `Bank1.h` | UI layer: menu screens, input prompts, navigation |
| `Algo.h` | Logic layer: `Client` struct and namespaces |

`Algo.h` namespaces:
- `Bank` - client CRUD, file I/O, deposit/withdraw, record printing
- `StringMan` - string helpers (split, join, trim, case conversion, etc.)
- `Matrix` - 3x3 matrix practice utilities
- `Algorithms` - Fibonacci (iterative and recursive)

## Data Storage

Clients are stored in `clients.txt` (created automatically in the working directory), one record per line, fields separated by `###`:

```
AccountNumber###PinCode###Name###Phone###Balance
```

Example:

```
A101###1234###John Doe###0123456789###1500.000000
```

## Build & Run

Requirements: Windows, a C++17 compiler (MSVC / Visual Studio recommended).

With MSVC (Developer Command Prompt):

```
cl /EHsc /std:c++17 Algo-Level3.cpp /Fe:bank.exe
bank.exe
```

Or open the files in Visual Studio / Rider and build as a Console Application.

## Usage

On launch, the main menu appears:

```
[1] Show Client List
[2] Add New Client
[3] Delete A Client
[4] Update Client Info
[5] Find Client
[6] Transactions
[7] Exit
```

Option 6 opens the transactions menu (Deposit, Withdraw, Total Balances, back to Main Menu).

## Known Limitations

- Windows-specific APIs; not portable to Linux/macOS without changes.
- PIN codes and data are stored in plain text.
- Functions are defined in headers (not split into `.cpp` files), so each header should be included from a single translation unit.
- Screens navigate by calling each other recursively rather than returning to a loop.
- Minimal input validation (e.g., non-numeric menu input).

## License

MIT
