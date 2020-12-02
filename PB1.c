#include <stdio.h>
#include <string.h>
#include <ctype.h>

int CHECK_KEYWORD(char *);
int CHECK_IDENTIFIER(char *);
int CHECK_CONST(char *);
int CHECK_SPL(char *);
int CHECK_ARTH(char *);
int CHECK_RELATION(char *);
int CHECK_COMMENT(char *);

char Keywords[32][10] = {"auto", "double", "int", "struct", "break", "else", "long", "switch",
						"case", "enum", "register", "typedef", "char", "extern", "return", "union",
						"continue", "for", "signed", "void", "do", "if", "static", "while", "default",
						"goto", "sizeof", "volatile", "const", "float", "short", "unsigned"};
						
char SPL[13] = {'$', '#', '&', '^', '{', '}', '[', ']', '?', ':', '(', ')', ';'};
char ARTH[6] = {'+', '-', '*', '/', '%'};
char RELATION1[2] = {'>', '<',};
char RELATION2[4][2] = {">=", "<=", "==", "!="};
int count = 0;

int main() {
	char get_data[20];
	printf("Enter Data : ");
	gets(get_data);
	
	int len = strlen(get_data);
	int i = 0;
	
	while (1) {
		char temp[20] = {'\0'};
		int j = 0;
		
		while (i-1 != len) {
			if (isspace(get_data[i]))
				break;
			temp[j] = get_data[i];
			j++;
			i++;
		}
		
		while (1) {
			if (CHECK_KEYWORD(temp))
				break;
			if (CHECK_IDENTIFIER(temp))
				break;
			if (CHECK_SPL(temp))
				break;
			if (CHECK_ARTH(temp))
				break;
			if (CHECK_RELATION(temp))
				break;
			if (CHECK_COMMENT(temp))
				break;
			if (CHECK_CONST(temp))
				break;
		}
		
		if (i++ >= len)
			break;
	}
	
	return 0;
}

int CHECK_KEYWORD(char data[]) {
	int i;
	
	for (i = 0; i < 32; i++) {
		if (strcmp(data, Keywords[i]) == 0) {
			printf("%s is a Keyword\n",data);
			return 1;
		}
	}
	
	return 0;
}

int CHECK_IDENTIFIER(char ptr[]) {
	if (isalpha(ptr[0]) || ptr[0] == '_') {
		printf("%s is a IDENTIFIER\n",ptr);
		return 1;
	}

	return 0;
}

int CHECK_CONST(char ptr[]) {
	int len = strlen(ptr), flag = 0, i;
	
	for (i = 0; i < len; i++) {
		if (ptr[i] == '.' || ptr[i] == 'E' || ptr[i] == 'e') {
			flag = 1;
			break;
		}
	}
	
	if (flag) {
		printf("%s is a floating number\n",ptr);
		return 1;
	} else {
		printf("%s is a Integer\n",ptr);
		return 1;
	}
}

int CHECK_SPL(char ptr[]) {
	if (strlen(ptr) > 1)
		return 0;
	int i;
	
	for (i = 0; i < 13; i++) {
		if (ptr[0] == SPL[i]) {
			printf("%c is Special Character\n",ptr[0]);
			return 1;
		}
	}
	
	return 0;
}

int CHECK_ARTH(char ptr[]) {
	if (strlen(ptr) > 1)
		return 0;
	int i;
	
	for (i = 0; i < 6; i++) {
		if (ptr[0] == ARTH[i]) {
			printf("%c is Arithmetic Operator\n",ptr[0]);
			return 1;
		}
	}
	
	return 0;
}

int CHECK_RELATION(char ptr[]) {
	int i;
	int len = strlen(ptr);
	
	if (len == 1) {
		for (i = 0; i < 2; i++) {
			if (ptr[0] == RELATION1[i]) {
				printf("%s is Relational Operator\n",ptr);
				return 1;
			}
		}
	} else {
		for (i = 0; i < 4; i++) {
			if (ptr[0] == RELATION2[i][0] && ptr[1] == RELATION2[i][1]) {
				printf("%s is Relational Operator\n",ptr);
				return 1;
			}
		}
	}
	
	return 0;
}

int CHECK_COMMENT(char ptr[]) {
	if (ptr[0] == '/' && ptr[1] == '/') {
		count = count -1
		return 1; 
	}
	
	return 0;
}