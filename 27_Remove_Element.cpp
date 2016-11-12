//
// Created by will on 16-11-6.
//You are here!
//Your runtime beats 26.33% of cpp submissions

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /*int local = 0;
        int returnValue = 0;
        queue<int> vacancy; //空缺位
        while(local != nums.size()){

            if(nums[local] == val){ //若等于，进队列
                vacancy.push(local);
                returnValue++;
                nums.erase(nums.begin() + -1);
            }
            else{
                if(!vacancy.empty()) {
                    nums[vacancy.front()] = nums[local];
                    vacancy.pop();
                }
            }
            local++;
        }
*//*        if(nums[0] ==val){
            nums.erase(nums.begin());
        }*//*
        nums.erase(nums.cend()-vacancy.size(),nums.cend());

        for(auto temp: nums){
            cout<<temp<<" ";
        }
        cout<<endl;*/

        int returnValue = 0;
        for(vector<int>::iterator iter = nums.begin(); iter!=nums.end(); iter++){
            if(*iter == val){
                nums.erase(iter);
                iter--;
            }
            else {
                returnValue++;
            }
        }
        return returnValue;
    }
};


int main(){
    vector<int> nums;
    nums.push_back(1);


    vector<int> nums2;
    nums2.push_back(1);
    nums2.push_back(1);
    nums2.push_back(1);
    nums2.push_back(2);

    Solution s;

    int returnValue1 = s.removeElement(nums, 1);
    cout<< "returnValue " <<returnValue1<<endl;

    int returnValue2 = s.removeElement(nums2, 2);
    cout<< "returnValue " <<returnValue2<<endl;

    return 0;
}