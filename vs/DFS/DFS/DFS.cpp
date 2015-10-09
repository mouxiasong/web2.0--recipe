/*#include<iostream>
#include<string>
#include<list>
#include<stdio.h>
using namespace std;

int dir[4][2]= {{-1, 0},{1, 0},{0, -1}, {0, 1}}; //四个方向，分别代表上，下，左，右
int arr[10][10];   // 迷宫

struct node {  // x代表横坐标 y代表纵坐标
    int x;
    int y;
    node (int x1, int y1):x(x1), y(y1) {}
};

// 使用链表，易于输出

void print(list<node> m) {   //输出路径
    cout << "(" << m.front().x << "," << m.front().y << ")";   //解决每个坐标之间的空格问题
    m.pop_front();
    while (!m.empty()) {
        cout << " (" << m.front().x << "," << m.front().y << ")";
        m.pop_front();
    }
    cout << endl;
}

int Path(node cur, node end, list<node> s) {
    if (cur.x == end.x && cur.y == end.y) {  // 当前坐标等于结束坐标时返回1，即找到一条路径整个递归就会结束。原因请看下边注释
        print(s);
        return 1;
    }
    for (int i = 0; i < 4; i++) {  // 4个方向分别探索
        node next(cur.x + dir[i][0], cur.y + dir[i][1]);   // 构造下一个要进行探索的点
        if (next.x >= 0 && next.x <= end.x && next.y >= 0 && next.y <= end.y && arr[next.x][next.y] == 0) {   //判断下个点是否可行
            s.push_back(next);      // 可以，将这个点加入整个路径中。
            arr[next.x][next.y] = 1;    // 此时这个点已经走过，标记为1；
            if (Path(next, end, s)) return 1;   // 现在所在位置即cur中记录位置，递归进行下一位置的查找。循环往复。
                                               // 如果一直可以先向下查找，知道找到终点，最底层函数就会返回1，接着返回到倒数第二层，执行if语句，接着返回1。
                                              // 直到跳出整个递归函数。 
            s.pop_back();     // 如果向下查找失败，就会跳过if执行这一句，于是就要回溯，比如，由a找到b，再找到c，再往下查找失败。说明c这个点不可取，
                             // 重新返回b换一个方向搜索。因为当前我们位于c，我们将c加入了路径中，然后接着往下搜索。搜索失败说明c不可行，所以我们
                            // 要将它从路径中移除，即pop掉c.
         }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, i, j;
        string st;
        cin >> m >> n;
        getline(cin, st);
        for (i = 0; i < m; i++) {  //创建迷宫
            getline(cin, st);
            for (j = 0; j < n; j++)
                arr[i][j] = st[j] - '0';
        }
        list<node> s;
        node sta(0, 0), end(m-1, n-1);   //记录开始和结束坐标。
        s.push_back(sta);
        arr[0][0] = 1;    
        if (Path(sta, end, s) == 0) cout << "no" << endl;
    }
	system("pause");
    return 0;
}*/



