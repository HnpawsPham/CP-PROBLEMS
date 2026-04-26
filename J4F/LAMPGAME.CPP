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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    pii a[n];
    for(int i = 0; i < n; i++) cin>>a[i].fi;
    for(int i = 0; i < n; i++) cin>>a[i].se;
    sort(a, a + n);

    priority_queue<int, vi, greater<int>> pq;
    for(int i = 0; i < n; i++){
        // chua vuot T
        if(pq.size() < a[i].fi) pq.push(a[i].se);
        else if(pq.top() < a[i].se){
            pq.pop();
            pq.push(a[i].se);
        }
    }

    ll res = 0;
    while(!pq.empty()){
        res += pq.top();
        pq.pop();
    }
    cout<<res;
    return 0;
}