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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    
    const int oo = 1e4 + 3;
    int sum = 0, mino = oo, maxo = -oo;
    for(int x : a){
        if(x > 0){
            sum += x;
            if(x % 2) mino = min(mino, x);
        }
        else if(x % 2) maxo = max(maxo, x);
    }
    if(sum % 2 == 0) sum -= min(mino, -maxo);
    cout<<sum;
    return 0;
}