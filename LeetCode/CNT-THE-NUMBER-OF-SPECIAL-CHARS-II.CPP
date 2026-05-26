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
    vector<int> lastl(26, -1), firstu(26, n);

    for(int i = 0; i < n; i++){
        if('a' <= s[i] && s[i] <= 'z')
            lastl[s[i] - 'a'] = i;
        else{
            if(firstu[s[i] - 'A'] == n)
                firstu[s[i] - 'A'] = i;
        }
    }

    int cnt = 0;
    for(int i = 0; i < 26; i++)
        if(lastl[i] != -1 && firstu[i] != n && lastl[i] < firstu[i]) cnt++;
    cout<<cnt;
    return 0;
}