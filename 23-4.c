#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#define MAX_LEN 40

int getNextDelim(FILE* fp, char token[]);
int getNextWord(FILE* fp, char token[], int maxLen);

char filename[] = "c:\\Programs\\outtext3.txt";
int isalpha_my(unsigned char ch);

// ���������� 1 - ����  �� ����� �������� �����������.
// � ���� ������ � token ������������ ������, ���������� 
// ���� �����������.
// ���� � ����� ��� �� ����������� - ���������� 0.
// � ���� ������ ��������� token ������������.
int getNextDelim(FILE* fp, char token[])
{
	int ch = getc(fp);
	if (ch == EOF) {
		return 0;
	}
	if (isalpha_my((unsigned char)ch)) {
		ungetc(ch, fp);
		return 0;
	}
	token[0] = (unsigned char)ch;
	token[1] = '\0';
		return 1;
}
int getNextWord(FILE* fp, char token[], int maxLen)
{
	int i = 0;
	int ch;
	while (((ch = getc(fp)) != EOF) && (i < maxLen - 1)) {
		if (!isalpha_my((unsigned char)(ch))) {
			break;
		}
		token[i++] = ch;
	}
	ungetc(ch, fp);
	token[i] = '\0';
		if (i == 0)
			return 0;
	return 1;
}
int isalpha_my(unsigned char ch) {
	if (isalpha(ch))
		return 1;

	// ANSI ���������!!!
	if (ch >= 192 && ch <= 223)
		return 1;
	if (ch >= 224 && ch <= 255)
		return 1;

	/*
		if (ch >= '�' && ch <= '�') return 1;
		if (ch >= '�' && ch <= '�') return 1;
		if (ch >= '�' && ch <= '�')return 1;
		if (ch == '�' ) return 1;
		if (ch == '�') return 1;*/

	return 0;
}

void main() {
	printf("BEGIN!!!\n");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ��������� ���� � �������
	FILE* fin = fopen(filename, "rt");
	if (fin == NULL) {
		// ���� ���� �� ������ ������� - �������� �� ����
		printf("File %s doesn't opened!\n", filename);
		return;
	} 
	char token[MAX_LEN];
	int res;

	// ���� �� ����� �����
	while (!feof(fin)) {
		// ���� ���� ����������� - ����� ���
		while (getNextDelim(fin, token)) {
			// ������� ����������� � �������
			printf("<DELIM>%s</DELIM>\n", token);
		}
		// ���� ���� ����� - ����� ���
		if (getNextWord(fin, token, MAX_LEN)) {
			// ������� ����� � �������
			printf("<WORD>%s</WORD>\n", token);
		}
	}

	// ��������� ���� � �������
	fclose(fin);
	printf("END!!!\n");

}
