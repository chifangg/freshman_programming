#include<iostream>
#include<stack>
#include<map>
#include<algorithm>
#include<string>
#include<list>
#include<queue>

using namespace std;
list<int> line;
queue<int> country[3];
int main()
{
	string str;
	int n, id;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> str;
		if(str == "ENQUEUE")
		{
			cin >> id;
			//cout << id << "here";
			int num = id % 3;
			country[num].push(id);
			if(find(line.begin(),line.end(),num)==line.end())
			line.push_back(num);//list:push_back
		}
		else if(str == "DEQUEUE")
		{
			int num = line.front();//from the front country
			cout << country[num].front() << endl;
			country[num].pop();
			if(country[num].empty()) line.pop_front();//pop that country num
		}
		
	}	
	return 0;
}



