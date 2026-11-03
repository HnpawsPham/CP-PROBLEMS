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

const int maxn = 3e5 + 5;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;
    int pos[maxn];
    int st = maxn, en = maxn;
    while(q--){
        char opt; 
        int i;
        cin>>opt>>i;
        
        if(opt == 'L')
            pos[i] = --st; 
        else if(opt == 'R')
            pos[i] = en++;
        else cout<<min(pos[i] - st, en - pos[i] - 1)<<el;
    }
    return 0;
}