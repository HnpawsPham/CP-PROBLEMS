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

    int n;;
    cin>>n;
    string a[n];
    int w[26];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < 26; i++) cin>>w[i];

    string res = "";
    for(const string& s : a){
        int sum = 0;
        for(const char& x : s)
            sum += w[x - 'a'];
        res.push_back(char(25 - (sum % 26) + 'a'));
    }
    cout<<res;
    return 0;
}

// 3
// abcd def xyz 
// 5 3 12 14 1 2 3 2 10 6 6 9 7 8 7 10 8 9 6 9 9 8 3 7 7 2