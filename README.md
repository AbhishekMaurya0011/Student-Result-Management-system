# Student Result Management System

A **Student Result Management System** developed in **C Language** that allows users to manage student records, calculate results, search, update, delete, display, and save records to a file. The project demonstrates the use of **Arrays, Structures, Functions, File Handling, and Input Validation**.

---

## 📌 Features

- Add new student records
- Validate Roll Number and Student Name
- Enter subject-wise marks
- Automatically calculate:
  - Total Marks
  - Percentage
  - Grade
- Search student by Roll Number
- Display all student records
- Update student details
- Delete student records
- Save all records to a text file

---

## 📚 Subjects

The system stores marks for the following five subjects:

- English
- Mathematics
- Science
- Computer
- Social Science

---

## 🛠 Technologies Used

- C Programming Language
- Arrays
- Structures
- Functions
- File Handling
- Standard C Libraries

---

## 📂 Project Structure

```
StudentResultManagementSystem
│
├── main.c
├── StudentResult.txt   (Generated after saving records)
└── README.md
```

---

## 📋 Menu Options

```
1. Add Student
2. Search Student
3. Display All Students
4. Update Student
5. Delete Student
6. Calculate Student Result
7. Save Records To File
8. Exit
```

---

## ⚙️ How It Works

### 1. Add Student
- Accepts Roll Number
- Accepts Student Name
- Accepts marks of five subjects
- Calculates Total, Percentage, and Grade automatically

### 2. Search Student
Searches student details using Roll Number.

### 3. Display Students
Displays all stored student records with subject-wise marks.

### 4. Update Student
Updates existing student information and recalculates results.

### 5. Delete Student
Deletes a student record using Roll Number.

### 6. Calculate Result
Displays Total Marks, Percentage, and Grade of a selected student.

### 7. Save Records
Stores all student records into **StudentResult.txt**.

---

## 📊 Grade Criteria

| Percentage | Grade |
|------------|-------|
| 90 - 100 | A |
| 75 - 89 | B |
| 60 - 74 | C |
| 40 - 59 | D |
| Below 40 | F |

---

## 🧮 Time Complexity

| Operation | Complexity |
|-----------|------------|
| Add Student | O(n) |
| Search Student | O(n) |
| Display Students | O(n) |
| Update Student | O(n) |
| Delete Student | O(n) |
| Save Records | O(n) |

---

## 💾 File Handling

The program creates a file named:

```
StudentResult.txt
```

The file stores:

- Roll Number
- Student Name
- Subject-wise Marks
- Total Marks
- Percentage
- Grade

---

## 📖 Data Structures Used

### Structure

```c
struct Student
```

Stores:

- Roll Number
- Name
- Marks
- Total
- Percentage
- Grade

### Array

```c
struct Student s[MAX];
```

Stores multiple student records.

---

## ▶️ How to Compile

Using GCC:

```bash
gcc main.c -o StudentResult
```

Run the program:

```bash
./StudentResult
```

For Windows:

```bash
StudentResult.exe
```

---

## 📌 Input Validation

The system validates:

- Roll Number (Numeric only)
- Duplicate Roll Numbers
- Student Name (Alphabets and spaces only)
- Marks (0–100 only)

---

## 🎯 Learning Outcomes

This project demonstrates:

- Structures in C
- Arrays
- Functions
- File Handling
- Input Validation
- Searching Algorithms
- Record Management
- Result Calculation
- Console-based Menu Programming

---

## 📷 Sample Output

```
==========================================
STUDENT RESULT MANAGEMENT SYSTEM
==========================================

1. Add Student
2. Search Student
3. Display All Students
4. Update Student
5. Delete Student
6. Calculate Student Result
7. Save Records To File
8. Exit

Enter Your Choice:
```

---

## 👨‍💻 Author

**Student Result Management System**
Developed using **C Programming Language** as an educational project to demonstrate data management using structures, arrays, functions, and file handling.

---
## 📄 License

This project is developed for educational and learning purposes. Feel free to modify and use it for academic projects.
