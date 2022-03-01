#include <stdio.h>

int main(void) {
	char a[] = "ABCabcABC";
	char b[] = "bc";
	int len_a = sizeof(a) / sizeof(char) - 1;
	int len_b = sizeof(b) / sizeof(char) - 1;
	int i, j, k;
	
	for(i = 0; i < len_a; i++) {
		k = i;
		for(j = 0; j < len_b, k < len_a; j++, k++) {
			if(b[j] != a[k]) {
				break;
			}
		}
		if(j == len_b) {
			break;
		}
	}

	printf("%s\n", a);
	for(j = 0; j < i; j++) {
		printf(" ");
	}
	printf("%s\n", b);
	printf("%d\n", i);

	return 0;
}