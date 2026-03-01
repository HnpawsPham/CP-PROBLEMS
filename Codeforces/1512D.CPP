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
    n += 2;

    int a[n];
    ll sum = 0;

    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum += a[i];
    }
    sort(a, a + n);

    for(int i = 0; i < n - 1; i++){
        if(sum - a[i] - a[n - 1] != a[n - 1])
            continue;

        for(int j = 0; j < i; j++) cout<<a[j]<<" ";
        for(int j = i + 1; j < n - 1; j++) cout<<a[j]<<" ";
        return;
    }

    if(sum - a[n - 1] - a[n - 2] == a[n - 2]){
        for(int i = 0; i < n - 2; i++) 
            cout<<a[i]<<" ";
        return;
    }

    cout<<-1;
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

// 1
// 3
// 1 1 1 1 2

// 1
// 4
// 2 2 4 1 9 100