#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, d;
const int maxn = 105;
string a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>d;
    for(int i = 0; i < n; i++) cin>>a[i];

    int maxx = 0;
    int len = 0;

    for(int i = 0; i < d; i++){
        int cnt = 0;

        for(int j = 0; j < n; j++)
            if(a[j][i] == 'o') cnt++;
        
        if(cnt == n) len++;
        else{
            maxx = max(maxx, len);
            len = 0;
        }
    }
    cout<<maxx;

    return 0;
}