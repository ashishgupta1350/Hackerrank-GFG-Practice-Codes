// Function to return gcd of a and b
#include<iostream>
#include<cstdio>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
 
// Driver program to test above function
int main()
{
    int a = 10, b = 15;
    printf("GCD(%d, %d) = %d \n", a, b, gcd(a, b));
    a = 35, b = 15;
    printf("GCD(%d, %d) = %d \n", a, b, gcd(a, b));
    a = 31, b = 2;
    printf("GCD(%d, %d) = %d \n", a, b, gcd(a, b));
    return 0;
}