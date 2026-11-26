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

    int n, d;
    ll k;
    cin>>n>>k>>d;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll p[n + 1];
    p[0] = 0;
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i - 1];

    deque<int> dq;
    int l = 1, res = min(n, d);
    for(int i = 1; i <= n; i++){
        if(i >= d){
            while(!dq.empty() && p[dq.back()] - p[dq.back() - d] <= p[i] - p[i - d])
                dq.pop_back();
            dq.push_back(i);
        }

        while(l <= i){
            ll sum = 0;
            if(i - l + 1 > d){
                while(!dq.empty() && dq.front() < l + d - 1)
                    dq.pop_front();
                sum = p[i] - p[l - 1] - p[dq.front()] + p[dq.front() - d];
            }
            if(sum <= k) break;
            l++;
        }
        if(l <= i) res = max(res, i - l + 1);
    }
    cout<<res;
    return 0;
}