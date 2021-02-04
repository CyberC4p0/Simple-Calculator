#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STRING_SIZE 50
#define ARRAY_SIZE 20

/*int addition( );
int subtraction(int );
int multiplication(int );
int division(int );
*/
int main()
{
	char *operator;
	char equation[STRING_SIZE] = {'\0'};

	printf("*Format* Ex: 5+6\n"); 
	scanf("%s", equation);
	operator = strchr(equation, '+');

	while (operator != NULL)
	{
		printf("found at %ld\n", operator - equation + 1);
		operator = strchr(operator + 1, '+');		
	}
	
	char *position;
	long int numbers[ARRAY_SIZE] = {0};
	int place = 0;

	numbers[place++] = strtol(equation, &position, 10);
	while (*position)
	{
		if (isdigit(*position))
		{
			numbers[place++] = strtol(position, &position, 10);
		}
		else
		{
			position++;
		}
	}

	int arraySize = sizeof(numbers)/sizeof(int);

	for (int i = 0; i < arraySize; i++)
	{
		printf("numbers[%d] = %ld\n", i, numbers[i]);
	}
	
	int sum = 0;
	for (int i = 0; i < arraySize; i++)
	{
		int sum = sum + numbers[i];
		printf("The sum is: %d\n", sum);
	}
}
