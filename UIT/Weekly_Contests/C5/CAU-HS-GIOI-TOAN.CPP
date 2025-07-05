#include <iostream>
#include <iomanip>
using namespace std;

const float PI = 3.141592654f;
const float EPS = 0.0001f;

float ssin(float rad) {
    float m = rad;
    float sum = rad;
    int k = 1;

    while (1) {
        float tmp = -m * rad * rad / ((2 * k) * (2 * k + 1));
        if (tmp > -EPS && tmp < EPS) break;
        sum += tmp;
        m = tmp;
        k++;
    }
    return sum;
}

int main() {
    float x;
    cin >> x;

    float rad = x * PI / 180.0f;
    cout << fixed << setprecision(6) << ssin(rad);
    return 0;
}
