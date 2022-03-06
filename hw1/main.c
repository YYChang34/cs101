#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	FILE* fp;
	int n;
	int num[5][7];
		
	printf("歡迎光臨長庚樂透彩購買機台\n請問您要買幾組樂透彩 : ");
	scanf("%d", &n);

	fp = fopen("lotto.txt", "w+");
//output time
	time_t curtime;
	struct tm *info;
	char buffer[80];
	time(&curtime);
	info = localtime(&curtime);
	fprintf(fp, "========= lotto649 =========\n");
	strftime(buffer, 80, "%a %b %d %X %Y", info);
	fprintf(fp, "= %s =\n", buffer);
//output random number
	for(int i = 0; i < 5; i++) {
		fprintf(fp, "[%d]: ", i + 1);
		num[i][6] = rand() % 10 + 1;
		for(int j = 0; j < 6; j++) {
			num[i][j] = rand() % 69 + 1;
			if(i >= n) {
				fprintf(fp, "-- ");
			} else if(num[i][j] < 10) {
				fprintf(fp, "0%d ", num[i][j]);
			} else {
				fprintf(fp, "%d ", num[i][j]);
			}
			if(num[i][6] == num[i][j]) {
				num[i][6] = rand() % 10 + 1;
			}
		}
		fprintf(fp, "\n");
	}

	fprintf(fp, "========= csie@CGU =========\n");
	fclose(fp);
	printf("已為您購買的 %d 組樂透彩組合輸出至 lotto.txt", n);

	return 0;
}