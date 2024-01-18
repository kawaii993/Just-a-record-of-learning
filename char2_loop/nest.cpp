#include<stdio.h>
#include <string>
#include<sstream>
#include <stack>
using namespace std;

/* 双层 for 循环 */
string nestedForLoop(int n) {
    ostringstream res;
    // 循环 i = 1, 2, ..., n-1, n
    for (int i = 1; i <= n; ++i) {
        // 循环 j = 1, 2, ..., n-1, n
        for (int j = 1; j <= n; ++j) {
            res << "(" << i << ", " << j << "), ";
        }
    }
    return res.str();
}

/* 递归 */
int recur(int n) {
    // 终止条件
    if (n == 1)
        return 1;
    // 递：递归调用
    int res = recur(n - 1);
    // 归：返回结果
    return n + res;
}

/* 尾递归 */
//1+2+……+n
int tailRecur(int n, int res) {
    // 终止条件
    if (n == 0)
        return res;
    // 尾递归调用
    return tailRecur(n - 1, res + n);
}

/* 斐波那契数列：递归 */
int fib(int n) {
    // 终止条件 f(1) = 0, f(2) = 1
    if (n == 1 || n == 2)
        return n - 1;
    // 递归调用 f(n) = f(n-1) + f(n-2)
    int res = fib(n - 1) + fib(n - 2);
    // 返回结果 f(n)
    return res;
}

/* 使用迭代模拟递归 */
int forLoopRecur(int n) {
    // 使用一个显式的栈来模拟系统调用栈
    stack<int> stack;
    int res = 0;
    // 递：递归调用
    for (int i = n; i > 0; i--) {
        // 通过“入栈操作”模拟“递”
        stack.push(i);
    }
    // 归：返回结果
    while (!stack.empty()) {
        // 通过“出栈操作”模拟“归”
        res += stack.top();
        stack.pop();
    }
    // res = 1+2+3+...+n
    return res;
}

int main(){
    int n;
    printf("请输入整数 n：");
    scanf("%d", &n);

    std::string s = nestedForLoop(n);
    //调用函数计算双层for循环

    int result1 = recur(n);
    int result2 = tailRecur(n,0);
    int result3 = fib(n);
    int result4 = forLoopRecur(n);


    printf("双层for循环的结果：%s\n", s.c_str());
    printf("递归结果为：%d\n", result1);
    printf("尾递归结果为：%d\n", result2);
    printf("斐波那契数列第n个数字为：%d\n", result3);
    printf("用一个显式的栈来模拟调用栈：%d\n", result4); 
    //输出
    return 0;
}