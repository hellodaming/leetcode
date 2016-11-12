//
// Created by will on 16-11-2.
//You are here!
//Your runtime beats 41.49% of cpp submissions.
//
#include <iostream>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {


        if(numRows>= s.length() || numRows==1){
            return s;
        }
        auto begin = s.cbegin();

        string returnValue;

        for(int n = 0; n < numRows; ++n ) {

            if(n == 0 || n == numRows-1){

                for (auto beginPoint = begin; beginPoint < s.cend(); beginPoint += (2 * numRows - 2)){
                    returnValue += (*beginPoint);
                }
            }
            else {
                for (auto beginPoint = begin; beginPoint < s.cend(); beginPoint += (2 * numRows - 2)) { //(numRows-1)*2 = 2*numRows-2
                    int interval = numRows-1 -n;
                    returnValue+= (*beginPoint);
                    /*
                    if(interval>0 && interval<numRows-1 && (beginPoint + 2*numRows-2-2*n)< s.cend()){
                        returnValue+= ( *(beginPoint + 2*numRows-2-2*n) );
                    }*/
                    if(interval>0 && interval<numRows-1 && (beginPoint + 2*interval)< s.cend()){
                        returnValue+= ( *(beginPoint + 2*interval) );
                    }
                }
            }

            begin++; //下移一个
        }
        return returnValue;
    }
};

int main() {

    Solution s;
    string str1 = "abcdefghij";
    int numRows = 3;
    cout << str1 << " " << s.convert(str1, numRows) << endl;
    //s.reverse(a2);

    //cout<<numeric_limits<int>::max()<<endl;



};
