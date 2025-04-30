#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    priority_queue<pii> pq;
    vector<int> res;

    for(int i = 0; i < k; i++) 
        pq.push({a[i], i});
    res.push_back(pq.top().fi);
    
    for(int i = k; i < n; i++){
        pq.push({a[i], i});

        while(!pq.empty() && pq.top().se <= i - k)
            pq.pop();

        res.push_back(pq.top().fi);
    }

    for(int x : res) cout<<x<<" ";
    return 0;
}