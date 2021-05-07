#include <stdio.h>
#include <string.h>

char* filename(int argc, char** arg) //�����ļ���
{
	int i = 0;
	char* name;
	for (i = 1; i < argc; i++) {
		if (strcmp(arg[i], "-l") && strcmp(arg[i], "-w") && strcmp(arg[i], "-c")) {
			return arg[i];
		}
	}
}
FILE* openfile(int argc, char** arg) //���ļ� 
{
	char* name = filename(argc, arg);
	FILE * fp = fopen(name, "r");
	return fp;
}

// ͳ���ַ� 
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
	printf("�ַ��� :%d", number);
	fclose(fp);
	fclose(fp1);
}

 //ͳ�Ƶ���
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
	printf("���� %d:",count);
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