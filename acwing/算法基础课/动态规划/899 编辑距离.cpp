#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1005;
int n,m;
string a[maxn];
string b;
int q;
int f[12][12];

int edit(string a1,string a2){
	memset(f,0,sizeof(f));
	int len1=a1.length();
	int len2=a2.length();
	for(int i=0;i<=len2;i++) f[0][i]=i;
	for(int i=0;i<=len1;i++) f[i][0]=i;
	
	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1);
			if(a1[i-1]==a2[j-1])
				f[i][j]=min(f[i][j],f[i-1][j-1]);
			else
				f[i][j]=min(f[i][j],f[i-1][j-1]+1);
		}
	}
	return f[len1][len2];
}

int main(){
	int res;
	int tmp;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	while(m--){
		cin>>b>>q;
		res=0;
		for(int i=0;i<n;i++){
			tmp=edit(a[i],b);
			//cout << tmp << endl;
			if(tmp<=q)
				res++;
		}
		cout << res << endl; 
	}
} 
