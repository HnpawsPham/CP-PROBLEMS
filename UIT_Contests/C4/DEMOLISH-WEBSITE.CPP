#include <bits/stdc++.h>
using namespace std;
#define el "\n"

// DP BITMASK, KHI NAO BOT NGU DP THI QUAY LAI

int n, k, res = INT_MAX;
int a[15][25];
bool check[15] = {0};

void sol(int i, int j, int sum){
    if(j == n){
        res = min(res, sum);
        return;
    }

    for(int x = 0; x < k; x++){
        if(check[x]) continue;
        check[x] = 1;
        sol(x, j + 1, sum + a[x][j]);
        check[x] = 0;
    }

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i = 0; i < k; i++)
        for(int j = 0; j < n; j++) cin>>a[i][j];

    sol(0, 0, 0);
    cout<<res;

    return 0;
}