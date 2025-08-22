#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int res = 0;
    stack<int> st;

    for(int i = 0; i < n; i++){
        while(!st.empty() && a[st.top()] > a[i]){
            int h = a[st.top()];
            st.pop();
            int l = (st.empty() ? 0 : st.top());
            res = max(res, h * (i - l - 1));
        }
        st.push(i);
    }
    cout<<res;
    return 0;
}

// 2
// 2 4

// 6
// 2 1 5 6 2 3