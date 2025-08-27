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
ll res = 0;

void inp(vi& a){
    int k;
    cin>>k;
    for(int i = 0; i < k; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    return;
}

void calc(const vi& a, int h){
    res = max(res, 1LL * (a.back() - a[0]) * h);
    return;
}

ll sol(){
    int w, h;
    res = 0;
    cin>>w>>h;
    vi x1, x2, y1, y2;
    inp(x1);
    inp(x2);
    inp(y1);
    inp(y2);
    calc(x1, h);
    calc(x2, h);
    calc(y1, w);
    calc(y2, w);
    return res;
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