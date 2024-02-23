#ifndef _APPLICATIONS_H_ 
#define _APPLICATIONS_H_

#include <limits>
// Sum of first 'n' natural numbers
// 
//---Establishing recurrence relationship---
// Given,
//			1 + 2 + 3 + ... + n
//
// For 'n' number,
//			Sum(n) = 1 + 2 + 3 + ... + (n-1) + n -------------------- [1]
//							where,
//								n = last tern
//								n-1 = second last term
//
// Now, since eqn[1]
//			Sum(n) = Sum(n-1) + n
//
// Therefore, recurrence relation:
//				 	0			if n = 0	base case
//		   	Sum(n) =  	
//                   			Sum(n-1) + n		if n > 0	recursive call

int sum_recursive(int n) 
{
	if (n == 0)
		return 0;

	return sum_recursive(n - 1) + n;
}


// Using formula 
int sum_form(int n) 
{
	int sum = n * (1 + n) / 2;
	return sum;
}

// Using loop
int sum_iterative(int n)
{
	int sum = 0, i;
	for (i = 1; i <= n; i++)
	{
		sum += i;
	}

	return sum;
}


// Factorial of a number
//
//---Establishing recurrence relationship---
// We know,
//			n! = 1 * 2 * 3 * ... + n
//			0! = 1
//			1! = 1
//
// For 'n' number,
//			Fact(n) = 1 * 2 * 3 * ... * (n-1) * n -------------------- [1]
//							where,
//								n = last tern
//								n-1 = second last term
//
// Now, since eqn[1]
//			Fact(n) = Fact(n-1) * n
//
// Therefore, recurrence relation:
//					1			if n = 1	base case
//			Fact(n) =  	
//                    			Fact(n-1) * n		if n > 1	recursive call

int fact_recursive(int n)
{
	if (n == 1)
		return 1;
	else if (n > 1)
		return fact_recursive(n - 1) * n;
	else
		return std::numeric_limits<int>::max();	 // check for -ve input
}

// Using loop
int fact_iterative(int n)
{
	int result = 1, i;
	for (i = 1; i <= n; i++)
	{
		result *= i;
	}

	return result;

}

// Exponent
//
//---Establishing recurrence relationship---
// We know,
//			m^n = m * m * m * ... * n time
//			m^0 = 1
//
// For 'm' base and 'n' power,
//			Pow(m, n) = m * m * m * ... * (n-1) times * m -------------------- [1]
//							where,
//								m = last tern
//								n-1 times = till second last term
//
// Now, since eqn[1]
//			Pow(m, n) = Pow(m, n-1) * m
//
// Therefore, recurrence relation:
//					1			if n = 0	base case
//			Pow(m, n) =  	
//                      		Pow(m, n-1) * m		if n > 1	recursive call

int pow_recursive(int m, int n)
{
	if (n == 0)
		return 1;
	
	return pow_recursive(m, n - 1) * m;
}


// 2^8 = (2*2)^4 
// 2^9 = 2 * 2^8 = 2 * (2*2)^4
double pow_optimized(double m, double n)
{
	if (n == 1)		// also, n == 1
		return m;   	// also, return m;

	if ((static_cast<int>(n)) % 2 == 0)
		return pow(m * m, n / 2);		// if even power
	else
		return pow(m * m, (n - 1) / 2) * m; 	// if odd power
}

// Taylor series (e^x)
//
//---Establishing recurrence relationship---
// We know,
//			e^x = 1 + x/1 + x^2/2! + x^3/3! + ... + nth term
//			
//
// There are total 3 operations combinedly happening in the above equation.
//
//			Sum(n) = 1 + 2 + 3 + ... + (n-1) +  n
//	
//					0			if n = 0	base case
//			Sum(n) =  	
//                      		Sum(n-1) + n		if n > 0	recursive call
//
//			Fact(n) = 1 * 2 * 3 * ... * (n-1) *  n
//	
//					1			if n = 1	base case
//			Fact(n) =  	
//                      		Fact(n-1) * n		if n > 0	recursive call
//
//			Pow(x, n) = 1 + 2 + 3 + ... + (n-1) +  n
//	
//					1			if n = 1	base case
//			Pow(x, n) =  	
//                      		Pow(x, n-1) * x		if n > 0	recursive call
//
// When Input: double x = 2.0
//	       double n = 5.0
//
//	       taylor(x, n) = 1 + 2/1 + 2^2/2! + 2^3/3! + 2^4/4! + 2^5/5!
//			    = 1 + 2 + 2 + 1.333333 + 0.666666 + 0.266666
//	                    = 7.266667

double taylor(double x, double n)
{
	static double power = 1, factorial = 1;
	double result;

	if (n == 0)
		return 1;

	result = taylor(x, n - 1);		// recursive call

	power = power * x;			// executes at Returning time
	factorial = factorial * n;		// executes at Returning time

	return result + (power / factorial);	// executes at Returning time
}


