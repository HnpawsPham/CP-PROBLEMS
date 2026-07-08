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

int n, m;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>m>>n;
  
    string res = "";
    int cnt[m + 1] = {0}, diff = 0;

    while(n--){
        int x;
        cin>>x;

        if(!cnt[x]) diff++;
        cnt[x]++;

        if(diff == m){
            for(int i = 1; i <= m; i++){
                cnt[i]--;
                if(!cnt[i]) diff--;
            }
            res.push_back('1');
        }
        else res.push_back('0');
    }
    cout<<res;
    return 0;
}