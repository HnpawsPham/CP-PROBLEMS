#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

class Bank {
public:
    int n;
    vector<long long> a;
    Bank(vector<long long>& balance) {
        a = balance;
        n = a.size();
    }

    bool check(int i){
        if(i < 0 || i >= n) return 0;
        return 1;
    }
    
    bool transfer(int acc1, int acc2, long long money) {
        acc1--; acc2--;
        if(!check(acc1) || !check(acc2) || a[acc1] < money) return 0;

        a[acc2] += money;
        a[acc1] -= money;
        return 1;
    }
    
    bool deposit(int acc, long long money) {
        if(!check(--acc)) return 0;
        a[acc] += money;
        return 1;
    }
    
    bool withdraw(int acc, long long money) {
        if(!check(--acc)) return 0;
        if(a[acc] < money) return 0;

        a[acc] -= money;
        return 1;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}