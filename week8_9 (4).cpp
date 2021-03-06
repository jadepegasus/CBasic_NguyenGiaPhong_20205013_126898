#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct phoneaddress{
  char name[20];
  char tel[11];
  char email[25];
};
typedef struct phoneaddress phoneaddress;
struct node{
  phoneaddress data;
  struct node *left;
  struct node *right;
};
typedef struct node node;
node *insertNode(node *t, phoneaddress x){
	if(t == NULL){
		node *temp = (node*)malloc(sizeof(node));
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}else{
		if(strcmp(x.email,t->data.email)<0){
			t->left = insertNode(t->left,x);
		}
		else{
			t->right = insertNode(t->right, x);
		}
	}
}
node *searchNode(node *t,phoneaddress x){
  if(t == NULL) return NULL;
  else if(strcmp(x.email,t->data.email)==0) return t;
  else if(strcmp(x.email,t->data.email)<0) return searchNode(t->left,x);
  else return searchNode(t->right,x);
}
void printTree(node *t){
  if(t != NULL){
    printTree(t->left);
    printf("%-20s%-20s%-20s\n",t->data.name,t->data.email,t->data.tel);
    printTree(t->right);
  }
}
int main(){
  FILE *f;
  f = fopen("week_8/phonebook.txt","r");
  node *t = NULL;
  phoneaddress x;
  while(!feof(f)){
    fscanf(f,"%s\t",x.name);
    fscanf(f,"%s\t",x.email);
    fscanf(f,"%s\n",x.tel);
    t = insertNode(t,x);
  }
  fclose(f);
  printTree(t);
}