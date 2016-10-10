#include<iostream> 
#include<stack>
#include <string>
using namespace std;

//处理表达式过程中需要对括号匹配进行检验，括号匹配包括三种：“(”和“)”，“[”和“]”，“{”和“}”。例如表达式中包含括号如下：
//
//(	)	[	(	)	(	[	]	)	]	{	}
//1	2	3	4	5	6	7	8	9	10	11	12
//从上例可以看出第1和第2个括号匹配，第3和第10个括号匹配，4和5匹配，6和9匹配，7和8匹配，11和12匹配。从中可以看到括号嵌套的的情况是比较复杂的，使用堆栈可以很方便的处理这种括号匹配检验，可以遵循以下规则：
//
//1、 当接收第1个左括号，表示新的一组匹配检查开始；随后如果连续接收到左括号，则不断进堆栈。
//
//2、 当接受第1个右括号，则和最新进栈的左括号进行匹配，表示嵌套中1组括号已经匹配消除
//
//3、 若到最后，括号不能完全匹配，则说明输入的表达式有错

int main()

{ string str;
  int len,num;
  cin >> num;
  for(int i=1;i<=num;i++)
  {
  	int l = 0;
  	int error = 0;
  	cin>>str; //把输入的字符串保存在变量str中
  	
  	len = str.length();  //获取输入字符串的长度
  
	stack<char> s;

	//入栈
	for(int i=1;i<=len;i++)
	{
		if(str[i-1]=='('||str[i-1]=='['||str[i-1]=='{')
		{
			s.push(str[i-1]);
		}

		switch(str[i-1])
		{
			case ')':
				if(s.empty()){
					break;
					error = 1;
				}else{
					if(s.top()=='('){
						s.pop();
					}else{
						break;
					}	
				}

			case ']':
				if(s.empty()){
					break;
					error = 1;
				}else{
					if(s.top()=='['){
						s.pop();
					}else{
						break;
					}
				}
			case '}':
				if(s.empty()){
					break;
					error = 1;
				}else{
					if(s.top()=='{'){
						s.pop();
					}else{
						break;
					}
				}
		}
	} 

	if(s.empty()&&error!=1)
	{
		cout<<"ok"<<endl;
	}else{
		cout<<"error"<<endl;
	}

  }
}
