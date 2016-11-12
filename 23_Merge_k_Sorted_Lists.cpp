//
// Created by will on 16-10-14.
//

#include <iostream>
#include <vector>
using namespace std;




struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<ListNode *>  withoutNull(vector<ListNode *> &lists){
    for (auto iter = lists.begin(); iter != lists.end(); ++iter)
    {
        if((*iter) ==NULL) {
            lists.erase(iter);
        }
    }

}


ListNode *  merge_sort_recursive(vector<ListNode *> &lists, int start , int end){

    if (start == end)//只是一条ListNode *
        return lists[start];
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;

    ListNode * left = merge_sort_recursive(lists, start1, end1);
    ListNode * right = merge_sort_recursive(lists, start2, end2);

    ListNode* pre = new ListNode(222);//前一个指针
    ListNode* returnList = pre;
    while(left != nullptr && right != nullptr){

        if(left->val < right->val){//左更小
            pre->next = left;
            left = left->next;
        }
        else{//右更小
            pre->next = right;
            right = right->next;
        }
        pre = pre->next;

    }
    if(left != nullptr){
        pre ->next = left;
    }
    if(right != nullptr){
        pre ->next = right;
    }

    return  returnList->next;
}



class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {

        if(lists.size() != 0 ) {
            return merge_sort_recursive(lists, 0, lists.size() - 1);
        }
        else{
            return nullptr;
        }
    }
};



int main(){
    ListNode* head1 = new ListNode(0);
    ListNode* head1Temp = head1;
    for(int i = 0; i<3; i++){

        head1Temp->next = new ListNode(i);
        head1Temp = head1Temp->next;
    }


    ListNode* head2 = new ListNode(0);
    ListNode* head2Temp = head2;
    for(int i = 0; i<3; i++){
        head2Temp->next = new ListNode(i*2);
        head2Temp = head2Temp->next;
    }

    ListNode* head3 = new ListNode(0);
    ListNode* head3Temp = head3;
    for(int i = 0; i<3; i++){
        head3Temp->next = new ListNode(i*3);
        head3Temp = head3Temp->next;
    }

    ListNode* head4 = new ListNode(NULL);

    vector<ListNode*> vector1;
    vector1.push_back(head1);
    vector1.push_back(head2);
    vector1.push_back(head3);



    Solution s;
    ListNode* aaaaaa = s.mergeKLists(vector1);


/*
    ListNode* head5 = new ListNode(0);
    ListNode* head5Temp = head5;
    for(int i = 0; i<3; i++){
        head5->next = new ListNode(i*2);
        head5 = head5->next;
    }

    ListNode* head6 = new ListNode(0);
    ListNode* head6Temp = head6;
    for(int i = 0; i<3; i++){
        head6->next = new ListNode(i*3);
        head6 = head6->next;
    }


    ListNode* left = head5Temp;
    ListNode* right = head6Temp;

    ListNode* pre = new ListNode(222);//left链的前一个指针
    ListNode* return1111 = pre;
    while(left != nullptr && right != nullptr){

        if(left->val < right->val){//左更小
            pre->next = left;
            left = left->next;
        }
        else{//右更小
            pre->next = right;
            right = right->next;
        }
        pre = pre->next;

    }
    if(left != nullptr){
        pre ->next = left;
    }
    if(right != nullptr){
        pre ->next = right;
    }
*/


    return 0;
}



