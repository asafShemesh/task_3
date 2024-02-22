#include <stdio.h>
#include <string.h>
#include "StrList.h"

int main()
{
    StrList *list = StrList_alloc();
    int num;
    scanf("%d", &num);
    while (num != 0)
    {
        if (num == 1)
        {
            int rounds;
            scanf("%d", &rounds);
            while (rounds != 0)
            {
                char s;
                scanf("%s", &s);
                StrList_insertLast(list, &s);
                rounds = rounds - 1;
            }
            num = 0;
        }
        StrList_print(list);
    }
    if (num == 2)
    {
        int index;
        scanf("%d", &index);
        char userInput[50];
        scanf("%s", userInput);
        StrList_insertAt(list, userInput, index);
    }
    if (num == 3)
    {
        StrList_print(list);
    }
    if (num == 4)
    {
        printf(StrList_size);
    }
    if (num == 5)
    {
        int index;
        scanf("%d", &index);
        StrList_printAt(list, index);
    }
    if (num == 6)
    {

        StrList_printLen(list);
    }
    if (num == 7)
    {
        char userInput[50];
        scanf("%s", userInput);
        printf(StrList_count(list, userInput));
    }
    if (num == 8)
    {
        char userInput[50];
        scanf("%s", userInput);
        StrList_remove(list, userInput);
    }
    if (num == 9)
    {
        int index;
        scanf("%d", &index);
        StrList_removeAt(list, index);
    }
    if (num == 10)
    {
        StrList_reverse(list);
    }
    if (num == 11)
    {
        StrList_free(list);
    }
    if (num == 12)
    {
        StrList_sort(list);
    }
    if (num == 13)
    {
        if (StrList_isSorted(list))
        {
            printf("true");
        }
        else
        {
            printf("false");
        }
    }

    scanf("%d", &num);

    return 0;
}