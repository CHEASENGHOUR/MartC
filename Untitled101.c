#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main(){
	int code[30];
	char name[30][50];
	int qty[30];
	float price[30];
	int i,j,n,op;
	
	void Input(){
		printf("Enter Product Code : ");scanf("%d",&code[i]);
		printf("Enter Product Name : ");fflush(stdin);gets(name[i]);
		printf("Enter Product Quantity : ");scanf("%d",&qty[i]);
		printf("Enter Product Price : ");scanf("%f",&price[i]);
	}
	float Total(){
		return price[i] * qty[i];
	}
	void Head(){
		printf("|Code\t|Name\t|qty\t|price\t|Total\t|\n");
		printf("----------------------------------------------\n");
	}
	void Output(){
		printf("|%d\t|%s\t|%d\t|%.2f$\t|%.2f$\t|\n",code[i],name[i],qty[i],price[i],Total());
	}
	void clsUP(){
		system("cls");
		printf("\n\n\n");
	}
	void clsDOWN(){
		printf("\n\n\n");
		system("pause");
		system("cls");
	}
	do{
		printf("==================== Mart ================\n");
		printf("[1]. INPUT\n");
		printf("[2]. OUTPUT\n");
		printf("[3]. SEARCH\n");
		printf("[4]. UPDATE\n");
		printf("[5]. INSERT\n");
		printf("[6]. DELETE\n");
		printf("[7]. ADD\n");
		printf("[8]. SORT\n");
		printf("[9]. CASH MONEY\n");
		printf("[10]. CLEAN\n");
		printf("[11]. EXIT\n");
		printf("Enter Your Option above : ");
		scanf("%d",&op);
		switch(op){
			case 1:{
				clsUP();
				printf("How many product u wanna buy : ");scanf("%d",&n);
				for(i = 0; i < n ;i++){
					printf("=============== #%d Products ===============\n",i+1);
					Input();
				}
				clsDOWN();
			}break;
			case 2:{
				clsUP();
				Head();
				for(i = 0 ; i < n ; i++){
					Output();
				}
				clsDOWN();
			}break;
			case 3:{
				clsUP();
				int Search;
				int check = 0;
				printf("Enter Code to Search : ");scanf("%d",&Search);
				Head();
				for(i = 0; i < n ; i++){
					if(code[i] == Search){
						Output();
						check = 1;
					}
				}
				if(check == 0){
					printf("Search Not Found!!\n");
				}else{
					printf("\n\n\n\t\t\t\t\t Success!!!\n");
				}
				clsDOWN();
			}break;
			case 4:{
				clsUP();
				char Up[25];
				int k = 0;
				printf("Enter Name to update : ");fflush(stdin);gets(Up);
				for(i = 0 ; i < n ; i++){
					if(strcmp(Up,name[i])==0){
						Input();
						k = 1;
					}
				}
				if(k == 0){
					printf("Search Not Found!!\n");
				}else{
					printf("\n\n\n\t\t\t\t\t Success!!!\n");
				}
				clsDOWN();
			}break;
			case 5:{
				clsUP();
				int Code;
				int k = 0;
				printf("Enter Code to Search and Insert : ");scanf("%d",&Code);
				for(i = 0; i < n; i++){
					if(code[i] == Code){
						for(j = n ; j >= i ; j--){
							code[j] = code[j - 1];
							strcpy(name[j],name[j - 1]);
							qty[j] = qty[j - 1];
							price[j] = price[j - 1];
						}
						n++;
						k = 1;
						Input();
						break;
					}
				}
				if(k == 0){
					printf("Search Not Found!!\n");
				}else{
					printf("\n\n\n\t\t\t\t\t Success!!!\n");
				}
				clsDOWN();
			}break;
			case 6:{
				clsUP();
				int Del;
				int k = 0;
				printf("Enter Code to Delete : ");scanf("%d",&Del);
				for(i = 0 ; i < n ; i++){
					if(code[i] == Del){
						for(j = i ; j > n ; j++){
							code[j] = code[j + 1];
							strcpy(name[j],name[j + 1]);
							qty[j] = qty[j + 1];
							price[j] = price[j + 1];
						}
						n--;
						k = 1;
					}
				}
				if( k == 0){
					printf("Search Not Found !!!");
				}else{
					printf("\t\t\t\tSuccess!!!");
				}
				clsDOWN();
			}break;
			case 7:{
				clsUP();
				int Ad;
				printf("Enter more : ");scanf("%d",&Ad);
				for(i = n ; i < n + Ad ; i++){
					printf("=============== #%d Products ===============\n",i+1);
					Input();
				}
				n = n + Ad;
				printf("\t\t\t\t\t\tSuccess !!!\n");
				clsDOWN();
			}break;
			case 8:{
				clsUP();
				for(i = 0 ; i < n ; i++){
					for(j = i + 1; j < n ; j++){
						if(price[i] > price[j]){
							int codee = code[i];
							code[i] = code[j];
							code[j] = codee;
							char namee[20];
							strcpy(namee, name[i]);
							strcpy(name[i],name[j]);
							strcpy(name[j],namee);
							int qtyy = qty[i];
							qty[i] = qty[j];
							qty[j] = qtyy;
							float pricee = price[i];
							price[i] = price[j];
							price[j] = pricee;
						} 
					}
				}
				printf("\t\t\t Success!!\n");
				clsDOWN();
			}break;
			case 9:{
				clsUP();
				float sum = 0;
				char xop[20];
				float cash_recieve, cash_return,tip;
				for(i = 0 ; i < n ; i++){
					sum = sum + Total();
				}
				printf("All Amount : %.2f$\n",sum);
				printf("All Amount : %.2fKHR\n",sum*4100);
				printf("Pay in Dollar or Riel : ");fflush(stdin);
				gets(xop);
				if(stricmp(xop,"Dollar")==0){
					while(true){
					printf("Enter Cash : ");scanf("%f",&cash_recieve);
					if(cash_recieve > sum){
						cash_return = cash_recieve - sum;
						printf("This Your Change : %.2f$\n",cash_return);
						printf("Where our Tips : ");scanf("%f",&tip);
						cash_return = cash_return - tip;
						system("pause");
						printf("This Your Change : %.2f$\n",cash_return);
						break;
						}
					}
				}
				if(stricmp(xop,"Riel")==0){
					while(true){
					printf("Enter Cash : ");scanf("%f",&cash_recieve);
					if(cash_recieve > sum*4100){
						cash_return = cash_recieve - sum*4100;
						printf("This Your Change : %.2fKHR\n",cash_return);
						printf("Where our Tips : ");scanf("%f",&tip);
						cash_return = cash_return - tip;
						system("pause");
						printf("This Your Change : %.2fKHR\n",cash_return);
						break;
						}
					}
				}
				clsDOWN();
			}break;
			case 10:{
				system("cls");
			}break;
			default:{
				int k = 145 ;
				char n = (char)k;
				printf("\t\t\t %c%c Bye bye \1 \3 %c%c\n",n,n,n,n);
			}break;
		}
	}while(op < 11);
}
