#include<cassert>
#include<iostream>
#include<map>
#include<ostream>
#include<string>
#include<set>
#include"function.h"

using namespace std;


void oj::insert(map<int,String> &ma,int key,const std::string &str)
{
	auto pla = ma.find(key);
	string newstr;
	if(pla != ma.end())
	{
		newstr = str + pla -> second.str;
		ma.erase(pla);
	}
	else newstr = str;
	
	ma.insert(pair<int, String>(key,string(newstr)));
}
void oj::output(const map<int,String> &ma,int begin,int end)
{
	for(auto & it:ma)
	{
		if(it.first >= begin && it.first <= end) cout << it.second << ' ';
	}
	
}
void oj::erase(map<int,String> &ma,int begin,int end)
{
	set <int> eraselet;
	for(auto &it:ma)
	{
		if(it.first >= begin && it.first <= end) eraselet.insert(it.first);
	}
	for(auto now:eraselet) ma.erase(now);
}

ostream& oj::operator<<(ostream &key,const std::map<int,String> &ma)
{
	for(auto &it:ma)
        key << it.second << ' ';
    return key;
}


