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

int n;

void rotate90(vector<vi>& a){
    vector<vi> res = a;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            res[i][j] = a[j][n - i - 1];
    a = res;
    return;
}

void rotateC90(vector<vi>& a){
    vector<vi> res = a;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            res[i][j] = a[n - j - 1][i];
    a = res;
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

    cin>>n;
    vector<vi> a(n, vi(n)), target = a;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin>>a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin>>target[i][j];

    for(int i = 0; i < 3; i++){
        rotate90(a);
        if(a == target) return cout<<1, 0;
    }
    
    for(int i = 0; i < 3; i++){
        rotateC90(a);
        if(a == target) return cout<<1, 0;
    }

    cout<<0;
    return 0;
}

// 2
// 0 1 
// 1 0
// 1 0
// 0 1

// 3
// 0 0 0
// 0 1 0
// 1 1 1

// 1 1 1
// 0 1 0
// 0 0 0