//
//  Ex_1_1_19.c
//  Algorithms4Edition
//
//  Created by zykhbl on 15-11-10.
//  Copyright (c) 2015年 zykhbl. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

long double F(int n) {
    if (n == 0) {
        return 0;
    }
    
    if (n == 1) {
        return 1;
    }
    
    return F(n - 1) + F(n - 2);
}

static long N = 100;

long double F2(int n) {
    static long double *FF = NULL;
    if (FF == NULL) {
        FF = malloc(N * sizeof(long double));
    }
    
    if (n == 0) {
        *(FF + n) = 0;
        return 0;
    }
    
    if (n == 1) {
        *(FF + n) = 1;
        return 1;
    }
    
    *(FF + n) = *(FF + n - 1) + *(FF + n - 2);
    return *(FF + n);
}

int test_ex_1_1_19(int argc, const char * argv[]) {
    for (int n = 0; n < 100; n++) {
        printf("F2(%d) = %.0Lf\n", n, F2(n));
    }
    
    return 0;
}