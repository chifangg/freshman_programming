#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int N, M;
int queencount, rookcount, place[15];//橫排旗子位置
int who[15];//橫排上是誰
int ans;

void put(int rownum)
{
    if(rownum == N+M)
    {
        ans++;
        return;
    }
    for(int i = 0; i < N+M; i++)
    {
        //queen first!
        place[rownum] = i;
        if(queencount < N)
        {
            who[rownum] = 1;//queen = 1
            queencount++;
            if(check(rownum)) put(rownum+1);
            who[rownum] = 0;//reset this place
            queencount--;
            //put rook (if can)
            if(rookcount < M && check(rownum))
            {
                rookcount++;
                put(rownum+1);
                rookcount--;
            }
        }
        else
        {
            if(rookcount < M && check(rownum))
            {
                rookcount ++;
                put(rownum+1);
                rookcount--;
            }
        }
        place[rownum] = -1;//nothing
    }

}

int check(int rownum)
{
    for(int i = 0; i < rownum; i++)
    {
        if(who[i] || who[rownum])
        {
            if(place[i] == place[rownum] || place[i] - (rownum-i) == place[rownum] || place[i] + (rownum-i) == place[rownum])
            return 0;
        }
        else if(place[i] == place[rownum]) return 0;//rook's
    }
    return 1;
}



int main()
{
    while((scanf("%d%d", &N, &M)) != EOF)
    {
        ans = 0;
        queencount = 0;
        rookcount = 0;
        put(0);
        printf("%d\n", ans);

    }


}
