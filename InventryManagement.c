/*mini project*/ 
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
int same2(int,int); 
int same3(int,int);
int same4(int,int);
void rnp();
void rpn();
void save();
int number();
int g,m,n,o,t=0,del=0,dell=0,count,h=0,i;
int a[100];
int z[100];
FILE *fp,*f,*f1; 
int x,j,y,i1,z1,u,e=0,jim=0,jam=0,jes=0; 
int oid,opass,robin=0;
void main() 
{ 
	VOLVO:
	printf("\n\n");
	printf("\n\t\t\t\t\t-------------VERIFICATION SYSTEM FOR ADMIN---------------");
	printf("\nEnter your id:");
	scanf("%d",&oid);
	if(oid==100)
	{
		robin++;
		printf("\n!!!!!!!!!!!!!!!!!!!!!!!YOUR ID HAS BEEN VERIFIED!!!!!!!!!!!!!!!!!!!!!!!\n");
		BMW:
		printf("\nENTER YOUR PASSWORD:");
		scanf("%d",&opass);
		if(opass==98428)
		{
			printf("\n!!!!!!!!!!!!!!YOUR PASSWORD HAS BEEN VERIFIED!!!!!!!!!!!!!!!!!!");
		}	
		else
		{
			printf("\n!!!!!!!!!!!!YOU HAVE ENTERED THE INCORRECT PASSWORD!!!!!!!!!!!!");
			goto BMW;
		}
	}
	if(robin==0)
	{
		
		printf("\nYOUR ID HAS NOT BEEN VERIFIED");
		goto VOLVO;
	}	
	number();
	do 
	{ 
	printf("\n\t\t\t\t\tHELLO! WELCOME TO OUR PROJECT");
	HI:
	printf("\n***********************************************************************************************************************");
	printf("\n**************************************   MEDICAL SHOP MANAGEMENT  *****************************************************");
	printf("\n***********************************************************************************************************************");
	printf("\n\n");  
	printf("\n\t\tPRESS 1 FOR BILLING"); 
	printf("\n\t\tPRESS 2 TO SEE THE NEW STOCK"); 
	printf("\n\t\tPRESS 3 TO APPEND THE PRODUCT"); 
	printf("\n\t\tPRESS 4 TO SEARCH FOR A PRODUCT");
	printf("\n\t\tPRESS 5 TO EDIT AN PRODUCT");
	printf("\n\t\tPRESS 6 TO SORT");
	printf("\n\t\tPRESS 7 TO DELETE AN PRODUCT");
	printf("\n\t\tPRESS  TO EXIT");
	printf("\nENTER YOUR CHOICE:"); 
	scanf("%d",&x); 
	switch(x) 
	{ 
		case 1: 
		{ 
			printf("product_name\tproduct_code\twhole-sale_cost\t\ttselling_cost\t\tavailability"); 
			rnp();
			printf("\n\t\t**********************ENTER THE NECESSARY BILL DETAILS**********************");	
			printf("\n\n");
			float grand=0; 
			f=fopen("bill.txt","w"); 
			printf("\n\t\t**********IF THE REQUIRED PRODUCT IS NOT AVAILABLE**********\n");
			printf("\n\t\t**********SORRY FOR THE INCONVINIENCE**********");
			printf("\n\nPRESS 1 TO EXIT\n");
			printf("\n\nPRESS OTHER THAN 1 TO CONTINUE\n");
			scanf("\n%d",&jim);
			if(jim==1)
			{
				goto HI;
			}
			DI:
			printf("\nENTER THE NUMBER OF PRODUCTS THE USER NEEDED:"); 
			scanf("%d",&m); 
			if(m>n+h-del-dell)
			{
				printf("\n**********NOT THAT MUCH PRODUCT AVAILABLE********");
				goto DI;
			}
			for(j=0;j<m;j++) 
			{ 
				int p; 
				printf("\n\n\t*****ENTER THE DETAILS OF THE %d PRODUCT*****",j+1); 
				printf("\n"); 
				SHIFT:
				GUN: 
				g=0; 
				printf("\nEnter the code of the %d product:",j+1); 
				scanf("%d",&b[j].code); 
				t=0;
				for(o=0;o<n+h-del-dell;o++)
				{
					if(b[j].code!=s[o].code)
					{
						t++;
					}
				}
				if(t==n)
				{
					printf("\nTHE CODE DOES NOT EXIST\n");
					goto SHIFT;
				}	
				if(j>=1) 
				{ 
					g=same1(b[j].code,j); 
				} 
				if(g==1) 
				{ 
					goto GUN; 
				} 
				BALE:
				printf("\nEnter the quantity of %d product:",j+1); 
				scanf("%d",&b[j].quantity); 
				for(i=0;i<n+h-del-dell;i++) 
				{ 
					if(b[j].code==s[i].code) 
					{ 
						strcpy(b[j].name,s[i].name); 
						p=s[i].scost;
						if(b[j].quantity>s[i].available)
						{
							printf("\n-------SORRY INSUFFICIENT STOCK-----------");
							printf("\n-------AVAILABLE STOCK:%d-----------------",s[i].available);
							goto BALE;
						}
						else
						{
							s[i].available=s[i].available-b[j].quantity;
						} 
						break; 
					} 
					else 
					{ 
						continue; 
					} 
				} 
				b[j].price=p*b[j].quantity; 
				printf("\n"); 
			} 
			fprintf(f,"code\tquantity\tname\t\tprice"); 
			for(j=0;j<m;j++) 
			{ 
				grand=grand+b[j].price; 
			} 
			for(j=0;j<m;j++) 
			{ 
				fprintf(f,"\n%d\t%d\t\t%s\t\t%f",b[j].code,b[j].quantity,b[j].name,b[j].price); 
			} 
			fprintf(f,"\n\t\t\tGRAND TOTAL=%f",grand); 
			fclose(f); 
			save();
			f=fopen("bill.txt","r");
			printf("\n\t\t############################################");
			printf("\n\t\t############  BILL GENERATION   ############");
			printf("\n\t\t############################################"); 
			printf("\n\n"); 
			printf("\ncode\tquantity\tname\t\tprice"); 
			for(j=0;j<m;j++) 
			{ 
				fscanf(f,"%d%d%s%f",&b[j].code,&b[j].quantity,b[j].name,&b[j].price); 
				printf("\n%d\t%d\t\t%s\t\t%f",b[j].code,b[j].quantity,b[j].name,b[j].price); 
			} 
			fscanf(f,"%f",&grand); 
			printf("\n-----------------------------------------------------------"); 
			printf("\n\t\t\t\tGRAND TOTAL=%f",grand); 
			printf("\n-----------------------------------------------------------"); 
			break; 
		} 
		case 2: 
		{ 
			printf("\n\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
			printf("\n\t\t$$$$$$$$$$$$$   NEW STOCK AVAILABLE IN MEDICAL SHOP   $$$$$$$$$$$$$$$"); 
			printf("\n\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
			printf("\n\n"); 
			printf("\n\t\t%%%%%%%%%%%%%%%%%%ITEMS AVAILABLE IN THE MEDICAL SHOP%%%%%%%%%%%%%%%%"); 
			printf("\n\n"); 
			printf("product_name\tproduct_code\twhole-sale_cost\t\ttselling_cost\t\tavailability"); 
			rnp();
			break; 
								 
		} 
		case 3: 
		{
			printf("product_name\tproduct_code\twhole-sale_cost\t\ttselling_cost\t\tavailability"); 
			rnp();
			printf("\n\t\t********************ENTER THE NECESSARY FOR APPENDING*************************");	
			printf("\n\n");
			printf("\nEnter the number of products to be appended:"); 
			scanf("%d",&h); 
			for(i=n;i<n+h-del-dell;i++) 
			{ 
				printf("\n"); 
				printf("\t\t********DETAILS OF %d PRODUCT********",i+1); 
				printf("\n\n"); 
				RENAME1: 
				printf("\nEnter the name of the %d product:",i+1); 
				scanf("%s",s[i].name); 
				if(i>=1) 
				{ 
					for(j=0;j<i;j++) 
					{ 
						if(strcmp(s[i].name,s[j].name)==0) 
						{
							printf("\n****you have already entered this name*****\n"); 
							goto RENAME1; 
						} 
					} 
				} 
				NEW1: 
				g=0; 
				printf("Enter the code of the %d product:",i+1); 
				scanf("%d",&s[i].code); 
				s[i].code=s[i].code; 
				if(i>=1) 
				{ 
					g=same2(s[i].code,i); 
				} 
				if(g==1) 
				{ 
					goto NEW1; 
				} 
				printf("Enter the whole-sale cost of the %d product:",i+1); 
				scanf("%f",&s[i].wcost); 
				printf("Enter the selling cost of the %d product:",i+1); 
				scanf("%f",&s[i].scost); 
				printf("Enter the available stock for %d product:",i+1); 
				scanf("%d",&s[i].available); 
			} 
			save();
			break; 
		} 
		case 4:
		{	
			printf("\n\t\t*********************ENTER THE NECESSARY DETAILS FOR SEARCHING***************************");	
			printf("\n\n");
			int search,sea=0;
			rpn();
			do
			{
				printf("\nPRESS 1 TO SEARCH BY NAME");
				printf("\nPRESS 2 TO SEARCH BY CODE");
				printf("\nENTER YOUR CHOICE:");
				scanf("%d",&z1);
				switch(z1)
				{
					case 1:
					printf("\n\t\t*******ENTER THE NECESSARY DETAILS FOR SEARCHING BY NAME**************");	
					printf("\n\n");
					printf("\t\t*********SEARCH BY NAME***********");
					char sname[30];
					printf("\nenter the name to be searched:");
					scanf("%s",sname);
					sea=0;
					for(i=0;i<n+h-del-dell;i++)
					{
						if(strcmp(sname,s[i].name)==0)
						{
							printf("\n*****************THE SEARCHED NAME IS PRESENT****************\n\n");
							printf("product_name\tproduct_code\twhole-sale_cost\t\ttselling_cost\t\tavailability");
							printf("\n%s\t\t%d\t\t%f\t\t%f\t\t%d",s[i].name,s[i].code,s[i].wcost,s[i].scost,s[i].available); 
							sea=1;
						}
					}
					if(sea==0)
					{
						printf("\n***************THE NAME IS NOT PRESENT******************\n");
					}
					break;
					case 2:
					printf("\n\t\t**********ENTER THE NECESSARY DETAILS FOR SEARCHING BY CODE***********");	
					printf("\n\n");
					printf("\t\t*********SEARCH BY CODE***********");
					int scode;
					printf("\nenter the code to be searched:");
					scanf("%d",&scode);
					sea=0;
					for(i=0;i<n+h-del-dell;i++)
					{
						if(scode==s[i].code)
				  		{
							printf("\n********************THE SEARCHED CODE IS PRESENT********************\n\n");
							printf("product_name\tproduct_code\twhole-sale_cost\t\ttselling_cost\t\tavailability");
							printf("\n%s\t\t%d\t\t%f\t\t%f\t\t%d",s[i].name,s[i].code,s[i].wcost,s[i].scost,s[i].available);
							sea=1;
				
						} 
					}
					if(sea==0)
					{
						
						printf("\n********************THE CODE IS NOT PRESSENT****************\n");
					}
					break;
				}
			save();
			printf("\n\n");
			printf("\nPRESS 1 TO CONTINUE FOR SEARCHING");
			printf("\nPRESS OTHER THAN 1 TO EXIT");
			printf("\nENTER YOUR CHOICE:");
			scanf("%d",&search);
			}while(search==1);
			break;
		}
		case 5:
		{
			printf("\n\t\t****************ENTER THE NECESSARY DETAILS FOR EDITING**********************");	
			printf("\n\n");
			printf("product_name\tproduct_code\twhole-sale_cost\t\ttselling_cost\t\tavailability"); 
			rnp();
			int d,editn,ncode,navailable,nwcost,nscost,editc;
			char ename[30],nname[30];
			do
			{
				printf("\nPRESS 1 TO EDIT BY SEARCHING NAME");
				printf("\nPRESS 2 TO EDIT BY SEARCHING CODE");
				printf("\nENTER YOUR CHOICE:");
				scanf("%d",&u);
				switch(u)
				{
					case 1:
					{
					printf("\t\t*********SEARCH BY NAME***********");
					printf("\nenter the name to be searched:");
					scanf("%s",ename);
					e=0;
					for(i=0;i<n+h-del-dell;i++)
					{
						if(strcmp(ename,s[i].name)==0)
						{
							printf("\nTHE SEARCHED NAME IS PRESENT\n\n");
							printf("product_name\tproduct_code\twhole-sale_cost\t\ttselling_cost\t\tavailability");
							printf("\n%s\t\t%d\t\t%f\t\t%f\t\t%d",s[i].name,s[i].code,s[i].wcost,s[i].scost,s[i].available); 
							e=1;
							printf("\n\n\t\t\tDO YOU WANT TO CHANGE");
							printf("\n\t1.NAME\n\t2.CODE\n\t3.AVAILABILITY\n\t4.WHOLE SALE COST\n\t5.SELLING COST\n");
							printf("\nENTER YOUR CHOICE OF CHANGING:");
							scanf("%d",&editn);
							switch(editn)
							{
							case 1:
							{
								NRENAME:
								printf("\nENTER THE NEW NAME:");
								scanf("%s",nname);
								for(j=0;j<n+h-del-dell;j++) 
								{ 
									if(strcmp(nname,s[j].name)==0) 
									{ 
										printf("\n****THIS NAME IS ALREADY PRESENT*****\n"); 
										goto NRENAME; 
									} 
								} 
								strcpy(s[i].name,nname);
								break;
							}
							case 2:
							{
								KENT:
								printf("\nENTER THE NEW CODE:");
								scanf("%d",&ncode);
								for(j=0;j<n+h-del-dell;j++)
								{
									if(ncode==s[j].code)
									{
										printf("\n****THIS CODE IS ALREADY PRESENT****\n");
										goto KENT;
									}
								}
								s[i].code=ncode;
								break;
							}
							case 3:
							{
								printf("\nENTER THE NEWLY AVAILABLE STOCK:");
								scanf("%d",&navailable);
								s[i].available=navailable;
								break;
							}
							case 4:
							{
								printf("\nENTER THE NEW WHOLE-SALE COST OF THE PRODUCT:");
								scanf("%d",&nwcost);
								s[i].wcost=nwcost;
								break;
							}
							case 5:
							{
								printf("\nENTER THE NEW SELLING COST OF THE PRODUCT:");
								scanf("%d",&nscost);
								s[i].scost=nscost;
								break;
							}
							}	
						}
						
					}
					if(e==0)
					{
						printf("\nTHE NAME IS NOT PRESENT");
					}
					break;
					}
					case 2:
					{
					printf("\n\t\t*********SEARCH BY CODE***********");
					int ecode;
					printf("\nenter the code to be searched:");
					scanf("%d",&ecode);
					e=0;
					for(i=0;i<n+h-del-dell;i++)
					{
						if(ecode==s[i].code)
				  		{
							printf("\nTHE SEARCHED CODE IS PRESENT\n\n");
							printf("product_name\tproduct_code\twhole-sale_cost\t\ttselling_cost\t\tavailability");
							printf("\n%s\t\t%d\t\t%f\t\t%f\t\t%d",s[i].name,s[i].code,s[i].wcost,s[i].scost,s[i].available);
							e=1;
							printf("\n\n\t\t\tDO YOU WANT TO CHANGE");
							printf("\n\t1.NAME\n\t2.CODE\n\t3.AVAILABILITY\n\t4.WHOLE SALE COST\n\t5.SELLING COST\n");
							printf("\nENTER YOUR CHOICE OF CHANGING:");
							scanf("%d",&editc);
							switch(editc)
							{
							case 1:
							{
								N1RENAME:
								printf("\nENTER THE NEW NAME:");
								scanf("%s",nname);
								for(j=0;j<n+h-del-dell;j++) 
								{ 
									if(strcmp(nname,s[j].name)==0) 
									{ 
										printf("\n****you have already entered this name*****\n"); 
										goto N1RENAME; 
									} 
								}  
								strcpy(s[i].name,nname);
								break;
							}
							case 2:
							{
								CLARK:
								printf("\nENTER THE NEW CODE:");
								scanf("%d",&ncode);
								for(j=0;j<n+h-del-dell;j++)
								{
									if(ncode==s[j].code)
									{
										printf("\n****THIS CODE IS ALREADY PRESENT****\n");
										goto CLARK;
									}
								}

								s[i].code=ncode;
								break;
							}
							case 3:
							{
								printf("\nENTER THE NEWLY AVAILABLE STOCK:");
								scanf("%d",&navailable);
								s[i].available=navailable;
								break;
							}
							case 4:
							{
								printf("\nENTER THE NEW WHOLE-SALE COST OF THE PRODUCT:");
								scanf("%d",&nwcost);
								s[i].wcost=nwcost;
								break;
							}
							case 5:
							{
								printf("\nENTER THE NEW SELLING COST OF THE PRODUCT:");
								scanf("%d",&nscost);
								s[i].scost=nscost;
								break;
							}
							}
				
						}
					}
					if(e==0)
					{
						printf("\nTHE CODE IS NOT PRESENT");
					}
					break;
					}
				}
			save();
			printf("\n\n");
			printf("\nPRESS 1 TO CONTINUE FOR SEARCHING");
			printf("\nPRESS OTHER THAN 1 TO EXIT");
			printf("\nENTER YOUR CHOICE:");
			scanf("%d",&d);
			}while(d==1);
			break;	
		}
		case 6: 
		{ 
			printf("\nPRESS 1 TO SORT BY NAME");
			printf("\nPRESS 2 TO SORT BY CODE\n");
			printf("\nENTER YOUR CHOICE:");
			scanf("%d",&jam);
			switch(jam)
			{
			case 1:
			{
			int q;
			rpn(); 
			printf("\n\t\t**********SORTING OF PRODUCTS BY NAME***************"); 
			printf("\n\n"); 
			printf("product_name\tproduct_code\twhole-sale_cost\t\ttselling_cost\t\tavailability"); 
			for(i=0;i<n+h-del-dell;i++) 
			{ 
				for(q=i+1;q<n+h-del-dell;q++) 
				{ 
					if(strcmp(s[i].name,s[q].name)>0) 
					{ 
						temp=s[i]; 
						s[i]=s[q]; 
						s[q]=temp; 
					}	 
				} 
				printf("\n%s\t\t%d\t\t%f\t\t%f\t\t%d",s[i].name,s[i].code,s[i].wcost,s[i].scost,s[i].available); 
			} 
			save();
			break; 
			}//case1
			case 2: 
			{ 
			int q; 
			rpn();
			printf("\n\t\t**********SORTING OF PRODUCTS BY CODE***************"); 
			printf("\n\n"); 
			printf("product_name\tproduct_code\twhole-sale_cost\t\ttselling_cost\t\tavailability"); 
			for(i=0;i<n+h-del-dell;i++) 
			{ 
				for(q=i+1;q<n+h-del-dell;q++) 
				{ 
					if(s[i].code>s[q].code) 
					{ 
						temp=s[i]; 
						s[i]=s[q]; 
						s[q]=temp; 
					}	 
				} 
				printf("\n%s\t\t%d\t\t%f\t\t%f\t\t%d",s[i].name,s[i].code,s[i].wcost,s[i].scost,s[i].available); 
			} 
			save(); 
			}//case2
			break;
			}
			break;
		}
		case 7:
		{	
			printf("\nPRESS 1 TO DELETE BY CODE");
			printf("\nPRESS 2 TO DELETE BY NAME");
			printf("\nENTER YOUR CHOICE:");
			scanf("%d",&jes);
			switch(jes)
			{
			case 1:
			{
			int jok,tem=0,lr,l;
			printf("product_name\tproduct_code\twhole-sale_cost\t\ttselling_cost\t\tavailability"); 
			rnp();
			printf("\n\t\t**********DELETION OF PRODUCTS BY CODE***************"); 
			printf("\n\n"); 
			HOOD:
			printf("\nEnter the number of products to delete:");
			scanf("%d",&del);
			if(del>n+h-dell)
			{
				printf("\n**********NOT THAT MUCH PRODUCTS TO DELETE**********");
				goto HOOD;
			}
			for(i=0;i<del;i++)
			{
				printf("\nEnter the code of the product:");
				scanf("%d",&jok);
				for(j=0;j<n+h-del-dell;j++)
				{
					if(jok==s[j].code)
					{
						lr=j;
						tem=1;
						break;
					}
				}
				if(tem==1)
				{
					for(l=lr;l<n+h-del-dell;l++)
					{
						s[l]=s[l+1];
					}
				}
				if(tem!=1)
				{
					printf("\nTHE CODE IS INVALID");
				}
			}
			save();
			break;
			}
			case 2:
			{	
			int temm=0,lrd,l;
			char bane[30];
			printf("product_name\tproduct_code\twhole-sale_cost\t\ttselling_cost\t\tavailability"); 
			rnp();
			printf("\n\t\t**********DELETION OF PRODUCTS BY NAME***************"); 
			printf("\n\n"); 
			DHONI:
			printf("\nEnter the number of products to delete:");
			scanf("%d",&dell);
			if(dell>n+h-del)
			{
				printf("\n**********NOT THAT MUCH PRODUCTS TO DELETE**********");
				goto DHONI;
			}
			for(i=0;i<dell;i++)
			{
				printf("\nEnter the name of the product:");
				scanf("%s",bane);
				for(j=0;j<n+h-del-dell;j++)
				{
					if(strcmp(bane,s[j].name)==0)
					{
						lrd=j;
						temm=1;
						break;
					}
				}
				if(temm==1)
				{
					for(l=lrd;l<n+h-del-dell;l++)
					{
						s[l]=s[l+1];
					}
				}
				if(temm!=1)
				{
					printf("\nTHE NAME IS INVALID");
				}
			}
			save();
			break;
			}
			break;
			}
		}
		case 8:
		{
			printf("\n\n****************THANK YOU***************\n\n");
			exit(0);
			break;
		}
		default:
		{
			printf("\n\n***************PLEASE ENTER A VALID NUMBER***************\n\n");
			break;
		}

	}
	printf("\n\n"); 
	printf("\nPRESS 1 TO CONTINUE"); 
	printf("\nPRESS OTHER THAN 1 TO EXIT"); 
	printf("\nENTER YOUR CHOICE:"); 
	scanf("%d",&y); 
	}while(y==1); 
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
int same1(int n,int i) 
{ 
	int j,g; 
	for(j=0;j<i;j++) 
	{ 
		if(b[j].code==n) 
		{ 
			printf("\n**********The code has already been used***********\n\n"); 
			g=1; 
		} 
	} 
	return g; 
} 
int same2(int n,int i) 
{ 
	int j,g; 
	for(j=0;j<i;j++) 
	{ 
		if(s[j].code==n) 
		{ 
			printf("\n**********The code has already been used*************\n\n"); 
			g=1; 
		} 
	} 
	return g; 
}
int same3(int n,int i) 
{ 
	int j,g; 
	for(j=0;j<i;j++) 
	{ 
		if(s[j].code==n) 
		{ 
			printf("\n**********The code has already been used*************\n\n"); 
			g=1; 
		} 
	} 
	return g; 
}
int same4(int n,int i) 
{ 
	int j,g; 
	for(j=0;j<i;j++) 
	{ 
		if(s[j].code==n) 
		{ 
			printf("\n**********The code has already been used*************\n\n"); 
			g=1; 
		} 
	} 
	return g; 
}
void rnp()
{
	int n;
	n=number();
	fp=fopen("stock.txt","r");
	for(i=0;i<n+h-del-dell;i++) 
	{  
		fscanf(fp,"%s%d%f%f%d",s[i].name,&s[i].code,&s[i].wcost,&s[i].scost,&s[i].available); 
		printf("\n%s\t\t%d\t\t%f\t\t%f\t\t%d",s[i].name,s[i].code,s[i].wcost,s[i].scost,s[i].available); 
	} 
	fclose(fp);
}
void rpn()
{
	int n;
	n=number();
	fp=fopen("stock.txt","r");
	for(i=0;i<n+h-del-dell;i++) 
	{  
		fscanf(fp,"%s%d%f%f%d",s[i].name,&s[i].code,&s[i].wcost,&s[i].scost,&s[i].available);  
	} 
	fclose(fp);
}
void save()
{
	int n;
	n=number();
	fp=fopen("stock.txt","w");
	for(i=0;i<n+h-del-dell;i++) 
	{ 
		fprintf(fp,"\n%s\t\t%d\t\t%f\t\t%f\t\t%d",s[i].name,s[i].code,s[i].wcost,s[i].scost,s[i].available); 
	}
	fclose(fp);
}
int number()
{
	f1=fopen("num.txt","r");
	fscanf(f1,"%d",&n);
	return n;
}





