HOMEWORK 3: MATRIX CLASS


NAME:  Paul Gaddy


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< insert collaborators / resources >
https://www.programiz.com/cpp-programming/examples/matrix-transpose
https://www.codespeedy.com/print-corner-elements-of-matrix-using-cpp/

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  13



ORDER NOTATION:
For each of the functions below, write the order notation O().
Write each answer in terms of m = the number of rows and n = the
number of columns.  You should assume that calling new [] or delete []
on an array will take time proportional to the number of elements in
the array.

get

set

num_rows

get_column

operator<<

quarter

operator==

operator!=

swap_rows

rref (provided in matrix_main.cpp)



TESTING & DEBUGGING STRATEGY: 
Discuss your strategy for testing & debugging your program.  
What tools did you use (gdb/lldb/Visual Studio debugger,
Valgrind/Dr. Memory, std::cout & print, etc.)?  How did you test the
"corner cases" of your Matrix class design & implementation?
I used the visual studio code outputs to debug as well as the homework submission, most of my errors
were related to assertions and unused variables.

EXTRA CREDIT: 
Indicate here if you implemented resize() for extra credit.  
Also document the order notation for your resize() function.



MISC. COMMENTS TO GRADER:  
(optional, please be concise!)

Test case 8 works in the previous version but not this for some reason, here's the copy paste of it
Note: Dr. Memory IGNORED ERRORS do not affect autograding
 1~~Dr.M~~ Dr. Memory version 2.3.0
 2~~Dr.M~~ 
 3~~Dr.M~~ NO ERRORS FOUND:
 4~~Dr.M~~       0 unique,     0 total unaddressable access(es)
 5~~Dr.M~~       0 unique,     0 total uninitialized access(es)
 6~~Dr.M~~       0 unique,     0 total invalid heap argument(s)
 7~~Dr.M~~       0 unique,     0 total warning(s)
 8~~Dr.M~~       0 unique,     0 total,      0 byte(s) of leak(s)
 9~~Dr.M~~       0 unique,     0 total,      0 byte(s) of possible leak(s)
10~~Dr.M~~ ERRORS IGNORED:
11~~Dr.M~~      25 unique,    34 total,  94307 byte(s) of still-reachable allocation(s)
12~~Dr.M~~          (re-run with "-show_reachable" for details)
13~~Dr.M~~ Details: /var/local/submitty/autograding_tmp/untrusted01/tmp/TMP_WORK/test08/./DrMemory-batch.out.2484835.000/results.txt