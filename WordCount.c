#include <stdio.h>
#include <string.h>

char* filename(int argc, char** arg) //返回文件名
{
	int i = 0;
	char* name;
	for (i = 1; i < argc; i++) {
		if (strcmp(arg[i], "-l") && strcmp(arg[i], "-w") && strcmp(arg[i], "-c")) {
			return arg[i];
		}
	}
}
FILE* openfile(int argc, char** arg) //打开文件 
{
	char* name = filename(argc, arg);
	FILE * fp = fopen(name, "r");
	return fp;
}

// 统计字符 
void CharCount(int argc, char** arg, char* filename) 
{
	char c;
	int number;
	FILE * fp = openfile(argc, arg);
	while (!feof(fp)) {
		c = fgetc(fp);
		if (c == '\n'||c==' '||c=='\t') {
			number++;
		}else if (c>'a'&&c<'z'||c>'A'&&c<'Z'){
			number++;
		}else if (c>='0'&&c<='9'){
			number++;
		}
	}
	FILE* fp1 = fopen(filename, "a+");
	printf("字符数 :%d", number);
	fclose(fp);
	fclose(fp1);
}

 //统计单词
void WordCount(int argc, char** arg, char* filename)
{
	char c;
	int count = 1;
	FILE* fp = openfile(argc, arg);
	while (!feof(fp)) {
		c = fgetc(fp);
		if (c == ',' || c == ' ') {
			count++;
		}
	}
	FILE* fp1 = fopen(filename, "a+");
	printf("词数 %d:",count);
	fclose(fp);
	fclose(fp1);
}

int main(int argc,char ** arg) {
	int i = 1;
	char* filename = "result.txt";
	
	for (i = 0; i < argc; i++) {
		if (!strcmp(arg[i], "-c")) {
			CharCount(argc, arg, filename);
		}
		else if (!strcmp(arg[i], "-w")) {
			WordCount(argc, arg, filename);
		}
	};
}