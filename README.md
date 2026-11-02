# MCSL-209: Data Structures and Algorithms Lab — Submission Repository

This repository contains the complete source code, official question documents, and structural organization for the **MCSL-209 (Data Structures and Algorithms Lab)** Assignment and Practical Lab Record submission. 

---

## 👨‍🎓 Student Details
- **Name:** Gufran
- **Enrollment Number:** 2552562140
- **Course Code:** MCSL-209
- **Course Title:** Data Structures and Algorithm Lab
- **Assignment Number:** BCA_NEW/BCAOL(III)L-209/Assign/2026-27
- **Semester:** 3

---

## 📁 Repository Structure

```text
MCSL-209_Assignment_Submission/
│
├── README.md                                  <-- Repository documentation
│
├── 01_Question_PDFs/                          <-- Official university problem statements
│   ├── MCSL-209_Assignment_DSA-Lab.pdf        <-- Assignment question paper
│   └── MCSL-209_Lab-Manual_DSA-Lab.pdf        <-- Lab manual (40 questions record)
│
├── 02_Assignment_Source_Code/                 <-- Source code and implementation for the assignment
│   └── Question_1/                            <-- Assignment answer code (.c source files)
│
└── 03_Lab_Record_Programs/                    <-- Source code for the 40 lab record questions
    ├── 01_Session-01-02_Arrays/               <-- Arrays (Session 1 & 2)
    ├── 02_Session-03-04_Structures/           <-- Structures (Session 3 & 4)
    ├── 03_Session-05-06_Linked-Lists/         <-- Linked Lists (Session 5 & 6)
    ├── 04_Session-07-08_Stacks/               <-- Stacks (Session 7 & 8)
    ├── 05_Session-09-10_Queues/               <-- Queues (Session 9 & 10)
    ├── 06_Session-11-12_Trees/                <-- Trees and Binary Trees (Session 11 & 12)
    ├── 07_Session-13-14_Advanced-Trees/       <-- Advanced Trees (Session 13 & 14)
    ├── 08_Session-15-16_Graphs/               <-- Graphs (Session 15 & 16)
    ├── 09_Session-17-18_Searching-Sorting/    <-- Searching and Sorting (Session 17 & 18)
    └── 10_Session-19-20_Advanced-Data-Structures/ <-- Advanced Data Structures (Session 19 & 20)
```
---

## ⚙️ Technical Environment & Notes for Evaluators

* **Language:** Standard ISO C (`.c`)
* **Development Environment:** Visual Studio Code using the GCC (MinGW 32-bit) compiler.
* **Compiler Compatibility:** All programs adhere strictly to standard C guidelines and do not depend on legacy Turbo C-specific headers (such as `<conio.h>`, `clrscr()`, or `getch()`). They can be compiled cleanly on any modern standard C compiler using:

```bash
gcc filename.c -o output_name
```

* **Assumptions & Implementation Details:**
  1. **Implicit Assumptions (Unspecified Details):** Where a question or problem statement left certain aspects open or unstated (such as maximum array capacities, input buffer limits, or default menu handling), clean, logical, and robust bounds were assumed to ensure smooth program execution.
  2. **Explicit Assumptions (Directed by Guidelines):** Where the lab manual or question guidelines explicitly instructed to *"make assumptions if necessary"* (such as in specific advanced tree or data structure initialization sequences), structured and valid parameters have been defined accordingly.

*Provided as a clean source code repository to assist assignment evaluators in reviewing, testing, and running the Assignment and Lab Record programs.*
