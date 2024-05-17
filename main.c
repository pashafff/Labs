#include <stdio.h>
#include "lr.h"

int main(void)
{
    int choice = 0;
    while (choice < 1 || choice>13)
    {
        printf("1) The first laboratory work\n");
        printf("2) The first laboratory work (add)\n");
        printf("3) The second laboratory work\n");
        printf("4) The second laboratory work (add)\n");
        printf("5) The third laboratory work\n");
        printf("6) The third laboratory work (add)\n");
        printf("7) The four laboratory work \n");
        printf("8) The four laboratory work (add)\n");
        printf("9) The five laboratory work \n");
        printf("10) The five laboratory work (add)\n");
        printf("11) The six laboratory work \n");
        printf("12) The six laboratory work (add)\n");
        printf("13) The seven laboratory work \n");
        printf("Enter the number of the desired laboratory work: ");
        scanf("%d", &choice);
    }

    if (choice == 1)
        first();
    else if (choice == 2)
        first_add();
    else if (choice == 3)
        second();
    else if (choice == 4)
        second_add();
    else if(choice == 5)
        third();
    else if(choice == 6)
        third_add();
    else if(choice == 7)
        four();
    else if(choice == 8)
        four_add();
    else if(choice == 9)
        five();
    else if(choice == 10)
        five_add();
    else if(choice == 11)
        six();
    else if(choice == 12)
        six_add();
    else if(choice == 13)
        seven();
    getchar();
}
