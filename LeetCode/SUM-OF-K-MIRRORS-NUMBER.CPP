#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int k, n;
const ll oo = 1e6;
vector<ll> a;

void gen(){
    for(int i = 1; i <= oo; i++){
        int tmp = i;
        ll x = i;

        while(tmp > 0){
            x = x * 10 + (tmp % 10);
            tmp /= 10;
        }
        a.push_back(x);
        
        tmp = i / 10;
        x = i;
        while(tmp > 0){
            x = x * 10 + (tmp % 10);
            tmp /= 10;
        }
        a.push_back(x);
    }
    return;
}

bool convert(int x){
    string res = "";

    while(x > 0){
        res += ((x % k) + '0');
        x /= k;
    }
    string rs = res;
    reverse(rs.begin(), rs.end());

    return (res == rs);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>k>>n;
    ll sum = 0;
    gen();

    // for(int i = 100; i <= 200; i++) cout<<a[i]<<" ";
    int i = 0;
    while(n){
        if(convert(a[i])){
            n--;
            sum += a[i];
        }
        i++;
    }
    cout<<sum;
    return 0;
}