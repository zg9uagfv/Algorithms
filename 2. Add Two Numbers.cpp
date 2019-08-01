/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0x00;
        ListNode *node = l1, *node2 = l2, *prev = l1;
        while (NULL != node && NULL != node2) {
            int value = node->val + node2->val + flag;
            if (value >= 10) {
                flag = 0x01;
                node->val = value - 10;
            } else {
                flag = 0x00;
                node->val = value;
            }
            prev = node;
            node = node->next;
            node2 = node2->next;
        }
        
        if (NULL == node) {
            while (NULL != node2) {
                if (flag == 0x01) {
                    int value = node2->val + flag;
                    if (value >= 10) {
                        flag = 0x01;
                        value = value - 10;
                    } else {
                        flag = 0x00;                 
                    }
                    node2->val = value;
                }
                prev->next = node2;
                prev = node2;
                node2 = node2->next;
            }
        }
        if (NULL == node2) {
            while (NULL != node) {
                if (flag == 0x01) {
                    int value = node->val + flag;
                    if (value >= 10) {
                        flag = 0x01;
                        value = value - 10;
                    } else {
                        flag = 0x00;   
                    }
                    node->val = value;
                }
                prev = node;
                node = node->next;
            }            
        }
        if (flag == 0x01) {
            ListNode *p = new ListNode(1);
            prev->next = p; #需要做delete在～Solution()
        }
        return l1;
    }
};
