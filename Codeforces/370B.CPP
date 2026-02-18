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

int n, m, x;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int cnt[101] = {0}, minsz[101], cntminsz[101] = {0};
    vi a[n];
    for(int i = 1; i <= 100; i++)
        minsz[i] = 200;
 
    for(int i = 0; i < n; i++){
        cin>>m;
        while(m--){
            cin>>x;
            a[i].push_back(x);
            cnt[x]++;
            
        }
        for(int x : a[i])
            minsz[x] = min(minsz[x], (int)a[i].size());
    }
 
    for(int i = 0; i < n; i++)
        for(int x : a[i])
            if((int)a[i].size() == minsz[x])
                cntminsz[x]++;
 
    bool res[n] = {0};
    for(int i = 0; i < n; i++){
        bool ok = 1;
        for(int x : a[i])
            if(cnt[x] > 1 && minsz[x] == 1 && 
                ((int)a[i].size() != minsz[x] || cntminsz[x] > 1)){
                ok = 0;
                break;
            }
        res[i] = ok;
    }

    for(int i = 0; i < n; i++)
        sort(a[i].begin(), a[i].end());

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!res[j] || i == j) continue;
            int cnt = 0;
            for(int x : a[i]){
                if(binary_search(a[j].begin(), a[j].end(), x)) cnt++;
                if(cnt == a[i].size()){
                    res[j] = 0;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
        if(res[i]) cout<<"YES"<<el;
        else cout<<"NO"<<el;
    return 0;
}