#include <iostream> 
using namespace std;

const int maxn = 1e6+10;

int n;
int a[maxn];

void quick_sort(int* q,int l,int r){
	if(l<r){
		int x=q[l];
		int i=l-1,j=r+1;
		while(i<j){
			while(q[++i]<x);
			while(q[--j]>x);
			if(i<j)	swap(q[i],q[j]);
		}
		
		quick_sort(q,l,i);
		quick_sort(q,i+1,r);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	quick_sort(a,0,n-1);
	
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
