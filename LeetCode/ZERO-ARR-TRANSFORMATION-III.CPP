#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vi a(n);
    int d[n + 1] = {0};
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<vi> q;
    for(int i = 0; i < m; i++){
        int l, r;
        cin>>l>>r;
        q.push_back({l, r});
    }

    sort(q.begin(), q.end(), [](const vi& a, const vi &b){
        return a[0] < b[0];
    });

    priority_queue<int> pq;
    int sum = 0;

    for(int i = 0, j = 0; i < n; i++){
        sum += d[i];

        while(j < m && q[j][0] == i){
            pq.push(q[j][1]);
            j++;
        }

        while(sum < a[i] && !pq.empty() && pq.top() >= i){
            sum++;
            d[pq.top() + 1]--;
            pq.pop();
        }

        if(sum < a[i]) return -1;
    }
    cout<<pq.size();

    return 0;
}