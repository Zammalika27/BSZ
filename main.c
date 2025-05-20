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

//15.05
char buffer[256];
char create_file(const char *bsz.txt) {
    FILE *file = fopen("bsz.txt", "w");
    if (file) {
        printf("Файл '%s' создан.\n", "bsz.txt");
        fclose(file);
    } else {
        perror("Ошибка создания файла");
    }
}

int delete_file(const char* bsz.txt) {
    FILE *fp = fopen("filesystem.txt", "r+");
    if (fp == NULL) {
        perror("Ошибка открытия файла");
        return -1;
    }
    char *filesystem_content = NULL;
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp);

    if (fileSize > 0) {
        filesystem_content = (char*)malloc(fileSize + 1);
        if(filesystem_content == NULL) {
                perror("Ошибка выделения памяти"); 
        }
            fclose(fp);
            return -1;
    }

char *new_filesystem = NULL;
char *line = strtok(filesystem_content, "\n");
    while (line) {
        if (strcmp(line, bsz.txt) != 0) {
            if (new_filesystem == NULL) {
                new_filesystem = strdup(line);
            } else {
                new_filesystem = (char*)realloc(new_filesystem, strlen(new_filesystem) + strlen(line) + 2);
                strcat(new_filesystem, "\n");
                strcat(new_filesystem, line);
            }
        } else {
            while (line && line[0] != '/') {
                line = strtok(NULL, "\n");
            }
        }
        line = strtok(NULL, "\n");
    }

int modify_file(const char *bsz.txt, const char *new_content) {
    FILE *fp = fopen(bsz.txt, "r+");
    if (fp == NULL) {
        perror("Ошибка открытия файла");
        return 1;
}
    const char *bsz.txt = "bsz.txt";
    const char *new_content = "Замена";
    size_t new_content_len = strlen(new_content);
    if (modify_file(bsz.txt, new_content) == 0) {
        printf("Файл '%s' успешно изменен.\n", bsz.txt);
        }
    return 0;
    }
    return 0;
}


char* view_file(const char* bsz.txt) {
    File* file = open_file("bsz.txt");
    if (file == NULL) {
        return NULL;
    }
    char *filesystem_content = NULL;
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp);

    if (fileSize > 0) {
        filesystem_content = (char*)malloc(fileSize + 1);
        if (filesystem_content == NULL) {
            perror("Ошибка выделения памяти");
            fclose(fp);
            return NULL;
        }
        fread(filesystem_content, 1, fileSize, fp);
        filesystem_content[fileSize] = '\0';
    } else {
        fclose(fp);
        return NULL; 
    }
        if (strcmp(buffer, "создать") == 0) {
            scanf("%255s", "bsz.txt"); 
            create_file("bsz.txt");
        } 
        else if (strcmp(buffer, "удалить") == 0) {
            scanf("%255s", "bsz.txt"); 
            delete_file("bsz.txt");
        } 
        else if (strcmp(buffer, "изменить") == 0) {
            scanf("%255s", "bsz.txt"); 
            edit_file("bsz.txt");
        } 
        else if (strcmp(buffer, "посмотреть") == 0) {
            scanf("%255s", "bsz.txt"); 
            view_file("bsz.txt");
        } 
        else if (strcmp(buffer, "выход") == 0) {
            printf("Завершение работы...\n");
            break; 
        } 
        else {
            printf("Неизвестная команда: %s\n", buffer);
             while (getchar() != '\n');
        }

        while (getchar() != '\n');
    }

    return 0;
}
  fclose ("bsz.txt");
  return 0
