#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _cat
{
    char name[50];
    int place;
    int age;
}cat;

int todo(const void *a, const void *b);
int main()
{
    int N, M;
    while((scanf("%d%d", &N, &M)) != EOF)
    {
            cat cats[10010];
        for(int i = 0; i < N; i++)
        {
            char identity[50];
            scanf("%s%s%d", cats[i].name, identity, &(cats[i].age));
            switch(identity[0])
            {
                case 'e':
                    cats[i].place = 1;
                    break;
                case 'n':
                    cats[i].place = 2;
                    break;
                case 'k':
                    cats[i].place = 3;
                    break;
                case 'w':
                    cats[i].place = 4;
                    break;
                case 'a':
                    cats[i].place = 5;
                    break;
                case 'm':
                    cats[i].place = 6;
                    break;
                case 'd':
                    cats[i].place = 7;
                    break;
                case 'l':
                    cats[i].place = 8;
                    break;
            }

        }
        qsort(cats, N, sizeof(cat), todo);
        for(int i = 0; i < M && i < N; i++)
        {
            printf("%s\n", cats[i].name);
        }

    }
}



int todo(const void *a, const void *b)
{
    cat A = *(cat *) a;//強制轉型
    cat B = *(cat *) b;
    if(A.place == B.place)
    {
        if(A.age > B.age) return A.place == 5? 1:-1;
        else if (A.age < B.age) return A.place == 5? -1:1;
        else if (A.age == B.age) return strcmp(A.name, B.name);
    }
    else if(A.place < B.place) return -1;
    else if(A.place > B.place) return 1;
}




