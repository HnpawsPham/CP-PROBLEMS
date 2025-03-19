#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, m, res = 0;
const int maxn = 5;
int a[maxn][maxn];

void solve(int sum, vector<vector<bool>> check){
    bool ok = false;

    for(int i = 0;i <n;i++){
        for(int j =0;j<m;j++){
            if(check[i][j]) continue;
            ok = true;

            int sumi = 0;
            for(int y = i; y < n && !check[y][j]; y++){
                sumi = sumi * 10 + a[y][j];
                check[y][j] = 1;
            }
            solve(sum + sumi, check);
            
            for(int y = i; y < n && check[y][j]; y++) check[y][j] = 0;

            int sumj = 0;
            for(int x = j; x < m && !check[i][x]; x++){
                sumj = sumj * 10 + a[i][x];
                check[i][x] = 1;
            }
            solve(sum + sumj, check);

            for(int x = j; x < m && check[i][x]; x++) check[i][x] = 0;

            return;
        }
    }

    if(!ok) res = max(res, sum);
    return;
}

int main(){
    freopen(".\\txt\\MG.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j = 0; j <m;j++) cin>>a[i][j];

    vector<vector<bool>> check(n, vector<bool>(m, 0));
    solve(0, check);
    cout<<res<<el;

    return 0;
}