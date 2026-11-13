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

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];

    int r = n - 1;
    deque<int> dq;
    ll res = 0, sum = 0;
    for(int i = n - 1; i >= 0; i--){
        while(!dq.empty() && a[dq.back()] <= a[i]){
            int top = dq.back();
            dq.pop_back();
            sum += 1LL * ((dq.empty() ? r + 1 : dq.back()) - top) * 1LL * (a[i] - a[top]);  
        }
        dq.push_back(i);

        while(!dq.empty() && sum > k){
            int bot = dq.front();
            sum -= (a[bot] - a[r]);
            if(bot == r) dq.pop_front();
            r--;
        }
        if(dq.empty()) sum = 0;

        res += r - i + 1;
    }
    cout<<res;
    return 0;
}

// 6 7
// 6 3 1 2 4 4 