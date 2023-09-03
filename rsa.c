#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * isPrime - check if num is prime
 * @x: int
 * Return: True or false
 */
bool isPrime(int x)
{
	int j = 2;

	for (; j <= x/2; j++)
	{
		if (x % j == 0)
			return (false);
	}
	return (true);
}

/**
 * factorize - find factors of int
 * @n: input int
 */
void factorize(unsigned long long n)
{
	long long i = 2;

	while (i * i <= n && n > 1)
	{
		if (n % i == 0)
		{
			if (!isPrime(n / i))
			{
				fprintf(stderr, "%lld doesn't have exclusive prime factors\n", n);
				return;
			}
			else
			{
				printf("%lld=%lld*%lld\n", n, n / i, i);
				return;
			}
		}
		i++;
	}
}

/**
 * main - main func
 * @argc: num of args
 * @argv: vector
 * Return: 0 success or 1 failure
 */
int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	char buffer[256];
	long long num;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (!file)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		return (1);
	}

	while (fgets(buffer, sizeof(buffer), file))
	{
		num = atoll(buffer);
		if (num > 1)
			factorize(num);
		else
			fprintf(stderr, "no prime factors for num: %lld(less than 2)\n", num);
	}

	fclose(file);
	return (0);
}
