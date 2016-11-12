//
// Created by will on 16-10-17.
//


//  You are here!
//Your runtime beats 3.71% of cpp submissions.

#include <iostream>
#include <vector>
using namespace std;




class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {


        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target){
                    return vector<int>{i,j};
                }
            }
        }
        return vector<int>{};

    }
};



int main() {

    Solution s;
    vector<int> v = {3,2,4};
    vector<int> result = s.twoSum(v, 6);
    return 0;
};
