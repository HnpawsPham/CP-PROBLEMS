#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int, int>
#define fi first
#define se second
#define MOD 1000000007
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, k;

ll ppow(int a, int b){
    ll res = 1;
    while(b > 0){
        if(b % 2 == 1) res = (res * a) % MOD; 
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    // calc prime score
    int pscore[n] = {};
    for (int i = 0; i < n; ++i) {
        int x = a[i];

        for (int j = 2; j * j <= x; ++j) {
            if (x % j == 0) {
                pscore[i]++;
                while (x % j == 0) x /= j;
            }
        }
        if (x > 1) pscore[i]++;
    }

    // count range
    int l[n], r[n];
    stack<int> st;

    for(int i = 0; i < n; i++){
        while(!st.empty() && pscore[st.top()] < pscore[i]){
            r[st.top()] = i;
            st.pop();
        }

        if(!st.empty()) l[i] = st.top();
        st.push(i);
    }
    
    priority_queue<pii> pq;
    for(int i = 0; i < n; ++i) pq.push({a[i], i});

    // calc point
    ll point = 1;

    while(k > 0){
        pii cur = pq.top();
        pq.pop();

        int val = cur.fi;
        int i = cur.se;
        ll range = (ll)(i - l[i]) * (r[i] - i);

        ll times = min((ll)k, range);
        point = (point * ppow(val, times)) % MOD;
        k -= times;
    }
    cout<<point;
    return 0;
}