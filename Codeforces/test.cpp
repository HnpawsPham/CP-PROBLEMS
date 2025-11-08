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

int main(){
    int n, m;
    cin>>n>>m;
    string a[n];
    int l[n], r[n];

    int bot = 0;
    for (int i=0; i < n; i++){
        cin>>a[i];
        r[i] = 0;
        l[i] = m - 1;
        
        for (int j = 0; j < m; j++)
            if (a[i][j]=='W'){
                r[i] = j;
                l[i] = min(l[i], j);
                bot = i;
            }
    }

    int res = 0, pos = 0;
    for (int i = 0; i <= bot; i++){
        if(i & 1){
            int tmp = l[i];

            if(i != bot) 
                tmp = min(tmp, l[i + 1]);
            if(tmp < pos){
                res += pos - tmp;
                pos = tmp;
            }
        }

        else{
            int tmp = r[i];

            if (i!= bot) 
                tmp = max(tmp, r[i + 1]);
            if (tmp > pos){
                res += tmp - pos;
                pos = tmp;
            }
        }
    }
    cout<<res + bot;
    return 0;
} 