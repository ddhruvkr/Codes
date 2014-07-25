////////////////////////////////////////////////////////////////////////////////////////
//Author: Roper C. McIntyre
//Date: 23.12.2008
//Description: 'Sieve of Atkin' algorithm in the plain old C
////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	long long int limit,lim;
	long long int wlimit;long long int tmp=0;
	long long int i, j, k, x, y, z;
	unsigned char *sieb;

	printf("Please insert a number up to which all primes are calculated: ");
	scanf("%lld%lld", &lim,&limit);

	sieb = (unsigned char *)calloc(limit, sizeof(unsigned char));

	wlimit = sqrt(limit);

	for(x=lim; x<=wlimit; x++)
	{
		for(y=1; y<=wlimit; y++)
		{
			z = 4*x*x + y*y;
			if(z<=limit && (z%60==1 || z%60==13 || z%60==17 || z%60==29 || z%60==37 || z%60==41 || z%60==49 || z%60==53))
			{
				sieb[z] = !sieb[z];
			}
			z = 3*x*x + y*y;
			if(z<=limit && (z%60==7 || z%60==19 || z%60==31 || z%60==43))
			{
				sieb[z] = !sieb[z];
			}
			z = 3*x*x - y*y;
			if(x>y && z<=limit && (z%60==11 || z%60==23 || z%60==47 || z%60==59))
			{
				sieb[z] = !sieb[z];
			}
		}
	}

	for(i=lim; i<=wlimit; i++)
	{
		if(sieb[i]==1)
		{
			for(j=1; j * i*i <= limit; j++)
			{
				sieb[j*i*i] = 0;
			}
		}
	}

	printf("The following primes have been calculated:\n2\n3\n5");
	while(i<100000)
	{
		if(sieb[i]==1)
		{
			tmp++;
		}i++;
	}
	printf("%lld\n",tmp);
	scanf("%lld", &i);
	return 0;
}
