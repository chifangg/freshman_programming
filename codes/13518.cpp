#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include"function.h"
using namespace std;

void RleCodec::encode()
{
    int count = 0;
	string newstr = "\0";
	char text;
	text = code_str.front();
	//cout << text << endl;
	//cout << text << endl;
	code_str += '\0';
	for(auto c : code_str)
	{
		//cout << text << endl;
		if(c == text) 
			{
				count++;
				text = c;
				if(text == '\0')
				{
					//text = str[i];
					//cout << "hi"  << text << count << endl;
					if(count == 1) newstr += text;
					else if(count == 2) newstr = newstr + text + text;
					else newstr = newstr + to_string(count) + text;
				}
			}
		else
		{
			if(count == 1)  
				{
					newstr += text;///////
					//text = code_str[i];
				}
				else if(count == 2) 
				{
					newstr = newstr + text + text;
					count = 1;
					//text = code_str[i];
				}
				else 
				{
					//cout << count << endl;
					string cnt = to_string(count);
					//cout << cnt;
					newstr = newstr + cnt + text;
					count = 1;
					//text = code_str[i];
					//cout << newstr << endl;
				}
				text = c;
			//	cout << text << endl;
				
			}
			
		}
	code_str = newstr;
    encoded = true;
}

void RleCodec::decode()
{
    std::stringstream os;
    std::string int_str;
    for (auto c : code_str) {
        if (std::isdigit(c)) {
            int_str.push_back(c);
        } else {
            int cnt = 0;
            std::stringstream is{int_str};
            is >> cnt;
            if (cnt==0) {
                os << c;
            } else {
                for (int i=0; i<cnt; ++i)
                    os << c;
            }
            int_str.clear();
        }
    }

    code_str = os.str();
    encoded = false;

}
