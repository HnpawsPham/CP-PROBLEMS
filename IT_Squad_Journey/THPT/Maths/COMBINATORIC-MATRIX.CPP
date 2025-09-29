// MOD k can prime van ok O(n^2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 5005;
const int MOD = 1e9 + 7;
ll C[maxn][maxn];

void calc_comb(){
    for(int i = 0; i < maxn; i++){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    calc_comb();
    cout<<C[3][2];
    return 0;
}