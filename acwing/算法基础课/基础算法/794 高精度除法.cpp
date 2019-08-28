#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int res;

vector<int> div(vector<int> a,int b){
	int flag=1;
	vector<int> c;
	int t=0;
	for(int i=0;i<a.size();i++){
		t=t*10+a[i];
		c.push_back(t/b);
		t%=b;
	}
	
	res = t;
	
	reverse(c.begin(),c.end());
	while(c.size()>1&&c.back()==0) c.pop_back();
	
	return c;
}

int main(){
	int flag=1;
	string A;
	vector<int>a;
	int b;
	cin>>A>>b;
	for(int i=0;i<A.size();i++) a.push_back(A[i]-'0');
	
	auto c = div(a,b);
	
	for(int i=c.size()-1;i>=0;i--) cout << c[i];
	cout << endl;
	cout << res << endl;
	
}
