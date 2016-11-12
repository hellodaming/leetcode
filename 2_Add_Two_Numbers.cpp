//
// Created by will on 16-10-18.
//



//You are here!
//Your runtime beats 46.27% of cpp submissions.

#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr || l2 == nullptr){
            if(l1 == nullptr){
                return l2;
            }
            else{
                if(l2 == nullptr){
                    return l1;
                }
            }
        }

        bool flag = false;
        ListNode* returnNode = l1;
        ListNode* proL1 = nullptr;
        ListNode* proL2 = nullptr;

        //while(l1->next != nullptr && l2->next != nullptr){
        while(l1 != nullptr && l2 != nullptr){
            if((l1->val+l2->val+flag)/10){

                //pro->val = (l1->val+l2->val)% 10;
                l1->val = (l1->val+l2->val+flag)% 10;
                flag = true;
            }
            else{
                //pro->val = l1->val+l2->val;
                l1->val = l1->val+l2->val+flag;
                flag = false;
            }

            if(l1 ->next == nullptr || l2 ->next == nullptr){
                proL1 = l1;
                proL2 = l2;

            }
            l1 = l1->next;
            l2 = l2->next;
        }

        /*if(l1  == nullptr && l2  == nullptr){//处理最后一个节点

            if((l1->val+l2->val)/10){
                l1->val = (l1->val+l2->val+flag)% 10;
                flag = true;
            }
            else{
                l1->val = l1->val+l2->val+flag;
                flag = false;
            }
            if(flag) {
                l1->next = new ListNode{1};
            }
        }*/
        if(l1  == nullptr && l2  == nullptr){

            if(flag) {
                proL1->next = new ListNode{1};
            }
            return  returnNode;
        }
       /* else
        if(l2 ->next != nullptr){

            if((l1->val+l2->val)/10){

                //pro->val = (l1->val+l2->val)% 10;
                l1->val = (l1->val+l2->val+flag)% 10;
                flag = true;
            }
            else{
                //pro->val = l1->val+l2->val;
                l1->val = l1->val+l2->val+flag;
                flag = false;
            }
            l1->next = l2->next;

            while(flag) {
                if((l2->next->val + 1)/10){
                    l2->next->val = (l2->next->val + 1)%10;
                    //l2->next->next =  new ListNode{1};
                    l2 = l2->next;
                    flag = true;
                }
                else {
                    l2->next->val = l2->next->val + 1;
                }
            }

        }
        else if(l1 ->next != nullptr) {

            if((l1->val+l2->val)/10){
                //pro->val = (l1->val+l2->val)% 10;
                l1->val = (l1->val+l2->val+flag)% 10;
                flag = true;
            }
            else{
                //pro->val = l1->val+l2->val;
                l1->val = l1->val+l2->val+flag;
                flag = false;
            }
            //l1->next = l2->next;
            if(flag) {
                if((l1->next->val + 1)/10){
                    l1->next->val = (l1->next->val + 1)%10;
                    l1->next->next =  new ListNode{1};
                }
                else
                    l1->next->val = l1->next->val + 1;
            }
        }*/

        if(l1 == nullptr){
            proL1->next = proL2->next;
            l1 = proL1;
        }
        else{
            l1 = proL1;
        }

        while(l1->next!= nullptr&&(l1->next->val+flag)/10){
            l1->next->val = 0;
            l1 = l1->next;
        }
        if(flag&&l1->next == nullptr){
            l1->next = new ListNode{1};
        }
        else if(flag){
            l1->next->val = l1->next->val+1;
        }


        return  returnNode;
    }
};


int main(){
    ListNode* l11 = new ListNode(11);
    ListNode* l22 = new ListNode(11);

    ListNode* l1 = l11;
    ListNode* l2 = l22;
/*    vector<int>  a1{2,4,3};
    vector<int>  a2{5,6,4};*/
/*    vector<int>  a1{1,2,3,4};
    vector<int>  a2{1,2,3,6};*/
/*    vector<int>  a1{1};
    vector<int>  a2{9,9};*/
/*
    vector<int>  a1{8,9,9};
    vector<int>  a2{2};
*/

/*    vector<int>  a1{9,8};
    vector<int>  a2{1};*/

    vector<int>  a1{3,7};
    vector<int>  a2{9,2};

    for(vector<int>::iterator iter = a1.begin(); iter != a1.end(); iter++ ){
        l1->next = new ListNode(*iter);
        l1 = l1->next;
    }
    for(vector<int>::iterator iter = a2.begin(); iter != a2.end(); iter++ ){
        l2->next = new ListNode(*iter);
        l2 = l2->next;
    }

    Solution s;
    ListNode* result = s.addTwoNumbers( l11->next, l22->next);

    return 0;
}