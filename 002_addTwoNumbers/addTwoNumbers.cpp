

/*
题目描述：
    给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
    请你将两个数相加，并以相同形式返回一个表示和的链表。
    你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
    每个链表中的节点数在范围 [1, 100] 内
    0 <= Node.val <= 9
    题目数据保证列表表示的数字不含前导零
解法思路：
    直接遍历就行了，但是要注意进位的处理
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* listResult = new ListNode;
        ListNode* p1 = l1, *p2 = l2, *p3 = listResult;
        int nCarryBit = 0;
        while(p1 && p2)
        {
            p3->val = (nCarryBit + p1->val + p2->val) % 10;            
            nCarryBit =  (nCarryBit + p1->val + p2->val) / 10;

            if(p1->next || p2->next || nCarryBit)
            {
                p3->next = new ListNode;
                p3 = p3->next;
                p3->val = nCarryBit;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        while(p1)
        {
            p3->val = (nCarryBit + p1->val) % 10;
            nCarryBit =  (nCarryBit + p1->val) / 10;
            if(p1->next || nCarryBit)
            {
                p3->next = new ListNode;
                p3 = p3->next;
                p3->val = nCarryBit;
            }
            p1 = p1->next; 
        }

        while(p2)
        {
            p3->val = (nCarryBit + p2->val) % 10;
            nCarryBit =  (nCarryBit + p2->val) / 10;
            if(p2->next || nCarryBit)
            {
                p3->next = new ListNode;
                p3 = p3->next;
                p3->val = nCarryBit;
            }
            p2 = p2->next; 
        }

        return listResult;
    }
};