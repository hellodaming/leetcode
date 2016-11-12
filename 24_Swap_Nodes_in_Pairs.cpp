//
// Created by will on 16-11-6.
//You are here!
//Your runtime beats 12.66% of cpp submissions.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* move(ListNode* front){
    if(front != nullptr && front->next != nullptr) {
        ListNode *rear = front->next;
        ListNode *movePoint = rear->next; //移了两位后的节点
        front->next->next = front;
        front->next = move(movePoint);
        return rear;
    }
    else {
        return  front;
    }
}




class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //ListNode* front = head;
        //ListNode* returnValue = move(front);
        return move(head);

    }
};


int main() {

    ListNode *head = nullptr;
    ListNode *temp = nullptr;

    for (int i = 1; i <= 5 ; ++i) {
        ListNode *node = new ListNode(i);
        if (head == nullptr) {
            head = node;
            temp = node;
        } else {
            temp->next = node;
            temp = temp->next;
        }

    }
    Solution s;
    ListNode *returnValue = s.swapPairs(head);

    for (auto node = returnValue; node != nullptr; node = node->next) {
        cout << node->val << "->";
    }


    return 0;
}