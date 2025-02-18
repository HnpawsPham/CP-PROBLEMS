#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int n, m, t, res = 0;
const int maxn = 1005;
int a[maxn][maxn];

int solve (int h[]){
    int maxx = 0;
    stack<int> s;

    for(int i = 1; i <= m; i++){
        while(!s.empty() && h[s.top()] > h[i]){
            int h1 = h[s.top()]; s.pop();
            int w = (s.empty() ? i : i - s.top() - 1);
            maxx = max(maxx, h1 * w);
        }
        s.push(i);
    }
    while (!s.empty()) {
        int h1 = h[s.top()];
        s.pop();
        int w = (s.empty() ? m : m - s.top());
        maxx = max(maxx, h1 * w);
    }
    return maxx;
}

int main(){
    freopen(".\\txt\\REC.INP" ,"r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i = 1; i<=n;i++)
        for(int j = 1; j<=m;j++) cin>>a[i][j];

    int h01[n + 1][m + 1], h12[n + 1][m + 1];

    for(int i = 0;i<=n;i++)
        for(int j = 0;j<=m;j++) h01[i][j] = h12[i][j] = 0;
    

    for(int i = 1;i<=n;i++)
        for(int j = 1; j<=m; j++){
            if(a[i][j] < 2) h01[i][j] = h01[i - 1][j] + 1;
            if(a[i][j] > 0) h12[i][j] = h12[i - 1][j] + 1;
        }
    cin>>t;
    while(t--){
        int u, d;
        cin>>u>>d;

        int l01[m + 1], l12[m + 1];

        for(int j = 1; j <= m;j++){
            l01[j] = h01[d][j] - h01[u - 1][j];
            l12[j] = h12[d][j] - h12[u - 1][j];
        }  
        
        int s1 = solve(l01);
        int s2 = solve(l12);
        cout<<max(s1, s2)<<el;
    }
    return 0;
}