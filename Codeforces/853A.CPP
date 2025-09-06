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

    int n, k;
    cin>>n>>k;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    priority_queue<pii> pq;
    ll res = 0;

    int j = 1;
    for(int i = k + 1; i <= k + n; i++){
        while(j <= i && j <= n) {
            pq.push({a[j], j});
            j++;
        }

        a[pq.top().se] = i;
        res += 1LL * (i - pq.top().se) * pq.top().fi;
        pq.pop();
    }
    cout<<res<<el;
    for(int i = 1; i <= n; i++) cout<<a[i]<<" ";
    return 0;
}