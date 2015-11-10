//
//  Ex_1_1_18.c
//  Algorithms4Edition
//
//  Created by zykhbl on 15-11-10.
//  Copyright (c) 2015年 zykhbl. All rights reserved.
//

#include <stdio.h>

/*
 a的倍数增加方式（偶数时增加一倍，奇数时增加一倍，再加1），类似于b的递减（偶数时减少一半，奇数时减1后，再减少一半），所以最终mystery(a, b) = a * b
 */
int mystery(int a, int b) {
    if (b == 0) {
        return 0;
    }
    
    if (b % 2 == 0) {
        return mystery(a + a, b / 2);
    }
    
    return mystery(a + a, b / 2) + a;
}

/*
 a的指数增加方式（偶数时增加一倍，奇数时增加一倍，再加1），类似于b的递减（偶数时减少一半，奇数时减1后，再减少一半），所以最终mystery2(a, b) = a ^ b
 */
int mystery2(int a, int b) {
    if (b == 0) {
        return 1;
    }
    
    if (b % 2 == 0) {
        return mystery2(a * a, b / 2);
    }
    
    return mystery2(a * a, b / 2) * a;
}

int test_ex_1_1_18(int argc, const char * argv[]) {
    int a = 2, b = 25, m = 3, n = 11;;
    printf("%d\n", mystery(a, b));
    printf("%d\n", mystery(m, n));
    
    printf("%d\n", mystery2(a, b));
    printf("%d\n", mystery2(m, n));
    
    return 0;
}
