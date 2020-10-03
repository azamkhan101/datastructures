#include "cll.h"
void position_insert(List* cll, int data, int pos)
{	Node *p=create_node(data);
	Node* temp;
	temp=cll->head;
	
	if(pos==0)
	{
		if(cll->head==NULL)
		{	
			cll->head=p;
			p->next=cll->head;
			cll->length++;
		
		}
		
		else
		{
			while(temp->next!=cll->head)
			{
				temp=temp->next;
			}
			
			p->next=cll->head;
			temp->next=p;
			cll->head=p;
			cll->length++;
		
		}
			
		}
		
		else if(pos>0 && pos<cll->length)
		{	int count=0;
			int position=pos-1;
			while(count<position)
			{
				temp=temp->next;
				count++;
			}
			p->next=temp->next;
			temp->next=p;
			
			cll->length++;
		}
		
		else if(pos==cll->length)
		{
			while(temp->next!=cll->head)
			{
				temp=temp->next;
			}
			temp->next=p;
			p->next=cll->head;
			cll->length++;
		
		}
	
	
	}	
	

	
	


void position_delete(List* cll, int pos)
{
	Node* temp;
	Node* p;
	temp=cll->head;
	
	if(pos==0)
	{
		if(temp->next==cll->head)
			{
				cll->head=NULL;
				free(temp);
			}
		else
		{
			cll->head=cll->head->next;
			free(temp);
		}
		
		cll->length--;
	
	}
	
	else
	
	{
		for(int i=1;i<pos;i++)
			{
			temp=temp->next;
			}
			
		if(temp->next->next=cll->head)
		{	p=temp->next;
			temp->next=cll->head;
			free(p);
			cll->length--;
		}
		
		else
		{
			p=temp->next;
			temp->next=temp->next->next;
			free(p);
			cll->length--;
		
		}
	}
}

int josephus(List* cll, int k)
{
	Node* temp;
	Node* prev;
	prev=cll->head;
	temp=prev->next;
	for(int i=0;i<k;i++)
	{
		temp=temp->next;
		prev=prev->next;
	}
	while(cll->length>1){
		prev->next=temp->next;
		free(temp);
		temp=prev->next;
		prev=prev->next;
		temp=temp->next;
		cll->length--;		
	}
    cll->head=temp;
	return temp->data;
}
