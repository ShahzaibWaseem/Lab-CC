# Lab 08: Left Recursion & Factoring

## Language used: C

## Tasks

1. Write a C program to remove left factoring.

```
A -> aAB | aBc | aAc
```

2. Construction of recursive descent parsing for the following grammar

```
E -> TE'
E'-> +TE / ε
T -> FT'
T`-> *FT' / ε
F -> (E) / ID
```

3. Consider the following grammar and eliminate left recursion.

```
E -> E + T / T
T -> T x F / F
F -> id
```