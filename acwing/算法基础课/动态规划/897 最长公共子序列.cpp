#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n,m;
string s1,s2;
int dp[1005][1005];

int main(){
    cin>>n>>m;
    cin>>s1>>s2;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[n][m] << endl;
}
