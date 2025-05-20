#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
    struct node * prev;
};
// array struct user
struct node * createNode(int data){
    struct node * nn= (struct node *)malloc(sizeof(struct node));
    nn->data=data;
    nn->prev=NULL;
    nn->next=NULL;
    return nn;
}
struct node * InsertAtFirst(struct node * head,int data){
    struct node * nn=createNode(data);
    if(head==NULL) return nn;
    else{
      
        nn->next=head;
        head->prev=nn;
        // head=nn;
        // return head;
        return nn;
    }

}
struct node * InsertAtLast(struct node * head,int data){
    struct node * nn=createNode(data);
    if(head==NULL){
        return nn;
    }
    else{
        struct node * temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nn;
        nn->prev=temp;
    }
    return head;

}
struct node * InsertAtSpecificPos(struct node * head,int data,int pos){
    
    if(head==NULL && pos>1) return NULL;
    else if(pos==1) return InsertAtFirst(head,data);
    else{
      int count=0;
      struct node * temp=head;
     
      while(temp!=NULL){
          
          count++;
          if(count==pos){
          struct node * nn= createNode(data);
nn->next=temp;
nn->prev=temp->next->prev;
temp->prev->next=nn;
temp->prev=nn;


            //   nn->next=temp;
            //   nn->prev=temp->prev;
            //  nn->next->prev=nn;
            //  nn->prev->next=nn;
             return head;
          }
     
            temp=temp->next;
}
 if(count+1==pos){
              return InsertAtLast(head,data);
          }
}
}
       
  
struct node * deleteAtFirst(struct node * head){
    if(head==NULL) return NULL;
    else if(head->next==NULL) return NULL;// only one node so head->next==null (Dangling pointer)
    else{
        head->next->prev=NULL;
        return head->next;
    }
}
struct node * deleteAtLast(struct node * head){
    if(head==NULL) return NULL;
    else if(head->next==NULL) return NULL;// only one node so head->next==null (Dangling pointer)
    else{
        struct node * temp=head;
        while(temp->next!=NULL){
            // temp->next->prev=temp;
           temp=temp->next;
        }
        temp->prev->next=NULL;
        return head;
    }
}

struct node * DeleteAtSpecificPos(struct node * head,int pos){
    if(head==NULL && pos>1) return NULL;
    else if(pos==1) return deleteAtFirst(head);
    else{
        int count=0;
        struct node * temp=head;
        while(temp!=NULL){
            count++;
            if(count==pos){
                if(temp->next==NULL){
                    temp->prev->next=NULL;
                }
                else{
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                }
             return head;
            }
 temp=temp->next;
       }
           
           
        }
       
       
    }

void Update(struct node * head,int data,int update){
    if(head==NULL) printf("No list");
    else{
        struct node * temp=head;
        while(temp!=NULL){
            if(temp->data==data){
                temp->data=update;
            }
            // temp->prev=temp;
            temp=temp->next;
        }
    }
}

void display(struct node * head){
    if(head==NULL) {
        printf("There is no list\n");
    }
    else{
    struct node * temp=head;
    while(temp!=NULL){
      printf("%d->",temp->data) ;
      temp=temp->next;
    }
    printf("NULL\n");
}
}
int main(){
    struct node * head=NULL;
    int data,choice,pos,update;
    do{
        printf("\n1)Insert at first\n2)Insert at last\n3)Insert at specific position\n4)Delete at first\n5)Delete at last\n6)Delete at specific position\n7)Update the value\nEnter the choice: ");
        scanf("%d",&choice);

        switch(choice){
        case 1:
        printf("Enter the data: ");
        scanf("%d",&data);
        head=InsertAtFirst(head,data);
        display(head);
        break;
   
        case 2:
        printf("Enter the data: ");
        scanf("%d",&data);
        head=InsertAtLast(head,data);
        display(head);
        break;
        
        case 3:
        printf("Enter the data: ");
        scanf("%d",&data);
        printf("Enter the position: ");
        scanf("%d",&pos);
        head=InsertAtSpecificPos(head,data,pos);
        display(head);
        break;
        
         case 4:
         head=deleteAtFirst(head);
         display(head);
         break;
         
         case 5:
         head=deleteAtLast(head);
         display(head);
         break;
         
         case 6:
         printf("Enter the position to be deleted: ");
         scanf("%d",&pos);
         head=DeleteAtSpecificPos(head,pos);
         display(head);
         break;
         
         case 7:
         printf("Enter the data to be updated: ");
         scanf("%d",&data);
         printf("Enter the updated data: ");
         scanf("%d",&update);
         Update(head,data,update);
         display(head);
         break;
         

    }
}while(choice>=1 && choice<=7);


    return 0;
} 