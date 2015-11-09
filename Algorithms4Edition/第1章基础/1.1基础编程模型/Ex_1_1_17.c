//
//  Ex_1_1_17.c
//  Algorithms4Edition
//
//  Created by zykhbl on 15-11-10.
//  Copyright (c) 2015年 zykhbl. All rights reserved.
//

#include <stdio.h>

int mystery(int a, int b) {
    if (b == 0) {
        return 0;
    }
    
    if (b % 2 == 0) {
        return mystery(a + a, b / 2);
    }
    
    return mystery(a + a, b / 2) + a;
}

int mystery2(int a, int b) {
    if (b == 0) {
        return 1;
    }
    
    if (b % 2 == 0) {
        return mystery2(a * a, b / 2);
    }
    
    return mystery2(a * a, b / 2) * a;
}

int test_ex_1_1_17(int argc, const char * argv[]) {
    int a = 2, b = 25, m = 3, n = 11;;
    printf("%d\n", mystery(a, b));
    printf("%d\n", mystery(m, n));
    
    printf("%d\n", mystery2(a, b));
    printf("%d\n", mystery2(m, n));
    
    return 0;
}
