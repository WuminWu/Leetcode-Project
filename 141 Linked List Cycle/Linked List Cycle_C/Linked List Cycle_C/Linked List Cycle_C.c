// Linked List Cycle_C.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <stdbool.h>
#include <stdlib.h>

struct ListNode 
{
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head) 
{
	struct ListNode *fast = head;
	struct ListNode *slow = head;

	if (head == NULL || head->next == NULL) {
		printf("ERROR: pointer of struct is NULL\n");
		return false;
	}
	
	while (fast!=NULL && slow!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	printf("fast or slow is NULL\n");
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nodeNum = 4;
	struct ListNode *node;
	node = (struct ListNode*) malloc(nodeNum * sizeof(struct ListNode));
	for (int i = 0; i < nodeNum; i++)
	{
		(node + i)->val = i;
		(node + i)->next = NULL;
	}
// has no cycle
	(node + 0)->next = (node + 1);
	(node + 1)->next = (node + 2);
	(node + 2)->next = (node + 3);
	(node + 3)->next = NULL;
	for (int i = 0; i < nodeNum; i++)
		printf("array position = %x\n", (node + i)->next);
	bool flag = hasCycle(node);
	printf(flag ? "true" : "false\n");
// has cycle
	(node + 0)->next = (node + 1);
	(node + 1)->next = (node + 2);
	(node + 2)->next = (node + 3);
	(node + 3)->next = (node + 1);;
	for (int i = 0; i < nodeNum; i++)
		printf("array position = %x\n", (node + i)->next);
	bool flag2 = hasCycle(node);
	printf(flag2 ? "true\n" : "false\n");
	system("pause");
	return 0;
}

