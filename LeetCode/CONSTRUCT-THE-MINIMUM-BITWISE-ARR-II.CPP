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
// #define taskname "tmp"

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        // freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    
    vector<int> res;
    for(int x : a){
        if(x == 2){
            res.push_back(-1);
            continue;
        }
        
        int cnt1 = __builtin_popcount(x);
        string s = bitset<30>(x).to_string();
        int cnt0 = 0, num = x;
        while(num){
            cnt0 += !(num & 1);
            num >>= 1;
        }

        if(cnt0 == 0) res.push_back(x >> 1);
        else{
            string s = bitset<30>(x).to_string();
            for(int i = 29; i > 0; i--)
                if(s[i] == '0'){
                    s[i + 1] = '0';
                    break;
                }
            res.push_back(bitset<30>(s).to_ulong());
        }
    }

    for(int x : res) cout<<x<<" ";
    return 0;
}

// 4
// 2 3 5 7

// 3
// 11 13 31