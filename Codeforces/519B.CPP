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

    int n, x;
    cin>>n;
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for(int i = 0; i < n; i++){
        cin>>x;
        sum1 += x;
    }

    for(int i = 1; i < n; i++){
        cin>>x;
        sum2 += x;
    }
    
    for(int i =2 ; i < n; i++){
        cin>>x;
        sum3 += x;
    }
    cout<<sum1 - sum2<<el<<sum2 - sum3;
    return 0;
}