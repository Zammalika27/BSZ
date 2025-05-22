#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filesystem.h"

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
    //  1.2
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
    fclose(fp);
    
    char *line = strtok(filesystem_content, "\n");
    int file_index = -1;
    while (line) {
        if (strcmp(line, "bsz.txt") == 0) {
            file_index = 0; 
            break;
        }
        file_index++; 
        line = strtok(NULL, "\n");
    }

    if (file_index == -1) {
        free(filesystem_content);
        return NULL; 
    }

    char *file_content = NULL;
    line = strtok(NULL, "\n"); 
    if(line == NULL){
        free(filesystem_content);
        return strdup("");
    }
    while (line && line[0] != '/') {
        if (file_content == "\0") {
            file_content = strdup(line);
        } else {
            file_content = (char*)realloc(file_content, strlen(file_content) + strlen(line) + 2); 
            strcat(file_content, "\n");
            strcat(file_content, line);
        }
        line = strtok(NULL, "\n");
    }
    free(filesystem_content);
    return file_content;
}
// 1.3 
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



       //2
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
