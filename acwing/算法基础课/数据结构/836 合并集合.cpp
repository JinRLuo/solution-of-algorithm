#include <iostream>
using namespace std;

const int maxn = 100010;

int p[maxn];

int find(int x){
    if(p[x]==x) return x;
        return p[x]=find(p[x]);
}

void add(int x,int y){
    int a=find(x);
    int b=find(y);
    p[a]=b;
}

int main(){
    int a,b;
    int n,m;
    char c;
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=0;i<m;i++){
        cin>>c>>a>>b;
        if(c=='M')
            add(a,b);
        else{
            if(find(a)!=find(b))
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
    return 0;
}
