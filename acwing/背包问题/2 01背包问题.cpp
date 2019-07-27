#include <bits/stdc++.h>
using namespace std;

int f[1010];
int v[1010];
int w[1010];

int main(){
    int N,V;
    memset(f,0,sizeof(f));
    cin>>N>>V;
    for(int i=1;i<=N;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=V;j>0;j--){
            if(j>=v[i])
                f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    cout << f[V] << endl;
}
