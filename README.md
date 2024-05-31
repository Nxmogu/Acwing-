# Acwing-学习记录
## 基础算法
### 快速排序(时间复杂度`o(nlog2n)`)
1. 确定分界点`q[l]`,`q[2]`或者`q[(l+r)/2]`
2. 分段排列保证数组q前半段数字全部小于等于分界点，后半段全部大于等于分界点
   * 暴力法 (空间复杂度`o(n)`)
   * 双指针法 (空间复杂度`o(1)`)
3. 递归排序前半段与后半段
[快排模板](./代码模板/基础算法/快排.cpp)
### 归并排序(时间复杂度`o(nlog2n)`)
1. 确定分界点`q[(l+r)/2]`
2. 对左半段`(l,mid)`与右半段`(mid+1,r)`进行递归
3. 归并左半段与右半段(空间复杂度`o(n)`)
[归并排序模板](./代码模板/基础算法/归并排序.cpp)
### 二分查找(时间复杂度`o(nlog2n)`)
1. 整数二分
   1. 确定分界点mid，`mid=(l+r)/2`或者`mid=(l+r+1)/2`当需要将left更新为mid时使用`mid=(l+r+1)/2`
   2. 实现check函数，根据check函数重新确定区间
      + 当需要寻找值的左边界
        + 若`q[mid]<x`则目标区间应该在`[mid+1,right]`之中将`left=mid+1`![二分查找情况1](./图片/整数二分1.jpg)
        + 若`q[mid]>=x`则目标区间应该在`[left,mid]`之中将`right=mid`![二分查找情况2](./图片/整数二分2.jpg)
      + 当需要寻找值的右边界
        + 若`q[mid]<=x`则目标区间应该在`[mid,right]`之中将`left=mid`![二分查找情况3](./图片/整数二分3.jpg)
        + 若`q[mid]>x`则目标区间应该在`[left,mid-1]`之中将`right=mid-1`![二分查找情况4](./图片/整数二分4.jpg)
[整数二分查找模板](./代码模板/基础算法/整数二分查找.cpp)   
2. 浮点数二分
   浮点数二分较为简单可以直接看模板[浮点数二分查找模板](./代码模板/基础算法/浮点数二分.cpp) 
### 双指针算法
1. 对于两个序列，维护某种次序，比如归并排序中合并两个有序序列的操作
2. 对于一个序列，用两个指针维护一段区间
>for (int i = 0, j = 0; i < n; i ++ )
{
    while (j < i && check(i, j)) j ++ ;
    // 具体问题的逻辑
}

[799. 最长连续不重复子序列](https://www.acwing.com/problem/content/description/801/)

### 位运算
1. 求n的第k位数字: `n >> k & 1`
2. 返回n的最后一位1：`lowbit(n) = n & -n`(`-n`是`n`取反之后加1，位与之后就可以得到n的最后一位1，例:`n=0110100`则`-n=1001100`,`n&-n=0000100`得到最后一位1处于第三位)

## 数据结构
### 链表与邻接表
1. 单链表：利用邻接表可以存储树与图
   [数组模拟单链表模板](./代码模板/数据结构/数组模拟单链表.cpp)
   [826. 单链表](https://www.acwing.com/problem/content/828/)
2. 双链表
   [数组模拟双链表模板](./代码模板/数据结构/数组模拟双链表.cpp)
   [827. 双链表](https://www.acwing.com/problem/content/829/)
### 栈与队列
1. 栈
   [数组模拟栈模板](./代码模板/数据结构/数组模拟栈.cpp)
   [828. 栈](https://www.acwing.com/problem/content/830/)
2. 普通队列
   [数组模拟普通队列模板](./代码模板/数据结构/数组模拟普通队列.cpp)
   [829. 队列](https://www.acwing.com/problem/content/831/)
3. 循环队列
   [数组模拟循环队列模板](./代码模板/数据结构/数组模拟循环队列.cpp)
   [829. 队列](https://www.acwing.com/problem/content/831/)
4. 单调栈
   [数组模拟单调栈模板](./代码模板/数据结构/数组模拟单调栈.cpp)
   [830. 单调栈](https://www.acwing.com/problem/content/832/)
   应用场景比较有限一般用于左边第一个比他小或者比他大的数
5. 单调队列
   [数组模拟单调队列模板](./代码模板/数据结构/数组模拟单调队列.cpp)
   [154. 滑动窗口 ](https://www.acwing.com/problem/content/156/)
6. KMP
   [KMP代码模板](./代码模板/数据结构/KMP.cpp)
   [154. 滑动窗口 ](https://www.acwing.com/problem/content/156/)