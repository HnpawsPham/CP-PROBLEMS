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
        
        for(int i = 0; i < cnt1; i++){
            cnt0 += (num & 1);
            num >>= 1;
        }

        if(cnt0 == 0) res.push_back(x >> 1);
        else{
            for(int i = 1; i < x; i++)
                if((i | (i + 1)) == x){
                    res.push_back(i);
                    break;
                }
        }
    }

    for(int x : res) cout<<x<<" ";
    return 0;
}

// 4
// 2 3 5 7

// 3
// 11 13 31