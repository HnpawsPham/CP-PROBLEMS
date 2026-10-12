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

int tc = 1;
int n, k;
const int maxn = 1e6 + 5;
int a[maxn];

int sol(){
    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>a[i];

    if(k % 2 == 0) return 0;
    
    vi odd, even;

    for(int i = 0; i < n; i++){
        if(a[i] % 2) odd.push_back(a[i]);
        else even.push_back(a[i]);
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    for(int i = 0; i < n; i++){
        if(a[i] % 2){
            if(binary_search(even.begin(), even.end(), k - a[i]))
                return 1;
        }
        else{
            if(binary_search(odd.begin(), odd.end(), k - a[i]))
                return 1;
        }
    }
    return 0;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol();
    }
    return 0;
}