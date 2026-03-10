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

    string s, t;
    cin>>t>>s;

    int cnt[10] = {0};
    for(const char& x : s)
        cnt[x - '0']++;

    int res = 0;
    bool ok = 1;
    while(ok && *max_element(cnt, cnt + 10) > 0){
        for(const char& x : t){
            if(x == '2' || x == '5'){
                if(cnt[2] < cnt[5]) swap(cnt[2], cnt[5]);
                if(!cnt[2]){
                    ok = 0;
                    break;
                }
                cnt[2]--;
            }
            else if(x == '6' || x == '9'){
                if(cnt[6] < cnt[9]) swap(cnt[6], cnt[9]);
                if(!cnt[6]){
                    ok = 0;
                    break;
                }
                cnt[6]--;
            }
            else{
                if(!cnt[x - '0']){
                    ok = 0;
                    break;
                }
                cnt[x - '0']--;
            }
        }
        if(ok) res++;
    }
    cout<<res;
    return 0;
}