#ifndef HEAPSORT_H
#define HEAPSORT_H

typedef char bin160_t[20];

int bsearch_int32(int32_t arr[], int n, int32_t val);
int bsearch_int64(int64_t arr[], int n, int64_t val);
int bsearch_int128(__int128_t arr[], int n, __int128_t val);
int bsearch_bin160(bin160_t arr[], int n, bin160_t val);

void heapsort_int32(int32_t arr[], int n);
void heapsort_int64(int64_t arr[], int n);
void heapsort_int128(__int128_t arr[], int n);
void heapsort_bin160(bin160_t arr[], int n);


#endif /* HEAPSORT_H */
