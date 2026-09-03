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
    bool hasCycle(ListNode *head) {
        //     // O(N * 2 * log(N) )
    //    
    // ListNode* temp = head;  
    
   
    // unordered_map<ListNode*, int> nodeMap;  

   
    // while (temp != nullptr) {
    //     // If the node is already in the
    //     // map, there is a loop
    //     if (nodeMap.find(temp) != nodeMap.end()) {
    //         return true;
    //     }
  
    //     nodeMap[temp] = 1;
        
   
    //     temp = temp->next;  
    // }

  
    // return false;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        return true;
    }
    return false;

    }
};