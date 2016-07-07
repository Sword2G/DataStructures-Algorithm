/*
1 尾插，分别用一个指针指向链表头，val较小的节点尾插入新链表，同时移动指针，较大的指针不动
2 递归，第一个链表val小则结果链表头指针指向它，并将其next指向pHead1的后续链表与pHead2的Merge结果
*/
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == NULL)
        return pHead2;
    if(pHead2 == NULL)
        return pHead1;
        
    ListNode *p1 = pHead1;
    ListNode *p2 = pHead2;
    ListNode *p3 = NULL;
    ListNode *rear = NULL;
        
    if(p1->val < p2->val)
    {
        p3 = p1;
        rear = p1;
        p1 = p1->next;
    }
    else
    {
        p3 = p2;
        rear = p2;
        p2 = p2->next;
    }
            
    while(p1 && p2){
        if(p1->val < p2->val)
        {
            rear->next = p1;
            rear = p1;
            p1 = p1->next;
        }
        else
        {
            rear->next = p2;
            rear = p2;
             p2 = p2->next;
        }           

    if(p1 == NULL)
        rear->next = p2;
    else
        rear->next = p1;
        
    return p3;        
}



ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == NULL)
        return pHead2;
    if(pHead2 == NULL)
        return pHead1;
        
    ListNode *p = NULL;
        
    if(pHead1->val < pHead2->val)
    {
        p = pHead1;
        p->next = Merge(pHead1->next, pHead2);
    }
    else
    {
        p = pHead2;
        p->next = Merge(pHead2->next, pHead1);
    }
}      
      