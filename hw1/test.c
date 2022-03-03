#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	FILE* fp;

	time_t curtime;
	struct tm *info;
	char buffer[80];
	time(&curtime);
	info = localtime(&curtime);
	strftime(buffer,80,"%a %b %d %H:%M:%S %Y", info);

	fp = fopen("lotto.txt", "wb+");
	fprintf(fp, "= %s =", buffer);
	fclose(fp);

	return 0;
}