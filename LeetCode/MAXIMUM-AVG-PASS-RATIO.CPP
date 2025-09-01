#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pdi pair<db, int>
#define fi first
#define se second

db del(int i, const vector<vi>& a){
    return (db)(a[i][0] + 1) / (a[i][1] + 1) - (db)a[i][0] / a[i][1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    vector<vi> a(n, vi(2));
    for(int i = 0; i < n; i++) cin>>a[i][0]>>a[i][1];

    priority_queue<pdi, vector<pdi>> pq;
    for(int i = 0; i < n; i++)
        pq.push({del(i, a), i});

    while(!pq.empty() && k > 0){
        auto [_, i] = pq.top();
        pq.pop();

        k--;
        a[i][0]++;
        a[i][1]++;
        pq.push({del(i, a), i});
    }

    db res = 0;
    for(int i = 0; i < n; i++)  
        res += (db)a[i][0] / a[i][1];
    res /= n;
    cout<<res;
    return 0;
}

// 3 2
// 1 2
// 3 5
// 2 2

// 4 4
// 2 4
// 3 9
// 4 5
// 2 10