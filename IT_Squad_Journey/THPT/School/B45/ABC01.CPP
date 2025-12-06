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

int sol(){
    int a, b, c;
    cin>>a>>b>>c;
    int res = 1e6 + 5;

    res = abs(a - b + c);
    res = min(res, abs(a + b - c));
    res = min(res, abs(a + b + c));
    res = min(res, abs(a - b - c));
    res = min(res, abs(a * b + c));
    res = min(res, abs(a * b - c));
    res = min(res, abs(a + b * c));
    res = min(res, abs(a - b * c));
    res = min(res, abs(a * b * c));
    return res;
}

int main(){
    freopen("ABC01.INP", "r", stdin);
    freopen("ABC01.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}

// 2
// -5 7 -9
// 49 -7 8