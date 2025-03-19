#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int n, res = 0;
const int maxn = (int)1e5 + 5;
int a[maxn];

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

void getMax(){
    int maxx = 0, posi, posj;
    for(int i=0;i<n;i++){
        for(int j = 0; j < n;j++){
            if(i == j) continue;
            int t = gcd(a[i], a[j]);
            if(t > maxx){
                maxx = t;
                posi = i;
                posj = j;
            }
        }
    }
    a[posi] = a[posj] = -1;
    res += maxx;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n;i++) cin>>a[i];
    getMax(); getMax();
    cout<<res<<el;
    return 0;
}