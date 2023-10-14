#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n;
struct athlete {
	char Name[50];
	char Nation[50];
	int Register[3];
	short Pass[3];
	int Total;
	char Medal;
}; 

void form(){
  printf("%-20s","Name");
	printf("%-20s","Nation");
	printf("%-10s","R1");
	printf("%-10s","R2");
	printf("%-10s","R3");
  printf("%-10s","P1");
	printf("%-10s","P2");
	printf("%-10s","P3");
	printf("\n");
}
void form2(){
  printf("%-20s","Name");
	printf("%-20s","Nation");
	printf("%-10s","R1");
	printf("%-10s","R2");
	printf("%-10s","R3");
  printf("%-10s","P1");
	printf("%-10s","P2");
	printf("%-10s","P3");
  printf("%-10s","Total");
  printf("\n");
}
typedef struct athlete ath;
void sovdv(ath *a){
    printf("Nhap so van dong vien dang ky : ");
    scanf("%d",&n);
    while(n<=0||n>100){
    	printf("Nhap lai so van dong vien :");
    	scanf("%d",&n);
      }
}
void nhapthongtin(ath *a){
	int i,j;
	for(i=0;i<n;i++){
		printf("Nhap thong tin cua van dong vien thu %d\n",i+1);
		printf("Ten cua van dong vien:");
		fflush(stdin);
		fgets(a[i].Name,32,stdin);
    int size=strlen(a[i].Name)-1;
		a[i].Name[size]='\0';
		printf("Quoc tich cua van dong vien:");
		fflush(stdin);
		scanf("%s",a[i].Nation);
    for(j=0;j<3;j++){
			printf("Nhap R%d cua van dong vien thu %d : ",j+1,i+1);
			scanf("%d",&a[i].Register[j]);
			printf("Nhap P%d cua van dong vien thu %d : ",j+1,i+1);
			scanf("%d",&a[i].Pass[j]);
    }
  }
}

void inthongtin(ath *a){
  int i,j;
  form();
	for(i=0;i<n;i++){
		printf("%-20s",a[i].Name);
		printf("%-20s",a[i].Nation);
    for(j=0;j<3;j++){
		printf("%-10d",a[i].Register[j]);
		printf("%-10d",a[i].Pass[j]);
    }
    printf("\n");
	}
}

void tinhtong(ath *a){
  int i,j;
  form2();
	for(i=0;i<n;i++){
		printf("%-20s",a[i].Name);
		printf("%-20s",a[i].Nation);
    for(j=0;j<3;j++){
		printf("%-10d",a[i].Register[j]);
		printf("%-10d",a[i].Pass[j]);
    if(a[i].Pass[j]==1)
      a[i].Total+=a[i].Register[j];
    }
    printf("%-10d",a[i].Total);
    printf("\n");
	}
}
int main(){
	ath a[22];
  sovdv(a);
	nhapthongtin(a);
  inthongtin(a);
  tinhtong(a);
}