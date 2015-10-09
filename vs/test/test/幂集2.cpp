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
	char reTemp[21];//������Ҫ������һ���滻���飬��Ϊ���if�ж��������Ļ�����Ҫ���Temp�����Temp������Ļ����޸ĵĻ���������ļ���Ҳ����Ŀ�꼯��
	strcpy(reTemp,Temp);
	if(i==strlen(array))
	{
		cout<<"("<<Temp<<")";
		return ;
	}
	else
	{
		Func(i+1,reTemp);
		strncat(reTemp,(array+i),1);//��������ǽ��ڶ�������ӵ�i��λ�ú�1λ�ַ���ֵ��reTemp��
		Func(i+1,reTemp);
		//*������ؼ���Ҳ���������ｲһ�������ݹ���������ڶ����ݹ���Ҫ����һ���ݹ������reTemp������Ԫ���ٵݹ飬
		���������һ��һֱ��֧��ȥ��ֱ��return*/
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
		cin>>N>>F>>B;//�ֱ����������������������
		for(int i=0;i<N;i++){
		cin>>fi>>bi;//����ڼ��㣬���޺��ӣ�
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