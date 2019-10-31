#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
using namespace std;

string s;
unordered_map<string,int> m;
queue<string> q;
int dx[4]={-3,3,-1,1};

void bfs(){
	string s1,s2;
	while(!q.empty()){
		int k;
		s1=q.front();
		q.pop();
		for(int i=0;i<9;i++){
			if(s1[i]=='9')
				k=i;
		}
		for(int i=0;i<4;i++){
			if((k%3==0&&i==2)||(k%3==2&&i==3))
				continue;
			int next=k+dx[i];
			s2=s1;
			if(next>=0&&next<9){
				swap(s2[k],s2[next]);
				//cout << s1 << " " << s2 << " k:" << k << endl;
				if(m[s2]==0){
					m[s2]=m[s1]+1;
					if(s2=="123456789"){
						//cout << s1 << " " << s2 << " k:" << k << endl;
						return;
					}
					q.push(s2);
				}
			}
		}
	}
}

int main(){
	string sa;
	for(int i=0;i<9;i++){
		cin>>sa;
		if(sa=="x")
			sa="9";
		s.append(sa);
	}
	m[s]=1;
	q.push(s);
	bfs();
	cout << m["123456789"]-1 << endl;
}
