#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, m, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int l[m + 1], r[m + 1], w[m + 1];
    for(int i = 0; i < m; i++){
        cin>>l[i]>>r[i]>>w[i];
        l[i]--; r[i]--;
    }
    
    int f[m + 1] = {0};
    for(int i = 0; i < k; i++){
        int X, Y;
        cin>>X>>Y;
        X--; Y--;
        f[X]++;
        f[Y + 1]--;
    }

    ll d[n + 1] = {0};
    int cnt = 0;

    for(int i = 0; i < m; i++){
        cnt += f[i];
        if(cnt == 0) continue;
        
        d[l[i]] += 1LL * w[i] * cnt;
        d[r[i] + 1] -= 1LL * w[i] * cnt;
    }

    ll sum = 0, res = 0;
    for(int i = 0; i < n; i++){
        sum += d[i];
        res = 1LL * a[i] + sum;
        cout<<res<<" ";
    }
    return 0;
}