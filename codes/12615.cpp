#include<stdio.h>
#include<stdlib.h>

char map[100][100];
char str[11];
int visited[100][100] = {0};
int flag = 0;
int xy[8][2];
int index = 0;
void check(int x, int y, int index)
{

    if(flag == 1) return;
    if(map[x][y] == str[index+1] && visited[x][y] != 1)
    {
        index++;
        int cnt;
        cnt = moveto(x, y);
        for(int i = 0; i < cnt; i++)
        {
        	check(xy[i][0], xy[i][1], index);
        	visited[xy[i][0]][xy[i][1]] = 0;
		}

    }
    visited[x][y] = 1;
	if(index == 8) flag = 1;
}

int moveto(int x, int y)
{
    int count = 0;
    if(map[x+2][y+1] >= 'A' && map[x+2][y+1] <= 'Z')
    {
        xy[count][0] = x+2;
        xy[count][1] = y+1;
        count++;
    }
    if(map[x+1][y+2] >= 'A' && map[x+1][y+2] <= 'Z')
    {
        xy[count][0] = x+1;
        xy[count][1] = y+2;
        count++;
    }
    if(map[x-2][y-1] >= 'A' && map[x-2][y-1] <= 'Z')
    {
        xy[count][0] = x-2;
        xy[count][1] = y-1;
        count++;
    }
    if(map[x-2][y+1] >= 'A' && map[x-2][y+1] <= 'Z')
    {
        xy[count][0] = x-2;
        xy[count][1] = y+1;
        count++;
    }
    if(map[x+2][y-1] >= 'A' && map[x+2][y-1] <= 'Z')
    {
        xy[count][0] = x+2;
        xy[count][1] = y-1;
        count++;
    }
    if(map[x-1][y+2] >= 'A' && map[x-1][y+2] <= 'Z')
    {
        xy[count][0] = x-1;
        xy[count][1] = y+2;
        count++;
    }
    if(map[x+1][y-2] >= 'A' && map[x+1][y-2] <= 'Z')
    {
        xy[count][0] = x+1;
        xy[count][1] = y-2;
        count++;
    }
    if(map[x-1][y-2] >= 'A' && map[x-1][y-2] <= 'Z')
    {
        xy[count][0] = x-1;
        xy[count][1] = y-2;
        count++;
    }
    return count;



}


int main()
{
    str[0]='I';
    str[1]='C';
    str[2]='P';
    str[3]='C';
    str[4]='A';
    str[5]='S';
    str[6]='I';
    str[7]='A';
    str[8]='S';
    str[9]='G';
    //printf("%s\n", str);
    int num;
    scanf("%d", &num);
    getchar();
    //int visited[100][100] = {0};

    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
        {
            char a;
            a = getchar();
            map[i][j] = a;
        }
    }
    /*
    for(int i = 0; i < num; i++)
    {

        printf("%s", map[i]);
        printf("\n");
    }
    */
    //int xy[8][2];
    int back;
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
        {
            back = moveto(i, j);
            for(int k = 0; k < back; k++)
            {
            	if(map[i][j] == str[index]) check(xy[k][0], xy[k][1], index);
                visited[xy[k][0]][xy[k][1]] = 0;
                index = 0;
            }
        }
    }
    if(flag == 1) printf("YES\n");
    else printf("NO\n");
}


