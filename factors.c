#include <stdio.h>
#include <stdlib.h>

/**
 * factorize - find factors of int
 * @n: input int
 */
void factorize(unsigned long long n)
{
	unsigned long long i = 2;

	while (i * i <= n)
	{
		if (n % i == 0)
		{
			printf("%llu=%llu*%llu\n", n, n / i, i);
			return;
		}
		i++;
	}
	printf("%llu=1*%llu\n", n, n);
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
	unsigned long long num;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: ./factors <testfile>\n");
		return (1);
	}

	if (!file)
	{
		perror("Error opening the file\n");
		return (1);
	}

	while (fgets(buffer, sizeof(buffer), file))
	{
		num = atoll(buffer);
		factorize(num);
	}

	fclose(file);
	return (0);
}
