//
// Created by will on 16-10-25.
//You are here!
//Your runtime beats 14.95% of cpp submissions
//

#include <iostream>
#include <map>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {


        int size = static_cast<int>(s.length());
        if(size ==0 ){
            return 0;
        }
        int start = 0;
        int end = 1;
        int length = 1;
        int maxLength = 1;

        map<char, int> m;
        for(char i = 'a'; i!= 'z'+1; ++i){
            m[i] = -1;
        }
        m[s[0]] = 0;//初始化第一个
        while(end < size){

            if(m[s[end]] >= start){ //存在重复字母
                start = m[s[end]]+1;
                if(maxLength < length){
                    maxLength = length;
                }
               if(length<=1) {
                    length = 1;
                    //end = end+1;
                }
                /*else{
                    length = length-1;
                }*/
                length =  end -start+1;
                m[s[end]] = end; //重复的覆盖了新的
            }
            else{ //不存在重复字母
                length++;
                m[s[end]] = end;
            }
            end++;
        }
        if(maxLength < length){
            maxLength = length;
        }
        return maxLength;
    }
};


int main(){
    Solution solution;
    string s1 = "abcabcbb"; //3
    string s2 = "bbbbb"; //1
    string s3 = "pwwkew"; //3
    string s4 = "c"; //1
    string s5 = ""; //0
    string s6 = "aab"; //2
    string s7 = "au";
    string s8 = "dvdf";
    cout<<s1<<"的最大子串为： "<<solution.lengthOfLongestSubstring(s1)<<endl;
    cout<<s2<<"的最大子串为： "<<solution.lengthOfLongestSubstring(s2)<<endl;
    cout<<s3<<"的最大子串为： "<<solution.lengthOfLongestSubstring(s3)<<endl;
    cout<<s4<<"的最大子串为： "<<solution.lengthOfLongestSubstring(s4)<<endl;
    cout<<s5<<"的最大子串为： "<<solution.lengthOfLongestSubstring(s5)<<endl;
    cout<<s6<<"的最大子串为： "<<solution.lengthOfLongestSubstring(s6)<<endl;
    cout<<s7<<"的最大子串为： "<<solution.lengthOfLongestSubstring(s7)<<endl;
    cout<<s8<<"的最大子串为： "<<solution.lengthOfLongestSubstring(s8)<<endl;

    return 0;

}