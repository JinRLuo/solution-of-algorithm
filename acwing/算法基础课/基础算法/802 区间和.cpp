#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 300010;
vector<int> alls;
vector<pair<int,int> > add,que;
int a[maxn];
int m,n;

int find(int x){
	int l=0,r=alls.size()-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(alls[mid]>=x){
			r=mid;
		}else
			l=mid+1;
	}
	return r+1;
}

int main(){
	int x,c,l,r;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x>>c;
		alls.push_back(x);
		add.push_back({x,c});
	}
	for(int i=0;i<m;i++){
		cin>>l>>r;
		que.push_back({l,r});
		alls.push_back(l);
		alls.push_back(r);
	}
	
	sort(alls.begin(),alls.end());
	alls.erase(unique(alls.begin(),alls.end()),alls.end());
	
	for(int i=0;i<n;i++){
		a[find(add[i].first)]+=add[i].second;
	}
	int res;
	for(int i=1;i<=alls.size();i++){
		a[i]=a[i-1]+a[i];
	}
	
	for(int i=0;i<m;i++){
		res = a[find(que[i].second)]-a[find(que[i].first)-1];
		cout << res << endl;
	}
} 
