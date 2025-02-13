#include <stdio.h>
#include <string.h>

int main()
{
    int num1, num2;
    printf("Input 1: ");
    scanf("%d", &num1);
    printf("Input 2: ");
    scanf("%d", &num2);
    char operation[4];
    printf("Type operation type: `sum` `sub` `mult` `div`: ");
    scanf("%4s", operation);

    // Debug prints
    printf("num1: %d, num2: %d, operation: %s\n", num1, num2, operation);

    if (strcmp(operation, "sum") == 0)
    {
        int summed = num1 + num2;
        printf("Result: %d\n", summed);
    }
    else if (strcmp(operation, "sub") == 0)
    {
        int subbed = num1 - num2;
        printf("Result: %d\n", subbed);
    }
    else if (strcmp(operation, "mult") == 0)
    {
        int multed = num1 * num2;
        printf("Result: %d\n", multed);
    }
    else if (strcmp(operation, "div") == 0)
    {
        int dived = num1 / num2;
        printf("Result: %d\n", dived);
    }
    else
    {
        printf("Invalid operation\n");
    }
    char options[2];
    printf("do you want to make an alien tree? Y/N :");
    scanf("%s", &options);
    if (strcmp(options, "Y") == 0)
    {
        printf("Printing Drawing\n");
    }

    return 0;
}