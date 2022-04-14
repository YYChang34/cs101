#include <stdio.h>

void find_num(int* p, int num) {
	for(int i = 0; i < 10; i++) {
		if(*(p + i) == num) {
			printf("&n[%d]->%p, n[%d] = %d, ", i, (p + i), i, *(p + i));
			printf("p->%p, *p = %d\n", (p + i), *(p + i));
		}
	}
}
void sort(int** ap, int n[10]) {
	int i, j, a, b;
	for(i = 0; i < 10; i++) {
		for(j = 0; j < 10; j++) {
			if(*ap[i] == n[j]) {
				printf("&n[%d]->%p, n[%d] = %d; ", j, ap[i], j, n[j]);
				printf("ap[%d]->%p, *ap[%d] = %d\n", i, ap[i], i, *(ap[i]));
			}
		}
	}
}

int main(void) {
	int n[10] = {6, 4, 7, 2, 0, 9, 8, 1, 5, 3};
	int* p;
	int* ap[10];
	int num = 9;
	p = n;
	printf("n[5] = %p\n", &n[5]);
	int i, j;
	for(i = 0, j = 0; i < 10; i++) {
		ap[i] = &n[j++];
	}
	for(i = 0; i < 10; i++) {
		for(j = i + 1; j < 10; j++) {
			if(*ap[i] > *ap[j]) {
				int* temp = ap[i];
				ap[i] = ap[j];
				ap[j] = temp;
			}
		}
	}
	printf("N0.1 -------------------\n");
	find_num(p, num);
	printf("N0.2 -------------------\n");
	sort(ap, n);

	return 0;
}