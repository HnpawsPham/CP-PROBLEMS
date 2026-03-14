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
#define taskname "PS"

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n + 5];
    memset(a, 0, sizeof a); 
    for(int i = 1; i <= n; i++) cin>>a[i];

    ll p[n + 5];
    memset(p, 0, sizeof p);
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i];

    stack<int> st;
    for(int i = 0; i <= n; i++){
        if(st.empty() || p[i] < p[st.top()])
            st.push(i);
    }

    int l = 1, r = 1, res = 0;
    for(int i = n; i > 0; i--){
        while(!st.empty() && p[st.top()] < p[i]){
            int tmp = st.top();
            st.pop();

            if(i - tmp > res){
                res = i - tmp;
                l = tmp + 1;
                r = i;
            }
        }
    }
    cout<<l<<" "<<r;
    // cout<<el<<r - l+ 1;
    return 0;
}

// 10
// -5 -2 -3 4 -6 7 -8 9 -1 -20