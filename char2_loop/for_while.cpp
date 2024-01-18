#include<stdio.h>

/* for 循环 */
int forLoop(int n) {
    int res = 0;
    // 循环求和 1, 2, ..., n-1, n
    for (int i = 1; i <= n; ++i) {
        res += i;
    }
    return res;
}

/* while 循环 */
int whileLoop(int n) {
    int res = 0;
    int i = 1; // 初始化条件变量
    // 循环求和 1, 2, ..., n-1, n
    while (i <= n) {
        res += i;
        i++; // 更新条件变量
    }
    return res;
}

/* while 循环（两次更新） */
int whileLoopII(int n) {
    int res = 0;
    int i = 1; // 初始化条件变量
    // 循环求和 1, 4, 10, ...
    while (i <= n) {
        res += i;
        // 更新条件变量
        i++;
        i *= 2;
    }
    return res;
}
//不方便用for实现


int main() {
    int n;
    scanf("%d", &n);
    int result_1 = forLoop(n);
    int result_2 = whileLoop(n);
    int result_3 = whileLoopII(n);
    printf("for累加结果：%d\n", result_1);
    printf("while累加结果：%d\n", result_2);
    printf("whileII累加结果：%d\n", result_3);
    return 0;
}