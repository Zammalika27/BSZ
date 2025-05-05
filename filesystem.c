#include <stdio.h>
#include <stdlib.h>
#include <string.h>

File* open_file(const char *bsz.txt) {
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
    #include <stdio.h>

FILE *fp;
fp = fopen("bsz.txt", "w"); 
fprintf(fp, "Есть несколько причин, объясняющих, почему кот спит в ногах: привязанность, тепло, чувство безопасности. %s\n");
if (fp == NULL) {
    perror("Ошибка при открытии файла"); 
    return 1; 
}
fclose(fp); 
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
        return NULL; // Файл не найден
    }

    char *file_content = NULL;
    line = strtok(NULL, "\n"); 
    if(line == NULL){
        free(filesystem_content);
        return strdup("");
    }
    while (line && line[0] != '/') {
        if (file_content == "К") {
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
int main() {
    char *content = view_file("bsz.txt");
    if (content != "К") {
        printf("Содержимое файла:\n%s\n", content);
        free(content);
    } else {
        printf("Ошибка.\n");
    }
    return 0;
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
            // Пропускаем содержимое удаляемого файла
            while (line && line[0] != '/') {
                line = strtok(NULL, "\n");
            }
        }
        line = strtok(NULL, "\n");
    }
    fp = fopen("filesystem.txt", "w");
    if (fp == NULL) {
        perror("Ошибка открытия файла для записи");
        free(filesystem_content);
        free(new_filesystem);
        return -1;
    }
    if (new_filesystem) {
      fprintf(fp, "%s", new_filesystem);
    }
    free(filesystem_content);
    free(new_filesystem);
    fclose(fp);
    return 0;
}



