#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

#define BMP_HEADER_SIZE 54

void read_bmp(const char* filename, int* height, int* width)
{
	FILE* fp;

	if ((fp = fopen(filename, "rb")) == NULL)
	{
		printf("打开失败\n");
		exit(1);
	}
	int i, j;
	unsigned int data;
	int m = 0, n = 0;
	int p = 0, q = 0;
	int x[120][75] = { 0 };

	for (i = 0; i < 18; i++) fgetc(fp);

	fread(width, sizeof(int), 1, fp);

	fread(height, sizeof(int), 1, fp);

	for (i = 0; i < 28; i++) fgetc(fp);

	for (i = 0; i < (*height); ++i)
	{
		p = 0;
		m = 0;

		for (j = 0; j < (*width); ++j)
		{
			unsigned char b = fgetc(fp);
			unsigned char g = fgetc(fp);
			unsigned char r = fgetc(fp);
			data = (unsigned int)b;
			if (data >= 128)
			{
				x[m][n]++;
			}

			p++;
			if (p == 16)
			{
				p = 0;
				m++;
			}
		}
		q++;

		if (q == 15)
		{
			q = 0;
			n++;
		}
	}

	for (n = 0; n < 65; n++)
	{
		for (m = 0; m < 115; m++)
		{
			if (x[m][62 - n] < 80)
			{
				printf("  ");
				//m++;
			}
			else if (x[m][62 - n] >= 80)
			{
				printf("█ ");
			}
		}
		printf("\n");
	}
	printf("\n\n");
	fclose(fp);

}