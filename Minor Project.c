#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#define ENTER 13
#define TAB 9
#define BKSPC 8
#define COLA "\033[38;2;96;215;214m"
#define COLB "\033[0m"
#define REDA "\033[0;31m"
#define REDB "\033[0m"
struct user{
 char name[50];
 char email[50];
 char phone[50];
 char password[50];
};
struct menu{
    int sno;
   char name [30];
   float price;
};

struct order{
	char phone[20];
	char name[10] [30];
	int qt[10];
	char status[50];
	float total;
	int nitm;
};

void take(char pwd[50]){              //TO TAKE STRING INPUT 
	int i=0;
    char ch;
    int temp=0;
    while(1){
        ch =getch();
        if(ch ==ENTER || ch == TAB){
            pwd[i] ='\0';
            break;
            
        }else if (ch ==BKSPC){
		 if(i>0){
            printf("\b \b");
            i--;
        }
        }
        	else{
        
            pwd[i++]=ch;
              printf("%s%c%s",COLA,ch,COLB);
        }
        
    }
}
void takeemail(char pwd[50]){                // TO TAKE EMAIL  ' @ ' ' . ' REQUIRED
    int i=0;
    char ch;
    int temp=0,temp1=0;
    while(1){
        ch =getch();
        if(ch ==ENTER || ch == TAB){
            if(i<5){
                printf("\nmust contain atleast 5 Characters : ");
                do{
                    pwd[i]='\0';
                    i--;
                }while(i>0);
            }else if(temp!=1 || !(temp1>0)){
            	 printf("\nINVALID EMAIL :\t");
                do{
                    pwd[i]='\0';
                    i--;
                }while(i>0);
                temp =0;
			}
			else{
            pwd[i] ='\0';
            break;
            }
        }else if (ch ==BKSPC)
        {   if(i>0){
            printf("\b \b");
            i--;
            if(pwd[i]=='@'){
            	temp--;
			}else if(pwd[i]=='.'){
				temp1--;
			}
        }
        }else if(ch == '@'){
        	pwd[i++]=ch;
            printf("%c",ch);
        	temp++;
		}else if(ch == '.'){
        	pwd[i++]=ch;
            printf("%c",ch);
        	temp1++;
		}
        else{
            pwd[i++]=ch;
            printf("%c",ch);
        }
        
    }
}
void takeno(char pwd[50]){       //TO TAKE PHONE NO 10 DIGIT
    int i=0,temp1=0,j;
    char ch;
    int temp[20];
    for(i=0;i<20;i++){
    	temp[i]=0;
	}
	i=0;
    while(1){
        ch =getch();
        if(ch ==ENTER || ch == TAB){
        	for(j=0;j<=i;j++){
        		if(temp[j]==1){
        			
        			temp1++;
				}
			}
            if(i!=10 || temp1!=0){
            	 printf("\n%sinvalid :\t%s",COLA,COLB);
            	
                do{
                	
                    pwd[i]='\0';
                    i--;
                temp[i]=0;
				}while(i>0);
                if(temp1!=0){
                	temp1=0;
				}
			}
			else{
            pwd[i] ='\0';
            break;
            }
        }else if (ch ==BKSPC){
		 if(i>0){
            printf("\b \b");
           i--;
           temp[i]=0;
            
        }
        }else if(i>9){
        	pwd[i++]=ch;
            printf("\033[0;31m%c\033[0m",ch);
            
		}
		else if(!isdigit(ch)){
			temp[i]=1;
			pwd[i++]=ch;
           printf("\033[0;31m%c\033[0m",ch);
			
		}
        	else{
        
            pwd[i++]=ch;
              printf("%s%c%s",COLA,ch,COLB);
        }
        
    }
}


