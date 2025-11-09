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

int tc = 1;

void sol(){
    int n, t;
    cin>>n>>t;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int mid = (n + 1) / 2;
    // <          <=
    int cnt1 = 0, cnt2 = 0;
    for(int &x : a){
        if(x != -1 && x < t) cnt1++;
        if(x == -1 || x <= t) cnt2++;
        if(x == -1) x = t;
    }

    if(cnt2 >= mid && cnt1 < mid){
        cout<<"YES"<<el;
        for(int x : a) cout<<x<<" ";
    } 
    else cout<<"NO";
    return;
}

int main(){
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

// 5
// 3 2
// 0 -1 2
// 5 4
// 4 -1 6 0 -1
// 7 8
// 2 5 6 8 9 10 11
// 7 9
// 2 5 6 8 9 10 11
// 5 8
// 4 4 4 -1 -1