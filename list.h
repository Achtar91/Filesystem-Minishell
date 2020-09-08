#ifndef __LIST_HEADER__
#define __LIST_HEADER__

typedef struct Flist
{

    struct File *data;
    struct Flist *next;

} Flist;

typedef struct Dirlist
{

    struct Directory *data;
    struct Dirlist *next;
} Dirlist;

#endif /* __LIST_HEADER__ */