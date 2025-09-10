#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    ll n;
    cin>>tc;
    while(tc--){
        cin>>n;
        ll x = sqrt(n);
        cout<<(x * x == n)<<el;
    }
    return 0;
}

// 10
// 34533463
// 5674563452384
// 456746346345
// 769707856856
// 345345373423
// 123634675846
// 123456789123
// 1231231231312
// 12313435354353
// 67867967967969
