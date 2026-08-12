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

    int l, n;
    cin>>l>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll sum = 0;
    priority_queue<ll, vll, greater<ll>> pq;
    for(const int& x : a)
        pq.push(x);

    while(pq.size() > 1){
        ll cost = pq.top();
        pq.pop();

        cost += pq.top();
        pq.pop();

        sum += cost;
        pq.push(cost);
    }
    cout<<sum;
    return 0;
}