/*
在这个问题中，您必须分析特定的排序算法----超快速排序。

该算法通过交换两个相邻的序列元素来处理n个不同整数的序列，直到序列按升序排序。

对于输入序列9 1 0 5 4，超快速排序生成输出0 1 4 5 9。

您的任务是确定超快速排序需要执行多少交换操作才能对给定的输入序列进行排序。

输入格式
输入包括一些测试用例。

每个测试用例的第一行输入整数n，代表该用例中输入序列的长度。

接下来n行每行输入一个整数ai,代表用例中输入序列的具体数据，第i行的数据代表序列中第i个数。

当输入用例中包含的输入序列长度为0时，输入终止，该序列无需处理。

输出格式
对于每个需要处理的输入序列，输出一个整数op，代表对给定输入序列进行排序所需的最小交换操作数，每个整数占一行。

数据范围
0≤N<500000,
0≤ai≤999999999
输入样例：
5
9
1
0
5
4
3
1
2
3
0
输出样例：
6
0
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll int res;
ll int a[500050];
ll int b[500050];

void merge_sort(ll *A,ll x,ll y,ll *T){
	if(y-x>1){
		int m=(y-x)/2+x;
		int p=x,q=m,i=x;
		merge_sort(A,x,m,T);
		merge_sort(A,m,y,T);
		while(p<m||q<y){
			if(q>=y||(p<m&&A[p]<A[q]))
				T[i++]=A[p++];
			else{
				T[i++]=A[q++];
				res+=m-p;
			}
		}
		for(i=x;i<y;i++){
			A[i]=T[i];
		}
	}
}

int main(){
	int n;
	while(cin>>n){
		res=0;
		if(n==0)
			break;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		merge_sort(a,0,n,b);
		cout << res << endl;
	}
} 
