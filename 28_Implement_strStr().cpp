//
// Created by will on 16-11-8.
//You are here!
//Your runtime beats 58.36% of cpp submissions.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

int main(){
    Solution s;

    string haystack = "abcdefgh";
    string needle = "de";
    int returnValue = s.strStr(haystack, needle);
    cout<<returnValue<<endl;
    return 0;
}