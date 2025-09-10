#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin>>tc;
    while(tc--){
        string t;
        cin>>t;
        int m = t.length();

        int l = 0, sr = m - 1;
        while(l < sr && t[l] == t[sr]){
            l++;
            sr--;
        }

        if(l >= sr){
            cout<<t<<el;
            continue;
        }
        
        string s;
        for(int i = l; i <= sr; i++){
            s.push_back('|');
            s.push_back(t[i]);
        }
        s.push_back('|');

        int n = s.length();
        vector<int> p(n,0);

        int r = 0, c = 0, len = 0, cen = 0;
        for(int i = 1; i < n; i++){
            if(i < r)
                p[i] = min(p[2 * c - i], r - i);
            
            while(i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]])
                p[i]++;

            if(i + p[i] > r){
                r = i + p[i];
                c = i;
            }

            if(p[i] > len){
                len = p[i];
                cen = i;
            }
        }

        int bestpre = 0, bestsuf = 0;
        for(int i = 0; i < n; i++){
            if(p[i] == i + 1) bestpre = max(bestpre, p[i] - 1);
            if(p[i] == n - i) bestsuf = max(bestsuf, p[i] - 1);
        }

        string pre = t.substr(0, l);
        string suf = t.substr(sr + 1);
        string mid;

        if(bestpre >= bestsuf) mid = t.substr(l, bestpre);
        else mid = t.substr(sr - bestsuf + 1, bestsuf);

        cout<<pre<<mid<<suf<<el;
    }
    return 0;
}
