/*
题目描述：
    将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
    两个链表的节点数目范围是 [0, 50]
    -100 <= Node.val <= 100
    l1 和 l2 均按 非递减顺序 排列
解法思路：
    迭代法
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* pListResult = nullptr,* q  = nullptr;
        while(list1 && list2)
        {
            ListNode* p = new ListNode;
            if(list1->val <= list2->val)
            {
                p->val = list1->val;
                list1 = list1->next;
            }
            else
            {
                p->val = list2->val;
                list2 = list2->next;
            }

            if(!pListResult)
            {
                pListResult = p;
                q = pListResult;
            }
            else
            {
                q->next = p;
                q = p;
            }
        }

        if(!pListResult)
        {
            pListResult = list1 ? list1 : list2;
        }
        else
        {
            q->next = list1 ? list1 : list2;
        }

        return pListResult;
    }
};