/*
•Implement the function my_strcat:
–Input –two strings, s1and s2
–Output –a pointer to a dynamically allocated concatenation
–For example: The concatenation of “hello_” and “world!” is the string “hello_world!” 
*/
•Test your function
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *my_strcat(char *str1,char *str2){
	int len1, len2;
	char *result;
	len1 = strlen(str1);
	len2 = strlen(str2);
	result = (char*)malloc((len1 + len2 + 1) *  sizeof(char));
	if(result == NULL) {
	printf("Allocation failed! Check memory\n");
	return NULL;
	}
	strcpy(result, str1);
	strcpy(result + len1, str2);
	return result;
}
int main(){
	char str1[]="Hello_";
	char str2[]="World";
	char *cat_str;
	cat_str=my_strcat(str1,str2);
	if (cat_str == NULL){
	printf("Problem allocating memory\n");
	return 1;
	}
	printf("The concatenation of %s and %s is %s\n", str1, str2, cat_str);
	free(cat_str);
	return 0;
}
