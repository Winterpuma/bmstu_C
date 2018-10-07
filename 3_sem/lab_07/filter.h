#ifndef FILTER_H
#define FILTER_H

float count_average(const int *pb, const int *pe);
int new_size(const int *pb, const int *pe, int average);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif // FILTER_H
