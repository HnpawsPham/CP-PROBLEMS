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

    int a, b;
    cin>>a>>b;

    if(a < 2 && b < 2) return cout<<0, 0;
    if(max(a, b) == 2) return cout<<1, 0;
    
    int t = 0;
    if(b < a) swap(a, b);
    while(a >= 2 || b >= 2){
        a++;
        b -= 2;
        t++;
        if(b <= 2) swap(a, b);
        if(b <= 2) return cout<<++t, 0;
    }
    cout<<t;
    return 0;
}

// 1 1
// 1 2