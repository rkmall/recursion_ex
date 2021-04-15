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
    //x = 100;
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
    printf("Result: %d\n", pow_recursive(4, 7));
    printf("Result: %d\n", pow_recursive(4, 7));




    

    std::cin.get();

}

