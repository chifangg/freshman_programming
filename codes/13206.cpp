#include<iostream>
#include<string>
#include"function.h"
using namespace std;

class ReverseCodec:public BaseCodec
{
	string encode(const std::string& str) override
	{
		return string(str.rbegin(), str.rend());
//		int len=n.length();
//	    string newl;
//	    for(int i=0; i<len; i++)
//	    {
//	        newl[i]=n[len-i-1];
//	        //cout << newl[i] << n[len-i-1] << endl;
//	    }
//	    for(int i = 0; i < len; i++)
//	    {
//	    	cout<<newl[i]; 	
//		}
//		//cout << endl;
//	    return newl;
	}
};/////////
class CompressCodec:public BaseCodec
{
	string encode(const std::string& str) override
	{
		int count = 0;
		string newstr = "\0";
		char text;
		text = str.front();
		//cout << text << endl;
		for(int i = 0; i < str.length(); i++)
		{
			//cout << text << endl;
			if(str[i] == text) 
			{
				count++;
				//cout << "yes" << endl;
			}
			else
			{
				if(count == 1)  
				{
					newstr += text;///////
					text = str[i];
				}
				else if(count == 2) 
				{
					newstr = newstr + text + text;
					count = 1;
					text = str[i];
				}
				else 
				{
					string cnt = to_string(count);
					//cout << cnt;
					newstr = newstr + cnt + text;
					count = 1;
					text = str[i];
					//cout << newstr << endl;
				}
				
			}
			if(i == str.length()-1)
			{
				//text = str[i];
				//cout << "hi"  << text << count << endl;
				if(count == 1) newstr += text;
				else if(count == 2) newstr = newstr + text + text;
				else newstr = newstr + to_string(count) + text;
			}
		}
		return newstr;
	}
};
class DelayCodec:public BaseCodec
{
	string ori = "None";
	string encode(const std::string& str) override
	{
		string real = str;
		swap(real, ori);
		return real;
	}
};
BaseCodec* getCodec(const std::string& name)
{
	if(name == "Reverse")
	return new ReverseCodec;
	else if(name == "Compress")
	return new CompressCodec;
	else if(name == "Delay")
	return new DelayCodec;
	//else assert(false);
	
}

