/*SPOJ Problem 11: Factorial – FCTRL

This problem boils down to counting how many zeros are at the end of N!, where N can be any number between 1 and 1000000000.

Clearly if we just calculate N!, we would never finish because this would take far too long!

We have to use a bit of math. It turns out that when you start calculating bigger and bigger factorials, more and more zeroes start getting added to the end… for example:

0! = 1
1! = 1
2! = 2
3! = 6
4! = 24
5! = 120 // NOTICE, the first trailing zero has appeared!
6! = 720
7! = 5040
8! = 40320
9! = 362880
10! = 3628800 //  Now there’s 2 zeroes!
11! = 39916800
12! = 479001600
13! = 6227020800
14! = 87178291200
15! = 1307674368000 // Now there’s 3 zeroes?
16! = 20922789888000
17! = 355687428096000
18! = 6402373705728000
19! = 121645100408832000
20! = 2432902008176640000 // Now there’s 4, see a pattern?
…
25! = // Trust me, this number has 6 zeroes, and that’s because 125 has 6 factors of 5



It turns out every single factor of 5 in the number adds another power, so we just need to check how many times the number 5 goes into N.



Here’s a sample implementation, it should be very straight forward to understand :*/



#include <stdio.h>
#include <conio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
        scanf("%lld",&n);
        long long solu=0;
        while(n)
        {
            n = n/5;
            solu+=n;
        }
        printf("%lld\n",solu);
    }
	getch();
    return 0;
}
