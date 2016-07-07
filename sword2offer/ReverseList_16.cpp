//头插法
ListNode* ReverseList(ListNode* pHead) {
        
    if(pHead == NULL)
        return NULL;
  
    ListNode *p = pHead->next;
    ListNode *q = NULL;
    pHead->next = NULL;
    
    while(p){
        q = p->next;
        p->next = pHead;
        pHead = p;
        p = q;
    }        
    return pHead;
}