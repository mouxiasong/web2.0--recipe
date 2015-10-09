// Problem#: 11881
// Submission#: 3153239
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/*#include<iostream>
using namespace std;
#include<list>
#include<stdio.h>

void recursion(int n, list<int> item) {
    if (n == 0) {
        bool flag = 0;
        cout << "{";
        while (!item.empty()) {
            if (flag != 0) {
                cout << ",";
            }
            flag = 1;
            cout << item.front();
            item.pop_front();
        }
        cout << "}" << endl;
        return; 
    }
        for (int i = 0; i < n; i++) {
            if (i) item.push_back(i);
            recursion(i, item);
            if (i) item.pop_back();
    
    }
}

int main() {
    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        list<int> item;
        item.clear();
        recursion(n + 1, item);
    }
	system("pause");
}      

/*#include <iostream>
#include <cstring>
using namespace std;
char array[21];
void Func(int i,char *Temp)
{
	char reTemp[21];//这里需要设置另一个替换数组，因为如果if判断语句成立的话，就要输出Temp，如果Temp在下面的环节修改的话，那输出的集合也不是目标集合
	strcpy(reTemp,Temp);
	if(i==strlen(array))
	{
		cout<<"("<<Temp<<")";
		return ;
	}
	else
	{
		Func(i+1,reTemp);
		strncat(reTemp,(array+i),1);//这个函数是将第二个数组从第i个位置后将1位字符赋值到reTemp中
		Func(i+1,reTemp);
		//*本题最关键的也就是在这里讲一个函数递归成两个，第二个递归需要将第一个递归的数组reTemp附上新元素再递归，
		就像二叉树一样一直分支下去，直到return*/
/*	}
}
int main()
{
	int n;
	char Temp[21]={0};
	cin>>n>>array;
	Func(0,Temp);
	return 0;
}*/

#include<iostream>
//#include<list>
#include<stdio.h>
//#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int t,ans=0;
	int N,F,B,fi,bi;
	cin>>t;
	int steps[1001];
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
}