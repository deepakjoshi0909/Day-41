class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }

        ListNode* temp = head;
        for(int i=0;i<k;i++){
            if(!temp) return head;
            temp = temp->next;
        }

        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int cnt = 0;

        while(curr != NULL && cnt < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        if(next != NULL){
            head->next = reverseKGroup(next,k);
        }

        return prev;

    }
};
