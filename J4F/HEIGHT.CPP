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

int tc = 1;

void sol(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    stack<int> st;
    int res[n] = {0}, h[n] = {0};
    
    for(int i = 0; i < n; i++){
        while(!st.empty() && a[st.top()] < a[i])
            st.pop();
        
        if(!st.empty() && a[st.top()] == a[i]) 
            res[i] = res[st.top()] + 1;

        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && a[st.top()] < a[i])
            st.pop();
        
        if(!st.empty() && a[st.top()] == a[i]){
            h[i] = h[st.top()] + 1;
            res[i] += h[i];
        }
        st.push(i);
    }

    for(int i = 0; i < n; i++)
        cout<<res[i]<<" ";
    return;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        sol();
        cout<<el;
    }
    return 0;
}