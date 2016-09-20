//C++中已经自带堆栈对象stack，无需编写堆栈操作的具体实现代码。
//本题目主要帮助大家熟悉stack对象的使用，然后实现字符串的逆序输出
//输入一个字符串，按字符按输入顺序压入堆栈，然后根据堆栈后进先出的特点，做逆序输出
#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	stack<char> s;
	int n,m,i;
	string str;
	int len;
	char ct;
	//s.push(ct);
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>> str;	 //把输入的字符串保存在变量str中
		len = str.length();		//获取输入字符串的长度
		for(m=0;m<len;m++)
		{
			s.push(str[m]);	
		}
		while(!s.empty())
			{
				ct=s.top();
				s.pop();
				cout<< ct ;
			}
		cout<< endl;
		
	}
	return 0;
}