void takealpha(char pwd[50]){                 //TO TAKE ONLY ALPHABETS
    int i=0,temp1=0,j;
    char ch;
    int temp[20];
    for(i=0;i<20;i++){
    	temp[i]=0;
	}
	i=0;
    while(1){
        ch =getch();
        if(ch ==ENTER || ch == TAB){
        	for(j=0;j<=i;j++){
        		if(temp[j]==1){
        			
        			temp1++;
				}
			}
            if(temp1!=0 || i<1){
            	 printf("\n%sinvalid :\t%s",COLA,COLB);
            	
                do{
                	
                    pwd[i]='\0';
                    i--;
                temp[i]=0;
				}while(i>0);
                if(temp1!=0){
                	temp1=0;
				}
			}
			else{
            pwd[i] ='\0';
            break;
            }
        }else if (ch ==BKSPC){
		 if(i>0){
            printf("\b \b");
           i--;
           temp[i]=0;
            
        }
        }else if(isdigit(ch)){
			temp[i]=1;
			pwd[i++]=ch;
           printf("\033[0;31m%c\033[0m",ch);
			
		}
        	else{
        
            pwd[i++]=ch;
              printf("%s%c%s",COLA,ch,COLB);
        }
        
    }
}

void takepassword(char pwd[50]){    //TO TAKE PASSWORD WITH ' * '
    int i=0;
    char ch;
    while(1){
        ch =getch();
        if(ch ==ENTER || ch == TAB){
            if(i<8 ){
                printf("\nPassword must contain atleast 8 Characters : \n");
                do{
                    pwd[i]='\0';
                    i--;
                }while(i>0);
            }else {
            pwd[i] ='\0';
            break;
            }
        }else if (ch ==BKSPC)
        {   if(i>0){
            printf("\b \b");
            i--;
        }
        }
        else{
        	
            pwd[i++]=ch;
            printf("* \b");
        }
        
    }
}

