/*The list is sorted in descending order of student's grades.
-Program provide the functionality of:
        -Insert new student (when you insert a new student into this list, first find the right position)
        -searching a student by ID: return to a pointer 
        -delete a student with a given ID
*/
/* - function : thay đổi điểm của một ID (điểm được sắp xếp đúng)*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct 
{
    char id[30];
    char name[30];
    int grade;
}student;
typedef struct student_t
{
    student data;
    struct student_t *next;
}node;
/* -Insert new student (when you insert a new student into this list, first find the right position) */
node* head;
node* add_student(node* head,student A){
    node* new;
    new=(node*)malloc(sizeof(node));
    new->data=A;
    new->next=NULL;
    if(head==NULL){
        head=new;
        return head;
    }
    if(A.grade>head->data.grade){
        new->next=head;
        head=new;
        return head;
    }
    else{
        node* cur;
        cur=head;
        while(cur->data.grade>new->data.grade){
            cur=cur->next;
        }
        node* prev;
        prev=head;
        while(prev->next!=cur)prev=prev->next;
        new->next=cur;
        prev->next=new;
        return head;
    }
}
/* find a student whose id matches the given id number */
node * find_id(node* head,char a[30]){
    node* cur;
    cur=head;
    if(strcmp(a,head->data.id)==0){
        printf("tim thay\n");
        printf("%s - %s - %d \n",head->data.name,head->data.id,head->data.grade);
        return cur;
    }
    else{
        for(;cur!=NULL;cur=cur->next){
        if(strcmp(a,cur->data.id)==0){
            printf("Tim thay \n");
            printf("%s - %s - %d \n",cur->data.name,cur->data.id,cur->data.grade);
            return cur;
        }
    }
    }
    printf("Khong tim thay \n");
    return NULL;
}
    /*delete a student with a given ID */
node* delete_id(node* head,char a[30]){
    node* cur;
    cur=head;
    if(head==NULL){
        return head;
    }
    if(strcmp(head->data.id,a)==0){
        node* cur;
        cur=head;
        head=head->next;
        free(cur);
        return head;
    }
    else{
        for(;cur!=NULL;cur=cur->next){
        if(strcmp(a,cur->data.id)==0){
            printf("Xoa thanh cong \n");
            node* prev;
            prev=head;
            while(prev->next!=cur)prev=prev->next;
            prev->next=cur->next;
            free(cur);
            return head;
        }
    }
    printf("Khong tim thay \n");
    return head;}
}
/*thay doi diem của mot ID (diem duoc sap xep dung)*/
node* change_grade(node* head,char id[30],int new_grade){
    node* cur;
    cur=find_id(head,id);
    if(cur==NULL)return head;
    else{
    node* new;
    new=(node*)malloc(sizeof(node));
    strcpy(new->data.id,id);
    strcpy(new->data.name,cur->data.name);
    new->data.grade=new_grade;
    delete_id(head,id);
    head=add_student(head,new->data);
    return head;}
}
    /*duyệt tất cả học sinh*/
    void traversing(node *head){
    node* new;
    new=head;
    while(new!=NULL){
        printf("%s-%s-%d\n",new->data.id,new->data.name,new->data.grade);
        new=new->next;
    }
}
    int main()
    {
        int n;
    node *cur;
    head=NULL;
   student X;  
    printf("Nhap so luong nguoi: ");
   scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("Nhap danh sach nguoi thu %d\n",i);
        printf("ID: ");fflush(stdin);gets(X.id);
        printf("Name: ");fflush(stdin);gets(X.name);
        printf("Grade: ");fflush(stdin);scanf("%d",&X.grade);
        head = add_student(head,X);
    }
    printf("\n");
    int k,j;
    do{
        printf("1,Insert new student (when you insert a new student into this list, first find the right position) \n");
        printf("2,searching a student by ID: return to a pointer .\n");
        printf("3, delete a student with a given ID\n");
        printf("4, thay doi diem của mot ID (diem duoc sap xep dung)\n");
        printf("5. in danh sach\n");
        printf("6,thoat ra \n");
        printf("chon chuc nang: "); 
        fflush(stdin);
        scanf("%d",&k);
        if(k==1){
            printf("ID: ");fflush(stdin);gets(X.id);
            printf("Name: ");fflush(stdin);gets(X.name);
             printf("Grade: ");fflush(stdin);scanf("%d",&X.grade);
             head = add_student(head,X);
            break;
        }
        if(k==2){
            char a[30];
            printf("Nhap id can tim: "); fflush(stdin);gets(a);
            find_id(head,a);
            break;        
        }
        if(k==3){
        }
         if(k==4){

        break;
        }
        if(k==5){
            traversing(head);
            break;
        }
        if(k==6){
            break;
        }
    }while(k!=6);
	return 0;
    }