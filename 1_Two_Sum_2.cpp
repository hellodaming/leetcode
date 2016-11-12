//
// Created by will on 16-10-17.
//


#include <iostream>
#include <vector>
#include <map>

using namespace std;




class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int size = int(nums.size());
        map<int, int> map1;
        map<int, vector<int>> same;

        for(int i=0; i< size;i++) {
                if(map1.count(nums[i]) > 0) {
                    same[nums[i]] = {map1[nums[i]],i};
                }
                else {
                    map1[nums[i]] = i;
                }
        }

        for(map<int,vector<int>>::iterator iter= same.begin();iter != same.end(); iter++){
            if(iter->first *2 == target){
                //cout<<same[iter->first][0]<<" "<<same[iter->first][1]<<endl;
                return same[iter->first];
            }
        }


        for(map<int,int>::iterator iter= map1.begin();iter != map1.end(); iter++){
            //cout<<iter->first<<" "<<iter->second<<endl;
            if(map1.count(target - iter->first)>0){
                //cout<<iter->first<<" "<<iter->second<<endl;
                return (map1[target - iter->first]>iter->second)?vector<int>{ iter->second,map1[target - iter->first]}:vector<int>{ map1[target - iter->first],iter->second};
            }
        }
        return vector<int>{};
    }
};



int main() {

    Solution s;
/*    vector<int> v = {3,2,4};
    vector<int> result = s.twoSum(v, 6);*/

    vector<int> v = {-3,4,3,90,0};
    vector<int> result = s.twoSum(v, 0);

/*    vector<int> v = {150,24,79,50,88,345,3};
    vector<int> result = s.twoSum(v, 200);*/

/*    vector<int> v = {0,4,3,0};
    vector<int> result = s.twoSum(v, 0);*/


    return 0;
};
