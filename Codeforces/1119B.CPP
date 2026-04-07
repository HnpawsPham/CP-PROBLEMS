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

int n, h;

bool check(int t, priority_queue<pii> pq){
    int cnt = 0, m = h;
    while(!pq.empty()){
        if(pq.top().se <= t && pq.top().fi <= m){
            cnt++;
            int tmp = pq.top().fi;
            pq.pop();
            m -= tmp;

            while(!pq.empty()){
                if(pq.top().se <= t && pq.top().fi <= tmp){
                    cnt++;
                    pq.pop();
                    break;
                }
                else pq.pop();
            }
        }
        else pq.pop();
    }
    return cnt >= t;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>h;
    priority_queue<pii> pq;
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        pq.push({x, i});
    }
    
    int l = 0, r = n, mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(check(mid, pq))
            l = mid + 1;
        else r = mid - 1;
    }
    cout<<l - 1;
    return 0;
}