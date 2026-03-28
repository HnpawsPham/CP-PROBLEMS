#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define blank '\0'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname cout<<"", 0

int n;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin>>a[i][j];

    string s(n, blank);
    char cur = 'a';

    for(int i = 0; i < n; i++)
        if(s[i] == blank){
            if(cur > 'z') return cout<<"", 0;

            s[i] = cur;
            for(int j = i + 1; j < n; j++)
                if(a[i][j] > 0) s[j] = s[i];

            cur++;
        }

    for(int i = n - 1; i >= 0; i--)
        for(int j = n - 1; j >= 0; j--){
            if(s[i] != s[j]){
                if(a[i][j] > 0) return cout<<"", 0;
            }
            else{
                if(i == n - 1 || j == n - 1){
                    if(a[i][j] != 1) return cout<<"", 0;
                }
                else if(a[i][j] != a[i + 1][j + 1] + 1)
                    return cout<<"", 0;
            }
        }
    cout<<s;
    return 0;
}

// 4 
// 4 3 2 1
// 3 3 2 1
// 2 2 2 1
// 1 1 1 1

// 4 
// 4 0 2 0
// 0 3 0 1
// 2 0 2 0
// 0 1 0 1