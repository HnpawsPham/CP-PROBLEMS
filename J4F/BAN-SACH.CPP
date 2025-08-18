#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    pii a[n + 1];
    int in[n + 1] = {0};
    for(int i = 1; i <= n; i++) cin>>a[i].fi>>a[i].se;
    sort(a + 1, a + n + 1);

    stack<pii> st, tmp;
    for(int i = 1; i <= n; i++){
        while(!st.empty() && st.top().se >= a[i].fi - a[i].se){
            in[st.top().fi]++;
            st.pop();            
        }
        st.push({i, a[i].fi - a[i].se});
    }
    swap(st, tmp);

    for(int i = n; i > 0; i--){
        if(i < n && a[i] == a[i + 1]) continue;
        
        while(!st.empty() && st.top().se <= a[i].fi + a[i].se){
            in[st.top().fi]++;
            st.pop();            
        }
        st.push({i, a[i].fi + a[i].se});
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(!in[i]) cnt++;

    cout<<cnt;
    return 0;
}