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

const int maxn = 13;
int q;
vll gud;

int ppow(int a, int b){
    if(b == 0) return 1;
    int half = ppow(a, b / 2);
    if(b & 1) return half * half * a;
    return half * half;
}

void sol(int i, ll x){
    if(i == maxn){
        gud.push_back(x);
        return;
    }

    sol(i + 1, x + ppow(3, i));
    sol(i + 1, x);
    return;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    sol(0, 0);
    sort(gud.begin(), gud.end());
    
    while(q--){
        int n;
        cin>>n;
        cout<<*lower_bound(gud.begin(), gud.end(), n)<<el;
    }
    return 0;
}