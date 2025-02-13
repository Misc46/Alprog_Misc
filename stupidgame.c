#include <stdio.h>
#include <math.h.>
#include <stdlib.h>
#include <time.h>

int points;
char inventory[] = "Fists";
int rnum;
int rand_num()
{
    rnum = rand() % 26;
    return main();
}

int test()
{
    printf("%d", rnum);
}
int main()
{
    int main_choice;
    printf("---CHOOSE ACTION---\n");
    printf("1. Check Health\n");
    printf("2. Check Items\n");
    printf("3. Activities\n");
    printf("4. Sleep\n");
    printf("5. End Game\n");

    printf("Make a choice! : ");
    scanf("%d", &main_choice);
    printf(" \n");

    if (main_choice >= 6 || main_choice <= 0)
    {
        printf("Input a valid choice! :<");
        return main();
    }
    if (main_choice == 2)
    {
        printf("Opening inventory...\n");
        printf("%s", inventory);
    }
    if (main_choice == 3)
    {
        return activities();
    }
    if (main_choice == 5)
    {
        return 0;
    }
}

int activities()
{
    int act, act_choice;
    printf("---CHOOSE ACTIVITIES!---\n");
    printf("1. Play with cat!\n");
    printf("2. Play with dog!\n");
    printf("3. Chill on sofa\n");
    printf("4. Eat food\n");
    printf("5. Explore!\n");
    printf("6. Back to Main Menu\n");
    printf("7. End Game\n");

    printf("Make a choice! : ");
    scanf("%d", &act_choice);

    if (act_choice >= 8 || act_choice <= 0)
    {
        printf("Input a valid choice! :<");
        return activities();
    }
    else if (act_choice == 1)
    { // cat
        act = 10;
        points = points + act;
        printf("Current points : %d\n", points);
        return activities();
    }
    else if (act_choice == 2)
    { // dog
        act = 10;
        points = points + act;
        printf("Current points : %d\n", points);
        return activities();
    }
    else if (act_choice == 3)
    { // sofa-chill
        act = 5;
        points = points + act;
        printf("Current points : %d\n", points);
        return activities();
    }
    else if (act_choice == 4)
    { // eat-food
        act = 5;
        points = points + act;
        printf("Current points : %d\n", points);
        return activities();
    }
    else if (act_choice == 5)
    { // exploration
        if (rnum <= 5)
        {
            char item_sword[] = " ,Sword";
            printf("You got : Sword!\n");
            // inventory = inventory + item_sword; -- will be added soon
            return activities();
        }
        else if (rnum >= 6)
        {
            printf("You took a calm stroll\n");
            return activities();
        }
    }
    else if (act_choice == 6)
    { // return-to-main
        return main();
    }
    else if (act_choice == 7)
    { // ending-game
        return 0;
    }
    if (points >= 100)
    {
        printf("Wow, you win!\n");
        return activities();
    }
}
