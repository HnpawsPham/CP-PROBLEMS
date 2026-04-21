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

void sol(){
    int n;
    cin>>n;
    int a[n + 1];
    bool check[n + 1] = {0};
    for(int i = 1; i <= n; i++) cin>>a[i];

    int pos = 1, cnt = n - 1;
    while(pos < n && cnt){
        int minn = pos;
        for(int i = pos + 1; i <= n; i++)
            if(a[i] < a[minn]) minn = i;

        if(minn == pos) pos++;
        else{
            for(int j = minn; j > pos && cnt; j--){
                swap(a[j], a[j - 1]);
                cnt++;
            }
            pos = minn;
        }
    }

    for(int i = 1; i <= n; i++) 
        cout<<a[i]<<" ";
    return;
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
        sol();
        cout<<el;
    }
    return 0;
}