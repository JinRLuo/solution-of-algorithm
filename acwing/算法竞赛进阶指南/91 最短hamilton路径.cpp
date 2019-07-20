#include <iostream>
#include <string.h>
using namespace std;

int a[25][25];
int dp[1<<20][25];

int main(){
	memset(dp,1,sizeof(dp));
	int i,j,k,n;
	cin >> n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			cin >> a[i][j];
	}
	dp[1][0]=0;
	for(i=1;i<(1<<n);i++){
		for(j=0;j<n;j++){
			if(i&(1<<j))
				for(k=0;k<n;k++){
					if(i!=k&&a[k][j]!=0)
						dp[i][j]=min(dp[i^(1<<j)][k]+a[k][j],dp[i][j]); 
				}
		}
	}
//	for(i=1;i<(1<<n);i++){
//		for(j=0;j<n;j++)
//			cout << dp[i][j] << "\t";
//		cout << endl;
//	}
	cout << dp[(1<<n)-1][n-1] << endl;
}
