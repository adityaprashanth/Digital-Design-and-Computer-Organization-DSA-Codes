#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int info;
    struct node* next;
};

struct node* insertFront(struct node* head, int ele);
struct node* insertAfter(struct node* head, int ele, int index);
struct node* insertLast(struct node* head, int ele);
struct node* deleteFront(struct node* head);
struct node* deleteLast(struct node* head);
struct node* deleteDuplicate(struct node* head);
void display(struct node* head);
struct node* freeList(struct node* head);

void main(){
    struct node* head = NULL;
    int choice;
    int info;
    int element;
    do{
        printf("<1> Insert Front <2> Insert End <3> Insert After \n<4> Delete Front <5> Delete End <6> Delete Duplicate\n<7> Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter the value: ");
					scanf("%d", &info);
					head = insertFront(head, info);
					break;
			case 2: printf("Enter the value: ");
					scanf("%d", &info);
					head = insertLast(head, info);
					break;
			case 3: printf("Enter the value and index: ");
					scanf("%d %d", &info, &element);
					head = insertAfter(head, info, element);
					break;
			case 4: head = deleteFront(head);
					break;
			case 5: head = deleteLast(head);
					break;
			case 6: head = deleteDuplicate(head);
					break;
			case 7: display(head);
					break;
        }
    }while(choice>0 && choice<8);
	head=freeList(head);
}

struct node* insertFront(struct node* head, int ele){
    struct node* temp = malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->info = ele;
    temp->next=head;
    if(head==NULL){
        return temp;
    }
    head->prev=temp;
    return temp;
}

struct node* insertLast(struct node* head, int ele){
    struct node* temp = malloc(sizeof(struct node));
    struct node* parser = head;
    if(head==NULL){
        temp->prev=NULL;
        temp->next=NULL;
        temp->info=ele;
        return temp;
    }
    while(parser->next!=NULL){
        parser=parser->next;
    }
    parser->next=temp;
    temp->prev=parser;
    temp->next=NULL;
    temp->info=ele;
    return head;
}

struct node* insertAfter(struct node* head, int ele, int index){
    struct node* temp = malloc(sizeof(struct node));
    struct node* parser = head;
    if(head==NULL){
        temp->prev=NULL;
        temp->next=NULL;
        temp->info=ele;
        return temp;
    }
    if(index==0){
        return insertFront(head, ele);
    }
    for(int i=0; i<index; i++){
        if(parser->next==NULL){
            parser->next=temp;
            temp->prev=parser;
            temp->info=ele;
            temp->next=NULL;
            return head;
        }
        parser=parser->next;
    }
    parser = parser->prev;
    struct node* current = parser->next;
    temp->info = ele;
    temp->next = current;
    temp->prev = parser;
    parser->next = temp;
    current->prev = temp;
    return head;
}

struct node* deleteFront(struct node* head){
    struct node* temp = head;
    if(head->next==NULL){
        head=head->next;
        return head;
    }
    head=head->next;
    head->prev=NULL;
    free(temp);
    return head;
}

struct node* deleteLast(struct node* head){
    struct node* parser = head;
    if(head->next==NULL){
        head=head->next;
        return head;
    }
    while(parser->next!=NULL){
        parser=parser->next;
    }
    struct node* temp = parser->prev;
    temp->next = NULL;
    free(parser);
    return head;
}

struct node* deleteDuplicate(struct node* head){
    struct node* parser = head;
    int val=0;
    while(parser->next){
        val=parser->info;
        struct node* post = parser->next;
        while(post){
            if(post->info==val){
                if(post->next==NULL){
                    struct node* lp = post->prev;
                    lp->next=NULL;
                    free(post);
                    post=NULL;
                    printf("deleting %d\n", val);
                    break;
                }
                struct node* lp = post->prev;
                struct node* rp = post->next;
                lp->next = rp;
                rp->prev = lp;
                free(post);
                post = lp;
            }
            post=post->next;
        }
        if(parser->next){
            parser=parser->next;
        }
    }
    return head;
}

void display(struct node* head){
    struct node* temp = head;
    while(temp){
        printf("%d, ", temp->info);
        temp=temp->next;
    }
    printf("\b\b  \n");
}

struct node* freeList(struct node* head){
    struct node* temp = head;
    while(head!=NULL){
        head=head->next;
        free(temp);
        temp=head;
    }
    return head;
}