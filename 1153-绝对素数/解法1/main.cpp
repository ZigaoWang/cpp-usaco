// 1153：绝对素数
// 解法 1
#include <iostream>

using namespace std;

bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int reverse(int n)
{
    int reversed = 0;
    while (n != 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

int main() {
    int aPrime;
    for (int i = 10; i <= 99; i++) {
        if (isPrime(i) == 1) {
            aPrime = reverse(i);
            if (isPrime(aPrime) == 1) {
                cout << i << endl;
            }
        }
    }
    return 0;
}