/*#include<iostream>
#include<string>
#include<list>
#include<stack>
#include<stdio.h>
using namespace std;
struct point{
	int x;//横坐标
	int y;//纵坐标
};

stack<point> path;

//define four directions which represents up,down,left,right;
char maze[11][11];//define maze;
int count=0;
void createmaze(int row,int col){
	for(int i=0;i<row+2;i++){
	maze[i][col+1]=maze[i][0]='1';
	}
	for(int i=0;i<col+2;i++){
	maze[0][i]=maze[row+1][i]='1';
	}
	for(int i=1;i<=row;i++){
		for(int j=1;j<=col;j++){
	cin>>maze[i][j];
	}
	}

}
bool apath(int row,int col,int x,int y){//前两个代表结束坐标，后面两个代表当前坐标
	maze[x][y]='-1';
	point t;
	t.x=x;
	t.y=y;
	path.push(t);
	if(row==x &&col==y){
	return true;
	}
	point move[4]={{-1,0},{1,0},{0,-1},{0,1}};
	for(int i=0;i<4;i++){
		if(maze[x+move[i].x][y+move[i].y]=='0'){
		if(apath(row,col,x+move[i].x,y+move[i].y))
			return true;
		}
	}
	path.pop();
	return false;
}
void print(int row,int col){
	point temp;
	stack<point>p;
	while(!path.empty()){
	temp=path.top();
	p.push(temp);
	path.pop();
	}
	//temp=p.top();
	//cout<<"("<<temp.x-1<<","<<temp.y-1<<")";
	//count++;
	//p.pop();
	while(!p.empty()){
	//temp=p.top();
	//cout<<" ("<<temp.x-1<<","<<temp.y-1<<")";
	count++;
	p.pop();
	}
	//cout<<endl;
	cout<<count<<endl;
}
int main(){
int t,r,c;
while(cin>>t&&t!=0){
int c=t;
int r=t;
createmaze(r,c);
if(apath(r,c,1,1)){
print(r,c);
}else{
cout<<0<<endl;
}
}
system("pause");
return 0;
}
*/



// Problem#: 11878
// Submission#: 3145923
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/*#include<iostream>
#include<stack>
#include<stdio.h>
using namespace std;

struct point {
    int x;
    int y;
};

stack<point> path;
point move[4]={{-1,0},{1,0},{0,-1},{0,1}};
//point move[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char maze[11][11];

void createMaze(int row,int column){
    //创建迷宫，注意到用0表示可走，1表示墙，将整个输入的迷宫再用墙围着，处理的时候就不用特别注意边界问题
    for(int i=0; i<row+2; i++)
        maze[i][0] = maze[i][column+1] = '1';
    for(int j=0; j<column+2; j++)
        maze[0][j] = maze[row+1][j] = '1';
    for(int i=1; i<=row; i++){
        for (int j = 1; j <= column; j++)
             cin >> maze[i][j];
    }
}

bool aPath(int row, int col, int x, int y) {
    maze[x][y] = '-1';
    point t;
    t.x = x;
    t.y = y;
    path.push(t);
    if (x == row && y == col) {
            return true;
        }
	point move[4]={{-1,0},{1,0},{0,-1},{0,1}};
    for (int i = 0; i < 4; i++) {
        if (maze[x + move[i].x][y + move[i].y] == '0') {
            if (aPath(row, col, x + move[i].x, y + move[i].y)) return true;
        }
    }
    path.pop();
    return false;
}

void printPath(int row, int col) {
    point temp;
    stack<point> p;
    while (!path.empty()) {
        temp = path.top();
        p.push(temp);
        path.pop();
    }
    temp = p.top();
    cout << "(" << temp.x - 1 << "," << temp.y - 1 << ")";
    p.pop();
    while (!p.empty()) {
        temp = p.top();
        cout << " (" << temp.x - 1 << "," << temp.y - 1 << ")";
        p.pop();
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int row, col;
        cin >> row >> col; 
        createMaze(row, col);
        if (aPath(row, col, 1, 1)) {
            printPath(row, col);
        } else {
            cout << "no" << endl;
        }
    }
	system("pause");
    return 0;
}   */              



#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;

struct point {
    int x;
    int y;
	int totaltonext;
};//方向结构体

int move_x[] = {-1, -1, -2, -2, 1, 1, 2, 2};
int move_y[] = {-2, 2, 1, -1, 2, -2, 1, -1};

