
#include <iostream>
#include <algorithm> 
#include <string>
using namespace std;
#include"function.h"

String_Calculator::String_Calculator(const string str):s(str)
{
	
}

String_Calculator& String_Calculator::Add(const string str)
{
	string tmpstr = s + str;
 	s = tmpstr;
 	//cout << s << endl;
 	return *this;
}

String_Calculator& String_Calculator::Subtract(const string str) 
{ 
	string tmpstr = s;
 	size_t found = 0;
 	found = s.find(str);
	int len = 0;
	len = str.length();
	if(found!=string::npos)
	{
		//cout << found << endl;
		tmpstr.erase(found, len);
		s = tmpstr;	
	}
	else
	{
		//cout << "hey" << endl;
		s = "error";
	}
	
	//String_Calculator t(s);
	//cout << s << endl;
 	return *this;
	//return *this;
}

String_Calculator& String_Calculator::DividedBy(const string str)
{
 	int count = 0;
	int placemem = 0;
	size_t found = s.find(str, 0);
	while(found!=string::npos)
	{
		//cout << "yeah" << endl;
		count++;
		placemem = found;
		found = s.find(str, placemem+1);	
	}
	cout << count << endl;
	//char *newcount = itoa(count, newcount, 10);
 	//s = string(newcount); 
 	//cout << s << endl;
//	char *newcount = itoa(count);
//	s = string(newcount); 
	return *this;
	
}

void String_Calculator::output() const
{
 	//cout << s << endl;
}
