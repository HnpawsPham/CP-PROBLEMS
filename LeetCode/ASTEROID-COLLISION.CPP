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
    vector<pii> tmp;
    vi res;
    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            st.push(i);
            continue;
        }

        bool ok = 1;
        while(!st.empty() && ok){
            if(a[st.top()] >= abs(a[i])) ok = 0;
            if(a[st.top()] <= abs(a[i]))
                st.pop();
        }
        if(st.empty() && ok) tmp.push_back({i, a[i]});
    }

    while(!st.empty()){
        tmp.push_back({st.top(), a[st.top()]});
        st.pop();
    }

    sort(tmp.rbegin(), tmp.rend());
    while(!tmp.empty()){
        res.push_back(tmp.back().second);
        tmp.pop_back();
    }
    
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 3
// 5 10 -5

// 6
// 3 5 -6 2 -1 4

// 2 
// 8 -8