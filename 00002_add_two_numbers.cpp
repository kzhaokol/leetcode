/**
* Name: Kevin Zhao
*
* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
* You may assume the two numbers do not contain any leading zero, except the number 0 itself.
* Example:
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
* Explanation: 342 + 465 = 807.
*/ 


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef int ValueType;
typedef ListNode* ListNodePtr;
typedef ValueType CarryOverValueType;
typedef ValueType SumValueType;
typedef pair<ListNodePtr, CarryOverValueType> ListNodePtrCarryOverValuePair;

SumValueType getSumValue(ListNode* listNode1,
                         ListNode* listNode2,
                         CarryOverValueType carryOverValue) {
    auto sumValue = carryOverValue;
    if (listNode1 != nullptr) {
        sumValue += (listNode1->val);
    }
    if (listNode2 != nullptr) {
        sumValue += (listNode2->val);
    }
    return sumValue;
}

CarryOverValueType getCarryOverValue(const SumValueType sumValue) {
    return (sumValue / 10);
}

ValueType getValue(const SumValueType sumValue) {
    return (sumValue % 10);
}

ListNodePtrCarryOverValuePair getListNodePtrCarryOverValuePair(
    ListNode* listNode1,
    ListNode* listNode2,
    CarryOverValueType carryOverValue) {
    
    auto sumValue = getSumValue(listNode1, listNode2, carryOverValue);
    auto nextCarryOverValue = getCarryOverValue(sumValue);
    auto value = getValue(sumValue);
    
    auto newListNodePtr = new ListNode(value);
    return make_pair(newListNodePtr, nextCarryOverValue);
}

bool canComputeAdditionalListNode(ListNode* listNode1,
                                  ListNode* listNode2,
                                  CarryOverValueType carryOverValue) {
    return ((carryOverValue != 0) ||
              (listNode1 != nullptr) ||
              (listNode2 != nullptr));
}

void advanceListNodePtr(ListNode** listNodePtr) {
    if ((listNodePtr != nullptr) && (*listNodePtr != nullptr)) {
        *listNodePtr = (*listNodePtr)->next; 
    }
}

class Solution {
public:
    ListNodePtr addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNodePtr headNodePtr = nullptr;
        ListNodePtr previousNodePtr = nullptr;
        CarryOverValueType carryOverValue = 0;
        
        while (canComputeAdditionalListNode(l1, l2, carryOverValue)) {
            auto listNodePtrCarryOverValue =
                getListNodePtrCarryOverValuePair(l1, l2, carryOverValue);
            if (previousNodePtr != nullptr) {
                previousNodePtr->next = listNodePtrCarryOverValue.first;
            }
            if (headNodePtr == nullptr) {
                headNodePtr = listNodePtrCarryOverValue.first;
            }

            previousNodePtr = listNodePtrCarryOverValue.first;
            carryOverValue = listNodePtrCarryOverValue.second;
            advanceListNodePtr(&l1);
            advanceListNodePtr(&l2);
            
        }
        return headNodePtr;
    }
};
