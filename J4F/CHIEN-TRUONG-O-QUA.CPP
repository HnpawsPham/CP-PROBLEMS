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

    int l[n], r[n];
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);

    stack<int> st;
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

    int maxx = 0, posl = 0, posr = 0;
    for(int i = 0; i < n; i++){
        int cur = a[i] * (r[i] - l[i] + 1);
        if(cur > maxx){
            maxx = cur;
            posl = l[i];
            posr = r[i];
        }
        else if(cur == maxx && l[i] < posl){
            posl = l[i];
            posr = r[i];
        }
    }
    cout<<maxx<<" "<<posl + 1<<" "<<posr + 1;
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