// Taylor series using Horner's Rule
// We know,
//			e^x = 1 + x/1 + x^2/2! + x^3/3! + x^4/4!
//
// Taking common multiple,
//				  x         x     x^2     x^3
//		   	     1 + --- [ 1 + --- + ----- + --------]
//			          1	    2     2*3     2*3*4
//
//				   x	    x          x       x^2
//			   = 1 + ----[ 1 + --- [ 1 + ----- + ------] ]
//                                 1        2          3       3*4
//
//                                x        x          x           x
//                        =  1 + ---[ 1 + ----[ 1 + -----[ 1 + ------- * 1] ] ]
//                                1        2          3           4
//
// Now we have reduced the number of multiplication

double taylor_optimized(double x, double n)
{
	static double result = 1;

	if (n == 0)
		return result;

	result = 1 + result*x/n;	// processing done at Calling time

	return taylor_optimized(x, n - 1);
}

double taylor_iterative(double x, double n)
{
	double result = 1, numerator = 1, denominator = 1;

	int i;
	for (i = 1; i <= n; i++)
	{
		numerator = numerator * x;
		denominator = denominator * i;

		result = result + numerator / denominator;
	}

	return result;
}


// Fibonacci series
//
// Except 0th and 1th term, all other terms are obtained by adding immdediate previous two terms
//
//				0		if n = 0	base case
//		Fib(n) =  	
//                     		1		if n = 1	
//									
//	 		Fib(n-2) + Fib(n-1)	if n > 1

int fib_recursive(int n)
{
	if (n <= 1)
		return n;

	return fib_recursive(n - 2) + fib_recursive(n - 1);
}


int fib_optimized(int n, int mem[])
{
	if (n <= 1)
	{
		mem[n] = n;
		return n;
	}
	else
	{
		// Check if the value for the element is already memoized
		if (mem[n - 2] == -1)			
			mem[n - 2] = fib_optimized(n - 2, mem);

		if (mem[n - 1] == -1)
			mem[n - 1] = fib_optimized(n - 1, mem);

		mem[n] = mem[n - 2] + mem[n - 1];

		return mem[n - 2] + mem[n - 1];
	}
}

int fib_iterative(int n)
{
	int term0 = 0, term1 = 1, result;
	
	if (n <= 1)
		return n;

	int i;
	for (i = 2; i <= n; i++)
	{
		result = term0 + term1;
		term0 = term1;
		term1 = result;
	}

	return result;
}

// Combination using formula
//	nCr = n!/(n-r)!.r!
//			where,
//				n = number of items
//				r = number of spaces

int combi_iterative(int n, int r)
{
	int numerator, dinominator;

	numerator = fact_iterative(n);
	dinominator = fact_iterative(n - r) * fact_iterative(r);

	return numerator / dinominator;
}

// Combination using Pascal's Triangle
//	
//				    0C0 = 1
//			            /    \
//	    		           /      \     
//			      1C0 = 1    1C1 = 1
//			      /      \   /     \ 
//			     /        \ /       \
//                       2C0 = 1     2C1 = 2    2C2 = 1
//			  /    \      /    \    /     \
//                       /      \    /      \  /       \
//                   3C0 = 1    3C1 = 3     3C2 = 3    3C3 = 1 
//
// From above pattern, we can observer, for instance in order to get 3C1,
//				
//		First previous term = (n-1)C(r-1)
//              Second previous term = (n-1)Cr
// Therefore,
//		nCr = (n-1)C(r-1) + (n-1)Cr

int combi_recursive(int n, int r)
{
	if (r == 0 || n == r)
		return 1;

	return combi_recursive(n - 1, r - 1) + combi_recursive(n - 1, r);
}


// Tower of Hanoi
//
// For n = 3, src = 1, aux = 2, dest = 3,
//				
//				3,1,2,3
//      		       /   |   \
//                            /    |    \
//			     /	   |     \
//                 ----------      |       ----------
//		  |		   |	             |
//             2,1,3,2           1 to 3            2,2,1,3      
//	      /   |   \                           /   |   \					
//           /    |    \			 /    |    \ 
//   	    /     |     \			/     |     \
//      1,1,2,3  1 to 2  1,3,1,2           1,2,3,1  2 to 3   1,1,2,3
//     /  |   \          /  |   \          /  |   \          /  |   \    
//    /	  |    \        /   |    \        /   |    \        /   |    \
//   /    |     \      /    |     \      /    |     \      /    |     \
//  X   1 to 3   X    X   3 to 2   X    X   2 to 1   X     X   1 to 3   X
//
//
//	toh(number of disk, source tower, auxiliary tower, destination tower)
//		=> the behaviour of the towers will change through out the process
//		=> the disk "moved from" will be the source
//		=> the disk "moved to" will be the destination
//		
//		=> print statement will be executed only for the disk 
//                 moved from source(a) to destination(c) as per the method signature (main step)
void toh(int n, int a, int b, int c)
{
	if (n > 0)
	{
		toh(n - 1, a, c, b);
		printf("Moved from %d to %d\n", a, c);
		toh(n-1, b, a, c);
	}
}


#endif
