#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "list.h"

void SortDir(Directory **root)
{
    Dirlist *temp;
    Dirlist *j;

    for (temp = (*root)->d; temp->next; temp = temp->next)
    {

        for (j = temp->next; j != NULL; j = j->next)
        {
            if (strcmp(temp->data->name, j->data->name) > 0)
            {

                Directory *x = temp->data;
                temp->data = j->data;
                j->data = x;
            }
        }
    }
}

void SortFile(Directory **root)
{
    Flist *temp;
    Flist *j;
    for (temp = (*root)->f; temp->next; temp = temp->next)
    {
        for (j = temp->next; j != NULL; j = j->next)
        {
            if (strcmp(temp->data->name, j->data->name) > 0)
            {

                File *x = temp->data;
                temp->data = j->data;
                j->data = x;
            }
        }
    }
}

void create_fs(Directory **root)
{
    *root = (Directory *)malloc(sizeof(Directory));
    (*root)->name = "/";
    (*root)->f = NULL;
    (*root)->d = NULL;
    (*root)->parentDir = NULL;
}

void delete_fs(Directory **root)
{
    free(*root);
}

void touch(char *fileName, char *content, Directory *root)
{
    Directory *head = root;
    Flist *temp = root->f;
    File *f = (File *)malloc(sizeof(File));
    f->name = (char *)malloc(100 * sizeof(char));
    strcpy(f->name, fileName);
    f->data = (char *)malloc(100 * sizeof(char));
    strcpy(f->data, content);
    f->size = strlen(content);

    Flist *subFile = (Flist *)malloc(sizeof(Flist));
    subFile->next = NULL;
    subFile->data = f;
    // Flist *file = root->f;
    // file->next = subFile;
    if (root->f == NULL)
    {

        root->f = subFile;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = subFile;
    }

    SortFile(&head);
}

void mkdir(char *dirName, Directory *root)
{
    Dirlist *dir2 = root->d;
    Dirlist *p = root->d;
    Directory *d = (Directory *)malloc(sizeof(Directory));
    d->name = (char *)malloc(100 * sizeof(char));
    strcpy(d->name, dirName);
    d->f = NULL;
    d->d = NULL;
    d->parentDir = root;
    Dirlist *subDir = (Dirlist *)malloc(sizeof(Dirlist));
    subDir->next = NULL;
    subDir->data = d;
    if (root->d == NULL)
    {
        root->d = subDir;
    }

    else
    {
        while (dir2->next != NULL)
            dir2 = dir2->next;
        dir2->next = subDir;
    }

    SortDir(&root);
}

void ls(Directory *dir)

{
    if (dir == NULL)
        return;
    Dirlist *subDir = dir->d;
    Flist *SubFile = dir->f;

    while (SubFile != NULL)
    {

        printf("%s ", SubFile->data->name);
        SubFile = SubFile->next;
    }

    while (subDir != NULL)
    {

        printf("%s ", subDir->data->name);
        subDir = subDir->next;
    }

    printf("\n");
}

void pwd(Directory *head)
{
    Directory *temp = head;
    char v[200][200];
    int i, k = 0;
    if (temp->parentDir == NULL)
    {
        printf("%s\n", temp->name);
    }

    else
    {

        while (temp->parentDir != NULL)
        {

            strcpy(v[k], temp->name);
            k++;
            temp = temp->parentDir;
        }

        for (i = k - 1; i >= 0; i--)
        {
            printf("/%s", v[i]);
        }
        printf("\n");
    }
}

Directory *cd(char *dirName, Directory *root)
{

    Dirlist *tempDir = root->d;

    if (strcmp(dirName, "..") == 0)
    {
        return root->parentDir;
    }

    for (tempDir; tempDir != NULL; tempDir = tempDir->next)
    {
        if (strcmp(tempDir->data->name, dirName) == 0)
        {
            return tempDir->data;
        }
    }

    printf("Cannot move to '%s': No such directory!\n", dirName);
    return root;
}
