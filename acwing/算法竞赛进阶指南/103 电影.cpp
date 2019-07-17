#include <bits/stdc++.h>
using namespace std;

const int maxn=200050;
int n,m;
int a;
unordered_map<int,int> mp;

struct move{
	int b,c;
}mv[maxn];

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a;
		mp[a]++;
	}
	cin >> m;
	for(int i=0;i<m;i++)
		cin >> mv[i].b;
	for(int i=0;i<m;i++)
		cin >> mv[i].c;
	int p=0,q=0;
	for(int i=0;i<m;i++){
		if(mp[mv[i].b]>p)
			p=mp[mv[i].b];
	}
	int index;
	for(int i=0;i<m;i++){
		if(mp[mv[i].b]==p){
			if(mp[mv[i].c]>q){
				q=mp[mv[i].c];
				index=i+1;
			}
		}
	}
	cout << index << endl;
}
