#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;
const ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int cntodd = 0, cnteven = 0;
    ll sumodd = 0, sumeven = 0;

    while(n--){
        int x;
        cin>>x;

        if(x % 2 == 0) {
            sumeven = (sumeven + x) % MOD;
            cnteven++;
        }
        else{
            sumodd = (sumodd + x) % MOD;
            cntodd++;
        }
    }
    ll res = ((cntodd % MOD) * (sumeven % MOD) % MOD 
    + (cnteven % MOD) * (sumodd % MOD) % MOD ) % MOD;
    cout<<res;
    return 0;
}