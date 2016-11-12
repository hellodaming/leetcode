//
// Created by will on 16-11-6.
//You are here!
//Your runtime beats 56.51% of cpp submissions.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(!nums.size()){
            return 0;
        }
        int returnValue = 1;
        int duplicates = nums[0];
        for(auto iter = nums.cbegin()+1; iter != nums.cend(); ++iter){
            if(duplicates == *iter){

            }
            else {
                duplicates = *iter;
                nums[returnValue] = duplicates;
                returnValue++;
            }
        }
        return returnValue;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);

    Solution s;
    int returnValue = s.removeDuplicates(nums);
    cout<< "returnValue " <<returnValue<<endl;
    return 0;
}