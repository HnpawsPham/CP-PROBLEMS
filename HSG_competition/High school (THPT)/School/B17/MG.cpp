#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, m, res = 0;
const int maxn = 5;
int a[maxn][maxn];

void solve(int sum, int r, int c){
    if(r == n && c == m){;
        res = max(res, sum);
        return;
    }

    for(int i = r + 1; i <= n; i++){
        string s = "";
        for(int j = 0; j < i; j++) s+= to_string(a[j][c]);
        // cout<<s<<el;
    
        solve(sum + stoi(s), i, c); 
    }

    if(r < n)
    for(int j = c + 1; j <= m; j++){
        string s = "";
        for(int i = 0; i < j; i++) s += to_string(a[r][i]); 
        cout<<"r: "<<r<<" sum: "<<sum<<" s: "<<s<<el;
  
        solve(sum + stoi(s), r, j);
    }

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

    solve(0, 0, 0);
    cout<<res<<el;

    return 0;
}