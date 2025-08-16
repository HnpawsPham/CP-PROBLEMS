#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int a, b, c, k, n;
ll f1 = 1, f2 = 2, f3 = 3;

ll calc(ll a, ll b, ll c){
    return ((a * f1) % k + (b * f2) % k + (c * f3) % k) % k;
}

ll sol(){
    if(n == 1) return 1;
    else if(n == 2) return 2;
    else if(n == 3) return 3;

    f1 %= k; f2 %= k; f3 %= k;
    for(int i = 4; i <= n; i++){
        ll tmp;
        
        if(i % 3 == 1) tmp = calc(a, b, c);
        else if(i % 3 == 2) tmp = calc(b, c, a);
        else tmp = calc(c, a, b);

        f1 = f2;
        f2 = f3;
        f3 = tmp;
    }
    return f3 % k;
}

int main(){
    freopen("FI3.INP", "r", stdin);
    freopen("FI3.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b>>c>>k>>n;
    cout<<sol();
    return 0;
}