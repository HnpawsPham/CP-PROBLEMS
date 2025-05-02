#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;

void sol1(int n){
    bool dp[n][n] = {{0}};

    string res;
    int maxlen = 0, st;

    for(int len = 1; len <= n; len++){
        for(int i = 0; i <= n - len; i++){
            int j = i + len - 1;

            if(len == 1 || (len == 2 && s[i] == s[j])) {
                dp[i][j] = 1;
            }
            else dp[i][j] = (dp[i + 1][j - 1] && (s[i] == s[j]));

            if(dp[i][j] && maxlen < len) {
                maxlen = len;
                st = i;
            }
        }
    }
    
    res = s.substr(st, maxlen);
    cout<<res;
    return;
}

void sol2(int n){
    int st, maxlen = 0, l, r;

    for(int i = 0; i < n; i++){
        if(n - i <= maxlen / 2) break;
        
        l = i; r = i;
        
        // odd length
        while(l >= 0 && r < n && s[l] == s[r]){
            l--;
            r++;
        }

        l++;
        r--;

        if(r - l + 1 > maxlen){
            maxlen = r - l + 1;
            st = l;
        }

        // even length
        l = i; r = i + 1;
        while(l >= 0 && r < n && s[l] == s[r]){
            l--;
            r++;
        }
        l++;
        r--;
        if(r - l + 1 > maxlen){
            maxlen = r - l + 1;
            st = l;
        }
    }

    string res = s.substr(st, maxlen);
    cout<<res;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    std::cout.tie(0);

    cin>>s;
    int n = s.length();

    if(n == 1) return cout<<s, 0;
    // sol1(n);
    sol2(n);
    
    return 0;
}