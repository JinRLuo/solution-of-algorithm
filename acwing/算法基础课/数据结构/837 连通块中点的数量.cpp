#include <iostream>
using namespace std;

const int maxn = 100010;
int n,m;
int p[maxn];
int c[maxn];

int find(int x){
	if(p[x]==x) return x;
	return p[x]=find(p[x]);
}

void add(int x,int y){
	int a=find(x);
	int b=find(y);
	if(a!=b){
	    c[a]+=c[b];
	    p[b]=a;
	}
}

int main(){
	int a,b;
	cin>>n>>m;
	char s[5];
	for(int i=1;i<=n;i++){
		p[i]=i;
		c[i]=1;
	}
	
	for(int i=0;i<m;i++){
		cin>>s;
		if(s[0]=='C'){
			cin>>a>>b;
			add(a,b);
		}else if(s[1]=='1'){
			cin>>a>>b;
			if(find(a)==find(b))
				cout << "Yes" << endl;
			else 
				cout << "No" << endl;
		}else{
			cin>>a;
			cout << c[find(a)] << endl;
		}
	}
    
}
