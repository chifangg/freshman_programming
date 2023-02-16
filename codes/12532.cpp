#include <stdio.h>
#include <string.h>
char N[3005];
char M[3005];
int Mmap[27];
int Nmap[27];
int map[3005];
char check[3005][3005];
int yes;
int number;

int main()
{
    scanf("%s %d %s", N, &number, M);
    int lenth=strlen(N);
    int lenthM=strlen(M);
    //the numbers of each kind of letters in A, B are equal.
    for(int i=0; i<lenthM; i++)
    {
        Mmap[M[i]-'a']++;
    }
    for(int i=0; i<number; i++)
    {
        Nmap[N[i]-'a']++;
    }
    int flag=1;
    for(int i=0; i<26; i++)
    {
        if(Nmap[i]==Mmap[i]);
        else
        {
            flag=0;
            break;
        }   
    }
    if(flag==1)
    {
        map[0]=1;
        yes++;
        for(int r=0; r<number; r++)
        {
            check[0][r]=N[r];
        }
    }
    for(int i=number; i<lenth; i++)
    {
        Nmap[N[i-number]-'a']--;
        Nmap[N[i]-'a']++;
        flag=1;
        for(int j=0; j<26; j++)
        {
            if(Nmap[j]==Mmap[j]);
            else
            {
                flag=0;
                break;
            }   
        }
        if(flag==1)
        {
            map[i-number+1]=1;
            yes++;
            for(int r=0; r<number; r++)
            {
                check[i-number+1][r]=N[i-number+1+r];
            }
        }
    }
    // for(int i=0; i<lenth; i++)
    // {
    //     if(map[i]!=0)
    //     printf("%d %s\n", i, check[i]);
    // }
    // printf("%d\n", yes);

    //occurence
    for(int i=0; i<lenth-number+1; i++)
    {
        if(map[i]>0)
        {
            for(int j=i+1; j<lenth-number+1; j++)
            {
                if(strcmp(check[i], check[j])==0)
                {
                    map[i]++;
                    yes--;
                    map[j]--;
                }
            }
        }
    }

    //sort strings
    
    for(int i=0; i<lenth-number+1; i++)
    {
        if(map[i]>0)
        {
            for(int j=i+1; j<lenth-number+1; j++)
            {
                if(map[j]>0  &&  map[j]==map[i])
                {
                    for(int r=0; r<number; r++)
                    {
                        if(check[i][r]<check[j][r])
                        {
                            break;
                        }
                        else if (check[i][r]==check[j][r])
                        { 
                        }
                        else
                        {
                            for(int a=r; a<number; a++)
                            {
                                char temp;
                                temp=check[i][a];
                                check[i][a]=check[j][a];
                                check[j][a]=temp;
                            }
                            int temp1;
                            temp1=map[i];
                            map[i]=map[j];
                            map[j]=temp1;
                            break;
                        }
                    }

                }
                else if(map[j]>map[i])
                {
                    for(int r=0; r<number; r++)
                    {
                        char temp;
                        temp=check[i][r];
                        check[i][r]=check[j][r];
                        check[j][r]=temp;
                    }
                    int temp1;
                    temp1=map[i];
                    map[i]=map[j];
                    map[j]=temp1;
                }
            }
        }
    }
    printf("%d\n", yes);
    for(int i=0; i<lenth-number+1; i++)
    {
        if(map[i]>0)
        {
            for(int k=0; k<number; k++)
            {
              printf("%c", check[i][k]);
            }
            printf(" %d\n", map[i]);
        }
    }
    return 0;
}
