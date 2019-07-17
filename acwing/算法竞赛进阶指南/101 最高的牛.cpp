#include <bits/stdc++.h>
using namespace std;

int f[10050]; 
set<pair<int,int> > s;


int main(){
	int n,p,h,m,a,b;
	cin >> n >> p >> h >> m;
	memset(f,0,sizeof(f));
	f[1]=h;
	while(m--){
		cin >> a >> b;
		if(a>b) swap(a,b);
		if(!s.count({a,b})){
			f[a+1]--;
			f[b]++;
			s.insert({a,b});
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+f[i];
		cout << f[i] << endl;
	}
	
}
