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

bool check[105];

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

    int sum = n;
    for(int i = 0; i < n; i++){
        memset(check, 0, sizeof check);
        int cnt = 1;
        check[a[i]] = 1;

        for(int j = i + 1; j < n; j++){
            if(!check[a[j]]){
                check[a[j]] = 1;
                cnt++;
            }
            sum += cnt * cnt;
        }
    }
    cout<<sum;
    return 0;
}