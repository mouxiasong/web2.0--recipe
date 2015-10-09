// Problem#: 11881
// Submission#: 3153239
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
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
	return 0;
}                                 