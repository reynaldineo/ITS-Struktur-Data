#include <stdio.h>
#define MAX_STACK 10

typedef struct { 
  int top;
  int data[10];
} stack;

stack tumpuk;

void inisialisasi() {
  tumpuk.top=-1;}

int isFull() {
  return (tumpuk.top==MAX_STACK-1) ? 1 : 0;}

int isEmpty() {
  return (tumpuk.top==-1) ? 1:0;}

void Push(int datanya) {  
  tumpuk.data[++tumpuk.top]=datanya; }

void Pop()
{ printf ("data ter-ambil %d \n",tumpuk.data[tumpuk.top]) ;tumpuk.top--; }

void tampilstack()
{ for(int i=tumpuk.top;i>=0;i--) printf("Data stack ke %d adalah %d \n",i,tumpuk.data[i]);}

void masukkanData() { 
  int datanya;
  while(!isFull()) {
  printf("masukkan data ");
  scanf("%d",&datanya);
  Push(datanya);
  }
}

void ambilData()
{  while(!isEmpty()) Pop();}

int main () {
  int operand [10];
  int operator [10];

  int postfix[100];

  // stack tumpuk;

  int jumlah;
  printf("jumlah data ");
  scanf("%d", &jumlah);

  for (int i = 0; i < jumlah; i++) {
    printf("operand : ");
    scanf("%d", &operand[i]);

    postfix[i]=operand[i];

    printf("\npilih angka untuk simbol operasi");
    printf("\n1.+ 2.- 3.* 4.bagi 5.selesai\n\n");
    scanf("%d", &operator[i]);

    if (operator[i]>tumpuk.top)
    {
    Push(operator[i]);
    } else if (operator[i]==1)
    {
      postfix[i] + postfix
    }
    
    


    masukkanData();

    // if (operator[i] == 1) printf("%d + %d", operand[i], operand[++i]");
    // else if (operator[i] == 2) printf("%d - %d", operand[i], operand[++i]);
    // else if (operator[i] == 3) printf("%d * %d", operand[i], operand[++i]);
    // else if (operator[i] == 4) printf("%d / %d", operand[i], operand[++i]);
  }

  /*
  1. operand masukin ke postfix
  */  


  
}