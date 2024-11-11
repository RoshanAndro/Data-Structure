#include<stdio.h>
#include<stdlib.h>
 
 struct node {
    int data;
    struct node*left,*right;
 };
 
 struct node* insert(struct node *,int);
 struct node* delete(struct node *,int);
 struct node* search(struct node *,int);
 void display(struct node*);
 
 void main() {
 	struct node* start =(struct node*)0;
 	int opt,data;
 	
 do{
     printf("\n1.Insert\n");
     printf("\n2.Delete\n");
     printf("\n3.Search\n");
     printf("\n4.Display\n");
     printf("\n5.Exit\n");
     printf("\nYour Option : ");
     scanf("%d",&opt);
 switch(opt) {
    case 1: printf("\nEnter the data : ");
         scanf("%d",&data);
         start = insert(start,data);
         break;
    case 2: 
    	   if (start == (struct node*)0) {
                    printf("\nList is Empty\n");
                } else {
                    printf("\nEnter data to delete: ");
                    scanf("%d", &data);
                    start = delete(start, data);
                }
                break;
    case 3: 
           if (start == 0) {
                    printf("\nList is Empty\n");
                } else {
                    printf("\nEnter data to Search: ");
                    scanf("%d", &data);
                    struct node* result = search(start, data);
                    if (result != 0) {
                        printf("\nItem Found: [%d]\n", result->data);
                    } else {
                        printf("\nItem not Found\n");
                    }
                }
                break;
    case 4: 
           display(start);
           break;
           
    case 5:
           exit(0);
 default : 
 	printf("\nEnter the valid Choice : \n");
 	break;
 
 }
 }
 while(1);
 }
 //Insert
struct node* insert(struct node* s,int item){
      struct node* t = (struct node*)malloc(sizeof(struct node));
      t -> data = item;
      t -> right = s;
      t -> left = (struct node*)0;
      if(s !=(struct node*)0)
      {
       	   s -> left = t;
       }
       return t;
       }
 //Delete
 
struct node* delete(struct node* s,int data){
 	struct node * t = search(s,data);
 	if(t !=(struct node*)0)
 	{
 	 printf("\n[%d] is deleted\n ", t ->data);
 	 if(t->left ==(struct node*)0 && t->right ==(struct node*)0)
 	 {
 	    s = (struct node*)0;
 	  }
 	 else if(t->left == (struct node*)0)
 	   {
 	     s = t->right;
 	     if(s != (struct node*)0)
 	     {
 	        s->left = (struct node*)0;
 	      }
 	  }
 	  else if(t->right ==(struct node*)0)
 	  {// Deleting the last node
 	     t->left->right =(struct node*)0;
 	   }
 	  else // Delete a node in the middle
 	   {
 	   t->left->right = t->right;
 	   t->right->left = t->left;
 	   }
 	   free(t);
 	  }
 	  else {
 	         printf("\nItem Not Found\n");
 	       }
 	   return s;
 	 }
 	 
 // Search
struct node* search(struct node * s,int item) {
   	struct node* t = s;
   	while(t !=(struct node*)0 && t->data != item) {
   	 	t= t->right;
   	}
   	return t;
  }
  
 // Display
 
  void display(struct node* s) {
        if(s ==(struct node*)0) {
           printf("\nList is Empty\n");
           return;
        }
        while (s != (struct node*)0){
               printf(" \n[%d]\t", s->data);
               s = s->right;
               }
             printf("\n");
        }
 	  
