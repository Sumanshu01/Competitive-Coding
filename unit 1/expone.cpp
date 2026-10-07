#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            ++digits[i];
            return digits;
        }
        digits[i] = 0;
    }

    digits.insert(digits.begin(), 1);
    return digits;
}

int main() {
    int n;
    cin >> n;

    vector<int> digits(n);
    for (int &digit : digits)
        cin >> digit;

    vector<int> result = plusOne(digits);

    for (int digit : result)
        cout << digit << " ";

    return 0;
}