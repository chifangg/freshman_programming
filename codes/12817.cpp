#include<iostream>
#include<stack>
#include<map>
#include<algorithm>
#include<string>
#include<list>
#include<queue>
#include<set>
#include<vector>


using namespace std;

struct Seg {
  int left, right;
  Seg(int a, int b) : left(a), right(b) {}
};

struct Cmp {
  bool operator()(const Seg &lhs, const Seg &rhs) const {
    int l_len = (lhs.right - lhs.left) / 2;
    int r_len = (rhs.right - rhs.left) / 2;
    if (l_len != r_len)////////////////////
      return l_len > r_len;
    else
      return lhs.left < rhs.left;
  }
};

int main() {
  char cmd;
  int n, m, s, x, D;
  set<int> pos;//record taken seats
  set<Seg, Cmp> seg;//record segment
  vector<int> id2pos;//record studen-seat

  cin >> n >> m >> s;
  D = n + 1;//shortest social distance
  id2pos.resize(m + 1, -1);//open the size to m+1 and initiaize them all to 1
  pos.insert(0);//left wall = seat 0
  pos.insert(n + 1);//right wall = seat n+1
  seg.insert(Seg(0, n + 1));//insert initial segment

  for (int t = 0; t < 2 * m; t++) 
  {
    cin >> cmd >> x;
    if (cmd == 'i') 
	{
      auto it = seg.begin();
      int left = it->left, right = it->right;
      int mid = (left + right) / 2;
      if (left != 0)//left is not wall
        D = min(mid - left, D);
      if (right != n + 1)//right is not wall
        D = min(right - mid, D);
        
      seg.erase(it);
      seg.insert(Seg(left, mid));//insert new segment to split
      seg.insert(Seg(mid, right));
      id2pos[x] = mid;
      pos.insert(mid);//taken
    } 
	else if (cmd == 'o') 
	{
      int mid = id2pos[x];//get x's seatnum
      auto it = pos.find(mid);//point to the taken seat
      auto left_it = it, right_it = it;////////copy iterator
      int left = *(--left_it);//get left taken seat
	  int right = *(++right_it);//get right taken seat
      seg.erase(Seg(left, mid));
      seg.erase(Seg(mid, right));
      seg.insert(Seg(left, right));
      id2pos[x] = -1;
      pos.erase(mid);
    }
  }

  if (D >= s)
    cout << "YES\n";
  else
    cout << "NO\n";
  if (D == n + 1)
    cout << "INF\n";
  else
    cout << D << "\n";
    
  return 0;
}
