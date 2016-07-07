/*
1 vector #include<vector>
2 stack 遍历链表的时候不断的push节点，打印的时候用top取出节点打印
3 递归
*/

void printListFromTailToHead(struct ListNode* head) 
{
        vector<int> res;
        vector<int>::iterator iter;

        struct ListNode* p = head;
        
        while(p)
        {
            res.insert(res.begin(),p->val);
            p = p->next;
        }

        for(iter=res.begin();iter!=res.end();iter++)  
        {  
             cout<<*iter;
        }  
        
}


void printListFromTailToHead(struct ListNode* head)
{
    std::stack <ListNode*> s;
    ListNode *p = head；
    while(p)
    {
        s.push(p);
        p = p->next;
    }

    while(!s.empty())
    {
        p = s.pop();
        cout << p->val;
    }
}

void printListFromTailToHead(struct ListNode* head)
{
    if(head)
    {
        if(head->next)
            printListFromTailToHead(head->next);
        cout << head->val;
    }
}