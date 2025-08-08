#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define tiii tuple<int, int, int>

int t, n, k;

ll sol(){
    vector<tiii> a;

    for(int i = 0; i < n; i++){
        int l, r, w;
        cin>>l>>r>>w;
        a.push_back({l, r, w});    
    }

    sort(a.begin(), a.end());

    for(auto [l, r, w] : a){
        if(k < l) break;
        if(k <= r) k = max(k, w);
    }
    return k;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>k;
        cout<<sol()<<el;
    }

    return 0;
}