#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;
const int maxn = 1e5 + 5;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];

    vi res(n, -1);
    unordered_map<int, int> mp;
    set<int> s;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            s.insert(i);
            res[i] = 1;
        } 
        else{
            if (mp.count(a[i])) {
                auto it = s.upper_bound(mp[a[i]]);
                if (it == s.end()) return {};

                res[*it] = a[i];
                s.erase(it);
            }
            mp[a[i]] = i;
        }
    }
    
    for(int i = 0; i < n; i++) 
        cout<<res[i]<<" ";
    return 0;
}

// 4
// 1 2 3 4

// 6
// 1 2 0 0 2 1

// 5
// 1 2 0 1 2