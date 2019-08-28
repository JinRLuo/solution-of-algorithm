#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool cmp(vector<int> a,vector<int> b){
	if(a.size()<b.size())
		return false;
	else if(a.size()>b.size())
		return true;
	else{
		int len=a.size()-1;
		while(len>=0){
			if(a[len]>b[len])
				return true;
			else if(a[len]<b[len])
				return false;
			len--; 
		}
		return true;
	}
}

vector<int> sub(vector<int> a,vector<int> b){
	vector<int> c;
	int t=0;
	for(int i=0;i<a.size();i++){
	    t+=a[i];
	    if(i<b.size()) t-=b[i];
	    c.push_back((t+10)%10);
	    if(t<0)
	        t=-1;
	    else
	        t=0;
	}
	return c;
}

int main(){
	string A,B;
	vector<int> a,b;
	cin>>A>>B;
	for(int i=A.size()-1;i>=0;i--) a.push_back(A[i]-'0');
	for(int i=B.size()-1;i>=0;i--) b.push_back(B[i]-'0');
	
	if(cmp(a,b)){
		auto c = sub(a,b);
		for(int i=c.size()-1;i>=0;i--) cout << c[i];
		cout << endl;
	}else{
		auto c = sub(b,a);
		cout << "-";
		for(int i=c.size()-1;i>=0;i--) cout << c[i];
		cout << endl;
	}
} 
