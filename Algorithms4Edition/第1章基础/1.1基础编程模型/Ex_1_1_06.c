//
//  Ex_1_1_06.c
//  Algorithms4Edition
//
//  Created by zykhbl on 15-11-5.
//  Copyright (c) 2015年 zykhbl. All rights reserved.
//

#include <stdio.h>

void ex_1_1_06() {
    int f = 0;
    int g = 1;
    for (int i = 0; i <= 15; i++) {
        printf("%d\n", f);
        f = f + g;
        g = f - g;
    }
}

int test_ex_1_1_06(int argc, const char * argv[]) {
    ex_1_1_06();
    
    return 0;
}
