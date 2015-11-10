//
//  Ex_1_1_20.c
//  Algorithms4Edition
//
//  Created by zykhbl on 15-11-10.
//  Copyright (c) 2015年 zykhbl. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int K = 10000;

/*
 lnx求值原理：
 x->0.0时，泰勒公式展开：ln(1+x)=x-x^2/2+x^3/3-……+(-1)^(k-1)*(x^k)/k 收敛得越快，所以k不大时就可以近似于ln(1+x)
 */

//递归版本
//long double lnx(long double x, int k) {
//    if (k == 0) {
//        return 0.0;
//    }
//    
//    long double t = 1.0;
//    if (k % 2 == 0) {
//        t = -1.0;
//    }
//    return lnx(x, k - 1) + t * powl(x - 1, k) / k;
//}

//非递归版本
long double lnx(long double x, int k) {
    long double sum = 0.0;
    for (int i = 1; i <= k; i++) {
        long double t = 1.0;
        if (i % 2 == 0) {
            t = -1.0;
        }
        sum += t * powl(x - 1, i) / i;
    }
    return sum;
}

/*
 求不大于lg(d)的最大整数[lg(d)]
 */
int lg(long double d) {
    int ex = 0;
    while ((d /= 2.0) >= 1.0) {
        ex++;
    }
    return ex;
}

/*
 因为ln(xy) = ln(x) + ln(y)，所以ln(n) = ln((2^[lg(n)]) * n / (2^[lg(n)])) = ln((2^[lg(n)]) + ln(n / (2^[lg(n)])) = [lg(n)] * ln2 + ln(n / (2^[lg(n)]));
 */

/*
 ?? 把n分解成所有素数的乘积，然后求ln(primt)，并用数组保存起来，可能会更快 ??
 */
long double ln_n(int n) {
    int lg_max = lg(n);
    long double ex = powl(2.0, lg_max);
    long double x = n / ex;
    
    return lg_max * M_LN2 + lnx(x, K);
}

/*
 ln(n!)求值原理：
 因为ln(xy) = ln(x) + ln(y)，所以ln(n!) = ln(1) + ln(2) + …… + ln(n);
 */

//递归版本，对于n > 100000时，会计算不出来，因为函数调用出栈入栈耗光了栈内存
//long double ln_n_1(int n) {
//    if (n == 1) {
//        return 0.0;
//    }
//    
//    if (n == 2) {
//        return M_LN2;
//    }
//    
//    return ln_n(n) + ln_n_1(n - 1);
//}

//非递归版本，对于n没限制
long double ln_n_1(int n) {
    if (n == 1) {
        return 0.0;
    }
    
    long double sum = M_LN2;
    for (int i = 3; i <= n; i++) {
        sum += ln_n(i);
    }
    return sum;
}

int test_ex_1_1_20(int argc, const char * argv[]) {
    int n = 1000000;
    
//    printf("ln_n(%d) = %.10Lf \n", n, ln_n(n));
//    printf("%d = %.10Lf \n", n, powl(M_E, ln_n(n)));
    printf("ln_n_1(%d!) = %.10Lf\n", n, ln_n_1(n));
    
    return 0;
}