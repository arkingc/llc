#include <stdio.h>

/********************
struct:
与最大成员的对齐相同
结构体大小为对齐的倍数
address:
	c:0
	i:4
	v:12
*********************/
struct S {
	char c;
	int i[2];
	double v;
};

/********************
union:
address:
	c:0
	i:0
	v:0
********************/
union U {
	char c;
	int i[2];
	double v;
};

int main(){
	printf("%lu\n",sizeof(int));
	printf("%lu\n",sizeof(double));
	printf("%lu\n",sizeof(struct S));
	printf("%lu\n",sizeof(union U));
	return 0;
}
