#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define pdl pair<db, ll>
#define fi first
#define se second

int tc;

db sol(){
    int n;
    ll k, x;
    cin>>n>>k>>x;
    priority_queue<pdl> pq;
    for(int i = 0; i < n; i++) {
        db eeee;
        cin>>eeee;
        pq.push({eeee, 1});
    }

    ll del = 0;
    vector<pdl> b;

    while(!pq.empty() && del < k){
        auto [len, cnt] = pq.top();
        pq.pop();

        ll cur = min(k - del, cnt);
        del += cur;

        pq.push({len / 2.0, cur * 2});
        if(cnt > cur) pq.push({len, cnt - cur});
    }

    while(!pq.empty()){
        b.push_back(pq.top());
        pq.pop();
    }
    sort(b.begin(), b.end(), greater<pdl>());

    db res = 0;
    ll i = 0;
    for(auto [len, cnt] : b){
        if(i + cnt >= x){
            res = len;
            break;
        }
        i += cnt;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<fixed<<setprecision(20)<<sol()<<el;
    }

    return 0;
}