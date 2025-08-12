#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int t, n;

ll sol(){
    int d[n + 1] = {0};
    for(int i = 1; i <= n; i++) cin>>d[i];
    sort(d + 1, d + n + 1);

    ll p[n + 1] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = 1LL * p[i - 1] + d[i];

    ll res = 0;
    for(int i = 1; i <= n; i++)
        res += 1LL * d[i] * (n - i) - 1LL * (p[n] - p[i]) + d[i] - d[i - 1];
    
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        cout<<sol()<<el;
    }

    return 0;
}

// 1  
// 3
// 0 2 3