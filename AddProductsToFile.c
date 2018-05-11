*mini project*/ 
/*inventory control management of a shop*/ 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
struct stock 
{ 
	char name[30]; 
	int code; 
	float wcost; 
	float scost; 
	int available; 
}s[100],temp; 
struct bill 
{ 
	int code; 
	char name[30]; 
	int quantity; 
	float price; 
	float total;
}b[100];  
int same(int,int);
int same1(int,int);
int g,m,n,o,t=0,del=0,dell=0,count,h=0,i;
int a[100];
int z[100];
FILE *fp,*f,*f1; 
int x,j,y,i1,z1,u,e=0; 
void main()
{	 
			printf("\n\t\t*************************ENTER THE NECESSARY STOCK DETAILS*****************");	
			printf("\n\n");		
			printf("\nEnter the number of products:"); 
			scanf("%d",&n);	
			f1=fopen("num.txt","w");
			fprintf(f1,"%d",n);
			for(i=0;i<n+h-del-dell;i++) 
			{ 
				printf("\n"); 
				printf("\t\t********DETAILS OF %d PRODUCT*************",i+1); 
				printf("\n\n"); 
				RENAME: 
				printf("\nEnter the name of the %d product:",i+1); 
				scanf("%s",s[i].name); 
				if(i>=1) 
				{ 
					for(j=0;j<i;j++) 
					{ 
						if(strcmp(s[i].name,s[j].name)==0) 
						{ 
							printf("\n****you have already entered this name*****\n"); 
							goto RENAME; 
						} 
					} 
				} 
				NEW: 
				g=0; 
				printf("Enter the code of the %d product:",i+1); 
				scanf("%d",&s[i].code); 
				s[i].code=s[i].code; 
				if(i>=1) 
				{ 
					g=same(s[i].code,i); 
				} 
				if(g==1) 
				{ 
					goto NEW; 
				} 
				printf("Enter the whole-sale cost of the %d product:",i+1); 
				scanf("%f",&s[i].wcost); 
				printf("Enter the selling cost of the %d product:",i+1); 
				scanf("%f",&s[i].scost); 
				printf("Enter the available stock for %d product:",i+1); 
				scanf("%d",&s[i].available); 
			} 
			fp=fopen("stock.txt","w+"); 
			//fprintf(fp,"product_name\tproduct_code\twhole-sale_cost\t\ttselling_cost\t\tavailability"); 
			printf("\n\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
			printf("\n\t\t^^^^^^^^^^^^^^^  ITEMS AVAILABLE IN THE MEDICAL SHOP  ^^^^^^^^^^^^^^^^^^^^^^^"); 
			printf("\n\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
			printf("\n\n"); 
			printf("product_name\tproduct_code\twhole-sale_cost\t\ttselling_cost\t\tavailability"); 
			for(i=0;i<n+h-del-dell;i++) 
			{ 
				fprintf(fp,"\n%s\t\t%d\t\t%f\t\t%f\t\t%d",s[i].name,s[i].code,s[i].wcost,s[i].scost,s[i].available); 
				fscanf(fp,"%s%d%f%f%d",s[i].name,&s[i].code,&s[i].wcost,&s[i].scost,&s[i].available); 
				printf("\n%s\t\t%d\t\t%f\t\t%f\t\t%d",s[i].name,s[i].code,s[i].wcost,s[i].scost,s[i].available); 
			} 
			fclose(fp); 
}
int same(int n,int i) 
{ 
	int j,g; 
	for(j=0;j<i;j++) 
	{ 
		if(s[j].code==n) 
		{ 
			printf("\n**********The code has already been used***********\n\n"); 
			g=1; 
		} 
	} 
	return g; 
} 