int main()
{	
	
	start: ;
	int loop=0;
	system("cls");
    struct user user;
    system("color 0b");
    int opt ,usrFound = 0;;
    FILE *fp ,*od;
    char password2[50];
    struct user usr;
   printf("\n\t\t\t\t\t\t\t\t <-------- Welcome To foodstall -------->\n\n");
   printf("\n1)Register\n2)Login\n3Forgot Password?\n4)Exit\n\n Your Choice:");
    scanf("%d",&opt);
    fgetc(stdin);
    switch (opt)
    {
    case 1:
    	reg:
      system("cls");
      		printf("\n\t\t\t\t\t\t\t\t <-------- Registeration -------->\n\n");
			printf("\nEnter your full name:\t");
			takealpha(user.name);
			system("color 0b");
			printf("\nEnter your email:\t");
			takeemail(user.email);
			printf("\nEnter your contact no:\t+91");
			takeno(user.phone);
			system("color 0b");
			printf("\nEnter your password:\t");
			takepassword(user.password);
			printf("\nConfirm your password:\t");
			takepassword(password2);
			struct user us;
				fp = fopen("Users.dat","r");
				while(fread(&us,sizeof(struct user),1,fp)){
				if(!strcmp(us.email,user.email)){
					printf("\nEmail Already Registered\nTry Again!!");
					fclose(fp);
					getch();
					goto reg;
				}if(!strcmp(us.phone,user.phone)){
					printf("\nPhone No Already Registered\nTry Again!!");
					fclose(fp);
					getch();
					goto reg;
				}
			}
			if(!strcmp(user.password,password2)){
				generate:
				fp = fopen("Users.dat","a+");
				fwrite(&user,sizeof(struct user),1,fp);
				if(fwrite != 0){
				 printf("\n\nUser registration success, Your email is %s",user.email);
				 fclose(fp);
				 getch();
				goto login;
				}
				else printf("\n\nSorry! Something went wrong :(");
       }else{
        int temp =3;
           while(temp>=1){
            Beep(700,300);
             printf("\nPassword Not Matched %d Attempts Left !!\n\n",temp);
            printf("\nEnter the Password Again !! :\t");
       takepassword(user.password); 
       printf("\nEnter the Confirm Password Again !! :\t");
            takepassword(password2);
            temp--;
            if(!strcmp(user.password,password2)){
           break;
        }
       }
        if(!strcmp(user.password,password2)){
            goto generate;
        }
       }
       fclose(fp);
        break;
        case 2: 
        	login: ;
        	system("cls");
        		printf("\n\t\t\t\t\t\t\t\t <-------- Login -------->\n\n");
       		char username[50],pword[50];
			struct user usr;
			
			printf("\nEnter your email:\t");
			takeemail(username);
			printf("\nEnter your password:\t");
			takepassword(pword);
			
			fp = fopen("Users.dat","r");
			while(fread(&usr,sizeof(struct user),1,fp)){
				if(!strcmp(usr.email,username)){
					if(!strcmp(usr.password,pword)){
						
                        menu: 
						system("cls");
						printf("\n\t\t\t\t\t\tWelcome %s",usr.name);
						printf("\n\n|Full Name:\t%s",usr.name);
						printf("\n|Email:\t\t%s",usr.email);
						printf("\n|Contact no.:\t%s",usr.phone);	
						fclose(fp);
						printf("\n\n\nEnter Choice\n\n1)Take Order\n2)Manage Items\n3)Orders Details\n4)Log Out\n");
                        int mm;
                        scanf("%d",&mm);
                         
					switch (mm)
                    {
                    case 1: ;
								int i=0,inp=0 ,inp2=0,j=0;
								int n=0; 
								char* arr[10];
								char*ar[10];
								char pend[50] ="pending";
								struct order ord;
								system("cls");
                    		 printf("\n\t\t\t\t\t\t\t\t <-------- Take Order -------->\n\n\n");
                    		  char phone[20];
							 printf("Enter customer phone no :");
                    		 takeno(phone);
                    		 system("color 0b");
                    		order: ;
                    		system("cls");
                    		 printf("\n\t\t\t\t\t\t\t\t <-------- Take Order -------->\n\n\n");
                           struct menu a;
                           struct menu b;
                           char inv2[10];
                      	int itemp =0,order ,quantity,ite ;
                        
						float total ,temp=0;
                        char opt;
                       
                        printf("\tSNO\t\tITEM NAME\t\tPRICE");
                           fp = fopen ("items.txt", "r");
						   while(fread (&a, sizeof (a) ,1,fp)){
						      
						      printf("\n\t%d\t\t%s\t\t\t%.2f", a. sno,a.name,a.price);
						      itemp++;
						    
						   }
						   fclose(fp);
						   		if(itemp==0){
						   			printf("\n%s 0 Items Available Add Item In Menu \n| 1 Add Item \n| 2 Go Back %s",REDA,REDB);
						   			scanf("%d",&ite);
						   			if(ite==1) {
									   system("color 0b");
									   goto add;
									   }
									   else{
									    system("color 0b"); goto menu;
								}
						   			
								   }
						   	printf("\nEnter SNO to order ([99]<-To Search [0]<-To Remove Item) :");
						   	take(inv2);
						   	system("color 0b");
						   	 if (sscanf(inv2, "%d", &order) != 1) {
							  		printf("%s\nInvalid%s",REDA,REDB);
									  getch();
									  system("color 0b");
									  goto order;
							  }
						   	int stemp=0;
						   	if(order==99){
						   		char se[20];
						   		
						   		printf("\nEnter Sno Or Food Name : ");
						   		take(se);
						   		int se2 = atoi(se);
						   		system("color 0b");
						   		fp=fopen("items.txt","r");
						   				
						   			if(se2>0){
						   			
						   				while(fread (&b, sizeof (b) ,1,fp)){
						   					if(se2==b.sno){
						   						order=b.sno;
						   						fclose(fp);

						   						stemp++;
						   						
											   }
									   }
								   
							   }else{
							   		while(fread (&b, sizeof (b) ,1,fp)){
						   					if(!strcmp(se,b.name)){
						   						order=b.sno;
						   						fclose(fp);
						   						stemp++;
						   						
											   }
									   }
							   }
							   if(stemp!=1) {
							   	printf("\nItem Not Found");
							   	stemp=0;
							   	getch();
							   	goto order;
							   }else stemp=0;
							   }
							   else if(order==0){
							   if(inp2==0){
							   		printf("\n%s0 item selected !%s",REDA,REDB);
							   		getch();
							   		system("color 0b");
							   		goto order;
							   		
								   }
								   else{
								   	int t;
								   	printf("\n-----------------------------------");
								   	for(t=0;t<j;t++){
										
										printf ("\nItem %d = %s Quantity = %d",t,ord.name[t], ord.qt[t]);
										}
										printf("\nTotal Right Now : %0.2f",total);
										printf("\n-----------------------------------");
										printf("\nWhich item To remove? : ");
										take(inv2);
										system("color 0b");
										if (sscanf(inv2, "%d", &t) != 1) {
							  		printf("%s\nInvalid Retry%s",REDA,REDB);
									  getch();
									  system("color 0b");
									  goto order;
							  			}
							  			if(!(t<j && t>=0)){
							  				printf("\nItem Not Present in Cart");
							  				getch();
							  				goto alter;
										  }
							  			fp=fopen("items.txt","r");
							  			while(fread (&b, sizeof (b) ,1,fp)){
						   					if(!strcmp(b.name,ord.name[t])){
						   						total=total-(b.price*ord.qt[t]);
											   }
									   }
									   	fclose(fp);
							  			for(loop=t;loop<j;loop++){
							  				strcpy(ord.name[loop],ord.name[loop+1]);
							  				ord.qt[loop]=ord.qt[loop+1];
							  				j--;
										  }
							  			
							  			printf("\nDONE");
							  			getch();
							  			goto alter;
								   }
							   }
							   
						   	printf("\nEnter Quantity :");
						   	scanf("%d",&quantity);
						   	 fp = fopen ("items.txt", "r");
						   	 
						   	 while(fread (&b, sizeof (b) ,1,fp)){
						      if(b.sno==order){
						      	
						      	temp=b.price * quantity;
						      	total =total+temp;
						      	strcpy(ord.name[j],b.name);
						      	ord.qt[j]=quantity;
						      	strcpy(ord.status,pend);
						      	printf("Product : %s Quantity : %d Unit-Price : %2.f\n",ord.name[j],ord.qt[j],b.price);
						      		inp++;	
						      		inp2++;
						      		j++;
							  }
							  
									  	
							  
							  	}if(inp!=1){
							   printf("%s| Wrong Input %s",REDA,REDB);
							  		getch();
							  		
									}else inp=0;
						    		
						    		system("color 0b");
						    		alter :
						    	printf("\nBuy another item? (y , n) :");
						    	scanf("%s",&opt);
						    	system("color 0b");
						    	if(opt=='y'){
						    		fclose(fp);
									goto order;
									
								}
								else if(opt=='n'){
											if(inp2>0){
											int	jtemp=j;
											ord.nitm=j;
												j=0;
											system("cls");
											printf("\n\t\t\t\t\t\t\t\t <-------- Billing -------->\n\n\n");
											
												ord.total=total;
												strcpy(ord.phone,phone);
											od=fopen("orders.txt","a+");
										fwrite(&ord,sizeof(struct order),1,od);
										fclose(od);
						      		
										od = fopen("orders.txt","r");
										printf("Phone : %s",ord.phone);
										for(j=0;j<jtemp;j++){
										
										printf ("\nItem %d = %s Quantity = %d",j ,ord.name[j], ord.qt[j]);
										}
										printf("\nTotal : %0.2f",ord.total);
										
									
										
										fclose(od);
									
									printf("\nPress Any Key To Go To Menu!!"); 
									total=0;
								}else{
									printf("No Item Selected");
									printf("\nPress Any Key To Go To Menu!!");
									total=0;
								}
									
								}
								else printf("Wrong Input");
							fclose(fp);	   
						   getch( );
						goto menu;
                        break;
                    case 2: ;
                    			system("cls");
                    			printf("\n\t\t\t\t\t\t\t\t <-------- Manage Items -------->\n\n\n");
                            struct menu menu;
                            int t;
                        printf("\n1)Add Item\n2)Delete Item\n3)View Menu\n4)Go Back\n");
                        scanf("%d",&t);
                        switch (t)
                        {
                        case 1:;
                        	add :
                        	system("cls");
                        struct menu person;
                        struct menu s2;
						   int i;
						   char inv[10];
						   fp = fopen ("items.txt", "a+");
						   od = fopen("items.txt","r");
						   
								 printf("Enter Item Name: ");
							   takealpha(person.name);
							   system("color 0b");
						      printf("\nEnter Sno : ");
						      take(inv);
						      system("color 0b");
						      if (sscanf(inv, "%d", &person.sno) != 1) {
							  		printf("\nInvalid SNO \nPress any key to go back");
							  			fclose(fp);
							  			fclose(od);
									  getch();
									  goto menu;
							  }
						      printf("\nPrice : ");
						       take(inv);
						      system("color 0b");
						      
						      
						      if (sscanf(inv, "%f", &person.price) != 1) {
							  		printf("\nInvalid\nPress any key to go back");
							  			fclose(fp);
							  			fclose(od);
									  getch();
									  goto menu;
							  }
						      if(person.sno==99 ){
								  	printf("\nChoose different Sno [99] , [0] Not Available ");
						      		getch();
						      		fclose(fp);
						      		fclose(od);
						      		goto menu;
								  }else if(person.sno == 0){
								  	printf("\nChoose different Sno [99] , [0] Not Available ");
						      		getch();
						      		fclose(fp);
						      		fclose(od);
						      		goto menu;
								  }
						      
						      while(fread(&s2,sizeof(s2),1,od)){
						      	if(person.sno==s2.sno || !strcmp(person.name,s2.name)) {
						      		printf("\nProduct Alread Exist ");
						      		getch();
						      		fclose(fp);
						      		fclose(od);
						      		goto menu;
								  }
								  
							  }
						      fwrite(&person, sizeof(person),1,fp);
						   	if(fwrite!=0)printf("\nItem Added !! ");
							   else printf("\nError Occurred Try Again !! \n");
						   fclose (fp);
						   fclose(od);
						   	getch();
                            goto menu;
                            break;
                        case 2:
                        		system("cls");
                        		struct menu d;
                        		int sno ,temp=0;
                        		printf("\nEnter The SNO You Want To Delete : ");
                        		scanf("%d",&sno);
								
                        		fp=fopen("items.txt","r");
                        		od=fopen("temp.txt","a+");
                        		while(fread(&d,sizeof(d),1,fp)){
                        			if(d.sno!=sno){
                        				fwrite(&d,sizeof(d),1,od);
									}else{
									temp++;}
								}
								if(fwrite!=0 && temp!=0){
								 printf("\nItem Deleted !!\n");
									fclose(fp);
									fclose(od);
								 remove("items.txt");
								 rename("temp.txt","items.txt");
								}else if(temp==0){	
									fclose(fp);
								fclose(od);
								printf("\nItem Not Found !!\n");
								}
								getch();
								goto menu;
									
								break;
								case 3: 
								system("cls");
								fp = fopen ("items.txt", "r");
								printf("\tSNO\t\tITEM NAME\t\tPRICE");
						   while(fread (&a, sizeof (a) ,1,fp)){
						      
						      printf("\n\t%d\t\t%s\t\t\t%.2f", a. sno,a.name,a.price);
						      itemp++;
						    
						   }
						   fclose(fp);
						   		if(itemp==0){
						   			printf("\n%s 0 Items Available Add Item In Menu \n| 1 Add Item \n| 2 Go Back %s",REDA,REDB);
						   			scanf("%d",&ite);
						   			if(ite==1) {
									   system("color 0b");
									   goto add;
									   }
									   else{
									    system("color 0b"); goto menu;
								}
						   			
								   }
								   getch();
								case 4:;
								goto menu;
                        default:
                        		goto menu;
                        }
                        case 3: ; ordd:;
                        			system("cls");
                        			printf("\n\t\t\t\t\t\t\t\t <-------- Orders Details -------->\n\n\n");
                        			printf("\n1)View Pending Orders\n2)All Orders\n3)Delete Order\n4)Search By No \n5)Back\t");
                        			int p;
                        			scanf("%d",&p);
                        			switch(p){
									case 1: ;
                        			system("cls");
                                    struct order ord3;
                                
                        		printf("\n\t\t\t\t\t\t\t\t <-------- Pending orders -------->\n\n\n");
                        		od=fopen("orders.txt","r");
                        			char ped[50]="pending";
                        			
								while(fread(&ord3,sizeof(struct order),1,od)){
									if(!strcmp(ord3.status,ped)){
										printf("\n|Phone : %s",ord3.phone);
										
										for(j=0;j<ord3.nitm;j++){
										
										printf ("\n|Item = %s Quantity = %d",ord3.name[j], ord3.qt[j]);
										}
										printf("\n|Total : %0.2f",ord3.total);
										printf("\n------------------------------------------");
								}}
								fclose(od);
								int pd;
								
								printf("\n1)Update Status\n2)Go Back\n");
								scanf("%d",&pd);
								switch (pd){
								case 1: ;	
										system("cls");
                        		
                        		struct order ord5 ,ord4;
                        		char no[20];
								int temp=0;
                        		printf("Enter The Phone No to update : ");
                        		takeno(no);
								system("color 0b");
                        		fp=fopen("orders.txt","r");
                        		od=fopen("odtemp.txt","a+");
                        		while(fread(&ord4,sizeof(ord4),1,fp)){
                        			if(strcmp(ord4.phone,no)){
                        				
                        				fwrite(&ord4,sizeof(ord4),1,od);
                        				
									}else if(!strcmp(ord4.phone,no)){
										strcpy(ord5.phone,ord4.phone);
										strcpy(ord5.status,"completed");
										ord5.total=ord4.total;
										ord5.nitm=ord4.nitm;
										for(loop=0;loop<ord4.nitm;loop++){
										strcpy(ord5.name[loop],ord4.name[loop]);
										ord5.qt[loop]=ord4.qt[loop];
										
									}
										fwrite(&ord5,sizeof(ord5),1,od);
									temp++;}
								}
								if(fwrite!=0 && temp!=0){
								 printf("\nDone !!\nPress any key to go back!!");
									fclose(fp);
									fclose(od);
								 remove("orders.txt");
								 rename("odtemp.txt","orders.txt");
								}else if(temp==0){	
									fclose(fp);
								fclose(od);
								printf("\norder notfound !!\n press any key to go back!!");
								}
								getch();
								goto menu;
								default : ;
										goto ordd;
								}							
								case 2: ;
									system("cls");
                                    
                                
                        		printf("\n\t\t\t\t\t\t\t\t <-------- All orders -------->\n\n\n");
                        		od=fopen("orders.txt","r");
                        				while(fread(&ord3,sizeof(struct order),1,od)){
								
										printf("\n|Phone : %s",ord3.phone);
										int j;
										for(j=0;j<ord3.nitm;j++){
										
										printf ("\n|Item = %s Quantity = %d",ord3.name[j], ord3.qt[j]);
										}
										printf("\n|Total : %0.2f\n",ord3.total);
										printf("\n-----------------------------------");
								}
								fclose(od);
								getch();
									goto ordd;
											case 3: ;
											system("cls");
                        		struct order dltord;
                        			char noo[20] ;
								int temp=0;
                        		printf("Enter The Phone No You Want To Delete : ");
                        		takeno(noo);
								system("color 0b");
                        		fp=fopen("orders.txt","r");
                        		od=fopen("ortemp.txt","a+");
                        		while(fread(&dltord,sizeof(dltord),1,fp)){
                        			if(strcmp(dltord.phone,noo)){
                        				fwrite(&dltord,sizeof(dltord),1,od);
									}else{
									temp++;}
								}
								if(fwrite!=0 && temp!=0){
									fclose(fp);
									fclose(od);
									system("cls");
								
								 printf("\norder Deleted !!\npress any key to go back");
									fclose(fp);
									fclose(od);
									remove("orders.txt");
								 rename("ortemp.txt","orders.txt");
									}else if(temp==0){	
									fclose(fp);
								fclose(od);
								printf("\norder Not Found !!\npress any key to go back");
								}
								getch();
								goto ordd;		
								case 4: ;
								system("cls");
                        		struct order ord4;
                        		char no[20];
                        		int et=0;
                        		printf("Enter The Phone No : ");
                        		takeno(no);
								system("color 0b");
                        		fp=fopen("orders.txt","r");
                        		while(fread(&ord4,sizeof(ord4),1,fp)){
                        			if(!strcmp(ord4.phone,no)){
                        				
                        				printf("\n|Phone : %s",ord4.phone);
										int j;
										for(j=0;j<ord4.nitm;j++){
										
										printf ("\n|Item = %s Quantity = %d",ord4.name[j], ord4.qt[j]);
										}
										printf("\n|Total : %0.2f\n",ord4.total);
										printf("\n-----------------------------------");
                        				et++;
									}
									}
									if(et==0){
										printf("\n\n| 0 Orders with %s Phone No .",no);
									}
									fclose(fp);
									getch();
								goto ordd;
								case 5: ;
								goto menu;
								default : ;
								goto menu;
							}
								case 4: ;
								 goto start;
                    default: ;
                        goto menu;
                    }
					
					
					
					
					}
					else {
					printf("\n\nInvalid Password! Try Again!!");
						Beep(800,300);
						getch();
						goto login;
					}
					usrFound = 1;
				}
			}
			if(!usrFound){
				Beep(800,300);
				printf("\n\nUser is not registered! \npress any key to go back!!");
					fclose(fp);
					getch();
					goto start ;
			}
			fclose(fp);
			break;
			
		case 3: ;
								
								system("cls");
                        		int tempq=0;
                        		char ema[50] , noo1[50] ;
                        		printf("\nEnter The Phone No  : ");
                        		takeno(noo1);
                        		system("color 0b");
								printf("\nEnter Email :");
								takeemail(ema);
                        		fp=fopen("orders.txt","r");
                        		char ppw[50], pwp[50];
                        		struct user ussr , use;
									fp = fopen("Users.dat","r");
									od=fopen("temp.dat","a+");
									while(fread(&ussr,sizeof(struct user),1,fp)){
									if(strcmp(ussr.email,ema) && strcmp(ussr.phone,noo1)){
								
										fwrite(&ussr,sizeof(struct user),1,od);
									
									}else if(!strcmp(ussr.email,ema) && !strcmp(ussr.phone,noo1)){
									
												printf("\nEnter New Password :");
												takepassword(ppw);
												printf("\nEnter Confirm Password :");
												takepassword(pwp);
												if(!strcmp(ppw,pwp)){
										
											strcpy(ussr.password,ppw);
											fwrite(&ussr,sizeof(struct user),1,od);
											
												tempq++;
											}
									}
								}
								if(fwrite!=0 && tempq!=0){
								 printf("\nDone !!\nPress any key to go back!!");
									fclose(fp);
									fclose(od);
								 remove("Users.dat");
								 rename("temp.dat","Users.dat");
								}else if(tempq==0){	
									fclose(fp);
								fclose(od);
								remove("temp.dat");
								printf("\nNot found !!\npress any key to go back!!");
								}
								getch();
								goto start;
			case 4: ;
					break;
					default : ;
					goto start;
		
	}
    
    
    return 0;
}
