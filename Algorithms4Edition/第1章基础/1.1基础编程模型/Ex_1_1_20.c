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

/*
 lnx求值原理：
 x->0.0时，ln(1+x)=x-x^2/2+x^3/3-……+(-1)^(k-1)*(x^k)/k收敛得越快，所以k不大时就可以近似于ln(1+x)
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

int loge(int n) {
    int ex = 0;
    while ((n /= M_E) >= 1) {
        ex++;
    }
    return ex;
}

/*
 因为ln(xy) = ln(x) + ln(y)，所以ln(n) = ln((e^[lnn]) * n / (e^[lnn])) = ln(e^[lnn]) + ln(n / (e^[lnn])) = [lnn] + ln(n / (e^[lnn]));
 */
long double ln_n(int n, int k) {
    int max_ex = loge(n);
    long double ex = powl(M_E, max_ex);
    long double x = n / ex;
    
    if (x <= 0.0) {
        printf("+++++++++++\n");
        exit(-1);
    } else if (x < 2.0) {
        return max_ex + lnx(x, k);
    } else {
        x = x / 2.0;
        if (x >= 2.0) {
            exit(-2);
        }
        return max_ex + M_LN2 + lnx(x, k);
    }
}

/*
 ln(n!)求值原理：
 因为ln(xy) = ln(x) + ln(y)，所以ln(n!) = ln(1) + ln(2) + …… + ln(n);
 */

//递归版本，对于n > 100000时，会计算不出来，因为函数调用出栈入栈耗光了栈内存
//long double ln_n_1(int n, int k) {
//    if (n == 1) {
//        return 0.0;
//    }
//    
//    if (n == 2) {
//        return M_LN2;
//    }
//    
//    return ln_n(n, k) + ln_n_1(n - 1, k);
//}

//非递归版本，对于n没限制
long double ln_n_1(int n, int k) {
    long double sum = M_LN2;
    for (int i = 3; i <= n; i++) {
        sum += ln_n(i, k);
    }
    return sum;
}

int test_ex_1_1_20(int argc, const char * argv[]) {
    int n = 1000000, k = 100;
    
//    printf("ln_n(%d) = %.10Lf \n", n, ln_n(n, k));
//    printf("%d = %.10Lf \n", n, powl(M_E, ln_n(n, k)));
    printf("ln_n_1(%d!) = %.10Lf\n", n, ln_n_1(n, k));
    
    return 0;
}