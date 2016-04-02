/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

int length_of_CLL(struct node **head)
{
	struct node *temp = *head;
	int i = temp->data,count=1;
	temp = temp->next;
	while (i<temp->data)
	{
		count++;
		i = temp->data;
		temp = temp->next;
	}
	return count;
}

int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	int flag;
	if((head1 == NULL && head2 == NULL) || (*head1 == NULL && *head2 == NULL))
		return -1;
	if (head1 == NULL || *head1 == NULL)
	{
		head1 = head2;
		return(length_of_CLL(head2));
	}
	if (head2 == NULL || *head2 == NULL)
	{
		return(length_of_CLL(head1));
	}
	struct node *temp1 = *head1;
	struct node *temp2 = *head2;
	struct node *prev = NULL;
	struct node *result,*start,*temp;
	if (temp1->data < temp2->data)
	{
		result = temp1;
		result->next = temp1;
		temp1 = temp1->next;
		start = result;
	}
	else
	{
		result = temp2;
		result->next = temp2;
		temp2 = temp2->next;
		start = result;
	}
	while ((temp1->next->data > temp1->data) &&  (temp2->next->data > temp2->data))
	{
		if (temp1->data < temp2->data)
		{

			temp = result->next;
			result->next = temp1;
			result = result->next;
			result->next = temp;
			temp1 = temp1->next;
		}
		else
		{
			temp = result->next;
			result->next = temp2;
			result = result->next;
			result->next = temp;
			temp2 = temp2->next;
		}
	}
	
	if ((temp1->next->data < temp1->data) && (temp2->next->data < temp2->data))
	{
		if (temp1->data < temp2->data)
		{
			temp = result->next;
			result->next = temp1;
			result = result->next;
			result->next = temp2;
			result = result->next;
			result->next = temp;
		}
		else
		{
			temp = result->next;
			result->next = temp2;
			result = result->next;
			result->next = temp1;
			result = result->next;
			result->next = temp;
		}
	}
	else if (temp1->next->data < temp1->data)
		{
			while (temp1->data > temp2->data)
			{
				temp = result->next;
				result->next = temp2;
				result = result->next;
				result->next = temp;
				temp2 = temp2->next;
			}
			//adding last node in list 1
			temp = result->next;
			result->next = temp1;
			result = result->next;
			result->next = temp;
			temp1 = temp1->next; 
			while (temp2->next->data > temp2->data)
			{
				temp = result->next;
				result->next = temp2;
				result = result->next;
				result->next = temp;
				temp2 = temp2->next;
			}
			//adding last element in list 2
			temp = result->next;
			result->next = temp2;
			result = result->next;
			result->next = temp;
			temp2 = temp2->next;
		}
	else
	{
		while (temp2->data > temp1->data)
		{
			struct node *temp = result->next;
			result->next = temp1;
			result = result->next;
			result->next = temp;
			temp1 = temp1->next;
		}
		//adding last node in list 2
		struct node *temp = result->next;
		result->next = temp2;
		result = result->next;
		result->next = temp;
		temp2 = temp1->next;
		while (temp1->next->data > temp1->data)
		{
			temp = result->next;
			result->next = temp1;
			result = result->next;
			result->next = temp;
			temp1 = temp1->next;
		}
		//adding last element in list 1
		temp = result->next;
		result->next = temp1;
		result = result->next;
		result->next = temp;
		temp1 = temp1->next;
	}
	*head1 = start;
	return length_of_CLL(head1);
	}
