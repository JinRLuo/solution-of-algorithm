/*
你一定玩过八数码游戏，它实际上是在一个3×3的网格中进行的,1个空格和1~8这8个数字恰好不重不漏地分布在这3×3的网格中。

例如：

5 2 8
1 3 _
4 6 7
在游戏过程中，可以把空格与其上、下、左、右四个方向之一的数字交换（如果存在）。

例如在上例中，空格可与左、上、下面的数字交换，分别变成：

5 2 8       5 2 _      5 2 8
1 _ 3       1 3 8      1 3 7
4 6 7       4 6 7      4 6 _
奇数码游戏是它的一个扩展，在一个n×n的网格中进行，其中n为奇数，1个空格和1~n2?1这n2?1个数恰好不重不漏地分布在n×n的网格中。

空格移动的规则与八数码游戏相同，实际上，八数码就是一个n=3的奇数码游戏。

现在给定两个奇数码游戏的局面，请判断是否存在一种移动空格的方式，使得其中一个局面可以变化到另一个局面。

输入格式
多组数据，对于每组数据：

第1行输入一个整数n，n为奇数。

接下来n行每行n个整数，表示第一个局面。

再接下来n行每行n个整数，表示第二个局面。

局面中每个整数都是0~n2?1之一，其中用0代表空格，其余数值与奇数码游戏中的意义相同，保证这些整数的分布不重不漏。

输出格式
对于每组数据，若两个局面可达，输出TAK，否则输出NIE。

数据范围
1≤n<500
输入样例：
3
1 2 3
0 4 6
7 5 8
1 2 3
4 5 6
7 8 0
1
0
0
输出样例：
TAK
TAK
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn=250010;
int a[maxn];
int b[maxn];
int c[maxn];
long long temp;

void merge_sort(int* a,int x,int y,int* T){
	if(y-x>1){
		int m=x+(y-x)/2;
		int i=x,j=m,k=x;
		merge_sort(a,x,m,T);
		merge_sort(a,m,y,T);
		while(i<m||j<y){
			if(j>=y||(i<m&&a[i]<a[j])){
				T[k++]=a[i++];
			}else{
				T[k++]=a[j++];
				temp+=m-i;
			}
		}
		for(int l=x;l<y;l++){
			a[l]=T[l];
		}
	}
}

int main(){
	long long a1,a2;
	int n;
	int k,w;
	while(cin>>n){
		k=0;
		for(int i=0;i<n*n;i++){
			cin >> w;
			if(w!=0)
				a[i-k]=w;
			else
				k=1;
		}
//  		for(int i=0;i<n*n-1;i++){
//  			cout << a[i] << " ";
//  		}
//  		cout << endl;
		temp=0;
		merge_sort(a,0,n*n-1,c);
		a1=temp;
		k=0;
		for(int i=0;i<n*n;i++){
			cin >> w;
			if(w!=0)
				b[i-k]=w;
			else
				k=1;
		}
//  		for(int i=0;i<n*n-1;i++){
//  			cout << b[i] << " ";
//  		}
//  		cout << endl;
		temp=0;
		merge_sort(b,0,n*n-1,c);
		a2=temp;
//		cout << a1 << " " << a2 << endl;
		if(a1%2==a2%2)
			cout << "TAK" << endl;
		else
			cout << "NIE" << endl;
	}
}
