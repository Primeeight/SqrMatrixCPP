[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/JcsC3B2x)
# Matrix Multiplication

<img src="https://docs.csgrader.org/files/readme/SquareMatrix.svg" height="auto" width="auto" style="border-radius:3%">

## Description
In this assignment, the aim is to understand the core matrix operations (put, get, and multiply)
while managing memory. Memory management is the process of putting values into RAM (memory) 
and ensuring that they follow a proper life cycle. We do this through the 'new' and 'delete' operators in C++. 
To allocate space for a new dynamic variable in memory, do this:
```
    ObjType * ptrName = new ObjType();
```
This makes a pointer to an allocated space (enough space for
whatever type of object you create) in memory. This is how we create memory.
The variable we made does not hold the object itself, but rather just the memory address to 
that object.

Once memory created, it needs to be eventually deleted:
```
    delete ptrName;
```
If memory is not deleted (or deconstructed), it can cause a memory leak. This can lead to situations where the
code can begin writing over someone else's allocated memory or is reading garbage information leftover from a previous 
process. Most notably, this causes the Windows blue screen. Memory leaks are one of the biggest cause of security bugs in
software to this date.

This assignment also covers overloading
operands to perform non-default specified tasks, that being outputting, inputting
and multiplying matrices. 

Follow the documentation in sqrMatrix.h to see what you need to implement and run the "Run Test" task for 
Google_test to see how your code is running.

## Required Tasks
To complete this assignment you must do the following:
- Finish the methods in the SqrMatrix.cpp file
- Have at least **3 total** unit tests in each test file and ensure all tests pass.
- [Have your code coverage be a minimum of 80%](https://www.jetbrains.com/help/idea/running-test-with-coverage.html#run-config-with-coverage).

## Resources
[Matrix Multiplication](https://www.geeksforgeeks.org/cpp-program-to-multiply-two-matrices/)

[Samples](https://github.com/google/googletest/tree/main/googletest/samples)

[Cmake tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

[Google Test docs](https://google.github.io/googletest/quickstart-cmake.html)

[Tutorial on stringstream](https://www.softwaretestinghelp.com/stringstream-class-in-cpp/)




