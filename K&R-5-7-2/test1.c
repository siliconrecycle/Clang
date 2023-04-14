#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a[3]; // 定义一个指针数组，其中每个元素都是一个指向 int 类型变量的指针
    int i;

    for (i = 0; i < 3; i++) {
        a[i] = malloc(sizeof(int)); // 为每个元素动态分配内存
        *a[i] = i * 10; // 给每个元素赋值
    }

    for (i = 0; i < 3; i++) {
        printf("%d\n", *a[i]); // 打印每个元素的值
        free(a[i]); // 释放每个元素的内存
    }

    return 0;
}
