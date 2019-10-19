#include <iostream>
using namespace std;

const int maxn = 100010;
int n,k;
int a[maxn];

int quick_sort(int* q,int l,int r,int k){
	if(l==r)
		return q[l];
	int x=q[l];
	int i=l-1,j=r+1;
	
	while(i<j){
		while(q[++i]<x);
		while(q[--j]>x);
		if(i<j)
			swap(q[i],q[j]);
	}
	int s1=j-l+1;
	if(s1>=k)
		return quick_sort(q,l,j,k);
	else
		return quick_sort(q,j+1,r,k-s1);
}

int main(){
	
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	cout << quick_sort(a,0,n-1,k) << endl;
} 
