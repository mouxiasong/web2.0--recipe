/*#include<iostream>
//#include<list>
#include<stdio.h>
//#include<vector>
#include<algorithm>
#include<Memory>
using namespace std;

int main(){
	int t,ans=0;
	int N,F,B,fi,bi;
	cin>>t;
	int steps[1001];
	memset(steps,0,sizeof(int));
	while(t--){
		cin>>N>>F>>B;//分别代表人数、层数、盒子数
		for(int i=0;i<N;i++){
		cin>>fi>>bi;//代表第几层，有无盒子；
		if(bi){
		steps[i]=2*F-fi;
		}else{
		steps[i]=F+fi;
		}
		}
		if(B%N==0){
		ans=(B/N-1)*2*F + steps[N-1];
		}else{
		ans=(B/N)*2*F+steps[B%N-1];
		}
		cout<<ans<<endl;
	}
	system("pause");
	return 0;
}*/

// Problem#: 12246
// Submission#: 3222244
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University

/*#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
bool alread(int n,int a[]){
	
for(int i=0;i<n-1;i++){
if(a[i]>a[i+1]){
	return false;
}
}
	return true;
}

void print(int n,int a[]){
for(int i=0;i<n;i++){
cout<<a[i]<<" ";
}
}

int main(){
int t,n,k,count=0;
cin>>t;
while(t--){
cin>>n;
int *a=new int[n];
for(int i=0;i<n;i++){
cin>>a[i];
}

if(alread(n,a)){
	//print(n,a);
	cout<<"0";
	cout<<endl;
}else{
	//print(n,a);
    //cout<<endl;
for(int i=0;i<n-1;i++){
	
	for(int j=i+1;j<n;j++ ){
	if(a[i]>a[j]){
		k=a[i];
	    a[i]=a[j];
		a[j]=k;
		count++;
	}else{
	break;
	}
		sort(a,a+j);
	/*for(int i=0;i<n;i++){
	cout<<a[i]<<" ";
	}
	break;
	}
	
	if(alread(n,a)){
	//print(n,a);
		cout<<count*5<<endl;
	break;
	}
}
delete []a;
}
}
system("pause");
return 0;
}

#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main(){
int t,n,k,temp,count=0;
int a[101];
cin>>t;
while(t--){
cin>>n;
for(int i=0;i<n;i++){
cin>>a[i];
//cout<<a[i]<<" ";
}
//cout<<endl;
for(int j=1;j<n;j++){
    if(a[j]<a[j-1]){
    k=j;
    while(k>0 && a[k]<a[k-1]){
    temp=a[k];
    a[k]=a[k-1];
    a[k-1]=temp;
    k--;
    }
    /*for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
    }
    count++;
    }
}
cout<<count*5<<endl;
count=0;
}
system("pause");
return 0;
}*/

/*#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
using namespace std;
int main(){

}

#include <iostream>
using namespace std;
#include<stdio.h>
int main()
{
	cout << "this is the first line\n";
	cout << "this is the second line\r";
	cout << "this is the third line\n";
	cout << "this is the fouth line\r";
	cout << "this is the fifth line\n";
	cout << "end" ;
	system("pause");
	return 0;
}


#include <iostream>
#include<map>
#include<stdio.h>
#include<string>
using namespace std;
int main(){
	map<string,string> mxs;
	string str1,str2;
    string str3;
	while(cin.peek()!='\n'){
	cin >> str1 >> str2;
	cin.get();
	mxs[str2]=str1;
	}
	while(cin>>str2){
		map<string,string>::iterator it;
		it=mxs.find(str2);
	if(it!=mxs.end()){
		cout<<mxs[str2]<<endl;
	}else{
		cout<<"eh"<<endl;
	}
	}
	system("pause");
	return 0;
}*/
/*week.07.1004
#include <iostream>
#include<stdio.h>
using namespace std;
void Index_BF(char S[],char T[],int pos){//main string is s,substring is T
  int i=pos,j=0;
  while(S[i+j]!='\0'&& T[j]!='\0')
	  if(S[i+j]==T[j])
		  j++;// compare the next characor
	  else
	  {
		  i++;
		  j=0;// restart a new match routinue
	  }
	  if(T[j]=='\0')
		  cout<<i<<endl;
	  else
		  cout<<"no solution"<<endl;
}

int main(){
	int t1,k;
	
	while(cin>>t1){
		char *S1=new char[t1+1];
		int i;
	for(i=0;i<t1;i++){
		char c;
		cin >> c;
		S1[i] = c;//the original string
	}
	S1[i] = '\0';
	int t2;
	cin>>t2;
	char* s2=new char[t2+1];
	for(i=0;i<t2;i++){
		cin>>s2[i];//the match string
	}
	s2[i] = '\0';
	if(t1>t2){
	cout<<"no solution"<<endl;
	}else{
		Index_BF(s2,S1,0);
	  }
	delete []S1;
      delete []s2;
     }
	system("pause");
	return 0;
	}*/

/*week.07.1005
#include <iostream>
#include<stdio.h>
#include<string>
using namespace std;

 void lcs_search(string str1, string str2)  

{  

    if (str1.length() < str2.length())                   //保证str1为母串（较长的哪个串)  

    {  

        string strTemp = str1;  

        str1 = str2;  

        str2 = strTemp;  

    }  
      int count=0;
      int len1=str1.length();
      int len2=str2.length();
     
              
			  if(str1[0]==str2[0]){
				   for(int i=0;i<len2;i++){
          for(int j=0;j<len1;j++){
              if(str1[j]==str2[i]){
              count++;
              i++;
              }else{
				   while(i==len2-1||j==len1-1){
             cout<<count<<endl;
                return;
              }
              continue;
              }
			 
		  }
				   }
			  }else{
				   for(int i=0;i<len2;i++){
          for(int j=0;j<len1;j++){
			  if(str1[j]==str2[i]){
              count++;
              i++;
              }else{
              continue;
              }
			   while(i==len2||j==len1-1){
             cout<<count<<endl;
                return;
              }
			  }
          }
      }
}    

int main()  

{    

    string a,b;
    while(cin>>a){
        cin>>b;  
    lcs_search(a,b);    
    }
    return 0;  
}*/

#include <iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(){
int t,T,min=0,temp,k,m;
cin>>t;
while(t--){
cin>>T;
int *a=new int[T];
for(int i=0;i<T;i++){
cin>>a[i];
}

for(k=0;k<T-1;k++){
	min=a[k];
	m=k;
for(int i=k+1;i<T;i++){
if(a[i]<min){
	min=a[i];
    m=i;
}
}
temp=a[m];
a[m]=a[k];
a[k]=temp;
for(int j=0;j<T-1;j++){
	cout<<a[j]<<" ";
}
cout<<a[T-1]<<endl;
}
}
system("pause");
return 0;
}