#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//折半插入排序
/*先折半查找出元素待插入位置，在统一移动待插入位置之后的所有元素，
给插入位置腾出空间，将待插入元素放到表中的插入位置*/
typedef int elem_type;
void Binary_InsertSort(elem_type a[],int n){
    int i,j,low,mid,high;
    for(i = 2;i < n;i++){             //依次将啊a[2]~a[n]插入到前面已排序序列
        a[0] = a[i];                  //将a[i]暂存到啊a[0]中（要插入的元素是i号，1~i-1都是有序的）
        low = 1;
        high = i - 1;                 //设置折半查找范围
        while(low <= high){           //折半查找
            mid = (low + high)/2;
            if(a[mid] > a[0])
                high = mid - 1;
            else
                low = mid + 1;
        }
        for(j = i - 1;j >= high + 1;j--)
            a[j + 1] = a[j];          //统一后移
        a[high + 1] = a[0];
    }
}
int main()
{
    elem_type a[] = {0,899,565,68,78,12,9,3,848,925,802,94,454,6465,756,
    5165,87,325,148,699,789,122,784,124,34,588,7,54,697,101,130};
    int len = sizeof(a)/sizeof(elem_type);
    Binary_InsertSort(a,len);
    for(int i = 1;i < len;i++)
        printf("%d ",a[i]);
    return 0;
}
