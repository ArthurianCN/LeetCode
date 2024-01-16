/*
题目描述：
    给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
    链表中节点数目在范围 [0, 300] 内
    -100 <= Node.val <= 100
    题目数据保证链表已经按升序 排列
    Definition for singly-linked list.
    struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
解法思路：
    题目里面说已经按升序排列，那么重复的元素必定是相邻的，只需要从头遍历到尾，然后将后一个元素所在节点删除即可。
    解法1：每次判断当前元素和下一个元素的值是否一样，若不一样，直接将指针后移；若一样，则删除后一个元素，循环往复
    解法2：使用快慢指针，慢指针p指向当前元素，快指针q一直后移，直到q处的值和p处的值不相等，然后将p的next指向q，循环往复
*/




// 解法1
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
        {
            return nullptr;
        }
        ListNode* result = head;
        while(head->next)
        {
            if(head->val == head->next->val)
            {
                ListNode* p = head->next;
                head->next = head->next->next;
                delete p;
            }
            else
            {
                head = head->next;
            }
        }

        return result;
    }
};





// 解法2
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
        {
            return nullptr;
        }
        ListNode* result = head;
        ListNode* p = head, *q = head;
        while(p && q)
        {
            if(p->val == q->val)
            {
                q = q->next;
                p->next = q;
                continue;
            }

            p = p->next;
        }
        
        return result;
    }
};