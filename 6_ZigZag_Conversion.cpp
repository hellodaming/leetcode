//
// Created by will on 16-11-2.

// 超时了！！！！！  Time Limit Exceeded
//
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {


        if(numRows>= s.size() || numRows==0){
            return s;
        }

        auto begin = s.cbegin();
        auto end = s.cend();
        string returnValue;
        for(int n = 0; n < numRows; ++n ) {
            for (auto beginPoint = begin; beginPoint < end; beginPoint+= (2*numRows-2)) { //(numRows-1)*2 = 2*numRows-2

                int interval = numRows-1 -n;

                returnValue+= (*beginPoint);
                if(interval>0 && interval<numRows-1 && beginPoint + 2*numRows-2-2*n<end){
                    returnValue+= ( *(beginPoint + 2*numRows-2-2*n) );
                }

            }
            begin++; //下移一个
        }

        return returnValue;
    }
};

int main() {

    Solution s;
    string str1 = "PAYPALISHIRING";
    int numRows = 4;
    cout << str1 << " " << s.convert(str1, numRows) << endl;
    //s.reverse(a2);

    //cout<<numeric_limits<int>::max()<<endl;



};
