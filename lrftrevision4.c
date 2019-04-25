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
	return p1.AT < p2.AT; 
} 

int findCT() 
{ 

	int index; 
	int flag = 0; 
	int i = p[0].AT; 
	while (1) { 
		if (i <= n) { 
			index = findlargest(i); 
		} 

		else
			index = findlargest(n); 
		printf( "Process executing at time %d is: P%d\t",totaltime, index + 1); 

		p[index].BT -= 1; 
		totaltime += 1; 
		i++; 

		if (p[index].BT == 0) { 
			p[index].CT = totaltime; 
			printf("Process P%d is completed at %d",p[index].processno,totaltime); 
		} 
		printf("\n"); 

		// loop termination condition 
		if (totaltime == prefinaltotal) 
			break; 
	} 
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
	totaltime += p[0].AT; 
	prefinaltotal += p[0].AT; 
	findCT(); 
	int totalWT = 0; 
	int totalTAT = 0; 
	for (i = 0; i < n; i++) { 
		
		p[i].TAT = p[i].CT - p[i].AT; 
		p[i].WT = p[i].TAT - p[i].BTbackup;  
		totalWT += p[i].WT; 
		totalTAT += p[i].TAT; 
	} 






}
