#include <set>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    set<string> S;
    string ss;
    while(cin>>ss)
    {
        for(int i=0; i<ss.size(); i++)
        {
            if(ss[i]<=91)
                ss[i]+=32;
        }
        set<string> :: iterator it=S.find(ss);
        if(it==S.end())
        {
            S.insert(ss);
            //cout<<"yes";
        }
    }
    for(auto t: S)
        cout<<t<<endl;
    return 0;
}
