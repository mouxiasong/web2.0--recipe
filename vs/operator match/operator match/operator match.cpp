#include<iostream>
#include<string>
#include<stack>
#include<stdlib.h>
using namespace std;
int main(){
	string str1;
	string str2;
	stack<char>m;
	int t,count=0;
	bool op=true;
	cin>>t;
	getline(cin,str1);//getlineĬ����'\n'��Ϊһ�н�����־���������һ����������и����У�������лᱻgeline��׽��
	while(t--){
		str2.clear();
		while(!m.empty()){
	m.pop();
	}
	getline(cin,str2);
	for(int i=0;i<str2.size();i++){
		if(str2[i]=='('||str2[i]=='{'||str2[i]=='['){
			m.push(str2[i]);
		}
		else if(str2[i]==')'){
		if(!m.empty() && m.top()=='('){
			m.pop();
			op=true;
		}
		else
			op=false;
		}
		else if(str2[i]=='}'){
			if(!m.empty()&&m.top()=='{'){
			op=true;
			m.pop();
			}
		else
			op=false;
		}
		else if(str2[i]==']'){
		if(!m.empty()&&m.top()=='['){
			op=true;
			m.pop();
		}
		else
			op=false;
		}

	}
	if(m.empty()&&op==true)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	}
	
	system("pause");
	return 0;
}