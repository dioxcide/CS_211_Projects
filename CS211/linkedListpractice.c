#include <stdio.h>
#include <stdlib.h>

typedef struct stack_s{
    int *data;
    int sizeOfStack;
    int topOfStack;
}Stack;

typedef Stack S;

void init(S *sad)
{
    sad->data = (int*)malloc(sizeof(int)*5);
    sad->sizeOfStack = 5;
    sad->topOfStack = 0;
}

int* grow(S *sad)
{
    int *temp;
    sad->sizeOfStack = sad->sizeOfStack+5;
    temp = (int*)realloc(sad->data, sizeof(int)*sad->sizeOfStack);
    return (int*)realloc(temp, sizeof(int)* sad->sizeOfStack);
}

void addToLinkedStack(S *sad, S *sad2, int d)
{

    if(d%2 == 0)
    {
        if(sad->topOfStack == sad->sizeOfStack)
        {
            sad->data = grow(&(*sad));
        }
        sad->data[sad->topOfStack] = d;
        sad->topOfStack++;
    }
    else if (d%2 != 0)
    {
        if(sad2->topOfStack == sad2->sizeOfStack)
        {
            grow(&(*sad2));
        }
        sad2->data[sad->topOfStack] = d;
        sad2->topOfStack++;
    }

}

void printStack(S sad, S sad2)
{
    printf("S: %d", sad.data[0]);
    printf("S2: %d", sad2.data[0]);
}

int main(int argc, char *argv[])
{
    S sad;
    S sad2;
    init(&sad);
    init(&sad2);
    int String;

    FILE *pFile;
    pFile = fopen(argv[1], "r");

    while(fscanf(pFile, " %d", &String) != EOF)
    {
        addToLinkedStack(&sad, &sad2, String);
    }

    //printStack(sad, sad2);
}
