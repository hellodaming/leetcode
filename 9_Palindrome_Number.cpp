//
// Created by will on 16-11-2.
//You are here!
//Your runtime beats 1.21% of cpp submissions.
//
#include <iostream>
#include <cmath>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0){
            return false;
        }

        int n = 9;
        while(x< pow(10, n)){
            n--;
        }

        int localtion = n;
        while(localtion > 0) {

            int start = x / pow(10, localtion);
            int end =x%10;//那么4就变成了最后一位,再用上面的方法

            if(start ==  end){
                if(localtion < 1){
                    return true;
                }
                else {
                    x -= ( start* pow(10, localtion) + end );
                    x /= 10;
                    int zeroNum = 0;
                    localtion -= 2;
                    while(x< pow(10, localtion- zeroNum)){
                        zeroNum++;
                        localtion--;
                    }
                    while(zeroNum){
                        if(! (x%10) ){
                            zeroNum--;
                            localtion--;
                            x /= 10;
                        }
                        else{
                            return false;
                        }
                    }
                    continue;
                }

            }
            else{
                return false;
            }
        }


        return true ;
    }
};






/*
class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0){
            return false;
        }

        for (int n = 9; n != 0; --n) {  //numeric_limits<int>::max() = 2147483647

            if (x >= pow(10, n)) {//找出开始的最高位

                int local = n;

                int midLocal =  (n-1)/2;
                int start = x /
                int end;
                while(local < n/2){



                }


            }//if
        }//for

        return true ;
    }
};
 */


int main() {

    Solution s;
    int x1 = 123454321;
    int x2 = 100010001;
    int x3 = 12344321;
    int x4 = 123456321;
    cout << x1 << " " << s.isPalindrome(x1) << endl;
    cout << x2 << " " << s.isPalindrome(x2) << endl;
    cout << x3 << " " << s.isPalindrome(x3) << endl;
    cout << x4 << " " << s.isPalindrome(x4) << endl;

};
