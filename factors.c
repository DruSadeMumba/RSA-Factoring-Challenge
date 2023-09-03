#include <stdio.h>
#include <stdlib.h>

/**
 * factorize - find factors of int
 * @n: input int
 */
void factorize(long long n)
{
	long long i = 2;

	while (i * i <= 2)
	{
		if (n % i == 0)
		{
			printf("%lld=%lld*%lld\n", n, n / i, i);
			return;
		}
		i++;
	}
	printf("%lld=1*%lld\n", n, n);
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
	char buffer[256], data;
	long long num;

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

	data = fgets(buffer, sizeof(buffer), file);
	while (data)
	{
		num = atoll(buffer);
		factorize(num);
	}

	fclose(file);
	return (0);
}
