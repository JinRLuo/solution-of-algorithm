#include <bits/stdc++.h>
using namespace std;

const int maxn=250010;
int a[maxn];
int b[maxn];
int c[maxn];
int temp;

void merge_sort(int* a,int x,int y,int* T){
	if(y-x>1){
		int m=(x+y)/2;
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
			a[i]=T[i];
		}
	}
}

int main(){
	int a1,a2;
	int n;
	int k,w;
	while(cin>>n){
		temp=0;
		k=0;
		for(int i=0;i<n*n;i++){
			cin >> a[i-k];
			if(a[i-k]==0)
				k=1;
		}
// 		for(int i=0;i<n*n;i++){
// 			cout << a[i] << " ";
// 		}
// 		cout << endl;
		merge_sort(a,0,n*n,c);
		a1=temp;
		temp=0;
		k=0;
		for(int i=0;i<n*n;i++){
			cin >> b[i-k];
			if(b[i-k]==0)
				k=1;
		}
// 		for(int i=0;i<n*n;i++){
// 			cout << a[i] << " ";
// 		}
// 		cout << endl;
		merge_sort(b,0,n*n,c);
		a2=temp;
		if(a1%2==a2%2)
			cout << "TAK" << endl;
		else
			cout << "NIE" << endl;
	}
}
