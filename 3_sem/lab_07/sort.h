#ifndef SORTING_H
#define SORTING_H

void copy_array(const int *pb_src, const int *pe_src, int *pb_dst, int **pe_dst);
int compare_int(const void* p, const void* q);
void swap(int *a, int *b);
void mysort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));

#endif // SORTING_H
