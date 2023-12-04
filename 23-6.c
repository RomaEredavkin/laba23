#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#define MAX_LEN 80
char s[MAX_LEN];



void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Ередавкин\n");
	printf("ЛР23 Задача 6\n");
	// Входной файл
	FILE* fin = fopen("c:\\Programs\\text6.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	// Выходной файл
	FILE* fout;
	fout = fopen("c:\\Programs\\outtext6.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	} 
	int chek = 0;
	// в цикле для всех строк
	while (!feof(fin)) {
		// загрузить строку
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// обработать загруженную строку
			for (int i = 0; s[i] != '\0'; i++) {

				if (s[i] == ';') // Если прочитан пробел
					chek++;

			}
			// сохранить строку в выходной файл
			fprintf(fout, "%s", s);
			printf(">>%s<<\n", s); 
			fprintf(fout, "Знаков найденно: %d", chek);
		}
	}
	// закрыли файлы
	fclose(fin);
	fclose(fout);

	printf("ЛР23 Задача 1 FINISH\n");
}
