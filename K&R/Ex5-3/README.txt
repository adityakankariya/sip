This directory contains solutions and a tester file for K&R Exercise 5-3 and
is being used as a C tutorial for SIP 2016.
Author: Sam Mansfield
Contributors: Sam Mansfield, Akshaya Vemuri, and Aditya Kankariya 

To use the tester program open the ex5_3_tester.c and change the name
of the included header file to the file you want to test.

For simplicity, name your file your_name_strcat.c and your header file
your_name_strcat.h, where your_name is your first name.

Compile the tester program:
> gcc ex5_3_tester.c your_file.c

This will create an object file called a.out. If you want to name the 
object file you can instead use the -o option.

To compile a c program with a named object file:
> gcc -o tester ex5_3_tester.c your_file.c

To run the tester:
> ./a.out
