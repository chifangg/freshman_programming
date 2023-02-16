#include<stdio.h>

int visitcount = 1;
int N;
int distance[10][10];
int visited[10];
int total = 0;//total distance
int min = 10000;
int main()
{
    int now = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &distance[i][j]);
        }
    }

    visited[0] = 1;
    count(now);
    printf("%d\n", min);
}
void count(int now)
{
    if(visitcount == N)
    {
        if((total+distance[now][0]) < min)
            min = (total+distance[now][0]);
    }
    else
    {
        for(int i = 0; i < N; i++)
        {
            if(visited[i] != 1)
            {
                visited[i] = 1;
                visitcount++;
                total += distance[now][i];
                count(i);
                visited[i] = 0;
                visitcount--;
                total -= distance[now][i];
            }

        }
    }
}
