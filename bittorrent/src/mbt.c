#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mbtstr/utils.h"
#include "mbtstr/view.h"
#include "mbtstr/str.h"

bool mbt_str_ctor(struct mbt_str *str, size_t capacity)
    MBT_NONNULL(1)
{
    str->data = malloc(sizeof(char) * (capacity + 1));
    if (str->data == NULL)
        return false;
    str->data[size] = NULL;
    str->size = 0;
    str->capacity = capacity;
    return true;
}

void mbt_str_dtor(struct mbt_str *str)
{
    if (str == NULL)
        return;
    free(str->data);
    str->size = 0;
    str->capacity = 0;
}

struct mbt_str *mbt_str_init(size_t capacity)
{
    struct heap_int *str = malloc(sizeof(struct heap_int));
    if (str == NULL)
        return NULL;
    if (!mbt_str_ctor(str, capacity))
    {
        free(str);
        return NULL;
    }
    return str;
}

void mbt_str_free(struct mbt_str *str)
{
    if (str == NULL)
        return;
    mbt_str_dtor(str);
    free(str);
}

bool mbt_str_pushc(struct mbt_str *str, char c)
    MBT_NONNULL(1)
{
    // resize
    if (str->size == str->capacity)
    {
        str->capacity *= 2;
        str = realloc(str, sizeof(char) * (str->capacity + 1));
        if (str == NULL)
            return false;
    }

    str->data[size] = c;
    str->size++;
    str->data[size] = NULL;
    return true;
}

bool mbt_str_pushcv(struct mbt_str *str, struct mbt_cview view)
    MBT_NONNULL(1)
{
    size_t i = 0;
    while (i < view.size)
    {
        if (!mbt_str_pushc(str, view.data[i]))
            return false;
        i++;
    }
    return true;
}

bool mbt_str_pushcstr(struct mbt_str *str, const char *cstr) 
    MBT_NONNULL(1)
{
    while (*cstr != '\0')
    {
        if (!mbt_str_pushc(str, *cstr))
            return false;
        cstr++;
    }
    return true;
}

int mbt_cview_cmp(struct mbt_cview lhs, struct mbt_cview rhs)
{
    return strcmp(lhs.data, rhs.data);
}

bool mbt_cview_contains(struct mbt_cview view, char c)
{
    return strchr(view.data, c) != NULL;
}

void mbt_cview_fprint(struct mbt_cview view, FILE *stream)
    MBT_NONNULL(2)
{
    size_t i = 0;
    while (i < view.size)
    {
        if (isprint(view.data[i]) != 0)
        {
            putc(view.data[i], stream);
        }
        else
        {
            fprintf(stream, "0x00%0x", view.data[i]);
        }
    }
}
