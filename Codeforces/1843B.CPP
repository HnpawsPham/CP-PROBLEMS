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

void sol(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll sum = 0;
    int cnt = 0;
    bool found = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < 0) found = 1;
        else if(a[i] > 0 && found){
            cnt++;
            found = 0;
        }
        sum += abs(a[i]);
    }
    cnt += found;

    cout<<sum<<" "<<cnt;
    return;
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