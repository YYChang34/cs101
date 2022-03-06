#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	FILE* fp;
	int n;
	int num[6];
		
	printf("歡迎光臨長庚樂透彩購買機台\n請問您要買幾組樂透彩 : ");
	scanf("%d", &n);

	fp = fopen("lotto.txt", "w+");
//time
	time_t curtime;
	struct tm *info;
	char buffer[80];
	time(&curtime);
	info = localtime(&curtime);
	fprintf(fp, "========= lotto649 =========\n");
	strftime(buffer, 80, "%a %b %d %X %Y", info);
	fprintf(fp, "= %s =\n", buffer);
//random number
	for(int i = 1; i <= 5; i++) {
		fprintf(fp, "[%d]: ", i);
		num[5] = rand() % 10 + 1;
		for(int j = 0; j < 5; j++) {
			num[j] = rand() % 69 + 1;
			if(i > n) {
				fprintf(fp, "-- ");
			} else if(num[j] < 10) {
				fprintf(fp, "0%d ", num[j]);
			} else {
				fprintf(fp, "%d ", num[j]);
			}
			if(num[5] == num[j]) {
				num[5] = rand() % 10 + 1;
			}
		}
//special number
		if(i > n) {
			fprintf(fp, "--\n");
		} else if(num[5] == 10) {
			fprintf(fp, "%d\n", num[5]);
		} else {
			fprintf(fp, "0%d\n", num[5]);
		}
	}
	fprintf(fp, "========= csie@CGU =========");
	fclose(fp);

	printf("已為您購買的 %d 組樂透彩組合輸出至 lotto.txt", n);

	return 0;
}