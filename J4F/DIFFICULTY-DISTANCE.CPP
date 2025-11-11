#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second

int tc = 1;
const int MOD = 998244353;

ll sol(){
    int n;
    cin>>n;
    int a[n + 1];
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);
    a[n] = a[n - 1] + 55;

    ll cnt = 1, len = 1;
    for(int i = 1; i <= n; i++){
        if(a[i] - a[i - 1] <= 1) len++;
        else{
            if(len % 2)
                cnt = cnt * 1LL * ((len + 1) / 2) % MOD;
            len = 1;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}

// 3
// 6
// 2 4 5 7 9 10
// 6
// 1 3 4 9 8 5
// 2
// 1 100