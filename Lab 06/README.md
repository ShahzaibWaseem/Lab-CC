# Lab 06: TDP Without Backtracking

## Language used: C

## Tasks

1. Write a C program for constructing of LL (1) parsing.
2. Write a C program for implementing the functionalities of predictive parser
3. Construction of recursive descent parsing for the following grammar

|||
|-|-|
|1|E → T E'|
|2|E'→ + T E'|
|3|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\| e|
|4|T → F T'|
|5|T' → * F T'|
|6|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\| e|
|7|F → (E)|
|8|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\| id|