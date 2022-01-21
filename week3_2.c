/* Chèn , xóa tại một vị trí cụ thể trong single linked list
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
/* chèn 1 node vào tại vị trí n*/
void insert_in_n(node * head, information X, int n){
    int i=0;
    node *new;
    new=(node*)malloc(sizeof(node));
    new->data=X;new->next=NULL;
    node *cur;
    cur=head;
    while(i!=n){
        i++;
        cur=cur->next;
    }
    new->next=cur->next;
    cur->next=new;
    cur=new;
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
/*duyệt và in ra tất cả các node*/
void traversing(node *head){
    node* new;
    new=head;
    while(new!=NULL){
        printf("%s-%s-%s\n",new->data.name,new->data.number,new->data.email);
        new=new->next;
    }
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
        printf("1,chen node tai vi tri n. \n");
        printf("2,duyet va in ra tat ca cac node");
        printf("3,xoa node tai vi tri n.\n");
        printf("4,thoat ra \n");
        printf("chon chuc nang: "); 
        fflush(stdin);
        scanf("%d",&k);
        if(k==1){
            printf("nhap thong tin danh ba muon nhap vao \n");
            printf("Name: ");fflush(stdin);gets(X.name);
            printf("Number: ");fflush(stdin);gets(X.number);
            printf("Email: ");fflush(stdin);gets(X.email);
            printf("Vi tri can xoa: ");
            scanf("%d",&j);
           insert_in_n(head,X,j);
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
            break;
        }
    }while(k!=4);
	return 0;
}
