#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#define MAX_LEN 80
char s[MAX_LEN];



void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Ередавкин Роман\n");
	printf("ЛР23 Задача 3\n");
	// Входной файл
	FILE* fin = fopen("c:\\Programs\\text2.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	// Выходной файл
	FILE* fout;
	fout = fopen("c:\\Programs\\outtext2.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	// в цикле для всех строк
	while (!feof(fin)) {
		// загрузить строку
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// обработать загруженную строку
			for (int i = 0; s[i] == 'a'; i++) { 
				for (int c = 0; s[c] == '\0'; i++) {
					s[c] = '#';
				}

				 // Если прочитан пробел
				 // Заменяем его на '%’

			}
			// сохранить строку в выходной файл
			fprintf(fout, "%s", s);
			printf(">>%s<<\n", s);
		}
	}
	// закрыли файлы
	fclose(fin);
	fclose(fout);

	printf("ЛР23 Задача 3 FINISH\n");
}