//
// Created by will on 16-10-16.
//

#include <iostream>
#include <vector>
using namespace std;




struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//[[2],[],[-1]]

/*void merge(vector<ListNode *> &lists, int start , int end){

    ListNode * left = lists[start];
    ListNode * right = lists[end];

    ListNode* pre = new ListNode(111);//前一个指针
    ListNode* returnList = pre;
    while(left != nullptr && right != nullptr){

        while(left != nullptr && right != nullptr && left->val < right->val){//左更小 right不动，单移动left
            pre->next = left;
            left = left->next;
            pre = pre->next;
        }
        while(left != nullptr && right != nullptr && left->val >= right->val){
            pre->next = right;
            right = right->next;
            pre = pre->next;
        }
    }
    if(left != nullptr){
        pre ->next = left;
    }
    if(right != nullptr){
        pre ->next = right;
    }
    lists[start] = returnList->next;
   // return  returnList->next;
}*/
void merge(vector<ListNode *> &lists, int start , int end){

    ListNode * left = lists[start];
    ListNode * right = lists[end];

    ListNode* pre = nullptr;//前一个指针
    ListNode* returnList = nullptr;

    while(left != nullptr && right != nullptr){

        if(left->val < right->val){//左更小
            if(pre == nullptr){
                pre = left;
                returnList = left;
                left = left->next;
            }
            else {
                pre->next = left;
                left = left->next;
                pre = pre->next;
            }
        }
        else{//右更小
            if(pre == nullptr){
                pre = right;
                returnList = right;
                right = right->next;
            }
            else {
                pre->next = right;
                right = right->next;
                pre = pre->next;
            }
        }


    }
    if(left != nullptr){
        if(pre == nullptr){
            returnList = left;

        }
        else {
            pre ->next = left;
        }

    }
    if(right != nullptr){
        if(pre == nullptr){
            returnList = right;

        }
        else {
            pre ->next = right;
        }
    }
    lists[start] = returnList;
}




void mergeSort(vector<ListNode *> &lists){
    int len = int(lists.size());

    for (int seg = 1; seg < len; seg += seg) {
        for (int start = 0; start < len; start += seg + seg) {
            if(start + seg < len) {
                merge(lists, start, start + seg);
            }
            else{
                continue;
            }
        }
    }
}








class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {

        if(lists.size() != 0 ) {
            mergeSort(lists);
            return lists[0];
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
/*    vector1.push_back(head1);
    vector1.push_back(head2);
    vector1.push_back(head3);
    vector1.push_back(head4);*/

    vector1.push_back(new ListNode(2));
    vector1.push_back(NULL);
    vector1.push_back(new ListNode(-1));
    Solution s;
    ListNode* aaaaaa = s.mergeKLists(vector1);



    return 0;
}



