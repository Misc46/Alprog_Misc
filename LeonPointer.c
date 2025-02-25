#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void gantinama(char **name, int *size)
{
    int i;
    char temp[1000];

    printf("Masukkin Nama Kamu: ");
    scanf("%s", temp);

    free(*name);

    *name = (char *)malloc((strlen(temp) + 1) * sizeof(char));
    if (*name == NULL)
    {
        printf("Memory cannot be allocated!\n");
        exit(0);
    }
    strcpy(*name, temp);
}

void ASCIIcount(char *name, int *value)
{
    int i;
    *value = 0;
    for (i = 0; i < strlen(name); i++)
    {
        if (name[i] != ' ')
        {
            *value += name[i];
        }
    }
}
int main()
{
    int size = 100;
    char *name;
    char opsi;
    int value = 0;

    name = (char *)malloc((size + 1) * sizeof(char));
    if (name == NULL)
    {
        printf("Memory cannot be allocated!\n");
        exit(0);
    }

    printf("Masukkin Nama Kamu: ");

    int i = 0;
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (i >= size - 1)
        {
            size *= 2;
            name = (char *)realloc(name, size * sizeof(char));
            if (name == NULL)
            {
                printf("Memory cannot be allocated!\n");
                exit(0);
            }
        }
        name[i++] = c;
    }
    name[i] = '\0';

    ASCIIcount(name, &value);

    while (true)
    {
        printf("Opsi (Nama: %s):\n", name);
        printf("a. Value ASCII Nama\n");
        printf("b. Ganti Nama\n");
        printf("c. Exit\n");
        printf("\n");
        scanf(" %c", &opsi);
        printf("\n");
        getchar();
        switch (opsi)
        {
        case 'a':
            ASCIIcount(name, &value);
            printf("\nValue nama Anda adalah %d\n", value);
            break;
        case 'b':
            gantinama(&name, &size);
            getchar();
            break;
        case 'c':
            free(name);
            exit(0);
            break;
        default:
            printf("\nInvalid input!\n");
            break;
        }
    }

    return 0;
}