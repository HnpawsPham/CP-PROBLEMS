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

    string s;
    cin>>s;
    int n = s.length();

    int cnt[26] = {0};
    int res = 1;
    for(int i = 0; i < n; i++){
        memset(cnt, 0, sizeof cnt);

        for(int j = i; j < n; j++){
            cnt[s[j] - 'a']++;

            int cur = *max_element(cnt, cnt + 26);
            bool ok = 1;
            for(const int& x : cnt)
                if(x > 0 && x != cur){
                    ok = 0;
                    break;
                }
            if(ok) res = max(res, j - i + 1);
        }
    }
    cout<<res;
    return 0;
}