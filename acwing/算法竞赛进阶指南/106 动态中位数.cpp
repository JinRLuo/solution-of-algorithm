/*
依次读入一个整数序列，每当已经读入的整数个数为奇数时，输出已读入的整数构成的序列的中位数。

输入格式
第一行输入一个整数P，代表后面数据集的个数，接下来若干行输入各个数据集。

每个数据集的第一行首先输入一个代表数据集的编号的整数。

然后输入一个整数M，代表数据集中包含数据的个数，M一定为奇数，数据之间用空格隔开。

数据集的剩余行由数据集的数据构成，每行包含10个数据，最后一行数据量可能少于10个，数据之间用空格隔开。

输出格式
对于每个数据集，第一行输出两个整数，分别代表数据集的编号以及输出中位数的个数（应为数据个数加一的二分之一），数据之间用空格隔开。

数据集的剩余行由输出的中位数构成，每行包含10个数据，最后一行数据量可能少于10个，数据之间用空格隔开。

输出中不应该存在空行。

数据范围
1≤P≤1000,
1≤M≤9999
输入样例：
3 
1 9 
1 2 3 4 5 6 7 8 9 
2 9 
9 8 7 6 5 4 3 2 1 
3 23 
23 41 13 22 -3 24 -31 -11 -8 -7 
3 5 103 211 -311 -45 -67 -73 -81 -99 
-33 24 56
输出样例：
1 5
1 2 3 4 5
2 5
9 8 7 6 5
3 12
23 23 22 22 13 3 5 5 3 -3 
-7 -3
*/

//对顶堆
//维护一个大根堆和小根堆,以此将数添加到堆中，如果该数大于小根堆顶，则将该数加入大根堆，反之亦然；
//如果两堆的数量不等，从堆顶弹出一个数加入另一个堆 
//小根堆的大小应和大根堆的大小相等或大一 
#include <bits/stdc++.h>
using namespace std;

priority_queue<int> bigq;
priority_queue<int,vector<int>,greater<int> > smq;
queue<int> resq;

int main(){
	int p,a;
	int t,m;
	cin>>p;
	while(p--){
		while(!bigq.empty()) bigq.pop();
		while(!smq.empty()) smq.pop();
		cin >> t >> m;
		
		cin >> a;
		smq.push(a);
		resq.push(smq.top());
		for(int i=2;i<=m;i++){
			cin >> a;
			if(a>smq.top()){
				//cout << "-" << endl;
				smq.push(a);
				if(smq.size()-1>bigq.size()){
					bigq.push(smq.top());
					smq.pop();
				}
			}else{
				bigq.push(a);
				if(bigq.size()>smq.size()){
					smq.push(bigq.top());
					bigq.pop();
				}
			}
			if(i%2!=0){
				resq.push(smq.top());
			}
		}
		cout << t << " " << (m+1)/2 << endl;
		int count=0;
		while(!resq.empty()){
			if(count<10){
				cout << resq.front() << " ";
				resq.pop();
				count++;
			}else{
				cout << endl;
				count = 0;
			}
		}
		if(count!=0)
			cout << endl;
		
		
	}
}
