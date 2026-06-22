# CS 210: Corner Grocer Item-Tracker

A data analysis and reporting utility designed for the Corner Grocer to analyze daily transaction logs. This application processes unstructured text data to track purchase frequencies, helping store management optimize the physical layout of the produce section based on consumer demand.

---

## Project Summary
The Corner Grocer application solves a data-tracking problem by converting a raw, newline-separated text file of item sales into structured, actionable insights. Developed in C++ using an Object-Oriented design, the system reads daily transactional records, aggregates the data to compute exact purchase frequencies, and generates an automated data backup file (`frequency.dat`). It provides a clean, interactive console interface for store managers to look up specific items, view alphabetical lists of all items sold, and print graphical data histograms.

---

## Reflection and Portfolio Review

### 1. What did you do particularly well?
The selection and implementation of the core data structure were executed well. By choosing a standard ordered map (`std::map<std::string, int>`) over an unordered hash map, the application natively leverages the underlying balanced binary search tree layout. This architectural choice automatically alphabetizes the keys upon insertion. As a result, the application seamlessly fulfills the business requirements for ordered list and histogram displays without requiring additional sorting algorithms, minimizing computational overhead.

### 2. Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
While the text parsing is robust, the current string lookup system is strictly case-sensitive. If a user queries "apples" instead of "Apples", the search returns zero results despite the item being present. An impactful enhancement would involve integrating a string-standardization helper method that handles user queries with case-insensitivity.

### 3. Which pieces of the code did you find most challenging to write, and how did you overcome this?
The most challenging component to write cleanly was the interactive menu loop's exception-handling block in `main.cpp`. Preventing terminal lockups and infinite loops during input type mismatches (such as a user entering text where an integer is expected) required meticulous management of the input stream. I overcame this challenge by implementing a precise recovery sequence using `std::cin.clear()` to reset the stream fail state, followed by `std::cin.ignore()` to purge invalid data from the buffer before explicitly throwing a `std::runtime_error`. 

### 4. What skills from this project will be particularly transferable to other projects or course work?
The file I/O handling, data serialization routines, and robust input streaming defense pipelines built for this project are highly transferable to upcoming advanced software engineering tracks. Specifically, the principles of data encapsulation, const-correctness for member functions, and defensive runtime exception handling will directly translate to building enterprise-grade backend systems in Java, C++, and database applications.

### 5. How did you make this program maintainable, readable, and adaptable?
This application adheres strictly to professional structural guidelines. By separating the codebase cleanly across three files (`main.cpp`, `GroceryTracker.cpp`, and `GroceryTracker.h`), the program establishes a clear separation of concerns where the user interface does not depend on data-storage details. Readability and long-term maintainability are guaranteed by utilizing strict industry naming standards—such as distinguishing private class member variables with the `m_` prefix and function parameters with the `t_` prefix—along side modular function blocks protected by robust header guards.
