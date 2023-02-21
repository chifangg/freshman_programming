#include<stdio.h>
#include<stdlib.h>
char map[10][10];
int flag = 0;
void teststraight()
{
	//int count = 0;
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			if(map[i][j] == 'o' && map[i+1][j] == 'o' && map[i+2][j] == 'o' && map[i+3][j] == 'o')
			{
				flag = 1;
				return;
			}
			if(map[i][j] == 'x' && map[i+1][j] == 'x' && map[i+2][j] == 'x' && map[i+3][j] == 'x')
			{
				flag = 2;
				return;
			}
		}
	}
}


void testvert()
{
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			if(map[i][j] == 'o' && map[i][j+1] == 'o' && map[i][j+2] == 'o' && map[i][j+3] == 'o')
			{
				flag = 1;
				return;
			}
			if(map[i][j] == 'x' && map[i][j+1] == 'x' && map[i][j+2] == 'x' && map[i][j+3] == 'x')
			{
				flag = 2;
				return;
			}
		}
	}
}

void test3()
{
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			if(map[i][j] == 'o' && map[i+1][j+1] == 'o' && map[i+2][j+2] == 'o' && map[i+3][j+3] == 'o')
			{
				flag = 1;
				return;
			}
			if(map[i][j] == 'o' && map[i-1][j+1] == 'o' && map[i-2][j+2] == 'o' && map[i-3][j+3] == 'o')
			{
				flag = 1;
				return;
			}

			if(map[i][j] == 'x' && map[i+1][j+1] == 'x' && map[i+2][j+2] == 'x' && map[i+3][j+3] == 'x')
			{
				flag = 2;
				return;
			}
			if(map[i][j] == 'x' && map[i-1][j+1] == 'x' && map[i-2][j+2] == 'x' && map[i-3][j+3] == 'x')
			{
				flag = 2;
				return;
			}
		}
	}
}



int main()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            map[i][j] = '-';
        }
    }
    int nowo, nowx;
    int ocount = 5;
    int xcount = 5;
    /*
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            map[i][j] = '-';
        }
    }
    */
    while((scanf("%d %d", &nowo, &nowx)) != '\n')
    {
        if(map[ocount][nowo] == 'o' || map[ocount][nowo] == 'x')
        {
            while(map[ocount][nowo] == 'o' || map[ocount][nowo] == 'x')
            {
                ocount--;
            }
            map[ocount][nowo] = 'o';
            ocount = 5;
            teststraight();
            testvert();
			test3();
            if(flag == 1)
            {
            	printf("o wins!\n");
            	for(int i = 0; i < 6; i++)
                {
                    for(int j = 0; j < 6; j++)
                    {
                        printf("%c ", map[i][j]);
                    }
                    printf("%c", map[i][6]);
                    printf("\n");
                }
                //printf("\n");
                break;

			}
			if(flag == 2)
            {
            	printf("x wins!\n");
            	for(int i = 0; i < 6; i++)
                {
                    for(int j = 0; j < 6; j++)
                    {
                        printf("%c ", map[i][j]);
                    }
                    printf("%c", map[i][6]);
                    printf("\n");
                }
                //printf("\n");
                break;
			}
        }
        else
        {

            map[ocount][nowo] = 'o';
            ocount = 5;
            teststraight();
            testvert();
            test3();
            if(flag == 1)
            {
            	printf("o wins!\n");
            	for(int i = 0; i < 6; i++)
                {
                    for(int j = 0; j < 6; j++)
                    {
                        printf("%c ", map[i][j]);
                    }
                    printf("%c", map[i][6]);
                    printf("\n");
                }
                //printf("\n");
                break;

			}
			if(flag == 2)
            {
            	printf("x wins!\n");
            	for(int i = 0; i < 6; i++)
                {
                    for(int j = 0; j < 6; j++)
                    {
                        printf("%c ", map[i][j]);
                    }
                    printf("%c", map[i][6]);
                    printf("\n");
                }
                //printf("\n");
                break;
			}
        }

        if(map[xcount][nowx] == 'x' || map[xcount][nowx] == 'o')
        {
            //xcount--;
            while(map[xcount][nowx] == 'x' || map[xcount][nowx] == 'o')
            {
                xcount--;
            }
            map[xcount][nowx] = 'x';
            xcount = 5;
            teststraight();
            testvert();
            test3();
            if(flag == 1)
            {
            	printf("o wins!\n");
            	for(int i = 0; i < 6; i++)
                {
                    for(int j = 0; j < 6; j++)
                    {
                        printf("%c ", map[i][j]);
                    }
                    printf("%c", map[i][6]);
                    printf("\n");
                }
                //printf("\n");
                break;

			}
			if(flag == 2)
            {
            	printf("x wins!\n");
            	for(int i = 0; i < 6; i++)
                {
                    for(int j = 0; j < 6; j++)
                    {
                        printf("%c ", map[i][j]);
                    }
                    printf("%c", map[i][6]);
                    printf("\n");
                }
                //printf("\n");
                break;
			}
        }
        else
        {
            map[xcount][nowx] = 'x';
            xcount = 5;
            teststraight();
            testvert();
            test3();
            if(flag == 1)
            {
            	printf("o wins!\n");
            	for(int i = 0; i < 6; i++)
                {
                    for(int j = 0; j < 6; j++)
                    {
                        printf("%c ", map[i][j]);
                    }
                    printf("%c", map[i][6]);
                    printf("\n");
                }
                //printf("\n");
                break;

			}
			if(flag == 2)
            {
            	printf("x wins!\n");
            	for(int i = 0; i < 6; i++)
                {
                    for(int j = 0; j < 6; j++)
                    {
                        printf("%c ", map[i][j]);
                    }
                    printf("%c", map[i][6]);
                    printf("\n");
                }
                //printf("\n");
                break;
			}
        }
    }


}
