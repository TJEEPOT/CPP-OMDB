# What It Does #
This project is a port of my previous [Java Offline Movie Database](https://github.com/TJEEPOT/Java-OMDB) project to C++, similar to the C port. This helped me to understand the difference between Object Oriented Programming in Java and C++ and allowed me to use more modern features from C++11 to optimise the design and readability of my program. Here, I have split the contents of the Java classes into C++ headers and .cpp files, where the headers define the class and the cpp files give the implementation of those classes.

# What I Learned #
As I hadn't used C++ for a couple years, this project had me reacquainted with the basics, like **file I/O**. This was my introduction to **OOP**, **struts** and **enums** in C++ and I was introduced to **C++ Header** files, **operator overloading**, **inline statements** and **shared_ptr**.

# Usage Notes #
Compile the contents of \src with your favorite compiler. Ensure that films.txt is located in your executable folder - a version of this file has been provided in the repository root.

The program processes films.txt according to the tasks listed in main.cpp and outputs to stdout the answers to those questions. There are no command line arguments for this program.