#include <bits/stdc++.h>
using namespace std;
#define el "\n"

class NumArray {
public:
    int n, node = 1;
    vector<int> a;

    NumArray(vector<int>& t) {
        n = t.size();
        while(node < n) node *= 2;

        a.resize(n * 4);
        for(int i = 0; i < n; i++)
            a[i + node] = t[i];

        for(int i = node - 1; i > 0; i--)
            a[i] = a[2 * i] + a[2 * i + 1];
        return;
    }
    
    void update(int i, int val) {
        i += node;
        a[i] = val;

        while(i){
            i /= 2;
            a[i] = a[i * 2] + a[i * 2 + 1];
        }
        return;
    }
    
    int sumRange(int l, int r) {
        int res = 0;

        l += node;
        r += node;

        while(l <= r){
            if(l % 2){
                res += a[l];
                l++;
            }
            if(r % 2 == 0){
                res += a[r];
                r--;
            }
            l /= 2;
            r /= 2;
        }    
        return res;    
    }
};

int main(){
    return 0;
}