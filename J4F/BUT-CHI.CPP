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
//#define taskname ""

int tc = 1;

int lcm(int a, int b){
    return a * b / __gcd(a, b);
}

int sol(){
    int a, b, x, y;
    cin>>a>>b>>x>>y;

    if(a * x == b * y) return 0;
    int n = max(a * x, b * y);
    int l = lcm(x, y);
    n = ((n + l - 1) / l) * l;
    return n / x + n / y - a - b;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}