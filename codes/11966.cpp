#include<iostream>
#include<stack>
#include<map>
#include<string>
#include <algorithm>
using namespace std;
map<char, char> parens = { { '{' , '}' },
                          { '(' , ')' },
                          { '<' , '>' },
                          { '[' , ']' } };

int main()
{
	string str;
	int num;
	cin >> num;
	getchar();
	//getline(cin, str); //to avoid the circumstances of \n
	for(int i = 1; i <= num; i++)
	{
		stack<char> rec;
		getline(cin, str);
		bool flag = true;
		for(char c : str)
		{
			if(c=='{' || c=='[' || c=='(' || c=='<')
			{
				rec.push(c);
			}
			else if(c=='}' || c==']' || c==')' || c=='>')
			{
				if(rec.empty())
				{
					flag = false;
                    break;
				}
				else if(parens[rec.top()] != c)
				{
					flag = false;
                    break;
				}
				else
				{
                    rec.pop();
                }
			}
        	
		}
			if (!rec.empty()) 
			{
            	flag = false;
        	}
			cout << "Case " << i << ": ";
        	if (flag) 
			{
            	cout << "Yes\n";
        	} 
			else 
			{
            	cout << "No\n";
        	}		
        
	}
}



