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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin>>k;
    int minn = 2000;
    for(int i = 1; i < 10; i++)
        for(int j = 0; j < 10; j++){
            if(j == i) continue;
            for(int z = 0; z < 10; z++){
                if(z == i || z == j) continue;
                int a = i * 100 + j * 10 + z;

                for(int ii = 1; ii < 10; ii++){
                    if(ii == i || ii == j || ii == z) continue;
                    for(int jj = 0; jj < 10; jj++){
                        if(jj == i || jj == j || jj == z || jj == ii) continue;
                        for(int zz = 0; zz < 10; zz++){
                            if(zz == i || zz == j || zz == z || zz == jj || zz == ii) 
                                continue;
                            if(ii == z * k)
                                minn = min(minn, a + ii * 100 + jj * 10 + zz);
                        }
                    }
                }
            }
        }
    cout<<minn;
    return 0;
}