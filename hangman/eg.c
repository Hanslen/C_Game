#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int a[4][3] = {{1,2,3}, {2,3,4},{3,4,5},{4,5,6}};
	int length = sizeof(a)/(sizeof(a[0]));
	
	printf("%d\n", length);	
}