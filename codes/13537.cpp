#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    std::set<int> mset,wset;
    int M,W,E, mv, wv, ev;
    cin >> M >> W >> E;
    
    
    for (int i=0;i<M;i++)
      {
       cin >> mv;
       mset.insert(mv);
   }
   
 for (int i=0;i<W;i++)
      {
       cin >> wv;
       wset.insert(wv);
   }
 
 for (int i=0;i<E;i++)
 {
  	int flag=0;
  	cin >> ev;
    std::set<int>::iterator it;
        if(wset.size() > mset.size())
        {
	        for(it=mset.begin();it!=mset.end();it++)
	        {
	             int cur = *it;
	             mv=cur;
	             //if (ev>=mv)
	             //  {
	                if (wset.count(ev-mv)>0)
	                   {
	                    flag=1;
	                    break;
	                }
	       }
		}
		else
		{
			for(it=wset.begin();it!=wset.end();it++)
	        {
	             int cur = *it;
	             wv=cur;
	             //if (ev>=mv)
	             //  {
	                if (mset.count(ev-wv)>0)
	                   {
	                    flag=1;
	                    break;
	                }
	       }
		}
        
       //  }
    //else
    //   break;
        
        if (flag)
          printf("Yes\n");
        else
          printf("No\n");
    }
    
}
