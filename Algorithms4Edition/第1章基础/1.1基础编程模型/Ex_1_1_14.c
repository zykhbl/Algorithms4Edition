//
//  Ex_1_1_14.c
//  Algorithms4Edition
//
//  Created by zykhbl on 15-11-10.
//  Copyright (c) 2015年 zykhbl. All rights reserved.
//

#include <stdio.h>

int ex_1_1_14(long double d) {
    int ex = 0;
    while ((d /= 2.0) >= 1.0) {
        ex++;
    }
    return ex;
}

int test_ex_1_1_14(int argc, const char * argv[]) {
    printf("%d\n", ex_1_1_14(8));
    
    return 0;
}
