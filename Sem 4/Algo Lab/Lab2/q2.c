#include <stdio.h>
#include <stdlib.h>

int gcd(int m , int n)
{
	int fact = 2;
	int gcd = 1;
	int k = m;
	int count = 0;
	
	for(fact = 2; fact <= k; fact++)
	{
		count++; // Counting each time the factor is changed
		while(((m % fact) == 0) && ((n % fact) == 0))
		{	
			count++; // Counting each time there is a common factor
			gcd = gcd * fact;
			n = n / fact;
			m = m / fact;
			
			if (m == 0 || n == 0)
			{
				printf("Count = %d\n", count);
				return gcd;
			}
		}
	}
	
	printf("Count = %d\n",count);
	
	return gcd;
}

int main()
{
	int m , n;
	
	printf("Enter two numbers\n");
	scanf("%d %d", &m, &n);
	int i;
	
	printf("The GCD of %d and %d = %d\n", m, n, (n > m)?gcd(m,n): gcd(n, m));	
}