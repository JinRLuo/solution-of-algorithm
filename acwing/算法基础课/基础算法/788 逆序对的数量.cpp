#include <iostream>
using namespace std;

int N;
int a[100010];
int t[100010];
long long res;

void merge_sort(int* b,int n,int m){
	if(m>n+1){
		int mid=(n+m)/2;
		int i=n,j=mid,k=n;
		merge_sort(b,n,mid);
		merge_sort(b,mid,m);
		while(i<mid||j<m){
			if(j>=m||(i<mid&&b[i]<=b[j]))
				t[k++]=b[i++];
			else{
				t[k++]=b[j++];
				res+=mid-i;
			}
		}
		for(int l=n;l<m;l++)
			b[l]=t[l];
	}
}

int main(){
	res=0;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>a[i];
	merge_sort(a,0,N);
	cout << res << endl;
} 
