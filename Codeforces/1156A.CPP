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
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt = 0;
    for(int i = 1; i < n; i++){
        if(a[i] + a[i - 1] == 5 || a[i] == a[i - 1]) 
            return cout<<"Infinite", 0;
        else if(a[i] + a[i - 1] == 4) 
            cnt += 4;
        else if(a[i] + a[i - 1] == 3)
            cnt += 3;

        if(i > 1 && a[i] == 2 && a[i - 1] == 1 && a[i - 2] == 3)
            cnt--;
    }
    cout<<"Finite"<<el<<cnt;
    return 0;
}