//
// Created by will on 16-11-5.
//You are here!
//Your runtime beats 23.18% of cpp submissions
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }

        int minLengthStringLocal = 0;
        int i = 0;
        while(i != strs.size()){
            if(strs[minLengthStringLocal].size() > strs[i].size()){
                minLengthStringLocal = i;
            }
            i++;
        }

        string minLengthString = strs[minLengthStringLocal]; //找出最短的串

        int minLength =  minLengthString.length();

        while(minLength ){

            bool flag = true;
            for(string str : strs){
                //string temp1 = str.substr(0, strMinLengthLocal);
                //string temp2 = strMinLength.substr(0, strMinLengthLocal);
                //if(temp1 != temp2){
                if(str.substr(0, minLength) != minLengthString.substr(0, minLength)){
                    flag = false;
                    break;
                }
                else{
                    continue;
                }
            }
            if(!flag) {
                minLength--;
            } else{
                break;
            }
        }
        return minLengthString.substr(0, minLength);

    }
};

int main(){

    string str1 = "abcdef";
    string str2 = "abc afs";
    string str3 = "abcdff";
    string str4 = "abcd";
    vector<string> v ;
    v.push_back(str1);
    v.push_back(str2);
    v.push_back(str3);
    v.push_back(str4);

    Solution s;
    string returnValue = s.longestCommonPrefix(v);
    cout<<"Longest Common Prefix : "<< returnValue<<endl;
    return 0;
}