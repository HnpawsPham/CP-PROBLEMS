#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc;
const ll oo = 1e11;

int id(const string& s){
    if(s == "01") return 0;
    if(s == "10") return 1;
    if(s == "11") return 2;
    return 3;
}

int sol(){
    int n;
    cin>>n;
    ll minn[4];
    minn[0] = minn[1] = minn[2] = oo;

    while(n--){
        int x;
        string s;
        cin>>x>>s;
        minn[id(s)] = min(minn[id(s)], 1LL * x);
    }

    ll res = oo;
    res = min(minn[id("01")] + minn[id("10")], minn[id("11")]);
    return (res < oo ? res : -1);
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