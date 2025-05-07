# Library Management System

A comprehensive C++ console application for managing library resources, user accounts, and book transactions.

## 📚 Features

### For Administrators
- **Book Management**
  - Add new books to the library collection
  - Modify existing book records
  - Delete books from the database
  - Search for specific books
  - Display all book records

### For Users
- **Account Management**
  - User registration (sign-up)
  - Secure login system
- **Book Operations**
  - Search for available books
  - Borrow books
  - Return borrowed books
  - View all available books

## 🛠️ Technologies Used
- C++
- File Handling for Data Persistence
- Console UI

## 🔧 System Requirements
- Windows Operating System
- C++ Compiler (preferably with C++11 support or newer)
- Minimum 512MB RAM
- 10MB of free disk space

## 📋 Installation & Setup

1. **Clone the repository**
   ```
   git clone https://github.com/yourusername/library-management-system.git
   ```

2. **Navigate to the project directory**
   ```
   cd library-management-system
   ```

3. **Compile the program**
   ```
   g++ -o library_system main.cpp
   ```

4. **Run the application**
   ```
   ./library_system
   ```

## 💻 Usage

### Login System
The application provides two access levels:
- **Administrator**: Manages the entire library system
- **User**: Accesses user-specific features

### Initial Login
1. Select login type (Admin/User)
2. Enter credentials
3. For first-time users, create an account using the sign-up option

### Admin Functions
- Add new books to the library
- Update book information
- Remove books from the collection
- Search for specific books
- View all books in the library

### User Functions
- Browse available books
- Search for specific titles
- Borrow books
- Return borrowed books

## 📁 File Structure
- `AdminRecord.txt` - Stores administrator credentials
- `UserRecord.txt` - Stores user account information
- `BookRecord.txt` - Contains all book information
- `BorrowedBooks.txt` - Keeps track of borrowed books

## 🧪 Future Enhancements
- Graphical User Interface
- Database integration
- Fine calculation for overdue books
- Book reservation system
- Email notification system

## 🤝 Contributing
Contributions are welcome! Please follow these steps:

1. Fork the repository
2. Create a new branch (`git checkout -b feature-branch`)
3. Make your changes
4. Commit your changes (`git commit -m 'Add some feature'`)
5. Push to the branch (`git push origin feature-branch`)
6. Open a Pull Request

## 📝 License
This project is licensed under the MIT License - see the LICENSE file for details.

## 👨‍💻 Author
Arsal Ajmal

## 🙏 Acknowledgements
- My C++ programming instructor
- Fellow students who provided feedback
- Open source community for inspiration and resources
