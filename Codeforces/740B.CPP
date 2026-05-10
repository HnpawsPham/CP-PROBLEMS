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

    int n, m;
    cin>>n>>m;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int p[n + 1] = {0};
    for(int i = 1; i <= n; i++) 
        p[i] = p[i - 1] + a[i - 1];

    int sum = 0;
    while(m--){
        int l, r;
        cin>>l>>r;
        if(p[r] - p[l - 1] > 0)
            sum += p[r] - p[l - 1];
    }
    cout<<sum;
    return 0;
}