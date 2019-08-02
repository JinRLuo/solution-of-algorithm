#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;

int N, T, M1, M2;
int tt[55];
bool has_train[1000][55][2];
int dp[205][55];

int main(){
	int a,k=0;
	while (cin >> N&&N){
		memset(has_train, 0, sizeof(has_train));
		memset(tt, 0, sizeof(tt));
		k++;
		cin >> T;
		for (int i = 1; i < N; i++){
			cin >> tt[i];
		}
		cin >> M1;
		for (int i = 0; i < M1; i++){
			cin >> a;
			has_train[a][0][0] = true;
			for (int j = 1; j < N; j++){
				a += tt[j];
				if (a <= T)
					has_train[a][j][0] = true;
				else
					break;
			}
		}
		cin >> M2;
		for (int i = 0; i < M2; i++){
			cin >> a;
			has_train[a][N - 1][1] = true;
			for (int j = N; j > 1; j--){
				a += tt[j-1];
				if (a <= T)
					has_train[a][j - 2][1] = true;
				else
					break;
			}
		}
		//for (int i = 0; i <= T; i++){
		//	for (int j = 0; j < N; j++){
		//		cout << has_train[i][j][0] << " ";
		//	}
		//	cout << endl;
		//}
		for (int i = 0; i < N; i++){
			dp[T][i] = INF;
		}
		dp[T][N - 1] = 0;
		for (int i = T - 1; i >= 0; i--){
			for (int j = 0; j < N; j++){
				dp[i][j] = dp[i+1][j]+1;
				if (j < N-1 && has_train[i][j][0] && T >= i + tt[j+1]){
					dp[i][j] = min(dp[i][j], dp[i + tt[j+1]][j + 1]);
				}
				if (j > 0 && has_train[i][j][1] && T >= i+tt[j]){
					dp[i][j] = min(dp[i][j], dp[i + tt[j]][j - 1]);
				}
			}
		}
		//for (int i = 0; i <= T; i++){
		//	cout << "i:" << i << " ";
		//	for (int j = 0; j < N; j++){
		//		cout << dp[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		cout << "Case Number " << k << ": ";
		if (dp[0][0] >= INF)
			cout << "impossible" << endl;
		else
			cout << dp[0][0] << endl;
	}
}
