/*
查找第 k 个节点
1 遍历两遍，第一遍找出总结点数 n，第二遍找出第 n-k+1 个数，即为倒数第 k 个数
2 两个指针同时遍历，第一个指针先移动 k-1 个节点，此时第二个指针开始移动，当第一个指针到达链表尾部时，第二个指针就指向第 k 个节点。
两种方式都需要注意对输入条件进行判断，保证程序的鲁棒性
*/
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        
    if(pListHead == NULL || k <= 0)
        return NULL;
        
    int n = 0;
        
    ListNode* p = pListHead;
    while(p){
        n++;
        p = p->next;
    }
        
    if(k > n)
        return NULL;
        
    int i = 1;

    p = pListHead;
        
    while(p && i < n - k + 1){
        i++;
        p = p->next;
    }
        
    return p;
}

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        
    if(pListHead == NULL || k <= 0)
        return NULL;
    
    int i;
    ListNode *p1 = pListHead;
    ListNode *p2 = pListHead;

    for(i = 0; i < k - 1; i++)
    {
        if(p1->next)
            p1 = p1->next;
        else
            return NULL;
    }
        
    while(p1->next)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
       
    return p2;
}
