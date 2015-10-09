#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
	string a;
	int leng;
	stack<string> m;
getline(cin,a);
leng=a.length();
for(int i=0;i<leng;i++){
	m.push(a);
}
for(int i=0;i<leng;i++){
	if(a[i]>='0'||a[i]<='9')
		m.pop();
	else
		if(a[i]=='^'&&a[i-1]=='*')
			m.pop();
	m.pop();
}
}