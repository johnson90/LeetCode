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
	struct ListNode * Merge(struct ListNode *left, struct ListNode *right)
	{
		struct ListNode *p = left;
		struct ListNode *q = right;
		struct ListNode *t;
		struct ListNode *k;
		
		if ( p->val < q->val )
		{
			t = p;
			p = p->next;
			k = t;
		}
		else
		{
			t = q;
			q = q->next;
			k = t;
		}

		while(p != NULL && q != NULL)
		{
			if ( p->val < q->val )
			{
				k->next = p;
				p = p->next;
				k = k->next;
			}
			else
			{
				k->next = q;
				q = q->next;
				k = k->next;
			}
		}

		while( p != NULL)
		{
				k->next = p;
				p = p->next;
				k = k->next;
		}

		while( q != NULL)
		{
				k->next = q;
				q = q->next;
				k = k->next;
		}

		return t;
	}

	struct ListNode * MergeSort(struct ListNode *head)
	{
		struct ListNode *p = head;
		int len = 0;
		while( p != NULL )
		{
			p = p->next;
			len++;
		}

		if(len == 1)
			return head;

		struct ListNode *mid = head;
		for(int i = 0; i < len/2-1; ++i)
			mid = mid->next;

		struct ListNode *left = head;
		struct ListNode *right = mid->next;

		mid->next = NULL;

		left = MergeSort(left);
		right = MergeSort(right);

		left = Merge(left, right);
		return left;
	}
    ListNode *sortList(ListNode *head) 
	{
		if (head == NULL || head->next == NULL)
			return head;
		head = MergeSort(head);
		return head;     
    }
};