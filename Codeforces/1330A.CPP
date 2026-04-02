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

int sol(){
    int n, x;
    cin>>n>>x;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);

    int cur = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == cur) continue;
        else{
            if(x >= a[i] - cur - 1){
                x -= a[i] - cur - 1;
                cur = a[i];
            }
            else{
                cur += x;
                x = 0;
                break;
            }
        }
    }
    cur += x;
    return cur;
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
        cout<<sol()<<el;
    }
    return 0;
}

// 1
// 6 2
// 3 1 1 5 7 10