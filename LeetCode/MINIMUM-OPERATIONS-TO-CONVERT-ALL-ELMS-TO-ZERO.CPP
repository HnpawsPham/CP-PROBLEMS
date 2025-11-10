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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    stack<int> st;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            while(!st.empty()) st.pop();
            continue;
        }
        while(!st.empty() && st.top() > a[i]) st.pop();

        if(st.empty() || st.top() < a[i]){
            cnt++;
            st.push(a[i]);
        }
    }
    cout<<cnt;
    return 0;
}

// 7
// 1 2 3 3 1 2 3

// 6
// 1 2 1 2 1 2

// 4
// 3 1 2 1

// 2
// 0 2