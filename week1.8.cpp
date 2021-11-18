/*
•Write a program to read sentences from a specified file one character at a time. 
•Each capital letter is converted into a lower-case letter, and each lower-case letter is converted into a capital letter. The new sentence is then written into another file.
•Note that you must output numbers, the signs as they are.
*/
#include <stdio.h>
#include<ctype.h>
enum {SUCCESS, FAIL};
void CharReadWrite(FILE *fin, FILE *fout){
	int c;
	while ((c=fgetc(fin)) != EOF){
	if (islower(c))c=toupper(c);
	else if (isupper(c))c=tolower(c);
	fputc(c, fout);  
	putchar(c); 
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
	CharReadWrite(fptr2, fptr1);
	fclose(fptr1);
	fclose(fptr2);
}
	return reval;
}
