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

    string s;
    int n;
    cin>>s>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int maxx = a[0], sum = a[0], res = 0;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i - 1]){
            sum += a[i];
            maxx = max(maxx, a[i]);
        }
        else{
            res += sum - maxx;
            sum = a[i];
            maxx = a[i];
        }
    }
    cout<<res + sum - maxx;
    return 0;
}

// abaac
// 5
// 1 2 3 4 5

// abc 
// 3
// 1 2 3

// aabaa
// 5
// 1 2 3 4 1