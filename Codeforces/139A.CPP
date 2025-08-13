#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[7];
    for(int i = 0; i < 7; i++) cin>>a[i];

    int sum = 0, i = 0;
    while(sum < n){
        if(i == 7) i = 0;
        sum += a[i];
        i++;
    }
    cout<<i;
    return 0;
}