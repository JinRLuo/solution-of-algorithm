#include <iostream>
#include <string>
using namespace std;

const int maxn = 10010;
int n,m;
char p[maxn],s[maxn];
int ne[maxn];

int main(){
//	scanf("%d %s",&n,&p);
//	scanf("%d %s",&m,&s);
	cin>>n>>p+1>>m>>s+1;
	//cin>>n>>p>>m>>s;
	//ÇónextÊı×é
	int j=0;
	//ne[0]=-1;
	for(int i=2;i<=n;i++){
		while(j&&p[j+1]!=p[i]) j=ne[j];
		if(p[j+1]==p[i]) j++;
		ne[i]=j;
	}
	j=0;
	for(int i=0;i<=m;i++){
		while(j&&p[j+1]!=s[i]) j=ne[j];
		if(p[j+1]==s[i]) j++;
		if(j==n){
			cout << i-j << " ";
			j=ne[j];
		}
	} 
	cout << endl;
}
