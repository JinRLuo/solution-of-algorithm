#include <iostream>
#include <cstring> 
using namespace std;

const int maxn = 1010;
int n,m;
int f[maxn][maxn];
string s1,s2;

int main(){
	memset(f,0,sizeof(f));
	cin>>n>>s1>>m>>s2;
	for(int i=0;i<m;i++) f[0][i+1]=i+1;
	for(int i=0;i<n;i++) f[i+1][0]=i+1;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=min(f[i][j-1]+1,f[i-1][j]+1);
			if(s1[i-1]==s2[j-1])
				f[i][j]=min(f[i][j],f[i-1][j-1]);
			else
				f[i][j]=min(f[i][j],f[i-1][j-1]+1);
		}
	}
	cout << f[n][m] << endl;
} 
