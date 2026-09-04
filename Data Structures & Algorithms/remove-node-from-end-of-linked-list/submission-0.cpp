

//Approach-1 (2 Pass)
//T.C : O(n)
//S.C : O(1)
// class Solution {
// public:
    
//     int lengthLinkedList(ListNode* head) {
//         int l = 0;
        
//         while(head) {
//             l++;
//             head = head->next;
//         }
//         return l;
//     }
    
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int length = lengthLinkedList(head);
        
//         if(length == n) { //Length node form end means first node
//             ListNode* temp = head->next;
//             delete(head);
//             return temp;
//         }

//         ListNode* temp = head;
//         ListNode* prev = NULL;
//         int travel = length-n;
        
//         while(travel--) {
//             prev = temp;
//             temp = temp->next;
//         }

//         prev->next = temp->next;
        
//         delete(temp);   
        
//         return head;
        
//     }
// };


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow= head;
        ListNode* fast= head;

        for(int i = 1;i<=n;i++){
            fast = fast->next;
        }
          if(fast == NULL) {
            ListNode* result = head->next;
            delete(head);
            return result;
        }
         while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* temp = slow-> next;
        slow->next = slow->next->next;
        delete(temp);
        return head;

    }
};
