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

int n, k;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    if(k > n * n) return cout<<-1, 0;

    int a[n][n];
    memset(a, 0, sizeof a);
    for(int i = 0; i < n && k; i++){
        for(int j = i; j < n && k; j++){
            if(i == j){
                a[i][i] = 1;
                k--;
            }
            else if(k >= 2){
                a[i][j] = a[j][i] = 1;
                k -= 2;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout<<a[i][j]<<" ";
        cout<<el;
    }
    return 0;
}

// 3 5