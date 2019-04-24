#include<stdio.h>
#include<stdlib.h>
int n;
int totaltime = 0; 
int prefinaltotal = 0;
struct process { 
	int processno; 
	int AT; 
	int BT; 
	int BTbackup; 
	int WT; 
	int TAT; 
	int CT; 
}; struct process p[10]; 
_Bool compare(struct process p1, struct process p2) 
{ 
	// compare the Arrival time of two processes 
	return p1.AT < p2.AT; 
} 

int main()
{
int i; 
	printf("\n Enter the number of processes : ");
	scanf("%d",&n);
	 
	for (i = 0; i < n; i++) { 
		printf("\n Enter the  of process ID");
		scanf("%d",&p[i].processno) ; 
	} 

	 
	for (i = 0; i < n; i++)  
	{ 
		printf("\n Arrival Time");
		scanf("%d",&p[i].AT); 
	} 

	 
	for (i = 0; i < n; i++) { 

		printf("\n BUrst Time:") ;
		scanf("%d",&p[i].BT) ;
		p[i].BTbackup = p[i].BT; 
		prefinaltotal += p[i].BT; 
	} 
	for (i = 0; i < n; i++) { 
		printf("%d\t",p[i].processno); 
		printf("%d\t",p[i].AT); 
		printf("%d\t",p[i].BT); 
		printf("\n"); 
	} 
	printf("\n"); 
	qsort(p, 10,sizeof(_Bool), compare); 



}
