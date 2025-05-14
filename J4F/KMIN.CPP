#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

int n, m, k;
const int maxn = 50002;
ll a[maxn], b[maxn];

struct comp{
    bool operator()(const pii &i, const pii &j){
        return a[i.fi] + b[i.se] > a[j.fi] + b[j.se]; 
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    sort(a, a + n);
    sort(b, b + m);

    priority_queue<pii, vector<pii>, comp> pq;

    for(int i = 0; i < n; i++) pq.push({i, 0});

    while(k--){
        pii x = pq.top();
        pq.pop();

        cout<<a[x.fi] + b[x.se]<<el;

        if(x.se < m - 1)
            pq.push({x.fi, x.se + 1});
    }
    return 0;
}