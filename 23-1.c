#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#define MAX_LEN 80
char s[MAX_LEN];



void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("�������� ����\n");
	printf("��23 ������ 1\n");
	// ������� ����
	FILE* fin = fopen("c:\\Programs\\text1.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}

	// �������� ����
	FILE* fout;
	fout = fopen("c:\\Programs\\outtext1.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ��������");
		return;
	}
	// � ����� ��� ���� �����
	while (!feof(fin)) {
		// ��������� ������
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// ���������� ����������� ������
			for (int i = 0; s[i] != '\0'; i++) {

				if (s[i] == '\t') // ���� �������� ������
					s[i] = '%'; // �������� ��� �� '%�

			}
			// ��������� ������ � �������� ����
			fprintf(fout, "%s", s);
			printf(">>%s<<\n", s);
		}
	} 
	// ������� �����
	fclose(fin);
	fclose(fout);

	printf("��23 ������ 1 FINISH\n");
}
