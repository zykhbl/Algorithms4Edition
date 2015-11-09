//
//  Ex_1_1_14.c
//  Algorithms4Edition
//
//  Created by zykhbl on 15-11-10.
//  Copyright (c) 2015年 zykhbl. All rights reserved.
//

#include <stdio.h>

int lg(int n) {
    int ex = 0;
    while ((n /= 2) >= 1) {
        ex++;
    }
    return ex;
}

int test_ex_1_1_14(int argc, const char * argv[]) {
    printf("%d\n", lg(1111));
    
    return 0;
}
