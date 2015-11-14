#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getstring(){
	char* buf = (char*)malloc(sizeof(char) * 256);

	int i;
	for(i=0; i < 256; i++){
		buf[i] = getchar();

		if(buf[i] == '\n'){
			buf[i] = '\0';
			break;
		}
	}

	return buf;
}

char rot(char c){
	if((c < 'a' + 13 && c >= 'a') || (c < 'A' + 13 && c >= 'A')){
		c = c + 13;
	}
	else if((c >= 'a' + 13 && c <= 'z') || (c >= 'A' + 13 && c <= 'Z')){
		c = c - 13;
	}

	return c;	
}

char* rotstr(char str[]){
	int slen = strlen(str);
	char* res = (char*)malloc(sizeof(char) * (slen + 1));

	int i;
	for(i=0; i < slen; i++){
		res[i] = rot(str[i]);
	}
	res[slen] = '\0';

	return res;
}

int main(){
	char* str, * res;

	printf("Enter a string to be encoded or decoded: ");
	str = getstring();

	res = rotstr(str);
	printf("%s\n", res);

	return 0;
}
