# ATM Machine Simulation

## Overview
This project is a simple ATM Machine Simulation built using C++. It allows users to perform basic banking operations such as opening a bank account. Additional features like withdrawing money, depositing money, and loan requests are planned for future development.

## Features
- Open a bank account
- Generate a random account number
- Set up a secure MPIN code
- Store user data in a text file (`data.txt`)
- Read and write data from a file
- Basic user authentication with MPIN (future implementation)
- Placeholder functions for money withdrawal, deposit, and loan requests



## How to Use
1. Run the program.
2. Choose an option from the menu:
   - Press `1` to open a new bank account.
   - Press `2` to withdraw money (**under development**).
   - Press `3` to deposit money (**under development**).
   - Press `4` to request a loan (**under development**).
   - Press `5` to exit the program.
3. Follow the prompts to enter your details.
4. If opening a new account, an account number will be generated and saved.
5. Set up an MPIN for secure transactions.

## File Handling
- The program stores user data in `data.txt`.
- If the file is empty, it writes a header row before storing data.
- Each new account entry is appended to the file.

## Future Enhancements
- Implement withdrawal, deposit, and loan request functionalities.
- Add transaction history logging.
- Implement user authentication using the MPIN.
- Improve data security with encryption.
- Develop a GUI-based version.

## Author
- **Samir Dhakal**
- **Email:** [samirdhakal.9279@gmail.com]

## License
This project is open-source and available under the MIT License.

