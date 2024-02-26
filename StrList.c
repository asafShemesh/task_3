#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    char *string;
    struct _node *next;
} Node;

typedef struct _StrList
{
    Node *head;
    size_t size_t;
} StrList;

Node *StrList_nodealloc(const char *data)
{

    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Error allocating memory");
        return NULL;
    }

    if (data != NULL)
    {
        newNode->string = strdup(data);
        if (newNode->string == NULL)
        {
            printf("Error duplicating string");
            free(newNode);
            return NULL;
        }
    }
    else
    {
        newNode->string = NULL;
    }

    newNode->next = NULL;

    return newNode;
}

StrList *StrList_alloc()
{
    StrList *newList = (StrList *)malloc(sizeof(StrList));

    if (newList == NULL)
    {
        printf("Error allocating memory");
        return NULL;
    }
    newList->head = StrList_nodealloc(NULL);
    newList->size_t = 0;

    return newList;
}

void StrList_free(StrList *strList)
{
    if (strList != NULL)
    {
        Node *current = strList->head;
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            free(temp->string);
            free(temp);
        }
        free(strList);
    }
}

size_t StrList_size(const StrList *strList)
{
    return strList->size_t;
}

void StrList_insertLast(StrList *strList, const char *data)
{

    Node *newNode = StrList_nodealloc(data);

    if (strList->head == NULL)
    {
        strList->head = newNode;
    }
    else
    {
        Node *current = strList->head;
        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newNode;
    }

    strList->size_t++;
}

void StrList_insertAt(StrList *StrList, const char *data, int index)
{
    if (index < 0 || index > StrList->size_t)
    {
        return;
    }
    Node *newNode = StrList_nodealloc(data);
    Node *current = StrList->head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = newNode;
    newNode->next = temp;
    StrList->size_t++;
}

char *StrList_firstData(const StrList *StrList)
{
    return StrList->head->next->string;
}

void StrList_print(const StrList *StrList)
{
    if (StrList == NULL || StrList->size_t == 0)
    {
        printf("\n");
        return;
    }
    Node *current = StrList->head->next;
    int count = 0;
    while (current != NULL)
    {
        printf("%s ", current->string);
        current = current->next;
        count++;
    }
    printf("\n");
}

void StrList_printAt(const StrList *Strlist, int index)
{
    if (index >= 0 && index < Strlist->size_t)
    {

        Node *current = Strlist->head->next;
        int count = 0;
        while (count < index)
        {
            current = current->next;
            count++;
        }
        printf("%s ", current->string);
        printf("\n");
    }
}

int StrList_printLen(const StrList *Strlist)
{
    int totalChars = 0;
    Node *current = Strlist->head->next;

    while (current != NULL)
    {
        totalChars += strlen(current->string);
        current = current->next;
    }

    return totalChars;
}

int StrList_count(StrList *StrList, const char *data)
{
    if (StrList == NULL || data == NULL)
    {
        return 0;
    }
    int times = 0;
    int count = 0;
    Node *current = StrList->head->next;
    while (count < StrList->size_t)
    {
        if (strcmp(current->string, data) == 0)
        {
            times++;
        }
        current = current->next;

        count++;
    }
    return times;
}

void StrList_remove(StrList *StrList, const char *data)
{
    if (StrList == NULL || data == NULL)
    {
        return;
    }
    Node *current = StrList->head;
    Node *prev = NULL;

    while (current != NULL)
    {
        if (current->string != NULL && strcmp(current->string, data) == 0)
        {
            Node *temp = current;
            if (prev == NULL)
            {
                StrList->head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            current = current->next;
            free(temp->string);
            free(temp);
            StrList->size_t--;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}

void StrList_removeAt(StrList *strList, int index)
{
    if (strList == NULL || index < 0 || index >= strList->size_t)
        return;
    Node *current = strList->head;
    if (index == 0)
    {
        strList->head = current->next;
        free(current);
        --(strList->size_t);
        return;
    }
    for (int i = 0; i < index && current != NULL; ++i)
    {
        current = current->next;
    }
    if (current == NULL || current->next == NULL)
        return;
    Node *temp = current->next;
    current->next = temp->next;
    free(temp->string);
    free(temp);
    --(strList->size_t);
}

int StrList_isEqual(const StrList *StrList1, const StrList *StrList2)
{
    if (StrList1 == NULL && StrList2 == NULL)
    {
        return 1;
    }

    if (StrList1 == NULL || StrList2 == NULL)
    {
        return 0;
    }

    if (StrList1->size_t != StrList2->size_t)
    {
        return 0;
    }

    Node *current1 = StrList1->head->next;
    Node *current2 = StrList2->head->next;

    while (current1 != NULL && current2 != NULL)
    {
        if (strcmp(current1->string, current2->string) != 0)
        {
            return 0;
        }

        current1 = current1->next;
        current2 = current2->next;
    }

    return 1;
}

StrList *StrList_clone(const StrList *originalList)
{
    if (originalList == NULL)
    {
        return NULL;
    }

    StrList *newList = StrList_alloc();
    if (newList == NULL)
    {
        return NULL;
    }

    Node *current = originalList->head->next;
    while (current != NULL)
    {
        StrList_insertLast(newList, current->string);
        current = current->next;
    }

    return newList;
}

void StrList_reverse(StrList *StrList)
{
    if (StrList == NULL || StrList->head == NULL)
    {
        return;
    }

    Node *current = StrList->head->next;
    Node *prev = NULL;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    StrList->head->next = prev;
}
int StrList_isSorted(StrList *StrList)
{
    if (StrList == NULL || StrList->head == NULL)
    {
        return 0;
    }

    Node *current = StrList->head->next;
    while (current != NULL && current->next != NULL)
    {
        if (strcmp(current->string, current->next->string) > 0)
        {
            return 0;
        }
        current = current->next;
    }

    return 1;
}

void StrList_sort(StrList *StrList)
{
    if (StrList == NULL || StrList_isSorted(StrList) || StrList->head == NULL)
    {
        return;
    }

    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    if (StrList->head->next == NULL)
    {
        return;
    }

    do
    {
        swapped = 0;
        ptr1 = StrList->head->next;
        while (ptr1->next != lptr)
        {
            if (strcmp(ptr1->string, ptr1->next->string) > 0)
            {
                char *temp = ptr1->string;
                ptr1->string = ptr1->next->string;
                ptr1->next->string = temp;
                swapped = 1;
            }

            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
