#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=100010;
int n,m,t;
int row[maxn],col[maxn],s[maxn];

ll calc(int a[maxn],int c){
	ll avg=0,mid,res=0;
	if(t%c!=0)
		return -1;
	avg=t/c;
	for(int i=0;i<c;i++){
		s[i]=s[i-1]+a[i]-avg;
	}
	sort(s,s+c);
	mid=s[c/2];
	for(int i=0;i<c;i++)
		res+=abs(s[i]-mid);
	return res;
}

int main(){
	int a,b;
	ll r,c;
	cin >> n >> m >> t;
	for(int i=0;i<t;i++){
		cin >> a >> b;
		row[a]++;
		col[b]++; 
	}
	r=calc(row,n);
	c=calc(col,m);
	if(r==-1&&c==-1){
		cout << "impossible" << endl;
	}else if(r==-1){
		cout << "column " << c << endl;
	}else if(c==-1){
		cout << "row " << r << endl;
	}else{
		cout << "both " << r+c << endl;
	}
}
