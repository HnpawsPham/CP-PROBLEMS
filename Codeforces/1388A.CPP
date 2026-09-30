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
//#define taskname ""

int tc = 1;
int prime[6] = {2, 3, 5, 7, 11, 13};
vi a;

void gen(){
    for(int i = 0; i < 6; i++)
        for(int j = i + 1; j < 6; j++)
            a.push_back(prime[i] * prime[j]);
    sort(a.begin(), a.end());
}

void sol(){
    int n;
    cin>>n;
    if(n <= a[0] + a[1] + a[2]){
        cout<<"NO";
        return;
    }
    
    for(int mask = 0; mask < (1 << 15); mask++){
        if(__builtin_popcount(mask) != 3) continue;
        
        int x = n;
        bool ok = 1;
        vi tmp;
        for(int i = 0; i < 15; i++)
            if((mask >> i) & 1){
                x -= a[i];
                if(x < 0){
                    ok = 0;
                    break;
                }
                tmp.push_back(a[i]);
            }
        
        for(const int& num: tmp)
            if(x == num){
                ok = 0;
                break;
            }

        if(ok){
            cout<<"YES"<<el;
            for(const int& num : tmp)
                cout<<num<<" ";
            cout<<x;
            return;
        }
    }
    cout<<"NO";
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    gen();

    while(tc--){
        sol();
        cout<<el;
    }
    return 0;
}