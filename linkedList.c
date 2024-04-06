#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node* insertFront(node* head,int ele);
node* insertLast(node* head,int ele);
void display(node *head);
void sortdisplay(node *head);
int ListLength(node *head);
node* deleteFront(node* head,int *pele);
node* deleteLast(node* head,int *pele);
node* freeList(node* head);

int main(){
	node *head=NULL;
	int choice;
	int ele;

	do{
		printf(">> 1.InsertFront 2.InserLast 3.Display 4.SortDisplay 5.DeleteFront 6.DeleteLast 7.ListLength\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("Enter an integer\n");
					scanf("%d",&ele);
					head=insertFront(head,ele);
					break;
			case 2:printf("Enter an integer\n");
					scanf("%d",&ele);
					head=insertLast(head,ele);
					break;
			case 3:display(head);
					break;
			case 4:sortdisplay(head);
					break;
			case 5: if(head!=NULL){
						head=deleteFront(head,&ele);
						printf("Deleted element is %d\n",ele);
					}
					else
						printf("List is already empty\n");
					break;
			case 6: if(head!=NULL){
						head=deleteLast(head,&ele);
						printf("Deleted element is %d\n",ele);
					}
					else
						printf("List is already empty\n");
					break;
			case 7: printf("The length of the List is: %d\n", ListLength(head));
		}
	}while(choice<8 && choice>0);

	head=freeList(head);
}

node *createnode(int ele){
	node* newnode=malloc(sizeof(struct node));
	newnode->data=ele;
	newnode->next=NULL;
	return newnode;
}

node* insertFront(node* head,int ele){
	node* newnode=createnode(ele);
	newnode->next=head;
	head=newnode;
	return head;
}

node* insertLast(node* head,int ele){
	node* newnode=createnode(ele);
	if(head==NULL){
		head=newnode;
	}
	else{
		node* p=head;
		while(p->next!=NULL)
			p=p->next;
		p->next=newnode;
	}
	return head;
}

void display(node *head){
	if(head==NULL)
		printf("Empty List\n");
	else{
		node *p=head;
		while(p!=NULL){
			printf("%d ",p->data);
			p=p->next;
		}
	}
}

void sortdisplay(node *head){
	int x = ListLength(head);
	int arr[x];
	int i=0;
	if(head==NULL)
		printf("Empty List\n");
	else{
		node *p=head;
		while(p!=NULL){
			arr[i]=p->data;
			i++;
			p=p->next;
		}
	}
	for(int j=0; j<i; j++){
		for(int k=0; k<i; k++){
			if(arr[j]<arr[k]){
				int temp = arr[j];
				arr[j]=arr[k];
				arr[k] = temp;
			}
		}
	}
	for(int j=0; j<i; j++){
		printf("%d ",arr[j]);
	}
}

node* deleteFront(node* head,int *pele){
	node *p=head;
	*pele=head->data;
	head=head->next;
	free(p);
	return head;
}

node* deleteLast(node* head,int *pele){
	if(head->next==NULL){
		*pele=head->data;
		free(head);
		head=NULL;
	}
	else{
		node* p=head;
		node *q=NULL;
		while(p->next!=NULL){
			q=p;
			p=p->next;
		}
		*pele=p->data;
		q->next=NULL;
		free(p);
	}
	return head;
}

node* freeList(node* head){
	node *p=head;
	while(head!=NULL){
		head=head->next;
		// printf("Freeing %d\n",p->data);
		free(p);
		p=head;
	}
	return head;
}

int ListLength(node *head){
	if(head==NULL)
		return 0;
	return 1+ListLength(head->next);
}