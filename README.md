# C++ Job Portal with Resume Builder

A console-based Job Portal application developed in C++ using Object-Oriented Programming concepts. The application allows users to register as Job Seekers or Employers, build resumes, post jobs, view available jobs, and apply for positions through an interactive command-line interface.

---

## Features

### User Registration

- Register as a Job Seeker
- Register as an Employer
- Unique username validation
- Secure login authentication

### Job Seeker

- Build and update resume
- View generated resume
- Browse available jobs
- Apply for jobs

### Employer

- Post new job opportunities
- View all posted jobs
- Manage company job listings

### Job Portal

- User authentication
- Job management
- Resume management
- Interactive menu-driven interface

---

# Project Structure

```
JobPortal/
│
├── main.cpp
└── README.md
```

---

# Technologies Used

- C++
- Standard Template Library (STL)
- Smart Pointers (`shared_ptr`)
- Object-Oriented Programming

---

# OOP Concepts Implemented

## Encapsulation

The following classes encapsulate data and related methods:

- Resume
- Job
- User
- JobSeeker
- Employer
- JobPortal

Private data members are accessed only through public member functions.

---

## Abstraction

Each class hides its internal implementation and exposes only necessary operations.

Examples:

- Resume Builder
- Login System
- Job Management
- Dashboard Display

---

## Inheritance

The `User` class acts as the base class.

Derived classes:

- JobSeeker
- Employer

Both inherit common user properties such as:

- Username
- Password
- Email
- User ID

---

## Polymorphism

Runtime polymorphism is implemented using:

- Pure virtual function

```cpp
virtual void displayDashboard() const = 0;
```

Both derived classes override this function to display their respective dashboards.

---

## Dynamic Binding

Uses virtual functions to call the correct dashboard at runtime depending on the logged-in user.

---

## Smart Pointers

Uses `shared_ptr` for automatic memory management.

Examples:

- Users
- Job Listings

Benefits:

- Prevents memory leaks
- Automatic object destruction
- Safer memory handling

---

# Main Classes

## Resume

Responsible for:

- Resume creation
- Resume display
- Resume validation

Stores:

- Name
- Email
- Phone
- Education
- Experience
- Skills

---

## Job

Stores job information including:

- Job Title
- Company Name
- Description
- Required Skills
- Contact Email
- Employer ID

---

## User

Base class containing common user information.

Members:

- Username
- Password
- Email
- User ID

Functions:

- Login
- Dashboard (Virtual)

---

## JobSeeker

Provides:

- Resume Builder
- Resume Viewer
- Job Applications

---

## Employer

Provides:

- Job Posting
- View Posted Jobs

---

## JobPortal

Acts as the controller of the application.

Responsibilities:

- Registration
- Login
- User Management
- Job Management
- Navigation

---

# Application Workflow

```
Start Application
        │
        ▼
    Main Menu
        │
 ┌──────┴─────────┐
 │                │
 ▼                ▼
Register        Login
 │                │
 ▼                ▼
Job Seeker    Employer
 │                │
 ▼                ▼
Build Resume  Post Job
 │                │
 ▼                ▼
View Jobs     View Posted Jobs
 │
 ▼
Apply for Job
 │
 ▼
Logout
```

---

# Key Functionalities

### Registration

- Job Seeker Registration
- Employer Registration
- Duplicate username detection

---

### Authentication

- Username verification
- Password validation
- Secure login

---

### Resume Builder

Users can create resumes containing:

- Name
- Email
- Phone
- Education
- Experience
- Skills

---

### Job Posting

Employers can post jobs with:

- Position
- Company
- Description
- Required Skills
- Contact Email

---

### Job Search

Job seekers can:

- View available jobs
- Select a job
- Apply using their resume

---

# Data Structures Used

- Vector
- Shared Pointer (`shared_ptr`)
- Strings

---

# C++ Features Used

- Classes and Objects
- Constructors
- Inheritance
- Virtual Functions
- Pure Virtual Functions
- Function Overriding
- Smart Pointers
- STL Vector
- Dynamic Casting
- Access Specifiers
- Static Members

---

# Sample Execution

```
Welcome to the C++ Job Portal!

1. Login
2. Register
3. Exit

Register as:

1. Job Seeker
2. Employer

Login Successful!

Job Seeker Dashboard

1. Build Resume
2. View Resume
3. View Jobs
4. Logout
```

---

# Learning Outcomes

This project demonstrates:

- Object-Oriented Programming
- Encapsulation
- Abstraction
- Inheritance
- Runtime Polymorphism
- Dynamic Binding
- Smart Pointer Memory Management
- STL Containers
- Console-Based Application Development

---

# Future Improvements

- File-based data storage
- Database integration (MySQL/SQLite)
- Password encryption
- Job search filters
- Resume export to PDF
- Admin dashboard
- Employer applicant management
- Job recommendation system
- Online application tracking
- GUI version using Qt or C++/CLI

---

# How to Compile

Using g++:

```bash
g++ main.cpp -o job_portal
```

---

# How to Run

Windows:

```bash
job_portal.exe
```

Linux/macOS:

```bash
./job_portal
```

