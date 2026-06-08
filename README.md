# Mini Phonebook Application 📱

A lightweight, Command Line Interface (CLI) contact management system built in C. This project serves as Milestone 1 on my path to mastering Embedded C, focusing heavily on manual memory management, structured data, and pointer manipulation without relying on high-level abstractions.

## 🧠 Key Learning Objectives & Core Concepts
This project bridges the gap between basic syntax and low-level system design by integrating three fundamental C concepts:
* **Structures (`struct`):** Defines the blueprint for custom `Contact` data types (e.g., matching character arrays for names and phone numbers).
* **Dynamic Arrays:** Utilizing pointer-to-pointer architecture or dynamic arrays to hold a collection of contacts.
* **Dynamic Memory Allocation (`stdlib.h`):** * Using `malloc` / `calloc` to provision memory dynamically at runtime.
  * Implementing `realloc` to scale the phonebook capacity dynamically when the array fills up.
  * Using `free()` to prevent memory leaks, ensuring optimal heap management.

## 🛠️ Features
- [x] **Create Contact:** Add a new entry with names, numbers, and custom fields.
- [x] **Dynamic Scaling:** Automatically doubles the contact array size when maximum capacity is reached.
- [x] **Search & Update:** Efficiently traverse memory arrays to find or modify entry details.
- [x] **Memory Cleanup:** Cleanly frees all allocated blocks on program exit.

## 📋 Technical Implementation Details
Unlike standard desktop applications where memory is cheap, this project implements a strict boundary layout, a habit essential for resource-constrained microcontroller programming:

[ Heap Memory Allocation Structure ]
+-------------------+-------------------+-------------------+
| Contact 0 (Struct)| Contact 1 (Struct)| Contact 2 (Struct)| ... (Dynamically Expanded)
+-------------------+-------------------+-------------------+
| - Name (char[])   | - Name (char[])   | - Name (char[])   |
| - Phone (char[])  | - Phone (char[])  | - Phone (char[])  |
+-------------------+-------------------+-------------------+


## 🚀 How to Compile and Run

Ensure you have a C compiler (like `gcc`) installed.

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/your-username/your-repo-name.git](https://github.com/your-username/your-repo-name.git)
   cd your-repo-name
Compile the source code:

Bash
gcc main.c -o phonebook
Run the executable:

Bash
./phonebook
   
