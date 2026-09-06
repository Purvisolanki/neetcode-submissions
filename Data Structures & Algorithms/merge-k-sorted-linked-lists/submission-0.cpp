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

    ListNode* mergeTwoSortedLists(ListNode* L1,ListNode* L2){
        if(!L1) return L2;
        if(!L2) return L1;

        if(L1->val > L2->val){
            L2->next = mergeTwoSortedLists(L2->next,L1);
            return L2;
        }else{
             L1->next = mergeTwoSortedLists(L2,L1->next);
             return L1;
        }
        return NULL;
    }
    ListNode* partitionAndMerge(int start, int end,vector<ListNode*>& lists ){
        if(start>end){
            return NULL;
        }
        if(start == end){
            return lists[start];
        }

        int mid = start + (end-start)/2;
        ListNode* L1 = partitionAndMerge(start,mid,lists);
        ListNode* L2 = partitionAndMerge(mid+1,end,lists);

        return mergeTwoSortedLists(L1,L2);

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if(n == 0)
        return NULL;

        return partitionAndMerge(0,n-1,lists);
    }
};
