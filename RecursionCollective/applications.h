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
//									n = last tern
//									n-1 = second last term
//
// Now, since eqn[1]
//			Sum(n) = Sum(n-1) + n
//
// Therefore, recurrence relation:
//					 0					if n = 0	base case
//			Sum(n) =  	
//                   Sum(n-1) + n		if n > 0	recursive call
//
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
//									n = last tern
//									n-1 = second last term
//
// Now, since eqn[1]
//			Fact(n) = Fact(n-1) * n
//
// Therefore, recurrence relation:
//					  1					if n = 1	base case
//			Fact(n) =  	
//                    Fact(n-1) * n		if n > 1	recursive call
//
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
//			m^n = m * m * m * ... * n times
//			m^0 = 1
//
// For 'm' base and 'n' power,
//			Pow(m, n) = m * m * m * ... * (n-1) times * m -------------------- [1]
//							where,
//									m = last tern
//									n-1 times = till second last term
//
// Now, since eqn[1]
//			Pow(m, n) = Pow(m, n-1) * m
//
// Therefore, recurrence relation:
//					    1					if n = 0	base case
//			Pow(m, n) =  	
//                      Pow(m, n-1) * m		if n > 1	recursive call
//
int pow_recursive(int m, int n)
{
	if (n == 0)
		return 1;
	
	return pow_recursive(m, n - 1) * m;
}


// 2^8 = (2*2)^4 
// 2^9 = 2 * 2^8 = 2 * (2*2)^4
int pow_optimized(int m, int n)
{
	if (n == 1)		// also, n == 1
		return m;   // also, return m;

	if (n % 2 == 0)
		return pow(m * m, n / 2);			// if even power
	else
		return pow(m * m, (n - 1) / 2) * m; // if odd power
}


#endif
