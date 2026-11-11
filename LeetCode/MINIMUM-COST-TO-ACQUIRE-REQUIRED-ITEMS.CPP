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
    int cost1, cost2, cost3, need1, need2;
    cin>>cost1>>cost2>>cost3>>need1>>need2;

    if(cost3 >= cost1 + cost2)
        return cout<<1LL * cost1 * need1 + 1LL * cost2 * need2, 0;

    int need3 = min(need1, need2);
    cout<<1LL * need3 * cost3 + 1LL * (need1 - need3) * min(cost3, cost1) + 1LL * (need2 - need3) * min(cost2, cost3);
    return 0;
}