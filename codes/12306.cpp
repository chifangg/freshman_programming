#include<iostream>
#include<stack>
#include<map>
#include<algorithm>
#include<string>
#include<list>
#include<queue>

using namespace std;
struct State {
	int lv, hp, mhp;
	int lvcount;
	State(int lv, int hp, int mhp, int lvcount = 0): lv(lv), hp(hp), mhp(mhp), lvcount(lvcount) {}
};

bool vis[20][310][410];// level my_hp monster_hp
int main()
{
	int lv, hp, mhp, mdmg;
	int dmg[20], hl[20];
	cin >> lv >> hp >> mhp >> mdmg;
	for (int i = 1; i <= lv; i++)
		cin >> dmg[i] >> hl[i];
	queue<State> BFSq;//the queue for BFS
	BFSq.push(State(1, hp, mhp));//the initial state
	
	while(!BFSq.empty())
	{
		State s = BFSq.front();
		if (!s.mhp)
			break;
		BFSq.pop();
		
		
		if (s.lv < lv && s.hp - mdmg > 0) //can increase the lv
		{
			State t(s.lv + 1, s.hp - mdmg, s.mhp, s.lvcount + 1);
			if (!vis[t.lv][t.hp][t.mhp]) //haven't been
			{
				vis[t.lv][t.hp][t.mhp] = true;
				BFSq.push(t);
			}
		}
		
		if (s.hp - mdmg > 0 || s.mhp - dmg[s.lv] <= 0) 
		{
			State t(s.lv, s.hp - mdmg, max(0, s.mhp - dmg[s.lv]), s.lvcount + 1);
			if (!vis[t.lv][t.hp][t.mhp]) 
			{
				vis[t.lv][t.hp][t.mhp] = true;
				BFSq.push(t);
			}
		}
		
		if (hp > mdmg && hl[s.lv] > mdmg)//hp full
		{
			State t(s.lv, min(hp, s.hp + hl[s.lv]) - mdmg, s.mhp, s.lvcount + 1);
			if (!vis[t.lv][t.hp][t.mhp]) 
			{
				vis[t.lv][t.hp][t.mhp] = true;
				BFSq.push(t);
			}
		}

	}
	
	if (BFSq.empty())
		cout << -1 << endl;
	else
		cout << BFSq.front().lvcount << endl;
	return 0;
	
	
}


