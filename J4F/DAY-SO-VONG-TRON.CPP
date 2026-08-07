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

int n;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    bool ok = 1;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(a[i] > 0) ok = 0;
    }

    if(ok) return cout<<*max_element(a, a + n), 0;

    ll p[2 * n + 1] = {0};
    for(int i = 1; i <= 2 * n; i++)
        p[i] = p[i - 1] + a[(i - 1 + n) % n];

    
    const ll oo = 1e12 + 5;
    ll res = -oo;
    deque<int> dq;
    dq.push_back(0);

    for(int i = 1; i <= 2 * n; i++){
        while(!dq.empty() && i - dq.front() >= n)
            dq.pop_front();

        res = max(res, 1LL * a[(i - 1 + n) % n]);
        res = max(res, p[i] - p[dq.front()]);
        
        while(!dq.empty() && p[dq.back()] >= p[i - 1])
            dq.pop_back();
            
        dq.push_back(i - 1);
    }
    cout<<res;
    return 0;
}