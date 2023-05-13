# University of Engineering and Technology

## Table of contents

- [Overview](#overview)
  - [Language](#language)
  - [Working](#working)
- [Methodology](#methodology)
  - [Programming Model](#programming-model)
  - [Functions](#functions)
  - [Libraries](#libraries)
- [Author](#author)

## Overview

### Language

This project is made in [C++] programming language.

### Working

-	The welcome screen is displayed to the user.
-	The user is asked to select a choice from the following:
      1. Admission Documentation
      2. Student Enrollment
      3. Library Management
      4. Final Assessment
      5. Events at SCET
-	The program recognizes the wrong input like:
      1. Entering the wrong choice
      2. Entering the gender input wrong
      3. Entering the aggregate an invalid number.
- After entering wrong choices, the program will allow to the user to re-enter the incorrect input.s
-	The choices **1, 4, 5** are text-only.
- On selecting the option **2. Student Enrollment**, the program requires:
      1. Student Name
      2. Father Name
      3. Gender
      4. Aggregate
-	The program then calculates if the aggregate is enough for the enrollment and displays accordingly.
-	If the aggregate is enough, the program enrolls the student and save the student's information in **Student.txt**.
-	On selecting the option **3. Library Management**, the program displays the books available and requires:
      1. Student-ID
      2. Book-ID
- Entering a wrong student-id and book-id will be detected, and user will be asked to re-enter the correct information.
- The student-id with the book-id the student issued will be saved in the file **Record.txt**.
**- Format of Student.txt**
STUDENT-ID | STUDENT-NAME | FATHER-NAME | GENDER | AGGREGATE
**- Format of Library.txt**
BOOK-ID | BOOK-NAME	
- Books should be manually added in the file in the correct format.
**- Format of Record.txt**
STUDENT-ID | BOOK-ID

## Methodology

### Programming Model

This Project is made with the concept of [Intoduction-To-Programming].

### Functions

- void documentation()
- void enroll()
- bool saveStudent(string, string, string, float)
- void issueBook()
- void loadLibrary()
- bool issueRecord(int, int)
- void finalAssessment()
- void events()


### Libraries

- #include <iostream>
- #include <string>
- #include <fstream>
- #include <Windows.h>

## Author

[SumayyahSayyed]