bool tab[10][10];
int arr[64];
bool cmp(point,point);
bool solve(int ,point );
bool isvalued(point);
bool solve(int k,point m){//k代表步数
	point s;
//int x1,y1;
if(k==64){
for(int i=0;i<63;i++)
	cout<<arr[i]<<" ";
    cout<<arr[63]<<endl;
    return true;
}else {
	vector<point>tmp;
	for(int j=0;j<8;j++){
	s.x=m.x+move_x[j];
	s.y=m.y+move_y[j];
	s.totaltonext=0;

	if (isvalued(s)) {  
            //  cout << "p"; 
		       point w;
			   for(int l=0;l<8;l++){
			   w.x=s.x+move_x[l];
			   w.y=s.y+move_y[l];
			   if(isvalued(w))
				   s.totaltonext++;
			   }
			   tmp.push_back(s);
	}
	}
	sort(tmp.begin(),tmp.end(),cmp);

	for(int i=0;i<tmp.size();i++){
		      tab[tmp[i].x][tmp[i].y]=false;
                arr[k]=8*tmp[i].x+tmp[i].y+1;  
                if(solve(k+1,tmp[i]))
				return true;
                tab[tmp[i].x][tmp[i].y]=true;  
                //k--;  
            }  
	}
      return false;
 }

bool cmp(point a,point b){
	return a.totaltonext<b.totaltonext;
}
bool isvalued(point n){
return (n.x >= 1 && n.x <= 8 && n.y >= 1 && n.y <= 8 && tab[n.x][n.y]==true);
}

int main()  
{  
    int n;  
    point m;  
    //bool tab[8][8]=true;  
    
    while ( cin >> n && n!=-1 ) {  
		 memset(tab, 1, 10*10*sizeof(bool));
        m.x=(n-1)/8;  
        m.y=(n-1)%8;  
       
        arr[0]=n;  
        tab[m.x][m.y]=false;  
          
        solve(1,m);  
        //cin >> n;  
    }  
   //system("pause");  
    return 0;  
}  

/*#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
#include<stdio.h>
 
using namespace std;
 
struct point
{
    int x;
    int y;
    int totaltonext;
 
};
 
int board[10][10];
 
int move_x[] = {-1, -1, -2, -2, 1, 1, 2, 2};
int move_y[] = {-2, 2, 1, -1, 2, -2, 1, -1};
 
bool isfind;
int path[100];
bool dfs(point, int);
bool isvalue(point );
bool cmp(point , point );
 
int main()
{
    int n;
    point p;
     
 
    //freopen("C:\\Users\\Haojian\\Desktop\\test.txt", "r", stdin);
    while (cin >> n && n != -1)
    {
        isfind = false;
        memset(board, 0, 10*10*sizeof(int));
        p.x = (n - 1) / 8 + 1;
        p.y = n - ((p.x-1) * 8);
        //p.num = 1;
    //    path[p.num-1] = n;
        path[0] = n;
        board[p.x][p.y] = 1;
        dfs (p, 1);
 
    }
	system("pause");
    return 0;
}
 
 
bool dfs (point p, int current)
{
    point n;
 
     
    if (current == 64)
    {
        for (int i = 0; i < 63; i++)
            cout << path[i] << " ";
        cout << path[63];
        cout << endl;
        return true;
    }
    else
    {
        vector<point> tmp;
        for (int i = 0; i < 8; i++)
        {
            n.x = p.x + move_x[i];
            n.y = p.y + move_y[i];
            n.totaltonext = 0;
             
            if (isvalue(n))
            {
                 
                point k;
                for (int j = 0; j < 8; j++)
                {
                    k.x = n.x + move_x[j];
                    k.y = n.y + move_y[j];
                    if (isvalue(k))
                        n.totaltonext++;
                }
                 
                    tmp.push_back(n);
            }
        }
 
        sort(tmp.begin(), tmp.end(), cmp);
         
        for (int i = 0; i < tmp.size(); i++)
        {
            board[tmp[i].x][tmp[i].y] = 1;
            path[current] = (tmp[i].x - 1) * 8 + tmp[i].y;
            if (dfs(tmp[i], current+1)) return true;
            board[tmp[i].x][tmp[i].y] = 0;
        }
         
 
         
    }
    return false;
}
 
bool cmp(point a, point b)
{
    return a.totaltonext < b.totaltonext;
}
 
bool isvalue(point n)
{
    return (n.x >= 1 && n.x <= 8 && n.y >= 1 && n.y <= 8 && !board[n.x][n.y]);
}*/