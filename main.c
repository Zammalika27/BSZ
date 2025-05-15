#include "filesystem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () 
{
FILE* open_file(const char *bsz.txt) {
    FILE *fp = fopen("bsz.txt", "r+");
    if (fp == NULL) {
        fp = fopen("bsz.txt", "w+"); 
        if (fp == NULL) {
            perror("Ошибка при создании файла");
            return NULL;
        }
    }
char *filesystem_content = NULL;
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp);

    if (fileSize > 0) {
        filesystem_content = (char*)malloc(fileSize + 1);
        if(filesystem_content == NULL) {
            perror("Ошибка выделения памяти");
            fclose(fp);
            return NULL;
        }
        fread(filesystem_content, 1, fileSize, fp);
        filesystem_content[fileSize] = '\0';
    }
    fclose(fp);
    return 1;
}
fprintf(*bsz.txt, "%s.\n");
  int readFileAndPrint(const char *bsz.txt) {
  if (fp == NULL) {
    perror("Ошибка при открытии файла для чтения");
    return 1; }
  fgetc ("bsz.txt"); 
  }

//15.05
char a[256];
char create_file(const char *bsz.txt) {
    FILE *file = fopen("bsz.txt", "w");
    if (file) {
        printf("Файл '%s' создан.\n", "bsz.txt");
        fclose(file);
    } else {
        perror("Ошибка создания файла");
    }
}

int delete_file(const char *bsz.txt) {
    if (remove("bsz.txt") == 0) {
        printf("Файл '%s' удален.\n", "bsz.txt");
    } else {
        perror("Ошибка удаления файла");
    }
}

int modify_file(const char *bsz.txt, const char *content) {
    FILE *file = fopen("bsz.txt", "a");
    if (file) {
        fprintf(file, "%s\n", content);
        printf("Файл '%s' изменен.\n", "bsz.txt");
        fclose(file);
    } else {
        perror("Ошибка изменения файла");
    }
}

char view_file(const char *bsz.txt) {
    char buffer[256];
    FILE *file = fopen ("bsz.txt", "r");
    if (file) {
        printf("Содержимое файла '%s':\n", "bsz.txt");
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("%s", buffer);
        }
        fclose(file);
    } else {
        perror("Ошибка просмотра файла");
    }
}

    char command[20]; // Увеличил размер для надежности
    char filename[MAX_FILENAME_LENGTH];
    int result;

    while (1) {
        printf("> "); // Приглашение командной строки
        result = scanf("%19s", command); // Считываем команду
  if (result == EOF){
   printf("Конец ввода. Завершение.\n");
   break;
  }

        if (strcmp(command, "создать") == 0) {
            scanf("%255s", filename); // Считываем имя файла
            create_file(filename);
        } else if (strcmp(command, "удалить") == 0) {
            scanf("%255s", filename); // Считываем имя файла
            delete_file(filename);
        } else if (strcmp(command, "изменить") == 0) {
            scanf("%255s", filename); // Считываем имя файла
            edit_file(filename);
        } else if (strcmp(command, "посмотреть") == 0) {
            scanf("%255s", filename); // Считываем имя файла
            view_file(filename);
        } else if (strcmp(command, "выход") == 0) {
            printf("Завершение работы...\n");
            break; // Выход из цикла
        } else {
            printf("Неизвестная команда: %s\n", command);
             while (getchar() != '\n'); // Очистка остатка строки в буфере ввода
        }

        while (getchar() != '\n');


    }

    return 0;
}
  fclose ("bsz.txt");
  return 0
