//Nikole Solano
//NID: 5252251
//Homework 1 "homework1.c"
//COP3223C Section 1, Fall 2020

#include <stdio.h>

//problem 1
//takes a non-negative integer n as input and returns a non-negative integer containing the sum of n’s digits as output
unsigned int SumOfDigits(unsigned int n)
{
    unsigned int sum = 0;
  
    //i is a temporary value that I used to store the integer value
    for(unsigned int i = n; i > 0; i = i / 10)
    {
        sum = sum + (i % 10);
    }
    return sum;
}

//problem 2
//takes a non-negative integer n as input and prints out all its divisors as output
void PrintDivisors(unsigned int n)
{
    //m is a temporary value that is going to represent the divisors
    for (unsigned int m = 1; m <= n; m = m + 1)
    {
        //if n modulus m is 0, that means that the it evenly divides which makes it a divisor
        if (n % m == 0)
        {
            if(m == n)
            {
                //since an integer is always a divisor of itself, this function is going to print out the inital number last,
                //so we need a new line after it is printed
                printf("%d \n", m);
            }
            else
            {
                //this is just printing out the divisor with a comma and a space in between
                printf("%d, ", m);
            }
        }
    
    }
  
}

//problem 3
// takes two positive integers n and m  as input and returns their binomial coefficient as output
unsigned long GetBinomialCoefficient(unsigned int n2, unsigned int m2)
{
    unsigned long factn = 1; //defining n! in the equation

    for(unsigned int i = 1; i <= n2; i++ )
    {
        factn = factn * i;
    }
    unsigned long factm = 1; //defining m! in the equation

    for(unsigned int i = 1; i <= m2; i++ )
    {
        factm = factm * i;
    }
    unsigned long factm_n=1; //defining (n-m)! in the equation

    for(unsigned int i = 1; i <= (n2-m2); i++)
    {
        factm_n=factm_n*i;
    }
    //this is combining all of the parts of the equation above into one binomial coefficient equation
    unsigned long bc = factn / ((factm) * (factm_n));
    return bc;
}

//bonus question
// Since n is the largest number, you are going to compute m! and (n-m)! when computing n!.
//So you can make one function that finds n! and stores m! and (n-m)! once it reaches those values.
//You can then take all of those values and compute the binomial coefficient.

int main() 
{

    unsigned int num = 17239;
    unsigned int sum=SumOfDigits(num);

    //this is going to print out the sum of the digits of the integer we input
    printf("Sum Of Digits is %d \n", sum);
    printf("\n");
    //I added a newline character here to make the output neater

    unsigned int n = 3150;

    //this will print out the divisors of the input
    printf("Divisors of %d: ", n);
    PrintDivisors(n);
    printf("\n");
  
    unsigned int n2 = 5;
    unsigned int m2 = 2;
    unsigned long bc = GetBinomialCoefficient(n2, m2);

    //this will find the binomial coefficient of the integers we inputed
    printf("Binomial Coefficient of %d, %d is %ld", n2, m2, bc);
    printf("\n");
  
}
