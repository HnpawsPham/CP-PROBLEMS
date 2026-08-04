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
const int oo = 1e9 + 5;

ll getsum(const vi& gr1, const vi& gr2){
    if(gr1.empty()) return 0;
    ll res = 0;
    int sz1 = gr1.size(), sz2 = gr2.size();

    int i = 0;
    for(; i < min(sz1, sz2); i++)
        res += 2LL * (gr1[i] + gr2[i]);

    if(sz1 == sz2) res -= gr1.back();

    for(; i < sz1; i++)
        res += gr1[i];

    for(; i < sz2; i++)
        res += gr2[i];
    return res;
}

ll sol(){
    int n;
    cin>>n;
    int a[n + 5];
    bool b[n];
    for(int i = 0; i < n; i++) cin>>b[i];
    for(int i = 0; i < n; i++) cin>>a[i];

    vi gr1, gr2;
    for(int i = 0; i < n; i++){
        if(b[i])
            gr1.push_back(a[i]);
        else gr2.push_back(a[i]);
    }
    sort(gr1.rbegin(), gr1.rend());
    sort(gr2.rbegin(), gr2.rend());

    return max(getsum(gr1, gr2), getsum(gr2, gr1));
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