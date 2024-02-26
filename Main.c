#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StrList.h"

char *inputString(FILE *fp, size_t size)
{
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str) * size);
    if (!str)
        return str;
    while (EOF != (ch = fgetc(fp)) && ch != '\n')
    {
        str[len++] = ch;
        if (len == size)
        {
            str = realloc(str, sizeof(*str) * (size += 16));
            if (!str)
                return str;
        }
    }
    str[len++] = '\0';

    return realloc(str, sizeof(*str) * len);
}

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

            char *input = inputString(stdin, 100);
            char *token = strtok(input, " ");
            int wordCount = 0;

            while (token != NULL && wordCount < index)
            {
                StrList_insertLast(list, token);
                token = strtok(NULL, " ");
                wordCount++;
            }
        }

        else if (num == 2)
        {
            int index;
            scanf("%d", &index);
            char *userInput = inputString(stdin, 100);
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
            char *userInput = inputString(stdin, 100);
            scanf("%s", userInput);
            printf("%d", StrList_count(list, userInput));
            printf("\n");
        }
        else if (num == 8)
        {
            char *userInput = inputString(stdin, 100);
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