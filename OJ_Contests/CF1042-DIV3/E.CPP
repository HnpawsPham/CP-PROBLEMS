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

string sol(){
    int a[n + 1], b[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) cin>>b[i];

    if (a[n] != b[n]) return "no";

    vector<bool> check(n);
    bool ok = true;

    for (int i = n - 1; i >= 1; --i) {
        ll del = a[i] ^ b[i];
        set<ll> pos;
        if (i + 1 == n) 
            pos.insert(a[n]);

        else {
            if (check[i + 1]) {
                pos.insert(a[i + 1]);
                pos.insert(b[i + 1]);
            } 
            else pos.insert(a[i + 1]);
        }

        if (del == 0) 
            check[i] = false;
        else {
            if (pos.count(del)) 
                check[i] = true;
            else {
                ok = false;
                break;
            }
        }
    }

    if (ok) return "yes";
    return "no";
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