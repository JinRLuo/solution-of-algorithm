#include <iostream>
using namespace std;

const int maxn = 50010;
int p[maxn],c[maxn];
int n,k;

int find(int x){
	if(p[x]!=x){
		int t=p[x];
		p[x]=find(p[x]);
		c[x]+=c[t];
	}
	return p[x];
}

int main(){
	int a,b;
	int res=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)  p[i]=i;
	int t;
	while(k--){
		cin>>t>>a>>b;
		if(a>n||b>n) res++; 
		else if(t==1){
			int pa=find(a),pb=find(b);
			if(pa==pb){
				if((c[a]-c[b])%3){
					res++;
				}
			}else{
				p[pb]=pa;
				c[pb]=c[a]-c[b];
			}
		}else{
			int pa=find(a),pb=find(b);
			if(pa==pb){
				if((c[a]-c[b]-1)%3) res++;
			}else{
				p[pa]=pb;
				c[pa]=c[b]-c[a]+1;
			}
		}
	}
	cout << res << endl;
} 
