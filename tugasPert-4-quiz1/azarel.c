#include <stdio.h>
#include <string.h>

typedef long long int ll;
typedef unsigned long long int ull;
#define MAX_STACK 100

typedef struct {
	int top;
	char data[MAX_STACK];
} Stack;
Stack stackOperators;

char postfix[100];
int x = 0;

void init_stack() {
	stackOperators.top = -1;
}

char pop(){
	return stackOperators.data[stackOperators.top--];
}

void push(char input) {
	stackOperators.data[++stackOperators.top] = input;
} 

// apakah a > b?
void bandingkan(char soal, char stack) {
	if (stackOperators.top == -1){
		push(soal);
		return ;
	}
	if ((soal == '*' || soal == '/') && (stack == '+' || stack == '-')){
		push(soal);	
	} else {
		postfix[x++] = pop();
		bandingkan(soal, stackOperators.data[stackOperators.top]);
	} 
}

void pindahkan(char iterasi) {
	if (iterasi >= '0' && iterasi <= '9') {
		postfix[x++] = iterasi; 
	} else if (iterasi == '+' || iterasi =='-' || iterasi =='*' || iterasi == '/'){
		bandingkan(iterasi, stackOperators.data[stackOperators.top]);

    

	} 
}

int main() {
	char input[100];
	int j = 0;
	init_stack();
	fgets(input,100,stdin);
	for (size_t i = 0; i < strlen(input); i++) {
		pindahkan(input[i]);
		if (input[i] == ' ' || input[i] == '\n') {
			continue;
		}
	}
	while(stackOperators.top != -1) {
		postfix[x++] = pop();
	}
	printf("%s\n", postfix);
}
