#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 10

typedef struct STACK{
  int top;
  int data[10];
};
STACK tumpuk;

void inisialisasi() {
  tumpuk.top=-1;}

int isFull() {
  return (tumpuk.top==MAX_STACK-1) ? 1 : 0;}

int isEmpty() {
  return (tumpuk.top==-1) ? 1:0;}

void Push(int datanya) {  
  tumpuk.data[++tumpuk.top]=datanya; }

void Pop()
{ printf (“data ter-ambil %d \n",tumpuk.data[tumpuk.top]) ;tumpuk.top-- }}

void tampilstack()
{ for(int i=tumpuk.top;i>=0;i--) printf("Data stack ke %d adalah %d \n",i,tumpuk.data[i]);}

void masukkanData()
{ int datanya;while(!isFull())fiprintf("masukkan data ");scanf("%d",&datanya) ; Push(datanya)}

void ambilData()
{  while(!ismpty()) Pop()}

int main()
{ inisialisasi(); masukkanData(); tampilStack(); ambilData(); system("pause") return 0;}