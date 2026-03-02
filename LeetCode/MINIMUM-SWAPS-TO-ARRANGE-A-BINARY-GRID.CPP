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
    int a[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin>>a[i][j];

    int row[n];
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = n - 1; j >= 0; j--)
            if(a[i][j] == 0) cnt++;
            else break;

        row[i] = cnt;
    }
 
    int res = 0;
    for(int i = 0; i < n; i++){
        int j = i;
        while(j < n && row[j] < n - i - 1) j++;

        if(j == n) return cout<<-1, 0;

        while(j > i){
            swap(row[j], row[j - 1]);
            res++;
            j--;
        }
    }
    cout<<res;
    return 0;
}

// 3
// 0 0 1
// 1 1 0
// 1 0 0

// 4
// 0 1 1 0
// 0 1 1 0
// 0 1 1 0
// 0 1 1 0

// 3
// 1 0 0
// 1 1 0
// 1 1 1 