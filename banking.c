#include<stdio.h>
#include<stdlib.h>

char name[30];
int dep_amt;
int tot_amt=1000;
int acc_no;

void menu();
void deposit_money();
void withdraw_money();
void transfer_money();
void account_details();
void line();

void line()
{
	int i;
	for(i=0;i<30;i++)
	{
		printf(" - ");
	} 
}

int main()
{
	FILE *fptr;
	fptr=fopen("account.txt","a");
	printf("Enter Your Name:");
	gets(name);
	
	printf("Enter Your Account Number:");
	scanf("%d",&acc_no);
	
	int l;
	for(l=0;l<30;l++)
	{
		fprintf(fptr," - ");
	}
	fprintf(fptr,"\nName:%s\n",name);
	fprintf(fptr,"Account Number:%d\n",acc_no);
	menu();

	while(1)
	{
			
	int ch;
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	
		switch(ch)
		{
			case 1:
				deposit_money();
				line();
				break;
			case 2:
				withdraw_money();
				line();
				break;
			case 3:
				transfer_money();
				line();
				break;
			case 4:
				account_details();
				line();
				break;
			case 5:
				printf("--- Thank You for Your Bankings \n Have a Nice Day---");
				exit(1);
			default:
				printf("invalid choice !!!");
				line();
				break;
		}
	
	}
	
	for(l=0;l<30;l++)
		{
			fprintf(fptr," - ");
		}
}

void menu()
{
	printf("MAIN MENU\n");
	printf("1.Deposit Money\n");
	printf("2.Withdraw Money\n");
	printf("3.Transfer Money\n");
	printf("4.Account Details\n");
	printf("5.Exit\n");
}

void deposit_money()
{
	time_t tm;
	time(&tm);
	
	FILE *fptr;
	fptr=fopen("account.txt","a");
	printf("---// Money Depositing Section //---\n");
	printf("enter the amount:");
	scanf("%d",&dep_amt);
	
	tot_amt+=dep_amt;
	printf("--- Amount Credited Successfully---\n");
	printf("Current Balance: %d\n",tot_amt);
	fprintf(fptr,"Rs:%d has been deposited to your account.\n",dep_amt);
	
	fprintf(fptr,"Date / time of transaction: %s",ctime(&tm));
//	line();
//	fclose(fptr);
}

void withdraw_money()
{
	time_t tm;
	time(&tm);
	
	FILE *fptr;
	fptr=fopen("account.txt","a");
	
	int wd_amt;
	printf("---// Money Withdrawl //---\n");
	printf("Enter the amount:");
	scanf("%d",&wd_amt);
	if(wd_amt<tot_amt)
	{
		tot_amt-=wd_amt;
		printf("--- Amount Debited Successfully ---\n");
		printf("Current Balance: %d\n",tot_amt);
		
		fprintf(fptr,"Rs.%d withdrawn from your account.\n",wd_amt);
		fprintf(fptr,"Date/time of withdrawn :%s\n",ctime(&tm));
	}
	else
		printf("--- Insufficient balance!!! ---");
}

void transfer_money()
{
	time_t tm;
	time(&tm);
	
	FILE *fptr=fopen("account.txt","a");
	
	int t_accno,trans_amt;
	printf("---// Money Transfer //---\n");
	printf("Enter the amount:");
	scanf("%d",&trans_amt);
	
	if(tot_amt>trans_amt)
	{
		printf("Enter the Account Number to transfer the money:");
		scanf("%d",&t_accno);
		tot_amt-=trans_amt;
		printf("--- Transaction is Done ---\n");
		printf("Current Balance : %d\n",tot_amt);
		fprintf(fptr,"Rs.%d is transferred to this account no %d at this time %s\n",trans_amt,t_accno,ctime(&tm));	
	}
	else{
		printf("--- Money is Insufficient to Transfer ---\n");
	}	
}

void account_details()
{
	printf("---// Account Details //---\n");
	printf("Account Holder Name:%s\n",name);
	printf("Account Number:%d\n",acc_no);
	printf("Account Balance:%d\n",tot_amt);

}