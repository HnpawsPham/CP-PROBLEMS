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

    string s, t;
    getline(cin, s);
    getline(cin, t);

    int cntx = 0;
    ll res = 0;
    for(int x : s){
        cntx += x == t[0];
        if(x == t[1]) res += cntx;
    }
    if(t[0] == t[1]) cout<<1LL * cntx * (cntx - 1) / 2;
    else cout<<res;
    return 0;
}

// aabcbacb
// ab

// tt_tt_tt_t_
// tt

// a bÁcÐ eF!g
// aF