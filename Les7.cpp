#include <iostream>
#include <cmath>
using namespace std;
//for first task
void Qsort(int *a,int first,int last);
void Isort(int *a,int first,int last);
//for second
void Bsort(int *a,int len);
int main() {
    //test1
    /*int arr[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    for (int i=0;i<20;++i) cout << arr[i] << " ";
    cout << endl;
    Qsort(arr,0,19);
    for (int i=0;i<20;++i) cout << arr[i] << " ";*/
    //test2
    /*int ar2[] = {0, 2, 8, 3, 6, 4, 5, 9, 8, 2, 7, 3};
    for (int i=0;i<12;++i) cout << ar2[i] << " ";
    Bsort(ar2,12);
    cout << endl;
    for (int i=0;i<12;++i) cout << ar2[i] << " ";*/
    return 0;
}
void Qsort(int *a,int first,int last) {
    if(last - first <5)
    {
        Isort(a,first,last);
    }
    else {
        int i = first;
        int j = last;
        int x = a[(first + last) / 2];
        do {
            while (a[i] < x) ++i;
            while (a[j] > x) --j;
            if (i <= j) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
                ++i;
                --j;
            }
        } while (i <= j);
        if (i < last) Qsort(a, i, last);
        if (first < j) Qsort(a, first, j);
    }

}
void Isort(int *a,int first,int last)
{
    int temp,pos;
    for(int i=first+1;i<last-first+1;++i)
    {
        temp = a[i];
        pos = i-1;
        while(pos>=0 && a[pos]>temp)
        {
            a[pos+1]=a[pos];
            --pos;
        }
        a[pos+1] = temp;
    }
}
void Bsort(int *a,int len)
{
    int *co = new int[len];
    for (int i=0;i<len;++i) co[i]=a[i];
    const int max = len;
    const int b =10;
    int **buckets = new int * [b];
    for (int i = 0; i < b; i++) {
        buckets[i] = new int [max+1];
        buckets[i][max]=0;
    }
    for(int digit =1;digit<1000000;digit*=10)
    {
        for(int i =0;i<max;++i)
        {

            if(a[i]%2==0)
            {
                int d=(a[i]/digit)%b;
                buckets[d][buckets[d][max]++]=a[i];
            }

        }
        int idx=0;
        for(int i=0;i<b;++i)
        {
            for(int j=0;j<buckets[i][max];++j)
            {
                if(co[idx++]%2==0)
                {
                    a[idx]=buckets[i][j];
                }
            }
            buckets[i][max]=0;
        }

    }
}