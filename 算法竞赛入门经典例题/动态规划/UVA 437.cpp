#include <bits/stdc++.h>
using namespace std;

struct tower{
	int x,y;
	int h;
}tw[100];

int n,cnt;
int bi[3];
int g[100][100];
int r[100];

int dp(int i){
	if(r[i]!=0)
		return r[i];
	r[i]=tw[i].h;
	for(int j=0;j<cnt;j++){
		if(g[i][j]){
			r[i]=max(r[i],dp(j)+tw[i].h);
		}
	}
	return r[i];
}

int main(){
	int k=0;
	int a,b,c;
	while(cin>>n&&n){
		cnt=0;
		memset(r,0,sizeof(r));
		k++;
		while(n--){
			cin>>a>>b>>c;
			tw[cnt].x=min(a,b);
			tw[cnt].y=max(a,b);
			tw[cnt++].h=c;
			tw[cnt].x=min(a,c);
			tw[cnt].y=max(a,c);
			tw[cnt++].h=b;
			tw[cnt].x=min(b,c);
			tw[cnt].y=max(b,c);
			tw[cnt++].h=a;
		}
		memset(g,0,sizeof(g));
		for(int i=0;i<cnt;i++){
			for(int j=0;j<cnt;j++){
				if(tw[i].x<tw[j].x&&tw[i].y<tw[j].y){
					g[i][j]=1;
				}
			}
		}
		int res=0;
		for(int i=0;i<cnt;i++){
			res=max(res,dp(i));
		}
		cout << "Case " << k << ": maximum height = " << res << endl;
	}
}
