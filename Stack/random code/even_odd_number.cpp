#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int even = 0, odd = 0;
    int evenplace = 1, oddplace = 1;

    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 == 0) {
            even = digit * evenplace + even;
            evenplace *= 10;
        } else {
            odd = digit * oddplace + odd;
            oddplace *= 10;
        }
        n = n / 10;
    }
    cout<<"Even "<<even<<" Odd "<<odd;
    return 0;
}
