//
// Created by will on 16-10-25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double getMid(vector<int> num, vector<int> findMidLocation){

    if(findMidLocation.size()==1){
        return num[findMidLocation[0]];
    }
    else{
        return (num[findMidLocation[0]]+num[findMidLocation[1]]) / 2;
    }
}

vector<int> findMidLocation(int start, int end){

    vector<int > midLocation;
    int length = end -start+1 ;

    if(length % 2){ //奇数
        midLocation.push_back( (end + start)/2 );
    }
    else{
        midLocation.push_back( (end + start)/2 );
        midLocation.push_back( (end + start)/2 +1);
    }
    return midLocation;
}





class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int nums1Length = static_cast<int>(nums1.size());
        int nums2Length = static_cast<int>(nums2.size());

        if(nums1Length == 0){
            if(nums2Length == 0){
                return 0;
            }
            else {
                return getMid(nums2, findMidLocation( 0, nums2Length-1) );
            }
        }
        if(nums2Length == 0){
            return getMid(nums1, findMidLocation( 0, nums1Length-1) );
        }

        int num1Start = 0;
        int num1End = nums1Length-1;
        int num2Start = 0;
        int num2End = nums2Length-1;


        while( (num1End - num1Start) > 2 && (num2End - num2Start) > 2 ) {

            vector<int> nums1MidLocation = findMidLocation(num1Start, num1End);
            vector<int> nums2MidLocation = findMidLocation(num2Start, num2End);

            if(nums1MidLocation.size()==1 && nums2MidLocation.size()==1){
                if(nums1[nums1MidLocation[0]]< nums2[nums2MidLocation[0]]){
                    num1Start = nums1MidLocation[0];

                    num2End = nums2MidLocation[0];
                }
                else{
                    num1End = nums1MidLocation[0];

                    num2Start = nums2MidLocation[0];
                }


            }
            else if(nums1MidLocation.size()==1 && nums2MidLocation.size()==2){ //mid有三个数

                if(nums1[nums1MidLocation[0]] >= nums2[nums2MidLocation[1]]){
                    num1End = nums1MidLocation[0];
                    num2Start = nums2MidLocation[0]+1;

                }
                else if(nums1[nums1MidLocation[0]] <= nums2[nums2MidLocation[0]]){

                    num1Start = nums1MidLocation[0];
                    num2End = nums2MidLocation[1] -1;
                }
                else{ //位于中间
                    return nums1[nums1MidLocation[0]];
                }


            }
            else if(nums1MidLocation.size()==2 && nums2MidLocation.size()==1){

                if(nums1[nums1MidLocation[1]] >= nums2[nums2MidLocation[0]]){
                    num1End = nums1MidLocation[1];
                    num2Start = nums2MidLocation[1]+1;

                }
                else if(nums1[nums1MidLocation[1]] <= nums1[nums2MidLocation[0]]){

                    num1Start = nums1MidLocation[1];
                    num2End = nums2MidLocation[0] -1;
                }
                else{ //位于中间
                    return nums1[nums1MidLocation[1]];
                }
            }
            else if(nums1MidLocation.size()==2 && nums2MidLocation.size()==2){

                if(nums1[nums1MidLocation[1]] <= nums2[nums2MidLocation[0]]) { //34   56
                    num1Start =  nums1MidLocation[1];
                    num2End = nums2MidLocation[0];
                }
                else if(nums1[nums1MidLocation[0]] >= nums2[nums2MidLocation[1]]) { //56  34
                    num1End =  nums1MidLocation[0];
                    num2Start = nums2MidLocation[1];
                }
                else if(nums1[nums1MidLocation[0]] >= nums2[nums2MidLocation[0]] && nums1[nums1MidLocation[1]] <= nums2[nums2MidLocation[1]]) { //45 36
                    return (nums1[nums1MidLocation[0]]+ nums1[nums1MidLocation[1]])/2;
                }
                else if(nums1[nums1MidLocation[0]] < nums2[nums2MidLocation[0]] && nums1[nums1MidLocation[1]] > nums2[nums2MidLocation[1]]) { //36  45
                    return (nums2[nums2MidLocation[0]]+ nums2[nums2MidLocation[1]])/2;
                }
            }
        }


        if ((num1End - num1Start)<= 2){
            vector<int> nums2MidLocation = findMidLocation(num2Start, num2End);
            if(nums2MidLocation.size()==1){
                num2Start = num2End = nums2MidLocation[0];
            }
            else{
                num2Start = nums2MidLocation[0];
                num2End = nums2MidLocation[1];
            }
        }
        else if((num2End - num2Start)<= 2){

            vector<int> nums1MidLocation = findMidLocation(num1Start, num1End);
            if(nums1MidLocation.size()==1){
                num1Start = num1End = nums1MidLocation[0];
            }
            else{
                num1Start = nums1MidLocation[0];
                num1End = nums1MidLocation[1];
            }
        }




        vector<double> v;

        double sum = 0.0;
        if(num1Start == num1End){
            sum += nums1[num1Start];
            v.push_back(nums1[num1Start]);
        } else{
            sum += nums1[num1Start];
            sum += nums1[num1End];
            v.push_back(nums1[num1Start]);
            v.push_back(nums1[num1End]);
        }
        if(num2Start == num2End){
            sum += nums2[num2Start];
            v.push_back(nums2[num2Start]);
        } else{
            sum += nums2[num2Start];
            sum += nums2[num2End];
            v.push_back(nums2[num2Start]);
            v.push_back(nums2[num2End]);
        }
        sort(v.begin(), v.end());

        if(v.size()%2) {
            return (sum - v[0] - v[v.size() - 1]);
        }
        else{
            return (sum - v[0] - v[v.size() - 1]) /2;
        }

    }
};


int main(){
    vector<int>  nums1{1, 2};
    vector<int>  nums2{3, 4};

    vector<int>  nums12{1, 2};
    vector<int>  nums22{4};

    vector<int>  nums13{1, 2, 3};
    vector<int>  nums23{4, 6};

    vector<int>  nums14{1, 2, 3};
    vector<int>  nums24{4};

    Solution s;
    double returnValue;

    returnValue = s.findMedianSortedArrays(nums1, nums2);
    cout<<"2.5  :"<<returnValue<<endl;

    returnValue = s.findMedianSortedArrays(nums12, nums22);
    cout<<"2  :"<<returnValue<<endl;

    returnValue = s.findMedianSortedArrays(nums13, nums23);
    cout<<"3.5  :"<<returnValue<<endl;

    returnValue = s.findMedianSortedArrays(nums14, nums24);
    cout<<"2.5  :"<<returnValue<<endl;


    return 0;

}