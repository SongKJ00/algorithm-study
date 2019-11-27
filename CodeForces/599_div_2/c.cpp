#include <iostream>
#include <math.h>
#include <set>
 
long long solution(long long n)
{
    long long tempN = n;
    long long t = 2;
    long long prime = -1;
 
    while(tempN > 1)
    {
        if(t*t > tempN)
        {
            if((prime != -1) && (prime != tempN)) { return 1;}
            else
            {
                prime = tempN;
                break; 
            }
        }
        if(tempN % t == 0)
        {
            tempN /= t;
            if(prime == -1)
            { 
                prime = t;
            }
            else
            {
                if(prime != t) { return 1; }
            }
        }
        else
        {
            t++;
        }
    }
    if(prime == -1) { return n; }
    else { return prime; }
}
 
int main(void)
{
    long long n;
    scanf("%I64d", &n);
    printf("%I64d\n", solution(n));
 
    return 0;
}