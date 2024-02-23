#ifndef _TYPES_H_ 
#define _TYPES_H_

#include <iostream>


// Tail recursion
// Last statement of the function is the Recursive call
void fun_tail(int n)
{
    if (n > 0)              // base condition  
    {
        printf("%d ", n);   // executes at Calling time
        fun_tail(n - 1);   // recursive call => Last statement
    }
}


// Head recursion
// Function has statements to process after recursive call
void fun_head(int n)
{
    if (n > 0)
    {
        fun_head(n - 1);   // recursive call
        printf("%d ", n);   // executes at Returning time
    }
}


// Returning recursive function
int fun_return(int n) {

    if (n > 0)
        return fun_return(n - 1) + n;   // computation happens at Returning time
    
    return 0;
}

// Returning recusive function and static variable
int fun_static(int n)
{
    static int z = 0;   // only one copy inside code section 

    if (n > 0)
    {
        z++;
        return fun_static(n - 1) + z;  
    }

    return 0;
}


// Tree Recursion
// Function calls itself more than once
//
// When, input: int n = 3
//                            fun(3)
//                           /  |   \
//                          /   |    ---------------------------------------------------
//                         /    |                                                       \
//                        3    fun(2)                                                 fun(2)
//                           /  |   \                                                /  |   \
//                          /   |    -------------------                            /   |    -------------------
//                         /    |                       \                          /    |                       \
//                        2   fun(1)                   fun(1)                     2   fun(1)                   fun(1)  
//                           /  |   \                  /  |   \                      /  |   \                  /  |   \
//                          /   |    \                /   |    \                    /   |    \                /   |    \
//                         /    |     \              /    |     \                  /    |     \              /    |     \
//                        1   fun(0)  fun(0)        1   fun(0)  fun(0)            1   fun(0)  fun(0)        1   fun(0)  fun(0)
//                              |       |                 |       |                     |       |                 |       |
//                              |       |                 |       |                     |       |                 |       |  
//                            return   return           return   return               return   return           return   return       
//
// 
// Output: 3 2 1 1 2 1 1
void fun_tree(int n)
{
    if (n > 0)
    {
        printf("%d ", n);  // executes at Calling time
        fun_tree(n - 1);   // recursive call
        fun_tree(n - 1);   // recursive call
    }
}


// Indirect Recursive Functions
// Both functions call eachother in cycle
// Function prototype declaration
void fun_indirectB(int);

void fun_indirectA(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        fun_indirectB(n - 1);          // calls B
    }
}

void fun_indirectB(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        fun_indirectA(n / 2);          // calls A
    }
}


// Nested Recursion
// Function calls itself passing itself as parameter
//
// When input: int n = 100
// Inner call -> 111
// Outer call -> 101 -> 91
//
// Output: 100 111 101
int fun_nested(int n)
{
    printf("%d ", n);

    if (n > 100)
    {
        return n - 10;
    }
    else
        return fun_nested(fun_nested(n + 11));
}


#endif
