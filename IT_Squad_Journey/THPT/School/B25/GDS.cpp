#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;
const int maxn = (int)1e6 + 5;
ll a[maxn];
stack<ll> st;

int main(){
    freopen(".\\txt\\GDS.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n, greater<ll>());

    for(int i = 0; i < n; i++){
        if(st.empty()){
            st.push(a[i]);
            continue;
        }

        ll x = a[i];
        while(!st.empty() && x == st.top()){
            st.pop();
            x++;
        } 
        st.push(a[i]);
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}