#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "list.h"

void create_fs(Directory **root);
void delete_fs(Directory **root);
void touch(char *fileName, char *content, Directory *root);
void mkdir(char *dirName, Directory *root);
void ls(Directory *dir);
Directory *cd(char *dirName, Directory *head);
void pwd(Directory *head);

int main(int argc, char const *argv[])
{
    Directory *root = NULL;
    Directory *current;
    current = root;
    char buffer[100];
    char comamnd[200];
    while (1)
    {
        fgets(buffer, 100, stdin);
        if (buffer[strlen(buffer) - 1] == '\n')
            buffer[strlen(buffer) - 1] = '\0';

        if (!strcmp(buffer, "create fs"))
        {
            create_fs(&root);
            current = root;
        }
        if (!strcmp(buffer, "delete fs"))
        {
            delete_fs(&root);
            break;
        }
        if (!strncmp(buffer, "touch", 5))
        {

            char *fileName, *content;
            strtok(buffer, " ");
            fileName = strtok(NULL, " ");
            content = strtok(NULL, " ");
            touch(fileName, content, current);
        }

        if (!strncmp(buffer, "mkdir", 5))
        {

            char *dirName;
            strtok(buffer, " ");
            dirName = strtok(NULL, " ");
            mkdir(dirName, current);
        }

        if (!strncmp(buffer, "ls", 2))
        {

            ls(current);
        }

        if (!strncmp(buffer, "pwd", 3))
        {

            pwd(current);
        }

        if (!strncmp(buffer, "cd", 2))
        {

            char *dirName2;
            strtok(buffer, " ");
            dirName2 = strtok(NULL, " ");
            Directory *subDir = cd(dirName2, current);
            current = subDir;
        }
    }

    return 0;
}