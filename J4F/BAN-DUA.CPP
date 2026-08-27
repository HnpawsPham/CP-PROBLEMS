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

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    stack<int> st;
    int l[n], r[n];

    for(int i = 0; i < n; i++){
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();
        
        l[i] = (st.empty() ? 0 : st.top() + 1);
        st.push(i);
    }
    while(!st.empty()) st.pop();

    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();
        
        r[i] = (st.empty() ? n - 1 : st.top() - 1);
        st.push(i); 
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        if(r[i] - l[i] + 1 >= a[i])
            res = max(res, a[i]);
    }
    cout<<res;
    return 0;
}