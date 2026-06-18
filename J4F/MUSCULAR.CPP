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

    int n, m;
    cin>>n>>m;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);

    unordered_set<int> s;
    for(int i = 0; i < n - 2 && a[i] <= m; i++){
        s.insert(a[i]);

        for(int j = i + 1; j < n - 1 && a[j] <= m; j++){
            if(a[i] + a[j] > m) break;
            s.insert(a[j]);
            s.insert(a[i] + a[j]);

            for(int z = j + 1; z < n && a[z] <= m; z++){
                if(a[i] + a[j] + a[z] <= m) s.insert(a[i] + a[j] + a[z]);
                if(a[j] + a[z] <= m) s.insert(a[j] + a[z]);
                if(a[i] + a[z] <= m) s.insert(a[i] + a[z]);
                s.insert(a[z]);
            }
        }
    }
    cout<<s.size();
    return 0;
}