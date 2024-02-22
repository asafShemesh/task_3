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
            int index;
            scanf("%d", &index);
            for (int i = 0; i < index; i++)
            {
                char input[1000];
                scanf("%s", input);
                StrList_insertLast(list, input);
            }
        }

        else if (num == 2)
        {
            int index;
            scanf("%d", &index);
            char userInput[50];
            scanf("%s", userInput);
            StrList_insertAt(list, userInput, index);
        }
        else if (num == 3)
        {
            StrList_print(list);
        }
        else if (num == 4)
        {
            printf("%ld", StrList_size(list));
            printf("\n");
        }
        else if (num == 5)
        {
            int index;
            scanf("%d", &index);
            StrList_printAt(list, index);
        }
        else if (num == 6)
        {

            printf("%d", StrList_printLen(list));
            printf("\n");
        }
        else if (num == 7)
        {
            char userInput[50];
            scanf("%s", userInput);
            printf("%d", StrList_count(list, userInput));
            printf("\n");
        }
        else if (num == 8)
        {
            char userInput[50];
            scanf("%s", userInput);
            StrList_remove(list, userInput);
        }
        else if (num == 9)
        {
            int index;
            scanf("%d", &index);
            StrList_removeAt(list, index);
        }
        else if (num == 10)
        {
            StrList_reverse(list);
        }
        else if (num == 11)
        {
            StrList_free(list);
            list = StrList_alloc();
        }
        else if (num == 12)
        {
            StrList_sort(list);
        }
        else if (num == 13)
        {
            if (StrList_isSorted(list))
            {
                printf("%s", "true");
                printf("\n");
            }
            else
            {
                printf("%s", "false");
                printf("\n");
            }
        }
        scanf("%d", &num);
    }

    StrList_free(list);
    return 0;
}