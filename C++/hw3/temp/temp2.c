/* C/C++ program for Memoized version for nth Fibonacci number */
#include<stdio.h>

#include<time.h>

#define NIL -1
#define MAX 100

int lookup[MAX];

/* Function to initialize NIL values in lookup table */
void _initialize()
{
int i;
for (i = 0; i < MAX; i++)
	lookup[i] = NIL;
}

/* function for nth Fibonacci number */
int fib(int n)
{
if (lookup[n] == NIL)
{
	if (n <= 1)
		lookup[n] = n;
	else
		lookup[n] = fib(n-1) + fib(n-2);
}

return lookup[n];
}

int main ()
{
int n = 40;

clock_t begin, end;

double time_spent;

_initialize();

begin = clock();

printf("Fibonacci number is %d \n", fib(n));

end = clock();

time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

printf("\nTime Taken %lf\n", time_spent);

return 0;
}
