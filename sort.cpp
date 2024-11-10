#include <iterator>
#include <iostream>
using namespace std;
void quicksort(int *array, int right, int left = 0)
{
    if (left < right)
    {
        int seg = array[left];
        int newarr[right - left + 1];
        for (int i = left; i <= right; i++)
        {
            newarr[i - left] = array[i];
        }
        int he = left;
        int re = right;
        for (int i = 1; i < right - left + 1; i++)
        {
            if (newarr[i] < seg)
            {
                array[he] = newarr[i];
                he++;
            }
            else
            {
                array[re] = newarr[i];
                re--;
            }
            array[he] = seg;
        }
        quicksort(array, he - 1);
        quicksort(array, right, he + 1);
    }
}
void heap(int *array, int len, int now)
{
    int left = 2 * now + 1, right = 2 * now + 2, largest = now;
    if (left < len && array[left] > array[largest])
        largest = left;
    if (right < len && array[right] > array[largest])
        largest = right;
    int a = array[now];
    if (largest != now)
    {
        array[now] = array[largest], array[largest] = a;
        heap(array, len, largest);
    }
}
void heapsort(int *array, int len)
{
    for (int i = len - 1; i >= 0; i--)
        heap(array, len, i);
    for (int i = len - 1; i >= 0; i--)
    {
        int a = array[i];
        array[i] = array[0];
        array[0] = a;
        heap(array, i, 0);
    }
}
void mergesort(int *arr, int right, int left = 0)
{
    int mid = (right + left) / 2;
    if (right - left <= 1)
    {
        if (arr[right] < arr[left])
        {
            int a = arr[left];
            arr[left] = arr[right];
            arr[right] = a;
        }
    }
    else
    {
        mergesort(arr, mid, left);
        mergesort(arr, right, mid + 1);
    }
    if (right - left > 1)
    {
        int newarr[right - left + 1];
        int i = left, j = mid + 1;
        for (int k = 0; k < right - left + 1; k++)
        {
            if (i > mid)
            {
                newarr[k] = arr[j];
                j++;
            }
            else if (j > right)
            {
                newarr[k] = arr[i];
                i++;
            }
            else if (arr[i] < arr[j])
            {
                newarr[k] = arr[i];
                i++;
            }
            else
            {
                newarr[k] = arr[j];
                j++;
            }
        }
        for (int i = left; i <= right; i++)
        {
            arr[i] = newarr[i - left];
        };
    }
}
int main()
{
    int array[] = {1, 3, 3, 7, 12, 2, 4, 6, 5};
    quicksort(array, sizeof(array) / sizeof(array[0]) - 1);
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        printf("%d\n", array[i]);
    };
    return 0;
}