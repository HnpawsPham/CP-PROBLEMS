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
    for(int i= 0; i < n; i++) cin>>a[i];

    vector<int> res(n, 0);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--){
        int maxx = 0;
        while(!st.empty() && st.top() > maxx){
            maxx = st.top();
            res[i]++;

            if(maxx >= a[i]) break;
            st.pop();
        }

        st.push(a[i]);
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 6
// 10 6 8 5 11 9

// 5
// 5 1 2 3 10