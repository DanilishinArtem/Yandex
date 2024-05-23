#include <iostream>
#include <vector>

//  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* result = new ListNode();
        ListNode* current = result;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int x = l1 == nullptr ? 0 : l1->val;
            int y = l2 == nullptr ? 0 : l2->val;
            int sum = x + y + carry;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        return result->next;
    }
};


int main(){
    Solution s;
    ListNode* l1 = new ListNode(2);
    ListNode* l2 = new ListNode(4);
    ListNode* l3 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;
    ListNode* l4 = new ListNode(5);
    ListNode* l5 = new ListNode(6);
    ListNode* l6 = new ListNode(4);
    l4->next = l5;
    l5->next = l6;
    ListNode* answer;
    answer = s.addTwoNumbers(l1, l4);
    while(answer != nullptr){
        std::cout << answer->val << std::endl;
        answer = answer->next;
    }
    return 0;
}