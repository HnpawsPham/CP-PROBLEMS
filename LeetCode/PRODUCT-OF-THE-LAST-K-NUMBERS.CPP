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

class ProductOfNumbers {
public:
    vi mul;

    ProductOfNumbers() {
        mul = {1};
    }
    
    void add(int x) {
        if(x == 0) mul = {1};
        else mul.push_back(mul.back() * x);
    }
    
    int getProduct(int k) {
        if(k >= mul.size()) return 0;
        return mul.back() / mul[mul.size() - k - 1]; 
    }
};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}