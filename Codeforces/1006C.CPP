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

int n;
const int maxn = 2e5 + 5;
int a[maxn];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];

    int l = 0, r = n - 1;
    ll sum1 = 0, sum3 = 0, res = 0;
    while(l <= r){
        if(sum1 < sum3) sum1 += a[l++];
        else sum3 += a[r--];

        if(sum1 == sum3) res = sum1;
    }
    cout<<res;
    return 0;
}