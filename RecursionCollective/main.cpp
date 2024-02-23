#include <iostream>
#include "types.h"
#include "applications.h"


int main()
{
    //----------------------------------Types--------------------------------------//
    int x = 5;
    // Tail recursion
    //fun_tail(x);       // 5 4 3 2 1

    // Head recursion
    //fun_head(x);       // 1 2 3 4 5 

    // Returning recursive function
    //printf("%d", fun_return(x));    // 0 -> 0+1 -> 1+2 -> 3+3 -> 6+4 -> 10+5 -> 15

    // Returning recursive function and static variable  
    //printf("%d", fun_static(x));    // 0 -> 5 -> 5+5 -> 10+5 -> 15+5 -> 20+5 -> 25

    // Tree recursion
    //x = 3;
    //fun_tree(x);

    // Indirect recursion
    //x = 20;
    //fun_indirectA(x);

    // Nested recursion
    //x = 98;
    //fun_nested(x);


    //-----------------------------------Applications-----------------------------------//

    // Sum of n natural numbers
    //x = 10;
    //printf("Sum: %d\n", sum_recursive(x));
    //printf("Sum: %d\n", sum_form(x));

    // Factorial
    //x = 5;
    //printf("Factorial: %d\n", fact_recursive(x));
    //printf("Factorial: %d\n", fact_iterative(x));

    // Exponent
    //printf("Result: %d\n", pow_recursive(4, 7));
    //printf("Result: %d\n", pow_optimized(4, 7));

    // Taylor series
    //printf("Result: %lf\n", taylor(2, 5));
    //printf("Result: %lf\n", taylor_optimized(2, 5));
    //printf("Result: %lf\n", taylor_iterative(2, 5));

    // Fibonacci Series
    //int n = 5;
    //printf("%dth term: %d\n", n, fib_recursive(n));
    //printf("%dth term: %d\n", n, fib_iterative(n));

    //static int mem[10];             // for memoization
    //for (int i = 0; i < 10; i++)
        //mem[i] = -1;

    //printf("%dth term: %d\n", n, fib_optimized(n, mem));

    // Combination (nCr)
    //printf("Combination: %d\n", combi_iterative(4, 2));
    //printf("Combination: %d\n", combi_recursive(4, 2));

    // Tower of Hanoi
    //toh(3, 1, 2, 3);

    std::cin.get();
}

