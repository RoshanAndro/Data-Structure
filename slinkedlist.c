#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node * next;
 };
 void main()
 {
 struct node *start = (struct node * )0;
 struct node *insert  (struct node *,int);
 struct node *delete  (struct node * );
 void display(struct node*);
 int opt,data;
 do
 {
 printf("\n1.Insert\n");
 printf("\n2.Delete\n");
 printf("\n3.Display\n");
 printf("\n4.Exit\n");
 printf("\nYour Option : ");
 scanf("%d",&opt);
 switch(opt)
 {
 case 1: printf("\nEnter the data : ");
         scanf("%d",&data);
         start = insert(start,data);
         break;
 case 2: start = delete(start);
         break;
 case 3: display(start);
         break;
 case 4: exit(0);
 default : 
 	printf("\nEnter the valid Choice : ");
 	break;
 }
 }
 while(1);
 return ;
 }
 struct node* insert(struct node* s,int item)
 {
 struct node * t = (struct node *)malloc(sizeof(struct node));;
 t ->data = item;
 t ->next = s;
 return t;
 }
 struct node* delete(struct node * s)
 {
 struct node * t = s;
 if(s!=(struct node *)0){
 printf("\n[%d] deleted\n", t->data);
 s = s->next;
 free(t);
 }
 else {
    printf("\nEmpty list\n");
 }
 return s;
 }
 
 void display(struct node* s)
 {
 if (s == (struct node*)0) {
        printf("\nList is empty.\n");
        return;
  }
 printf("\nList elements: ");
 while(s !=(struct node *)0){
 printf("%d ", s->data);
 s = s ->next;
 }
 printf("\n");
 }
