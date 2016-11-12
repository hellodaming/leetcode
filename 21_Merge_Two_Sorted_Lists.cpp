//
// Created by will on 16-11-6.
//You are here!
//Your runtime beats 26.57% of cpp submissions.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if(l1 == nullptr || l2 == nullptr){
            if(l1== nullptr){
                return l2;
            }
            else{
                return l1;
            }
        }

        ListNode* pre = nullptr;//前一个指针
        ListNode* returnList = nullptr;

        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){

                if(returnList == nullptr){
                    returnList = l1;
                    pre = l1;
                    l1 = l1->next;
                }
                else{
                    pre->next = l1;
                    l1 = l1->next;
                    pre = pre->next;
                }

            }
            else{
                if(returnList == nullptr){
                    returnList = l2;
                    pre = l2;
                    l2 = l2->next;
                }
                else{
                    pre->next = l2;
                    l2 = l2->next;
                    pre = pre->next;
                }
            }
        }

        if(l1 == nullptr){
            pre->next = l2;
        }
        else{
            pre->next = l1;
        }

        return returnList;
    }
};

int main() {

    ListNode *head1 = nullptr;
    ListNode *temp1 = nullptr;

    for (int i = 1; i <= 2 ; ++i) {
        ListNode *node = new ListNode(i);
        if (head1 == nullptr) {
            head1 = node;
            temp1 = node;
        } else {
            temp1->next = node;
            temp1 = temp1->next;
        }

    }



    ListNode *head2 = nullptr;
    ListNode *temp2 = nullptr;

    for (int i = 0; i <= 1; ++i) {
        ListNode *node = new ListNode(i-5);
        if (head2 == nullptr) {
            head2 = node;
            temp2 = node;
        } else {
            temp2->next = node;
            temp2 = temp2->next;
        }

    }


    Solution s;
    ListNode *returnValue = s.mergeTwoLists(head1, head2);

    for (auto node = returnValue; node != nullptr; node = node->next) {
        cout << node->val << "->";
    }


    return 0;
}