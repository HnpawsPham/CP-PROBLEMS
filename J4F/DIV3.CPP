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

    ll n;
    cin>>n;
    int mod[3] = {0};

    int sum = 0, cnt = 0;
    while(n > 0){
        sum += n % 10;
        cnt++;
        mod[(n % 10) % 3]++;
        n /= 10;
    }
    
    if(sum % 3 == 0) return cout<<0, 0;
    else if(sum % 3 == 1){
        if(mod[1] > 0) cout<<1;
        else if(mod[2] > 1) cout<<2;
        else cout<<cnt;
    }
    else{
        if(mod[2] > 0) cout<<1;
        else if(mod[1] > 1) cout<<2;
        else cout<<cnt;
    }
    return 0;
}