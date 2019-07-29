#include <bits/stdc++.h>
using namespace std;

const int maxn=510;
int n;
int a[maxn][maxn];
int dp[maxn][maxn];

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cin >> a[i][j];
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<i+1;j++){
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
        }
    }
    cout << dp[0][0] << endl;
}
