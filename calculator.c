#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char* math_problem = (char*) malloc(101);
	char* operator;

	printf("Arithmetics Local Library: (Addition, Subtraction, Multiplication, Division)\n");
	printf("Input: ");
	fgets(math_problem, 101, stdin);
	math_problem[strcspn(math_problem, "\n")] = '\0';
	operator = strchr(math_problem, '+');
	printf("Searching for an operator in \"%s\"...\n", math_problem);

	while (operator != NULL)
	{
		printf("Found an operator at %ld\n", operator - math_problem + 1);
		operator = strchr(operator + 1, '+');
	}

	char* pointer;
	int position = 0;
	long int* numbers = (long int*) malloc(100);
	numbers[position++] = strtol(math_problem, &pointer, 10);
	while (*pointer)
	{
		if (isdigit(*pointer))
		{
			numbers[position++] = strtol(pointer, &pointer, 10);
			position++;
		}
		else
		{
			pointer++;
		}
	}
	int array_size = sizeof(numbers) / sizeof(numbers[0]);

	for (int i = 0; i < array_size; i++)
	{
		printf("numbers[%d] = %ld", i, numbers[i]);
	}

	free(math_problem);
	free(numbers);

	return 0;
}
