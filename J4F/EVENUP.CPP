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
    for(int i = 0; i < n; i++){
        if(!st.empty() && (st.top() + a[i]) % 2 == 0)
            st.pop();
        else st.push(a[i]);
    }
    cout<<st.size();
    return 0;
}

// 10
// 1 2 3 4 5 6 7 8 9 10

// 10
// 1 3 3 4 2 4 1 3 7 1