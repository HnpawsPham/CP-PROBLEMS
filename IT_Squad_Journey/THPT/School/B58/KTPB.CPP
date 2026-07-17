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
#define taskname "KTPB"

string s;
int n, k;
bool check[26] = {0};

// f(s) max 26
int getfs(){
    for(const char& x : s)
        check[x - 'a'] = 1;
    return accumulate(check, check + 26, 0);
}

namespace sub1{
    void sol(){
        for(int i = 1; i <= k; i++){
            ll res = 0;
            for(int l = 0; l < n; l++)
                for(int r = l; r < n; r++){
                    memset(check, 0, sizeof check);

                    for(int x = l; x <= r; x++)
                        check[s[x] - 'a'] = 1;

                    if(accumulate(check, check + 26, 0) == i)
                        res++;
                }
            cout<<res<<el;
        }
        return;
    }
}

namespace sub2{
    void sol(){
        ll prev = 0;
        for(int i = 1; i <= k; i++){
            ll res = 0;
            int diff = 0, l = 0;
            int cnt[26] = {0};

            for(int r = 0; r < n; r++){
                cnt[s[r] - 'a']++;
                if(cnt[s[r] - 'a'] == 1) diff++;

                while(l <= r && diff > i){
                    cnt[s[l] - 'a']--;
                    if(cnt[s[l] - 'a'] == 0) 
                        diff--;
                    l++;
                }
                res += r - l + 1;
            }
            cout<<res - prev<<el;
            prev = res;
        }
        return;
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    n = s.length();
    k = getfs();

    if(n <= 105) sub1::sol();
    else sub2::sol();
    return 0;
}