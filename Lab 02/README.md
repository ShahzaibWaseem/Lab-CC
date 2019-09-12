# Lab 02: Lexical Analyzer

## Language used: C

## Tasks

###1: Write a C program to simulate lexical analyzer for validating operators.

PROGRAM LOGIC :
Read the given input.
If the given input matches with any operator symbol.
Then display in terms of words of the particular symbol.
Else print not a operator.

Example:

Input Enter any operator: *

Output: Multiplication

###2: Write a C program to test whether a given identifier is valid or not

PROGRAM LOGIC :
Read the given input string.
Check the initial character of the string is numerical or any special character , then print it is not a valid identifier. Otherwise print it as valid identifier if remaining characters of string doesn’t contains any special characters except '_'.
Example:

Input: Enter an identifier: first Output: Valid identifier
Input: Enter an identifier:1aqw Output: Not a valid identifier

###3: Write a C Program to Design Lexical Analyzer. Lexical analyzer should ignore redundant spaces, tabs
PROGRAM LOGIC :
Input : Enter the Program: a+b*c (this is just example, program should have the ability to take any given input
Output : The keywords and identifiers are:
a is an identifier b is an identifier c is an identifier
Special characters are +* Total no. of lines are:1