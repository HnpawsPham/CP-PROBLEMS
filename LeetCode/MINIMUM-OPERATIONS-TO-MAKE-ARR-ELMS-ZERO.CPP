#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

ll ppow(int a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    if(b & 1) return half * half * a;
    return half * half;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vi> que(n, vi(2));
    for(int i = 0; i < n; i++) cin>>que[i][0]>>que[i][1];

    vector<ll> d;
    for(int i = 1; i <= 15; i++)
        d.push_back(ppow(4, i));

    int res = 0;
    for(const auto& q : que){
        ll cnt = 0;
        int prev = -1;
        
        for(int i = 0; i < 15; i++){
            int l = max(q[0], prev);
            int r = min(1LL * q[1] + 1, d[i]);
            
            if(l < r) cnt += 1LL * (r - l) * (i + 1);
            if(d[i] - 1 >= q[1]) break;
            prev = d[i];
        }

        res += (cnt + 1) / 2;
    }
    cout<<res;
    return 0;
}

// 2
// 1 2
// 2 4