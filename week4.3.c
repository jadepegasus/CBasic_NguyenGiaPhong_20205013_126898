#include <stdio.h>
#include <string.h>

typedef struct phonenumber{
	char data[80];
}phone;
enum {SUCCESS, FAIL,MAX_LEN=81};
phone list[100];
int first,last;

void makenull(){
	first=-1;
	last=-1;
}

int isempty(){
	return first==-1;	
}

int isfull(){
	return (last-first+1)==100;
}

void push(char *x){
	if(!isfull()){
		if(isempty()) first++;
		last++;
		strcpy(list[last].data,x);
	}else printf("FULL");
}

void ReadWrite(FILE *fin, FILE *fout){
	int i;
	struct node* top=NULL;
	char buff[MAX_LEN]; 
	int count=0;
	while (fgets(buff, MAX_LEN, fin) != NULL) {
		printf("%s",buff);
		push(buff);
	}
	for(i=first;i<=last;i++){
		fprintf(fout,"%s",list[i].data);
	}
}
int main(void) {
	FILE *fptr1, *fptr2;
	char filename1[]= "lab1a.txt";
	char filename2[]= "lab1.txt";
	int reval = SUCCESS;
	if ((fptr1 = fopen(filename1, "w")) == NULL){
	printf("Cannot open %s.\n", filename1);
	reval = FAIL;
	} else if ((fptr2 = fopen(filename2, "r")) == NULL){
	printf("Cannot open %s.\n", filename2);
	reval = FAIL;
	} else {
	ReadWrite(fptr2, fptr1);
	fclose(fptr1);
	fclose(fptr2);
}
	return reval;
}
