#include <stdio.h>
#include <stdlib.h>
typedef struct linear_linked_list {
  int data;
  struct linear_linked_list *next;
} node;
node *head = NULL;

void insert_at_start() {
  node *new;
  new = (node *)malloc(sizeof(node));
  scanf("%d", &new->data);
  new->next = NULL;
  if (head == NULL) {
	head = new;
  } else {
	new->next = head;
	head = new;
  }
}
void insert_at_last(){
	node *new,*temp;
	new=(node*)malloc(sizeof(node));
	scanf("%d",&new->data);
	new->next=NULL;
	if(head==NULL){
		head=new;
	}
	else{
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=new;
	}
}
void insert_at_given_position(int pos)
{
	int count=0;
	node *new,*temp=head;
	new=(node*)malloc(sizeof(node));
	scanf("%d",&new->data);
	new->next=NULL;
	if(head==NULL)
	{
		if(pos==1)
			head=new;
	    else
		    printf("Invalid position");
	}
	else
	{
		if(pos==1)
		{
			new->next=head;
			head=new;
		}
		else
		{
			while(count!=pos-1 && temp->next!=NULL)
			{
				count++;
				temp=temp->next;
			}
			if(count==pos-1)
			{
				new->next=temp->next;
				temp->next=new;				
			}
			else
				printf("Not Possible");
		}
	}
}
void delete_at_start()
{
	node *temp;
	if(head==NULL)
		printf("List is empty");
	else
	{
		temp=head;
		head=head->next;
		free(temp);
	}
}
void delete_at_last()
{
	node *temp,*prev;
	if(head==NULL)
		printf("List is empty");
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=NULL;
		free(temp);
	}
}
void delete_at_given_position(int pos)
{
	int count=0;
	node *temp,*prev;
	if(head==NULL)
		printf("List is empty");
	else
	{
		temp=head;
		while(count!=pos-1 && temp->next!=NULL)
		{
			count++;
			prev=temp;
			temp=temp->next;
		}
		if(count==pos-1)
		{
			prev->next=temp->next;
			free(temp);
		}
		else
			printf("Not Possible");
	}
}
void delete_a_given_node(int data)
{
	node *temp,*prev;
	if(head==NULL)
		printf("List is empty");
	else
	{
		temp=head;
		while(temp->data!=data && temp->next!=NULL)
			{
				prev=temp;
				temp=temp->next;
			}
		if(temp->data==data)
		{
			prev->next=temp->next;
			free(temp);
		}			
		else
			printf("Not Possible");

	}
}
void delete_after_given_node(int data)
{
	node *temp,*prev;
	if(head==NULL)
		printf("List is empty");
	else
	{
		temp=head;
		while(temp->data!=data && temp->next!=NULL)
			{
				prev=temp;
				temp=temp->next;
			}
		if(temp->data==data)
		{
			prev->next=temp->next;
			free(temp);
		}
		else
			printf("Not Possible");
	}
}
void delete_before_given_node(int data)
{
	node *temp,*prev;
	if(head==NULL)
		printf("List is empty");
	else
	{
		temp=head;
		while(temp->next->data!=data && temp->next!=NULL)
			{
				prev=temp;
				temp=temp->next;
			}
		if(temp->next->data==data)
			{
				prev->next=temp->next;
				free(temp);
			}
		else
			printf("Not Possible");
	}
}
void traverse()
{
	node *temp;
	if(head==NULL)
		printf("List is empty");
	else
	{
		temp=head;
		while(temp!=NULL)
			{
				printf("%d ",temp->data);
				temp=temp->next;
			}
	}
}
void reverse()
{
	node *temp,*prev,*next;
	if(head==NULL)
		printf("List is empty");
	else
	{
		temp=head;
		prev=NULL;
		while(temp!=NULL)
		{
			next=temp->next;
			temp->next=prev;
			prev=temp;
			temp=next;
		}
		head=prev;
		//traverse();
	}
}
void print_reverse(node *temp)
{
	if(temp!=NULL)
	{
		print_reverse(temp->next);
		printf("%d ",temp->data);
	}
}
void search(int data)
{
	node *temp;
	int count=0;
	if(head==NULL)
		printf("List is empty");
	else
	{
		temp=head;
		while(temp!=NULL)
			{
				count++;
				if(temp->data==data)
					printf("Element found at %d position",count);
				temp=temp->next;
			}
		if(temp==NULL)
			printf("Element not found");
	}
	
}
void merge_linkedlist_after_a_given_node(node *temp1,node *head2,node *temp2)
{
	temp2=temp1->next;
	temp1->next=head2;
}
void bubble_sort_linked_list(node *head)
{
	node *temp,*prev;
	int swapped;
	if(head==NULL)
		printf("List is empty");
	else
	{
		do
			{
				swapped=0;
				temp=head;
				while(temp->next!=NULL)
					{
						if(temp->data>temp->next->data)
							{
								swap(temp,temp->next);
								swapped=1;
							}
						temp=temp->next;		
					}
			}while(swapped);
	}
}