# General Test

## Question 1

Please refer to `question1/main.go` file for the code. Two equivalent solutions with identical function signature are provided for this problem.

+ First solution utilises `evenFib1()` function which loops to obtain every third number which is even.
+ Second solution utilises `evenFib2()` function which uses formula to obtain every third number which is even. Formula: F_{n+6} = 4F_{n+3} + F_{n}

## Question 2

Three different data structures to possibly implement `Key:Value` associative array:

1. Hash Map
    + Insert by `Key` = O(1)
    + Delete by `Key` = O(1)
    + Search by `Key` = O(1)
    + Space needed = O(N)
    + Elements are stored randomly and ordered retrieval of `Key` values is difficult
    + Possible key collisions in imperfect hash tables

2. Search Tree: Trie/Prefix Tree/Radix Tree
    + Insert by `Key` = O(m), m is word length
    + Delete by `Key` = O(m), m is word length
    + Search by `Key` = O(m), m is word length
    + Elements are stored in order and traversing the search tree results in ordered retrieval. Provides lexicographical sorting of entries.
    + Supports searching by partial `Key`.

3. Association List
    + Insert new `Key` = O(1)
    + Delete by `Key` = O(N)
    + Search by `Key` = O(N)
    + Space needed = O(N)
    + Elements are stored randomly and ordered retrieval of `Key` values is difficult

## Question 3

Please refer to `question3/main.go` file for the code. The code utilises a recursive solution.

## Question 4

Please refer to `question4/main.go` file for the code. Two equivalent solutions with identical function signature are provided for this problem.

+ First solution utilises `convertBase1(value, base, &output)` function which uses recursive quotient and remainder to convert base of given decimal integer.
+ Second solution utilises `convertBase2(value, base, &output)` function which uses Python's inbuilt `strconv` function to convert base of given decimal integer.
