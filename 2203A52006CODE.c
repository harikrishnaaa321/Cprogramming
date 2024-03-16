/*
 AUTHOR: HARIKRISHNA
 HTNO:2203A52006
 TITLE:BANK MANAGEMENT SYSTEM
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct bank
{
	char firstname[20];
	char lastname[20];
	int age;
	char adharnumber[12];
	char pannumber[10];
	char phone[10];
	int amount_d;
};
struct bankaccounts{
	int accnum;
	int pin;
	int amount;
	char accname[20];
	int acc_age;
	char loan_edu[10];
	char phone[12];
    char loan_installment_paid;
	int salary;
	int amount_loan;
	int loan_tenure;
	int cibil_score;
	float loan_installment;
};
	struct bank *customer[5];
	struct bankaccounts accounts[10];
	int choice,x,i,l,digit,random_num=0,pass,passcode_num,login_accnum,login_passcode,staff_passcode;
	int amount_debit,amount_credit,see_account;
	int money_sender,money_receiver,money_pin,money_transfer_pin,j,c;
	int cibil_score,loan_amount,view;
	int k1,pay,emi_s=0,emi_s1=0,ac=0,loan_accnum,loan_passcode;
	int loan_account_num;
	float loan_amount_perm;
	char loan_s,per_loan_num,accounts_holder[20];
    int s1=0,s2=0,s3=0,ls=0,ls1=0,l=0;
    void openaccount(int,int);
    void withdrawal(int *,int *);
    void deposit(int *,int *);
    void moneytransfer_acc2(int);
    void edu_loan(int);
    void personal_loan(int);
    void loan_installment(int);
    int main()
{
	accounts[0].accnum=2203520;
	strcpy(accounts[0].accname,"HARI");
	accounts[0].acc_age=40;
    accounts[0].pin=2000;
    strcpy(accounts[0].phone,"7981575880");
    accounts[0].amount_loan=0;
    accounts[0].amount=100000;
    accounts[1].accnum=2203521;
    strcpy(accounts[1].phone,"7981575870");
    strcpy(accounts[1].accname,"KRISHNA");
    accounts[1].acc_age=30;
    accounts[1].pin=2001;
    accounts[1].amount=200000;
    accounts[1].amount_loan=0;
    accounts[2].accnum=2203522;
    strcpy(accounts[2].accname,"VIJAY");
    strcpy(accounts[2].phone,"7986575870");
    accounts[2].acc_age=26;
    accounts[2].pin=2002;
    accounts[2].amount=100000;
    accounts[2].amount_loan=0;
   accounts[3].accnum=2203523;
    accounts[3].acc_age=50;
    strcpy(accounts[3].accname,"HARSHAD");
    strcpy(accounts[3].phone,"7981579850");
    accounts[3].pin=2003;
    accounts[3].amount_loan=300000;
    accounts[3].loan_installment=12500.00;
    accounts[3].amount=100000;
    accounts[3].loan_installment_paid='N';
    int n=0,k=4;                           
	x:
	printf("\n\t\t\tWELCOME TO OUR BANK\n\n\n");
	printf("\n\t\t\tOUR SERVICES\n");
	printf("\n\t\t\t1)OPEN ACCOUNT\n");
	printf("\n\t\t\t2)WITHDRAW MONEY\n");
	printf("\n\t\t\t3)DEPOSIT MONEY\n");
	printf("\n\t\t\t4)MONEY TRANSFER\n");
	printf("\n\t\t\t5)EDU LOAN\n");
	printf("\n\t\t\t6)PERSONAL LOAN\n");
	printf("\n\t\t\t7)LOAN INSTALLMENT\n");
	printf("\n\t\t\t8)ONLY FOR STAFF\n");
	printf("\n\t\t\tENTER A CHOICE\t");
	scanf("%d",&choice);
	switch(choice)
	{
	  case 1:
	  		openaccount(k,n);
	  		n+=1;
			k+=1;
			break;
	   case 2:
	   	    	printf("\nENTER ACCOUNT NUMBER");
	   	scanf("%d",&login_accnum);
	   	
		   for(i=0;i<k;i++)
	   	{
	   		if(login_accnum==accounts[i].accnum)
	   		{
	   		  printf("\nENTER PASSCODE");
	   		  scanf("%d",&login_passcode);
	   		  	if(login_passcode==accounts[i].pin)
	   		  	{
	   		  		printf("\nAVAILABLE BALANCE: %d",accounts[i].amount);
	   		  	printf("\nENTER AMOUNT TO BE DEBITED");
				scanf("%d",&amount_debit);
				if(accounts[i].amount>=amount_debit)
				  {
				  	if(amount_debit>=500)
				  	{
				  		
					if(accounts[i].amount-amount_debit>=10000)
					{
				   withdrawal(&accounts[i].amount,&amount_debit);
					printf("\nMONEY SUCCESSFULLY DEBITED");
					printf("\nAVAILABLE BALANCE:%d",accounts[i].amount);
			     	}
			     	else
			     	{
			     		printf("\n PLEASE MAINTAIN MINIMUM BALANCE");
					 }
					}
					else
					{
					printf("\nENTER VALID AMOUNT");	
					}
				}
					else
					{
					 printf("\nINSUFFICIENT BALANCE");
						}	
			  }
			  else
			  {
			  	s2+=1;
			  }
			}
			else
			{
				s1+=1;
			}
		   }
		   if(s1==k)
		   {
		   	printf("\nINVALID ACCOUNT NUMBER");
		   }
		   if(s2==k)
		   {
		   	printf("\nINValid PASSCODE");
		   }
		   break;
		case 3:
		printf("\nENTER ACCOUNT NUMBER");
	   	scanf("%d",&login_accnum);
	   	
		   for(i=0;i<k;i++)
	   	{
	   		if(login_accnum==accounts[i].accnum)
	   		{
	   		  printf("\nENTER PASSCODE");
	   		  scanf("%d",&login_passcode);
	   		  	if(login_passcode==accounts[i].pin)
	   		  	{
	   		  		printf("\nAVAILABLE BALANCE :%d",accounts[i].amount);
	   		  	printf("\nEnter amount to be deposited");
				scanf("%d",&amount_credit);
				if(amount_credit>=1000)
				{
				 deposit(&accounts[i].amount,&amount_credit);
					printf("\nMONEY CREDITED SUCCESSFULLY");
					printf("\nAvailable balance :%d",accounts[i].amount);	
				}
				else
				{
					printf("\nDEPOSIT ABOVE 1000");
				}
			  }
			  else
			  {
			  printf("\nINVALID PASSCODE");
			  }
			}
			else
			{
				s1+=1;
			}
		   }
		   if(s1==k)
		   {
		   	printf("\nINVALID ACCOUNT NUMBER");
		   }
		   break;
		case 4:
	      moneytransfer_acc2(k);
			break;
		case 5:
		  edu_loan(k);
			break;
		case 6:
		 personal_loan(k);
			break;
		case 7:
		loan_installment(k);
			break;
	    case 8:
		   printf("\nENTER PASSCODE");
		   scanf("%d",&staff_passcode);
		   if(staff_passcode==1111)
		   {
		   	printf("\n1)VIEW LOANS");
		   	printf("\n2)VIEW ACCOUNTS");
		   	scanf("%d",&view);
		   	if(view==1)
		   	{
		   	for(i=0;i<k;i++)
			   {
			   	if(accounts[i].amount_loan!=0)
			   	{
			   		printf("\nACCOUNT NUMBER      :%d",accounts[i].accnum);
			   		printf("\nACCOUNT  HOLDER NAME:%s",accounts[i].accname);
			   		printf("\nPHONE NUMBER        :%s",accounts[i].phone);
			   		printf("\nLOAN AMOUNT         : %d",accounts[i].amount_loan);
			   		printf("\nMONTHLY INSTALLEMENT:%.2f",accounts[i].loan_installment);
			   		printf("\nTHIS MONTH INSTALLMENT(P-PAID__N-NOTPAID): %c",accounts[i].loan_installment_paid);
			   		printf("\n---------------------------------");
				   }
			   }	
			}
			if(view==2)
			{
				printf("\nENter account number to view\n");
				scanf("%d",&see_account);
				for(i=0;i<k;i++)
				{
					if(see_account==accounts[i].accnum)
					{
					printf("\nACCOUNT NUMBER     :%d",accounts[i].accnum);
					printf("\nACCOUNT HOLDER NAME: %s",accounts[i].accname);
					printf("\nACCOUNT HOLDER AGE :%d",accounts[i].acc_age);
					printf("\nAMOUNT IN ACCOUNT  :%d",accounts[i].amount);	
					}
					else
					{
					    ac+=1;
					}
				}
				if(ac==k)
				{
				    printf("INVALID ACCOUNT NUMBER");
				}
			}
		   } 
		   	else
			{
				printf("\nEnter correct code");
			} 
	}
	printf("\nENTER 1 TO CONTINUE ");
	scanf("%d",&c);
	if(c==1)
	goto x;
}
void openaccount(int k,int n)
{
	       customer[n]=(struct bank*)calloc(n+1,sizeof(struct bank));
        	printf("\nENTER YOUR FIRST NAME IN BLOCK LETTERS : ");
			scanf("%s",customer[n]->firstname);
			printf("\nENTER YOUR LAST NAME IN BLOCK LETTERS  : ");
			scanf("%s",customer[n]->lastname);
			printf("\nEnNTER YOUR AGE                        : ");
			scanf("%d",&customer[n]->age);
			printf("\nENTER AADHAR NUMBER                    : ");
			scanf("%s",customer[n]->adharnumber);
			printf("\nENTER PAN NUMBER                       : ");
			scanf("%s",customer[n]->pannumber);
			printf("\nENTER PHONE NUMBER                     : ");
			scanf("%s",customer[n]->phone);
			random_num=0;
			int *ptr;
			ptr=(int*)malloc(sizeof(int));
	        for(i=0;i<6;i++)
            {
            	*ptr=rand()%10;
            	random_num=random_num*10+*ptr;
			}
            printf("\nENTER YOUR PASSCODE                     : ");
            scanf("%d",&passcode_num);
			printf("\nWE ARE PROCEESING YOUR DETAILS          :"); 
			printf("\nENTER AMOUNT TO DEPOSIT(MIN AMOUNT 10000):");
			scanf("%d",&customer[n]->amount_d);
			printf("\nACCOUNT CREATED SUCCESFULLY             :");
			accounts[k].accnum=random_num;
			accounts[k].pin=passcode_num;
			strcpy(accounts[k].accname,customer[n]->firstname);
			strcpy(accounts[k].phone,customer[n]->phone);
			accounts[k].acc_age=customer[n]->age;
			accounts[k].amount=customer[n]->amount_d;
			printf("\nYOUR ACCOUNT NUMBER IS  : %d",accounts[k].accnum);
			printf("\nYOUR PASS CODE IS       : %d",accounts[k].pin);
			printf("\nAVAILABLE BALANCE      :%d\n\n",accounts[k].amount);

}
void withdrawal(int *amount_total,int *amount_debit)
{
	*amount_total-=(*amount_debit);
}
void deposit(int *amount_total,int *amount_credit)
{
	*amount_total+=(*amount_credit);	
}
void moneytransfer_acc2(int k)
{
	printf("\nENTER SENDER ACCOUNT NUMBER");
			scanf("%d",&money_sender);
			for(i=0;i<k;i++)
			{
				if(money_sender==accounts[i].accnum)
				{
					printf("\nENTER RECEIVER ACCOUNT NUMBER");
					scanf("%d",&money_receiver);
					for(j=0;j<k;j++)
					{
						if(money_receiver==accounts[j].accnum)
						{
							printf("ENTER PIN TO CHECK");
							scanf("%d",&money_pin);
							if(accounts[i].pin==money_pin)
							{
								printf("\nENTER MONEY TO TRANSFER");
								scanf("%d",&money_transfer_pin);
								if(accounts[i].amount>=money_transfer_pin)
								{
									accounts[j].amount+=money_transfer_pin;
									accounts[i].amount-=money_transfer_pin;
									printf("\nMONEY TRANSFERED SUCCESFULLY");
									printf("\nAVAILABLE BALANCE:%d",accounts[i].amount);
								}
							}
							else
							{
								s3+=1;
							}
						}
						else
						{
							s2+=1;
						}
					}
				}
				else {
					s1+=1;
				}
			}
			if(s1==k)
			{
				printf("\nINVALID SENDER ACCOUNT NUMBER");
				}	
			if(s2==k)
			{
				printf("\nINVALIS RECIEVER ACCOUNT NUMBER");
			}
			if(s3==k)
			{
				printf("\nINVALID PIN");
			}
}
void edu_loan(int k)
{
		printf("\nENTER ACCOUNT NUMBER OF STUDENT: ");
			scanf("%d",&loan_account_num);
			for(i=0;i<k;i++)
			{
				if(loan_account_num==accounts[i].accnum)
				{
					
				  printf("\nENTER COURSE YOU ARE STUDYING: ");
				  scanf("%s",&accounts[i].loan_edu);
				  printf("\nENTER ANNUAL SALARY OF YOUR FATHER : ");
				  scanf("%d",&accounts[i].salary);	
				  if(accounts[i].salary<=300000)
				  {
				  	printf("\nYOU ARE NOT ELIGIBLE FOR LOAN");
				  }
				  else
				  {
				  	printf("\nENTER LOAN AMOUNT REQUIRED: ");
				    scanf("%d",&accounts[i].amount_loan);
				  	printf("\n");
				  	printf("\nCHOOSE LOAN TENURE:1)2 YEARS\n2)3 YEARS\n3)4 YEARS ");
				  	scanf("%d",&accounts[i].loan_tenure);
				  	if(accounts[i].amount_loan<=400000)
				  	{
				  		loan_amount_perm=(float)(0.07)*accounts[i].amount_loan;
				  		loan_amount_perm+=(float)(accounts[i].amount_loan);
				  		loan_amount_perm/=(float)accounts[i].loan_tenure;
				  		loan_amount_perm/=12;
				  			accounts[i].loan_installment_paid='N';
				  		accounts[i].loan_installment=loan_amount_perm;
					  }
					  else
					  {
					  loan_amount_perm=(float)(0.09)*accounts[i].amount_loan;
				  		loan_amount_perm+=(float)(accounts[i].amount_loan);
				  		loan_amount_perm/=(float)accounts[i].loan_tenure;
				  		loan_amount_perm/=12;
				  		accounts[i].loan_installment=loan_amount_perm;
				  		accounts[i].loan_installment_paid='N';
					  }
					  printf("%.2f IS YOUR MONTHLY INSTALLMENT",loan_amount_perm);
					  printf("\nSUBMIT YOUR DOCUMENTS");
				  }
				}
				else
				{
					l+=1;
				}
			}
			if(l==k)
			printf("\nENTER VALID ACCOUNT NUMBER");
}
void personal_loan(int k)
{
	printf("\nENTER YOUR ACCOUNT NUMBER: ");
		scanf("%d",&loan_account_num);
			for(i=0;i<k;i++)
			{
				if(loan_account_num==accounts[i].accnum)
				{
			        if(accounts[i].amount_loan==0.00)
			        {
					printf("\nENTER ANNUAL SALARY");
					scanf("%d",&accounts[i].salary);
					if(accounts[i].salary>=400000)
					{
					    printf("\nENTER CIBIL SCORE");
						scanf("%d",&accounts[i].cibil_score);
						if(accounts[i].cibil_score>=550&&accounts[i].cibil_score<=750)
						{
							printf("\nYOUR ARE ELIGIBLE FOR LOAN");
							printf("\nENTER LOAN AMOUNT");
							scanf("%d",&loan_amount);
							accounts[i].amount_loan=loan_amount;
							printf("\nENTER LOAN TENURE");
							scanf("%d",&accounts[i].loan_tenure);
							printf("\n INTEREST RATES ARE 7 PER BELOW 400000 AND 9 PER ABOVE");
								printf("\nEnter S if u r interested: ");
					scanf("%s",&loan_s);
					if(loan_s=='s'||loan_s=='S')
					{
					printf("\nSUBMIT UR DOC");	
				  	if(accounts[i].amount_loan<=400000)
				  	{
				  		loan_amount_perm=(float)(0.07)*accounts[i].amount_loan;
				  		loan_amount_perm+=(float)(accounts[i].amount_loan);
				  		loan_amount_perm/=(float)accounts[i].loan_tenure;
				  		loan_amount_perm/=12;
				  			accounts[i].loan_installment_paid='N';
				  		accounts[i].loan_installment=loan_amount_perm;
					  }
					  else
					  {
					  loan_amount_perm=(float)(0.09)*accounts[i].amount_loan;
				  		loan_amount_perm+=(float)(accounts[i].amount_loan);
				  		loan_amount_perm/=(float)accounts[i].loan_tenure;
				  		loan_amount_perm/=12;
				  			accounts[i].loan_installment_paid='N';
						  	accounts[i].loan_installment=loan_amount_perm;	
						}
					printf("\n%.2f IS MONTHLY INSTALLMENT",loan_amount_perm);
					}
				}
				else
					{
						printf("VISIT AGAIN");
					}
						
					}
					else
					{
					printf("\n YOUR ANNUAL SALARY DOESNOT MATCH OUR REQUIREMENT");	
					}
				}
				else
				{
						printf("\nWE DONOT ACCEPT MULTIPLE LOANS");
				}
				 }
				else
				{
					ls+=1;
				}
			}
			if(ls==k)
			printf("\nINVALID ACCOUNT NUMBER");
}
void loan_installment(int k)
{
	printf("\nENTER ACCOUNT NUMBER");
			scanf("%d",&loan_accnum);
			for(i=0;i<k;i++)
			{
				if(accounts[i].accnum==loan_accnum)
				{
					printf("\nENTER PASSCODE");
					scanf("%d",&loan_passcode);
					if(accounts[i].pin==loan_passcode)
					{
						if(accounts[i].amount_loan!=0)
						{
							printf("\nWELCOME BACK   %s ",accounts[i].accname);
							printf("\nYOUR MONTHLY INSTALLMENT %.2f",accounts[i].loan_installment);
							printf("\nENter 1 to pay");
							scanf("%d",&pay);
							if(pay==1)
							{
								accounts[i].amount-=accounts[i].loan_installment;
								accounts[i].loan_installment_paid='P';
								printf("\nYOUR EMI IS PAID SUCCESSFULLY");
								printf("\nAVAILABLE BALANCE :%d",accounts[i].amount);
								
							}
							else
							{
								printf("\nYOU CANCELLED PAYMENT");
							}
						}
						else
						{
							printf("\nYOU DONOT HAVE HAVE EMI");
						}
					}
					else
					{
						emi_s+=1;
					}
				}
				else
				{
					emi_s1+=1;
				}
			}
			if(emi_s==k)
			{
				printf("\nINVALID PASSCODE");
			}
			if(emi_s1==k)
			{
				printf("\nINVALID ACC NUM");
			}
}
