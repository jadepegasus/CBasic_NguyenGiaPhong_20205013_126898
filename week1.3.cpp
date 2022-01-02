/*
•Implement a function that accepts two integer arrays and returns 1 if they are equal, 0 otherwise
•Write a program that accepts two arrays of integers from the user and checks for equality
*/
#include<stdio.h>
#define MAX 10000
int Sosanh(int a[],int b[],int n,int m){
	if(n!= m) return 0; 
	int j;
	for(j=0;j<n;j++){
		if(a[j]!=b[j]) return 0;
	}
	return 1;
}
int main(){
	int n,m,i;
	printf("Nhap so phan tu mang 1:");
	scanf("%d",&n);
    int a[MAX],b[MAX];
	printf("Nhap %d phan tu cua mang 1:",n);

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Nhap so phan tu mang 2:");
	scanf("%d",&m);
	printf("Nhap %d phan tu cua mang 2:",m);
	for(i=0;i<m;i++){
		scanf("%d",&b[i]);
	}
	if(Sosanh(a,b,n,m)==1) printf("2 mang bang nhau");
	else printf("2 mang ko bang nhau");
	return 0;
}
