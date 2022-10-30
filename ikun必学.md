# 这个工程项目可以让 ikun 们在闲暇无聊时欣赏坤坤的经典作品:blush:

前提是已经有了坤坤打篮球视频的逐帧bmp图片（黑白），可以用Pr导出

在运行时可以注意一下特殊字符的输出，不同的编码可能会有不同的效果，如果直接运行没问题的话可以忽略本条建议

所用编译器为 Visual Studio 2022

## 以下是主函数

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	//setvbuf(stdin, calloc(1 << 20, sizeof(char)), _IOFBF, 1 << 20);
	//setvbuf(stdout, calloc(1 << 20, sizeof(char)), _IOFBF, 1 << 20);
	int rows, cols;
	char str[60] = "F:\\Pr\\坤坤素材库\\坤坤无特效打篮球逐帧bmp图片\\test (";//这里是放逐帧图片的文件夹
	int a, b;
	a = 1;//220张开始准备跳，600张开始铁山靠
	int c, d;

	while (a < 1777)
	{
		char str[60] = "F:\\Pr\\坤坤素材库\\坤坤无特效打篮球逐帧bmp图片\\test (";
		char str2[5] = "\0";
		char str3[5] = "\0";
		char str4[10] = ").bmp";
		c = 0;
		b = a;

		while (a > 0)
		{
			str2[c] = a % 10 + '0';
			a = a / 10;
			c++;
		}

		d = 0;

		while (d < c)
		{
			str3[d] = str2[c - 1 - d];
			str3[c - 1 - d] = str2[d];
			d++;
		}
		//printf("%s\n", str3);	//显示第几张图片
		strcat(str, str3);
		strcat(str, str4);
		read_bmp(str, &rows, &cols);
		//system("cls");
		//getchar();

		a = b;
		a += 3;
		if (a == 1467 || a == 1466 || a == 1465) a = 1;
	}
	return 0;

}
```

## 以下是 read_bmp() 函数

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
	printf("\n");
	printf("\f");
	fclose(fp);

}
```

仅仅只需要这两个.c文件就可以实现逐帧读取坤坤打篮球的bmp图片中的RGB值，然后把坤坤的经典作品呈现出来！:blush:

