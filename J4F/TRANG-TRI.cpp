#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>

int n, m;
const int maxn = (int)1e6 + 5;
int a[maxn];
unordered_map<int, int> mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < n;i++) cin>>a[i];

    int i = 0, j = 0;
    int cnt = 0, len = n;
    bool found = 0;

    while(j < n){
        if(!mp[a[j]]) cnt++;
        mp[a[j]]++;
        j++;

        while(cnt == m){
            len = min(len, j - i);

            mp[a[i]]--;
            if(!mp[a[i]]) cnt--;

            found = 1;
            i++;
        }
    }
    cout<<(found ? len : 0);

    return 0;
}