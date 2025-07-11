#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define pii pair<unsigned int, int>
#define fi first
#define se second

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<vi> a(m);
    for(int i = 0; i < m; i++){
        int l, r;
        cin>>l>>r;
        a[i] = {l, r};
    }
    sort(a.begin(), a.end());

    int cnt[n] = {0};
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    priority_queue<int, vi, greater<int>> free;

    for(int i = 0; i < n; i++)
        free.push(i);

    for(int i = 0; i < m; i++){
        int l = a[i][0], r = a[i][1];

        while(!pq.empty() && pq.top().fi <= l){
            free.push(pq.top().se);
            pq.pop();
        }

        if(!free.empty()){
            int id = free.top();
            pq.push({a[i][1], id});
            free.pop();

            cnt[id]++;
        }
        else{
            auto [t, j] = pq.top();
            pq.pop();
            pq.push({t + r - l, j});
            cnt[j]++;
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++)
        if(cnt[i] > cnt[res])
            res = i;

    cout<<res;
    return 0;
}

// 2 4
// 0 10
// 1 5
// 2 7
// 3 4