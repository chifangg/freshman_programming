#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* str[105];
char todo[10];
int len[105];
void Add(int x, char *addstr)
{
    char* tmp = (char*)malloc(sizeof(char)*(len[x]+1));
    strcpy(tmp, str[x]);
    len[x] += strlen(addstr);
    //printf("hi%d\n", len[x]);
    free(str[x]);
    str[x] = (char*)malloc(sizeof(char)*(len[x]+1));
    strcpy(str[x], tmp);
    strcat(str[x], addstr);
    free(tmp);
}
void Delete(int x, int k)
{
    if(k > len[x])
    {
        len[x] = 0;
        free(str[x]);
        str[x] = (char*)malloc(sizeof(char)*(1));
        str[x][0] = '\0';
    }
    else
    {
        len[x] -= k;
        char* tmp = (char*)malloc(sizeof(char)*(len[x]+1));
        strncpy(tmp, str[x], len[x]);
        tmp[len[x]] = '\0';
        free(str[x]);
        //str = (char*)malloc(sizeof(char)*(len[x]+1)); //why i dont need to malloc again???
        str[x] = tmp;

    }
}

void Swap(int x, int y)
{
    char* tmp;
    tmp = str[x];
    str[x] = str[y];
    str[y] = tmp;
    int temp;
    temp = len[x];
    len[x] = len[y];
    len[y] = temp;
}

void Longest(int n)
{
    int start = len[1];
    int rem = 1;
    for(int i = 1; i <= n; i++)
    {
        if(start < len[i])
        {
            start = len[i];
            rem = i;
        }
    }
    printf("%d %s\n", start, str[rem]);
}

void Print(int n)
{
    for(int i = 1; i <= n; i++)
    {
        printf("%s\n", str[i]);
    }
}

int main()
{
    int x, y, k, M, N;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < 105; i++)
    {
        len[i] = 0;
        str[i] = (char*)malloc(sizeof(char)*(1));
        str[i][0] = '\0';
    }
    for(int i = 0; i < M; i++)
    {
        scanf("%s", todo);
        if(todo[0] == 'a' && todo[1] == 'd')
        {
            char addstr[105];
            scanf("%d%s", &x, addstr);
            Add(x, addstr);
        }
        if(todo[0] == 'd')
        {
            scanf("%d%d", &x, &k);
            Delete(x, k);
        }
        if(todo[0] == 's')
        {
            scanf("%d%d", &x, &y);
            Swap(x, y);
        }
        if(todo[0] == 'l')
        {
            Longest(N);
        }
        if(todo[0] == 'a' && todo[1] == 'l')
        {
            Print(N);
        }
    }
    for(int i = 0; i < 105; i++)
    {
        len[i] = 0;
        free(str[i]);
    }
}

