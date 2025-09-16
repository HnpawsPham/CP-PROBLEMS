#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int lcm(int a, int b){
    return a / __gcd(a, b) * b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    vi st;
    for(int x : a){
        int tmp = x;
        while(!st.empty() && __gcd(st.back(), tmp) > 1){
            tmp = lcm(st.back(), tmp);
            st.pop_back();
        }
        st.push_back(tmp);
    }
    for(int x : st) cout<<x<<" ";

    return 0;
}