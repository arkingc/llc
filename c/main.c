#include<stdio.h>
#include<string.h>

int main(){
	char str[10] = "hello";
	str[5] = '\0';
	char str1[sizeof str];
	printf("%s\n",typeof(sizeof str));
	printf("%s's size is %u\n",str,sizeof str);
	return 0;
}
