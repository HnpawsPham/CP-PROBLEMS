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

    string a, b;
    cin>>a>>b;

    int n = a.size(), m = b.size();
    int s[m + 1];
    memset(s, -1, sizeof s);
    s[m] = n + 5;

    for(int i = n - 1, j = m - 1; j >= 0 && i >= 0; i--)
        if(a[i] == b[j]){
            s[j] = i;
            j--;
        }

    vi res;
    bool ok = 1;
    for(int j = 0, i = 0; i < n && j < m; i++){
        bool changable = ok && (s[j + 1] > i);

        if((a[i] == b[j]) || changable){
            if(a[i] != b[j]) ok = 0;
            res.push_back(i);
            j++;
        }
    }
    
    if(res.size() != m) res.clear();
    for(const int& x : res) cout<<x<<" ";
    return 0;
}

// vbcca 
// abc

// bacdc
// abc