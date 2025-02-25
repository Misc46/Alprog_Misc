#include <stdio.h>

int main()
{
    int n, count = 0, num = 2;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    while (count < n)
    {
        int i = 2, isPrime = 1;

        while (i * i <= num)
        {
            if (num % i == 0)
            {
                isPrime = 0;
                break;
            }
            i++;
        }

        if (isPrime)
        {
            count++;
        }

        if (count < n)
        {
            num++;
        }
    }

    printf("The %dth prime number is: %d\n", n, num);

    return 0;
}
