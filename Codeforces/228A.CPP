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

    int a[4];
    for(int i = 0; i < 4; i++) cin>>a[i];
    sort(a, a + 4);

    int cnt = 0;
    for(int i = 1; i < 4; i++)
        if(a[i] == a[i - 1]) cnt++;
    cout<<cnt;
    return 0;
}