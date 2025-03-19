#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int t, n;
vector<int> a, b;

void inp(int n, vector<int>& a){
    a.clear();
    while(n--){
        int x;
        cin>>x;
        a.push_back(x);
    }
    return;
}

int sol(){
    int sum1 = a[n - 1];
    int sum2 = 0;

    for(int i = 0; i < n - 1; i++){
        if(a[i] > b[i + 1]) {
            sum1 += a[i];
            sum2 += b[i + 1];
        }
    }
    return sum1 - sum2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        inp(n, a);
        inp(n, b);
        cout<<sol()<<el;
    }

    return 0;
}