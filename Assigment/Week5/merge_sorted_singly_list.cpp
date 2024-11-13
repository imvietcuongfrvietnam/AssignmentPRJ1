
#include<stdio.h>
 struct ListNode {
      int val;
     struct ListNode *next;
  };
 
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *before=list1, *after = list1;
    while(after != NULL){
        while(after->val < list2->val){
             before = after;
            after = after->next;
            continue;
        }
        before->next = list2;
        list2 = list2->next;
        before = before->next;
        after = before->next;
    }
    if(list2 != NULL){
        after->next = list2;
    }
    return list1;
}
int main(){
	
}
