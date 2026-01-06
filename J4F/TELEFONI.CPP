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

int n, d;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>d;
    bool a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt = 0, prev = 0;
    for(int i = 1; i < n; i++){
        if(!a[i] && i - prev >= d){
            a[i] = 1;
            cnt++;
        }
        if(a[i]) prev = i;
    }
    cout<<cnt;
    return 0;
}