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
const ll oo = 1e18;
ll a, b;

void sol(){
    cin>>a>>b;

    if(b == 1){
        cout<<"NO";
        return;
    }

    cout<<"YES"<<el;
    cout<<a<<" "<<a * (b - 1)<<" "<<a * b;
}

// bool check(ll x, ll y, ll z){
//     if(z % (a * b) == 0)
//         return 1;
//     return 0;
// }

// void sol(){
//     cin>>a>>b;
//     if(b == 1 || a == b){
//         cout<<"NO";
//         return;
//     }

//     if(a == 1){
//         cout<<"YES"<<el;
//         cout<<b - 1<<" "<<b + 1<<" "<<2 * b;
//         return;
//     }

//     vll div;
//     ll x = a;
//     while(x <= oo){
//         div.push_back(x);
//         x *= a;
//     }
//     int sz = div.size();

//     for(const ll& i : div)
//         for(const ll& j : div){
//             if(i == j) continue;

//             if(check(i, j, i + j)){
//                 cout<<i<<" "<<j<<" "<<i + j;
//                 return;
//             }
//             else if(check(i, j + i, j)){
//                 cout<<i<<" "<<j + i<<" "<<j;
//                 return;
//             }
//         }
//     return;
// }

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