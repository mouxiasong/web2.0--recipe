#include<iostream>
using namespace std;
int main(){
int n,money,temp;
static int number=0;
cin>>n;
while(n--){
cin>>money;
temp=money/100;
if(temp!=0){
number+=temp;
money =money%100;
}
temp=money/50;
if(temp!=0){
number+=temp;
money =money%50;
}
temp=money/20;
if(temp!=0){
number+=temp;
money =money%20;
}

temp=money/10;
if(temp!=0){
number+=temp;
money =money%10;
}
temp=money/5;
if(temp!=0){
number+=temp;
money =money%5;
}
temp=money/1;
if(temp!=0){
number+=temp;
money =money%1;
}
cout<<number<<endl;
}

}