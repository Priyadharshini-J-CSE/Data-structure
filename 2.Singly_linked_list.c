#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node * create(int data){
    struct node * nn=(struct node * )malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    return nn;
    
}

struct node * InsertAtLast(struct node * head,int data){
    struct node * nn=create(data);
    if(head==NULL) return nn;
    else{
        struct node * temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nn;
        return head;
    }
}
struct node * InsertAtFirst(struct node * head,int data){
    struct node *nn=create(data);
    if(head==NULL) return nn;
    else{
        nn->next=head;
        return nn;
    }
    
}
struct node * InsertAtPos(struct node * head,int data,int pos){
    
   
    if(head==NULL){
        if(pos!=1){
            printf("Cannot be inserted..\n");
        }
        return NULL;
    } 
    else if(pos==1) return InsertAtFirst(head,data);
    else{
         int count=0;
      
        struct node * temp=head;
        struct node * prev=NULL;
       
      
        while(temp!=NULL){
            count++;
            if(count==pos){
                struct node * nn=create(data);
                nn->next=prev->next;
                prev->next=nn;
                return head;
                
            }
            prev=temp;
            temp=temp->next;
        }
        if((count+1)==pos){
            return InsertAtLast(head,data);
        }
        if((count+1)<pos) printf("Your position is greater than the number of node.\n");
         return head;
    }
   
    
}

void display(struct node * head){
    if(head==NULL) printf("List is empty\n");
    else{
        struct node * temp=head;
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("Null\n");
        
    }
}

struct node * DeleteAtFirst(struct node * head){
    if(head==NULL) return NULL;
    else{
        return head->next;
    }
}

struct node * DeleteAtLast(struct node * head){
    if (head==NULL) return NULL;
    else{
        struct node * temp=head;
        struct node * prev=NULL;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        return head;
    }
    
}
struct node * DeleteAtSpecificPos(struct node * head,int pos){
      int count=0;
    if(head==NULL && pos>0){
        return NULL;
    }
    
  else if(pos==1) return DeleteAtFirst(head);
  
    else{
        struct node *temp=head;
        struct node * prev=NULL;
        while(temp!=NULL){
            count++;
            if(count==pos){
                prev->next=temp->next;
                return head;
            }
            prev=temp;
            temp=temp->next;
        }
    }
    
}
void UpdateData(struct node * head,int data,int update){
    if(head==NULL) printf("List is empty\n");
    else{
        struct node* temp=head;
        int count=0,updation=0;
        while(temp!=NULL){
            count++;
            if(temp->data==data){
                temp->data=update;
                printf("The data is updated on the position : %d\n",count);
                updation++;
            }
            temp=temp->next;
        }
        if(updation==0) printf("Not updated\n");
        else printf("Succesfully updated!\n");
    }
    
}
struct node * Reverse(struct node *head){
    if (head==NULL) return NULL;
    else{
    struct node * prev=NULL;
    struct node * current=head;
    struct node * next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
}
//     if(head==NULL) return NULL;
//     else{
//         struct node * prev=NULL;
//         struct node * current=head;
//         struct node * next=NULL;
//         while(current->next!=NULL){
//             prev=current;
//             current=current->next;
//             current->next=prev;
//         }
//         current->next=head;
//         head->next=NULL;
//         return head;
//     }
//     return head;
// }
// struct node * Middle(struct node *head){
//     struct node * fast=head;
//     struct node * slow=head;
//     while(fast!=NULL && fast->next!=NULL){
//         fast=fast->next->next;
//         // if(fast->next==NULL){ return slow;}
//         slow=slow->next;
//     }
//     return slow;
// }
void middle(struct node * head){
     struct node * fast=head;
    struct node * slow=head;
    while(slow!=NULL && fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        // if(fast->next==NULL){ return slow;}
        slow=slow->next;
    }
    printf("%d \n",slow->data);
}

int main()
{
    struct node * head=NULL;
    int choice,data,pos,update;
    do{
    printf("1.Insert at last\n2.Insert at first\n3.Insert at specific position\n4.Delete at first\n5.Delete at last\n6.Delete at specific position\n7.Update the data\n8.Reverse the data\n9.Find the middle node value\nEnter the choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter the data to be inserted: ");
        scanf("%d",&data);
        head=InsertAtLast(head,data);
        display(head);
        break;
        case 2:
        printf("Enter the data to be inserted");
        scanf("%d",&data);
        head=InsertAtFirst(head,data);
        display(head);
        break;
        case 3:
         printf("Enter the data to be inserted");
        scanf("%d",&data);
         printf("Enter the position to be inserted");
        scanf("%d",&pos);
        head=InsertAtPos(head,data,pos);
        display(head);
        break;
        case 4:
        head=DeleteAtFirst(head);
        display(head);
        break;
        case 5:
        head=DeleteAtLast(head);
        display(head);
        break;
        case 6:
        printf("Enter the position to be deleted");
        scanf("%d",&pos);
        head=DeleteAtSpecificPos(head,pos);
        display(head);
        break;
        case 7:
        printf("Enter the data to be updated: ");
        scanf("%d",&data);
        printf("Enter the updated data: ");
        scanf("%d",&update);
        UpdateData(head,data,update);
        display(head);
        break;
        case 8:
        head=Reverse(head);
        display(head);
        break;
         case 9:
        //  struct node * middle=Middle(head);
        //  printf("Data of middle node: %d\n",middle->data);
        middle(head);
         break;
         
         
   
    }
    
    }while(choice>=1 && choice <=9);
    
    return 0;
}