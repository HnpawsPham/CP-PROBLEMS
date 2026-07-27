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

    const int oo = 1005;
    int max1 = -oo, max2 = -oo;
    for(const int& x : a){
        if(x > max1){
            max2 = max1;
            max1 = x;
        }
        else if(x > max2)
            max2 = x;
    }
    cout<<(max1 - 1) * (max2 - 1);
    return 0;
}