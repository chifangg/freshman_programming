#include<stdio.h>
#include<stdlib.h>

int child[200005][2] = {0};
int idx[200005] = {0};
int p[200005] = {0};
int ans = 1;      

void solve(int root, int left, int right);

void solve(int root, int left, int right)
{
	if(!ans) return;
	if(child[root][0] && child[root][1])// 2 children
	{
		if((idx[child[root][0]] > idx[root] && idx[child[root][0]] <= right) && (idx[child[root][1]] < idx[root] && idx[child[root][1]] >= left))
		{
			solve(child[root][0], idx[root]+1, right);
			solve(child[root][1], left, idx[root]-1);
		}
		else if((idx[child[root][1]] > idx[root] && idx[child[root][1]] <= right) && (idx[child[root][0]] < idx[root] && idx[child[root][0]] >= left))
		{
			solve(child[root][1], idx[root]+1, right);
			solve(child[root][0], left, idx[root]-1);
		}
		else ans = 0;
	}
	else if(child[root][0])//left
	{
		if(idx[child[root][0]] < idx[root] && idx[child[root][0]] >= left)
		{
			solve(child[root][0], left, idx[root]-1);
		}
		else if(idx[child[root][0]] > idx[root] && idx[child[root][0]] <= right)
		{
			solve(child[root][0], idx[root]+1, right);
		}
		else ans = 0;
	}
	else if(child[root][1])
	{
		if(idx[child[root][1]] < idx[root] && idx[child[root][1]] >= left)
		{
			solve(child[root][1], left, idx[root]-1);
		}
		else if(idx[child[root][1]] > idx[root] && idx[child[root][1]] <= right)
		{
			solve(child[root][1], idx[root]+1, right);
		}
		else ans = 0;
	}
	else return;
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		//printf("%d\n", n);
		ans = 1;
		for(int i = 0; i <= n; i++)
		{
			p[i] = 0;
			idx[i] = 0;
			child[i][0] = 0;
			child[i][1] = 0; //initialized
		}
		for(int i = 1; i <= n; i++)//from 1
		{
			scanf("%d %d", &child[i][0], &child[i][1]);
			//printf("%d %d\n", child[i][0], child[i][1]);
			p[child[i][0]] = i;
			p[child[i][1]] = i;//save child+p
		}
		for(int i = 1; i <= n; i++)
		{
			int num;
			scanf("%d", &num);
			idx[num] = i;//save infix
			//printf("infix%d\n",i);
		}
		int root;//run
		for(int i = 1; i <= n; i++)
		{
			if(!p[i])
			{
				root = i;
				break;
			}
		}
		solve(root, 1, n);
		if(ans) printf("YES\n");
		else printf("NO\n");
	}
	
	
	
	
	
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
