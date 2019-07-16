#include <bits/stdc++.h>
using namespace std;

int n,r;
//int we[5010][5010];
int di[5010][5010];

int main(){
	//memset(we,0,sizeof(we));
	memset(di,0,sizeof(di));
	int x,y,w;
	cin >> n >> r;
	int mx=r,my=r,ma=0,res;
	for(int i=0;i<n;i++){
		cin >> x >> y >> w;
		x++;
		y++;
		mx=max(mx,x);
		my=max(my,y);
		di[x][y]=w;
	}
	for(int i=1;i<=mx;i++){
		for(int j=1;j<=my;j++){
			di[i][j]=di[i-1][j]+di[i][j-1]-di[i-1][j-1]+di[i][j];
		}
	}
	
	for(int i=1;i<=mx-r+1;i++){
		for(int j=1;j<=my-r+1;j++){
			res=di[i+r-1][j+r-1]-di[i-1][j+r-1]-di[i+r-1][j-1]+di[i-1][j-1];
			ma=max(ma,res);
		}
	}
//  第二种遍历方法，由于正方形边界的点不会被轰炸，所以最后一项的i-r和j-r不需减一 
//	for(int i=r;i<=mx;i++){
//		for(int j=r;j<=my;j++){
//			res=di[i][j]-di[i-r][j]-di[i][j-r]+di[i-r][j-r];
//		}
//	}

	cout << ma << endl;
}
