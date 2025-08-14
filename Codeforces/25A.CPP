#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnteven = 0, cntodd = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 2) cntodd++;
        else cnteven++;
    }

    int r = (cnteven > cntodd ? 1 : 0);
    for(int i = 0; i < n; i++)
        if(a[i] % 2 == r) return cout<<i + 1, 0;
    return 0;
}