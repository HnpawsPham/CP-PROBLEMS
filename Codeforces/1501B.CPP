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

    int p[n + 1] = {0};
    for(int i = 0; i < n; i++){
        p[i + 1]--;
        p[max(0, i - a[i] + 1)]++;
    }

    for(int i = 1; i <= n; i++)
        p[i] += p[i - 1];

    for(int i = 0; i < n; i++)
        cout<<(p[i] > 0)<<" ";
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