#include <stdint.h>
#include "heapsort.h"

int bsearch_int32(int32_t arr[], int n, int32_t val)
{
    int lo = 0, hi = n - 1;
    
    while (lo + 8 <= hi) {
	const int mid = lo + (hi - lo) / 2;
	if (arr[mid] == val) return mid;
	if (arr[mid] < val) lo = mid + 1; else hi = mid - 1;
    }
    
    for ( ; lo <= hi && arr[lo] != val; lo++);
    
    return lo <= hi ? lo : -1;
}


#define SWAP(typ, a, b) { typ t = a; a = b; b = t; }


/* find biggest of of arr[i], arr[i*2+1], arr[i*2+2] */
static inline int max_int32(int32_t arr[], int n, int i)
{
    int m = i, j = i * 2 + 1, k = i * 2 + 2;
    if (j < n && arr[j] > arr[m]) m = j; /* [j] is bigger than [i] */
    if (k < n && arr[k] > arr[m]) m = k; /* [k] is bigger than [i] or [j] */
    return m;
}

static void downheap_int32(int32_t arr[], int n, int i)
{
    for (;;) {
	int j = max_int32(arr, n, i);
	if (j == i) break;
	SWAP(int32_t, arr[i], arr[j]); /* move [i] down to [j] */
	i = j; /* descend tree and continue at [j] */
    }
}


void heapsort_int32(int32_t arr[], int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
	downheap_int32(arr, n, i);

    for (int i = 0; i < n; i++) {
	SWAP(int32_t, arr[0], arr[n - i - 1]);
	downheap_int32(arr, n - i - 1, 0);
    }
}
