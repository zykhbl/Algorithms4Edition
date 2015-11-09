//
//  Ex_1_1_12.c
//  Algorithms4Edition
//
//  Created by zykhbl on 15-11-9.
//  Copyright (c) 2015年 zykhbl. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void ex_1_1_12() {
    int *a = malloc(10 * sizeof(int));
    
    for (int i = 0; i < 10; i++) {
        a[i] = 9 - i;
    }
    
    for (int i = 0; i < 10; i++) {
        a[i] = a[a[i]];
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
    
//    for (int i = 0; i < 10; i++) {
//        printf("%d\n", a[i]);
//    }
    
    free(a);
}

int test_ex_1_1_12(int argc, const char * argv[]) {
    ex_1_1_12();
    
    return 0;
}