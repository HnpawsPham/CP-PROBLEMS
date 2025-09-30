#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, ll>
#define fi first
#define se second

int tc, n, m, k, x;

pii convert(int x, int m){
    int cnt = 1;
    while(x % m == 0){
        x /= m;
        cnt *= m;
    }
    return {x, cnt};
}

void add(int x, vector<pii>& a){
    pii tmp = convert(x, m);
    if(!a.empty() && a.back().fi == tmp.fi)
        a.back().se += tmp.se;
    else a.push_back(tmp);
    return;
}

string sol(){
    cin>>n>>m;
    vector<pii> cnta, cntb;
    while(n--){
        cin>>x;
        add(x, cnta);
    }

    cin>>k;
    while(k--){
        cin>>x;
        add(x, cntb);
    }
    return (cnta == cntb ? "Yes" : "No");
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--)
        cout<<sol()<<el;
    return 0;
}