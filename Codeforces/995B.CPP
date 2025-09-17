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
    vi a(n * 2 + 1);
    int pos[n + 1] = {0};
    for(int i = 1; i <= n * 2; i++) {
        cin>>a[i];
        if(!pos[a[i]]) pos[a[i]] = i;
    }

    int cnt = 0;
    for(int i = 1; i < 2 * n; i += 2){
        if(a[i] == a[i + 1]) continue;
        int j = i + 2;

        while(j <= 2 * n && a[i] != a[j]) j++;
        cnt += j - (i + 1);

        int x = a[j];
        a.erase(a.begin() + j);
        a.insert(a.begin() + i + 1, x);
    }
    cout<<cnt;
    return 0;
}