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
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    stack<int> st;
    int res[n] = {0};

    for(int i = 0; i < n; i++){
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();

        if(!st.empty())
            res[i] = st.top() + 1;
        
        st.push(i);
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}