#include<iostream>



struct ListNode {
    int val;
    struct ListNode* next;
};
//�ϲ���������
struct ListNode* fun(struct ListNode* head1, struct ListNode* head2)
{
    struct ListNode* p = head1, * ptr = p;
    if (head1->val > head2->val)
    {
        p = head2;
        ptr = p;
        head2 = head2->next;
    }
    else
        head1 = head1->next;    //ѡ��ͷ�ڵ��Ӧֵ��С�ڵ㰡����Ϊ�ϲ��Ŀ�ʼ
    while (head1 && head2)   //���￪ʼ��ɺϲ�����
    {
        if (head1->val < head2->val)
        {
            p->next = head1;
            head1 = head1->next;
        }
        else
        {
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }
    if (head1)
        p->next = head1;
    if (head2)
        p->next = head2;
    return ptr;
}

//ѭ������
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0)
    {
        return NULL;
    }
    int k = 0, i = 0;
    while (i < listsSize)  //�������е�NULL�ų�
    {
        if (lists[i])
        {
            lists[k++] = lists[i];
        }
        i++;
    }
    listsSize = k;
    k = 0;
    while (listsSize > 1)
    {
        k = 0;
        if (listsSize % 2)   //��Ϊ������������ϲ�һ�α�Ϊż�������ٽ��������ϲ�
        {
            lists[listsSize - 2] = fun(lists[listsSize - 1], lists[listsSize - 2]);
            listsSize--;
        }
        for (int i = 0; i < listsSize; i += 2)
        {
            lists[k++] = fun(lists[i], lists[i + 1]);
        }
        listsSize /= 2;
    }
    return lists[0];
}

//�����Ż�
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0)
    {
        return NULL;
    }
    int k = 0, i = 0, start = 0, end = start;
    while (start < listsSize && end < listsSize)
    {
        while (start < listsSize && !lists[start])
            start++;
        end = start + 1;
        while (end < listsSize && !lists[end])
            end++;
        if (end < listsSize && start < listsSize)
            lists[k++] = fun(lists[start], lists[end]);
        else
        {
            if (start < listsSize)
                lists[k++] = lists[start];
        }
        start = end + 1;
    }
    listsSize = k;
    while (listsSize > 1)
    {
        k = 0;
        if (listsSize % 2)
        {
            lists[listsSize - 2] = fun(lists[listsSize - 1], lists[listsSize - 2]);
            listsSize--;
        }
        for (int i = 0; i < listsSize; i += 2)
        {
            lists[k++] = fun(lists[i], lists[i + 1]);
        }
        listsSize /= 2;
    }
    return lists[0];
}

//˫ָ��
struct ListNode* fun(struct ListNode* head1, struct ListNode* head2)
{
    if (!head1 && !head2)
        return NULL;
    struct ListNode* p = head1, * ptr = p;
    if (head1->val > head2->val)
    {
        p = head2;
        ptr = p;
        head2 = head2->next;
    }
    else
        head1 = head1->next;
    while (head1 && head2)
    {
        if (head1->val < head2->val)
        {
            p->next = head1;
            head1 = head1->next;
        }
        else
        {
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }
    if (head1)
        p->next = head1;
    if (head2)
        p->next = head2;
    return ptr;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0)
    {
        return NULL;
    }
    int start = 0, end = listsSize - 1;
    while (start < end)
    {
        while (start < end && !lists[start])
            start++;
        while (start < end && !lists[end])
            end--;
        if (start < end)
            lists[start] = fun(lists[start], lists[end--]);
        else
            break;
    }
    return lists[start];
}