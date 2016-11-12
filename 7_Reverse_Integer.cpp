//
// Created by will on 16-11-2.
//
#include <iostream>
#include <cmath>

using namespace std;


int reversePositiveNumber(int x) {
    int value = 0;
    for (int n = 9; n != 0; --n) {  //numeric_limits<int>::max() = 2147483647

        int pow1 = pow(10, n);
        if (x >= pow(10, n)) {//找出开始的最高位
            int startLocal = n;
            for (; n != 0; --n) {
                int temp = x / pow(10, n);
                value += temp * pow(10, startLocal - n);
                x -= temp * pow(10, n);
            }
            value += x * pow(10, startLocal);
            x = 0;
            break;
        }
    }

    return value + x;
}

class Solution {
public:
    int reverse(int x) {
        int returnValue;
        if (x < 0) {
            returnValue = -reversePositiveNumber(abs(x));
            if (returnValue > 0 || returnValue == -2147483648) {
                return 0;
            } else {
                return returnValue;
            }

        } else {
            returnValue = reversePositiveNumber(x);
            if (returnValue < 0) {
                return 0;
            } else {
                return returnValue;
            }
        }

    }
};


int main() {

    Solution s;
    int a1 = 1534236469;
    int a2 = -2147483647;
    cout << a1 << " " << s.reverse(a1) << endl;
     cout<<a2 <<" "<< s.reverse(a2);
    //s.reverse(a2);

    //cout<<numeric_limits<int>::max()<<endl;



};
