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

    int n, cur = 0;
    ll cnt = 0;

    cin>>n;
    while(n--){
        char opt;
        int x;
        cin>>opt>>x;

        cnt += x / 100;
        x %= 100;
        if(!x) continue;

        if(opt == 'L'){
            if(cur > 0 && cur - x <= 0) cnt++;
            cur = (cur - x + 100) % 100;
        }
        else{
            if(cur + x >= 100) cnt++; 
            cur = (cur + x) % 100;
        }
    }
    cout<<cnt;
    return 0;
}