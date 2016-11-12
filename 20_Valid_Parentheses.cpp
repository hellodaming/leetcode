//
// Created by will on 16-11-6.
//You are here!
//Your runtime beats 0.19% of cpp submissions.
//

#include <iostream>

#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        int size = s.size();
        if( size % 2 ){ //奇数个
            return false;
        }
        map<char, char> map1;
        //map1[')'] = '(';
        map1['('] = ')';
        //map1['}'] = '{';
        map1['{'] = '}';
        //map1[']'] = '[';
        map1['['] = ']';
        stack<char> stack1;
        size--;
        while(size != -1){
            if(!stack1.empty() && stack1.top() == map1[ s[size] ]){
                stack1.pop();
            }
            else{
                stack1.push(s[size]);
            }
            size--;
        }
        if(stack1.size()){
            return false;
        }
        else{
            return true;
        }
    }
};

int main(){


    Solution s;

    string string1 = "()";
    string string2 = "()]";
    string string3 = "([)]";
    string string4 = "{([])}";
    string string5 = "[][][][][{}]";

    cout<<string1<< "1 is  "<< s.isValid(string1)<<endl;
    cout<<string2<< "0 is  "<<s.isValid(string2)<<endl;
    cout<<string3<< "0 is  "<<s.isValid(string3)<<endl;
    cout<<string4<< "1 is  "<<s.isValid(string4)<<endl;
    cout<<string5<< "1 is  "<<s.isValid(string5)<<endl;
    return 0;
}
