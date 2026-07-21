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
    int l[n], r[n];

    for(int i = 0; i < n; i++)
        if(i > 0 && s[i - 1] == s[i])
            l[i] = l[i - 1];
        else l[i] = i;

    for(int i = n - 1; i >= 0; i--)
        if(i + 1 < n && s[i + 1] == s[i])
            r[i] = r[i + 1];
        else r[i] = i;

    int res = 0;
    for (const char& x : s) 
        res += x == '1';

    int maxx = 0;
    for (int i = 1; i < n - 1; i++) 
        if (s[i] == '1' && l[i] == i){
            if (s[i - 1] == '0' && r[i] < n - 1 && s[r[i] + 1] == '0') {
                int lenl = l[i] - l[i - 1];
                int lenr = r[r[i] + 1] - r[i];
                maxx = max(maxx, lenl + lenr);
            }
            i = r[i];
        }
    cout<<res + maxx;
    return 0;
}