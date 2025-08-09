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

ll lcm(int a, int b){
    return 1LL * a / __gcd(a, b) * b;
}

string sol(){
    ll p[n], s[n];
    for(int i = 0; i < n; i++) cin>>p[i];
    for(int i = 0; i < n; i++) cin>>s[i];

    if (lcm(p[0], s[0]) != p[0]) return "NO";
    if (lcm(p[n - 1], s[n - 1]) != s[n - 1]) return "NO";

    for(int i = 0; i < n; i++){
        ll a = lcm(p[i], s[i]);

        if(i > 0 && __gcd(p[i - 1], a) != p[i]) return "NO";
        if(i < n - 1 && __gcd(a, s[i + 1]) != s[i]) return "NO";
    }
    return "YES";
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