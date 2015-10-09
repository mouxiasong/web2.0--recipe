#include<iostream>
//#include<list>
#include<stdio.h>
//#include<vector>
//#include<algorithm>
#include<cstring>
using namespace std;


void newsort(char s[][100],int n){
	char temp1[100],temp2[100],temp3[100];
	int k;
	for(int j=0;j<n-1;j++){
		k=j;
		for(int i=j+1;i<n;i++){
		strcpy(temp1,s[j]);
		strcpy(temp2,s[i]);
		strcat(temp1,s[i]);
		strcat(temp2,s[j]);
		if(strcmp(temp1,temp2)>0)
			k=i;
		}
		if(k!=j){
		strcpy(temp3,s[k]);
		strcpy(s[k],s[j]);
		strcpy(s[j],temp3);
		}
	}
}
int main(){
	int t,n;
	char s[8][100];
	cin>>t;
	while(t--){
	cin>>n;
	for(int i=0;i<n;i++){
	cin>>s[i];
	}
	newsort(s,n);
	for(int i=0;i<n;i++){
	cout<<s[i];
	}
	cout<<endl;
	system("pause");
	return 0;
}
}