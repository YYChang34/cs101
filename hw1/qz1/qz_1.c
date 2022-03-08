#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	FILE* fp;
	FILE* fp_count;
	int n, i, j, k, temp;
	int num[5][6];
	int count[] = {1};
	fp_count = fopen("lotto_count.bin", "rb");
	fread(count, sizeof(int), 1, fp_count);
	fclose(fp_count);
		
	printf("歡迎光臨長庚樂透彩購買機台\n請問您要買幾組樂透彩 : ");
	scanf("%d", &n);

	fp = fopen("lotto.txt", "w+", count);
	while (true) {
    char buffer[32];
    snprintf(buffer, sizeof(char) * 32, "lotto[000%i].txt", count[0]);
    fp = fopen(buffer, "wb");
    }
    fwrite (data, 1, strlen(data) , fp);
	fprintf(fp, "========= lotto649 =========\n");
	fprintf(fp, "========+ No.000%d +=========\n", count[0]);

//time
	time_t curtime;
	struct tm *info;
	char buffer[80];
	time(&curtime);
	info = localtime(&curtime);
	strftime(buffer, 80, "%a %b %d %X %Y", info);
	fprintf(fp, "= %s =\n", buffer);
//random number
	for(i = 0; i < 5; i++) {
		for(j = 0; j < 5; j++) {
			num[i][j] = rand() % 69 + 1;
		}
	//bubble sort
		for(j = 0; j < 5; j++) {
			for(k = 0; k < 4 - j; k++) {
				if(num[i][k] > num[i][k + 1]) {
					temp = num[i][k];
					num[i][k] = num[i][k + 1];
					num[i][k + 1] = temp;
				}
			}
		}
	}
	for(i = 0; i < 5; i++) {
		fprintf(fp, "[%d]: ", i + 1);
		num[i][5] = rand() % 10 + 1;
		for(j = 0; j < 5; j++) {
			if(i >= n) {
				fprintf(fp, "-- ");
			} else if(num[i][j] < 10) {
				fprintf(fp, "0%d ", num[i][j]);
			} else {
				fprintf(fp, "%d ", num[i][j]);
			}
			if(num[i][5] == num[i][j]) {
				num[i][5] = rand() % 10 + 1;
			}
		}
//special number
		if(i >= n) {
			fprintf(fp, "--\n");
		} else if(num[i][5] == 10) {
			fprintf(fp, "%d\n", num[i][5]);
		} else {
			fprintf(fp, "0%d\n", num[i][5]);
		}
	}

	fprintf(fp, "========= csie@CGU =========\n");
	fclose(fp);
	count[0]++;
	fp_count = fopen("lotto_count.bin", "wb+");
	fwrite(count, sizeof(count), 1, fp_count);
	fclose(fp_count);
	printf("已為您購買的 %d 組樂透彩組合輸出至 lotto.txt\n", n);

	return 0;
}