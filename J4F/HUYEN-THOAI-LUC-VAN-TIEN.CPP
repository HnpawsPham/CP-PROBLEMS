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

int sol(){
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    deque<int> dq;
    for(int i = 0; i < n; i++){
        while(!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();

        dq.push_back(i);

        if(dq.front() <= i - k) 
            dq.pop_front();

        if(i >= k - 1)
            cout<<a[dq.front()]<<" ";
    }
    return 0;
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