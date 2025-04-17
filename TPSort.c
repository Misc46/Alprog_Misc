#include <stdio.h>
#include <string.h>

// Urutan warna RGBY (pokemon gen 1)
const char *colorOrder[] = {"red", "green", "blue", "yellow"};
const int colorOrderSize = sizeof(colorOrder) / sizeof(colorOrder[0]);

struct ColorData
{
    char name[100];
    int value;
};

int getColorIndex(const char *name)
{
    for (int i = 0; i < colorOrderSize; i++)
    {
        if (strcmp(name, colorOrder[i]) == 0)
            return i;
    }
    return colorOrderSize;
}

void swap(struct ColorData *a, struct ColorData *b)
{
    struct ColorData temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void sortColors(struct ColorData data[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            int indexA = getColorIndex(data[j].name);
            int indexB = getColorIndex(data[j + 1].name);

            if (indexA > indexB)
            {
                swap(&data[j], &data[j + 1]);
            }
            else if (indexA == indexB)
            {
                if (data[j].value < data[j + 1].value)
                {
                    swap(&data[j], &data[j + 1]);
                }
            }
        }
    }
}

int main()
{
    struct ColorData data[] = {
        {"red", 4},
        {"green", 3},
        {"red", 2},
        {"blue", 1},
        {"green", 5},
        {"blue", 6},
        {"yellow", 1}};

    int size = sizeof(data) / sizeof(data[0]);

    sortColors(data, size);

    for (int i = 0; i < size; i++)
    {
        printf("%s %d\n", data[i].name, data[i].value);
    }

    return 0;
}
