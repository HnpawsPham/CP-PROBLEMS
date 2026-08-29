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
#define taskname "CAU1"

void getdiv(int x, vi& a){
    for(int i = 1; i * i <= x; i++){
        if(x % i) continue;

        a.push_back(i);
        if(i != x / i)
            a.push_back(x / i);
    }
    sort(a.begin(), a.end());
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin>>x>>y;
    vi divx, divy;
    getdiv(x, divx);
    getdiv(y, divy);

    int n = divx.size(), m = divy.size();
    int cnt = 0;
    for(int i = 0, j = 0; i < n && j < m;){
        if(divx[i] == divy[j]){
            cnt++;
            i++;
            j++;
        }
        else if(divx[i] < divy[j]) i++;
        else j++;
    }
    cout<<cnt;
    return 0;
}