#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct lotto_Record {
	int lotto_no;
	int lotto_receipt;
	int emp_id;
	char lotto_date[9];
	char lotto_time[32];
} lotto_record_t;

typedef struct only_record {
	int receipt;
	char date[9];
} only_record_t;

int main(void) {
	FILE* fp_record_r = fopen("records.bin", "r");
	FILE* fp_record_w = fopen("records.txt", "w+");
	fprintf(fp_record_w, "========= lotto649 Report =========\n");
	fprintf(fp_record_w, "- Date ------ Num. ------ Receipt -\n");
	lotto_record_t lotto_record[50];
	only_record_t record[50];
	
	char line_ch;
	int count = 0;
	while((line_ch = fgetc(fp_record_r)) != EOF) {
		count++;
	}
	int total_case = count / sizeof(lotto_record_t);
	fclose(fp_record_r);

	fp_record_r = fopen("records.bin", "r");
	fread(lotto_record, sizeof(lotto_record_t), total_case, fp_record_r);
	for(int i = 0; i < total_case; i++) {
		strcpy(record[i].date, lotto_record[i].lotto_date);
		record[i].receipt = lotto_record[i].lotto_receipt;
	}
	fclose(fp_record_r);

	int k, m, n;
	int count_case[50], count_group[50], case_receipt[50];
	char case_date[50][9];
	for(int j = 0; j < total_case; j++) {
		count_case[j] = 1;
		case_receipt[j] = 0;
	}
	for(n = 0; n < total_case; n++) {
		m = n + 1;
		strcpy(case_date[n], record[n].date);
		case_receipt[n] = record[n].receipt;
		count_group[n] = record[n].receipt / 55;
		for(k = n + 1; k < total_case; k++) {
			if(!strcmp(record[n].date, record[k].date)) {
				count_case[n]++;
				case_receipt[n] += record[k].receipt;;
				count_group[n] += record[k].receipt / 55;
			} else {
				break;
			}
		}
		if(k == total_case - 1) {
			break;
		} else {
			n = k - 1;
		}
	}
	for(int j = 0; j < m; j++) {
		fprintf(fp_record_w, "%s      %d/%d           %d\n", case_date[j], count_case[j],
																count_group[j],
																case_receipt[j]);
	}
	fprintf(fp_record_w, "-----------------------------------\n");
	int total_case_of_date = 0;
	int total_group = 0;
	int total_receipt = 0;
	for(int j = 0; j < m; j++) {
		total_case_of_date += count_case[j];
		total_group += count_group[j];
		total_receipt += case_receipt[j];
	}
	fprintf(fp_record_w, "       %d      %d/%d           %d\n", m, total_case_of_date, total_group, total_receipt);

	time_t curtime;
	struct tm *info;
	char buffer[80];
	time(&curtime);
	info = localtime(&curtime);
	strftime(buffer, 80, "%Y%m%d", info);
	fprintf(fp_record_w, "======== %s Printed =========\n", buffer);
	fclose(fp_record_w);
	
	return 0;
}