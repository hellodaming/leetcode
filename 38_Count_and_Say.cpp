//
// Created by will on 16-11-8.
//You are here!
//Your runtime beats  of cpp submissions.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = to_string(n);
        string returnValue;
        char oldChar = s[0];
        int num = 1;
        for(int i = 1; i<s.size(); i++){

            if(oldChar == s[i]){
                num++;
            }
            else{
                returnValue+= to_string(num)+oldChar;
                oldChar = s[i];
                num = 1;
            }
        }

        returnValue+= to_string(num)+oldChar;
        return returnValue;

    }
};

int main(){
    Solution s;

    int n = 1123344555;
    string returnValue = s.countAndSay(n);
    cout<<returnValue<<endl;
    return 0;
}