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

    int res = 0, l = 0, mid = -1, r = -1;
    for(int i = 1; i < n;){
        if(a[i - 1] <= a[i]) mid = i++;
        else{
            while(i < n && a[i - 1] >= a[i]) i++;
            res = max(res, i - l + 1);
            l = i;
        } 
    }
    cout<<res;
    return 0;
}