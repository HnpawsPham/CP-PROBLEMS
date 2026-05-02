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

int mp[10] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};

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
    int cnt = 0;
    unordered_set<int> s;

    for(int i = 1; i <= n; i++){
        int res = 0, x = i, p = 1;
        while(x > 0){
            if(mp[x % 10] != -1) 
                res += mp[x % 10] * p;
            else{
                res = i;
                break;
            }
            p *= 10;
            x /= 10;
        }

        // cout<<i<<" "<<res<<el;
        if(res != i) s.insert(res);
    }
    cout<<s.size();
    return 0;
}