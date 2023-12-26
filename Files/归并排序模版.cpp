#include <iostream>

using namespace std;

void merge_sort(int q[], int l, int r)
{
    if(l >= r) return ;

    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid+1, r);
    int k = 0, i = l, j = mid + 1;
    int* tmp = (int*) malloc( (r+1) * sizeof(int));
    while(i <= mid && j <= r)
        if(q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r)   tmp[k++] = q[j++];

    for(int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}
int main(void)
{
    int n;
    scanf("%d", &n);
    int* q =(int *) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
    merge_sort(q, 0, n -1);
    for(int i = 0; i < n; i++) printf("%d", q[i]);
    return 0;
}