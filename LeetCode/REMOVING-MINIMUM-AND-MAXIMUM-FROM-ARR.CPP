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

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int pos1 = 0, pos2 = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > a[pos2]) 
            pos2 = i;
        if(a[i] < a[pos1])
            pos1 = i;
    }

    if(pos1 > pos2) swap(pos1, pos2);

    if(pos1 == pos2)
        return cout<<min(pos1 + 1, n - pos1), 0;

    int st = 0, en = n, res;
    if(pos1 - st + 1 < en - pos1){
        res = st = pos1 - st + 1;
        res += min(pos2 - st + 1, en - pos2);
    }
    else{
        res = en = en - pos1;
        res += min(pos2 - st + 1, en - pos2);
    }
    cout<<res;
    return 0;
}

// 8
// 2 10 7 5 4 1 8 6