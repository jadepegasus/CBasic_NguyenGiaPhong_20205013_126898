/*
•Create a singly linked list to store a list of phone address.
•Write a function to insert to a list a new element just after the current element and use it to add node to the list
•Write a function for traversing the list to print out all information stored.
•Write a function for the removal of a node in the list.   
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct information
{
	char name[30];
	char number[30];
	char email[50];
}information;

typedef struct addressList
{
	information data;
	struct addressList *next;
} node;
/*chèn node ngay sau node cur*/
node* insert_after(node *cur,node *head,information X){
    node *new;
    new=(node*)malloc(sizeof(node));
    new->data=X;new->next=NULL;
    if(head==NULL){
        head=new;
        cur=new;
        return head;
    }
    else{
        cur->next=new->next;
        cur->next=new;
        cur=new;
        return cur;
    }
}
/*chèn node đằng trước node cur*/
node* insert_before(node *cur,node *head,information X){
    node *new;
    new=(node*)malloc(sizeof(node));
    new->data=X;new->next=NULL;
    if(head==NULL){
        head=new;
        cur=new;
        return head;
    }
    else{
        node* prev;
        prev=head;
        while(prev->next!=cur){
            prev=prev->next;
        }
        new->next=cur;
        prev->next=new;
        cur=new;
        return cur;
    }
}
/*duyệt và in ra tất cả các node*/
void traversing(node *head){
    node* new;
    new=head;
    while(new!=NULL){
        printf("%s-%s-%s\n",new->data.name,new->data.number,new->data.email);
        new=new->next;
    }
}
/* xóa node tại vị trí n*/
void delete_in_n(node * head,int n){
    int i=0;
    node *cur;
    cur=head;
    while(i!=n){
        i++;
        cur=cur->next;
    }
    node *new;
    new=cur->next;
    cur->next=new->next;
    free(new);
}
/* giải phóng tất cả các node trong list*/
void free_all_list(node* head){
    node* new;
    while(head!=NULL){
         new=head;
        head=head->next;
        free(new);
    }
}
/* đảo ngược list*/
node* reverse(node* head){
    node* cur,*prev;
    cur=prev=NULL;
    while(head!=NULL){
        cur=head;
        head=head->next;
        cur->next=prev;
        prev=cur;
    }
    return cur;
}
int main()
{
    int n;
    node *head,*cur;
    head=NULL;
    cur=NULL;
    information X;
    int i=1;
    printf("Nhap so nguoi co trong danh ba: ");scanf("%d",&n);
    printf("Nhap danh sach nguoi thu %d\n",i);
    printf("Name: ");fflush(stdin);gets(X.name);
    printf("Number: ");fflush(stdin);gets(X.number);
    printf("Email: ");fflush(stdin);gets(X.email);
    head=insert_after(cur,head,X);
    cur=head;
    for(i=2;i<=n;i++){
        printf("Nhap danh sach nguoi thu %d\n",i);
        printf("Name: ");fflush(stdin);gets(X.name);
        printf("Number: ");fflush(stdin);gets(X.number);
        printf("Email: ");fflush(stdin);gets(X.email);
        cur=insert_after(cur,head,X);
    }
    printf("\n");
    int k,j;
    do{
        printf("1,insert to a list a new element just after the current element \n");
        printf("2,Write a function for traversing the list to print out all information stored.\n");
        printf("3, removal of a node in the list\n");
        printf("4, dao nguoc list\n");
        printf("5, giai phong toan bo list\n");
        printf("6,thoat ra \n");
        printf("chon chuc nang: "); 
        fflush(stdin);
        scanf("%d",&k);
        if(k==1){
            printf("nhap thong tin danh ba muon nhap vao \n");
            printf("Name: ");fflush(stdin);gets(X.name);
            printf("Number: ");fflush(stdin);gets(X.number);
            printf("Email: ");fflush(stdin);gets(X.email);
            insert_after(cur,head, X);
            continue;
        }
        if(k==2){
           traversing(head);
            continue;        
        }
        if(k==3){
            printf("Vi tri can xoa: ");
            scanf("%d",&j);
            delete_in_n(head,j);
            continue;
        }
         if(k==4){
          traversing(reverse(head));

        continue;
        }
        if(k==5){
            free_all_list(head);
            continue;
        }
        if(k==6){
            break;
        }
    }while(k!=6);
	return 0;
}
