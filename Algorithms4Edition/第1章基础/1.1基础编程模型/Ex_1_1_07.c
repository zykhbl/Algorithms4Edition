//
//  Ex_1_1_07.c
//  Algorithms4Edition
//
//  Created by zykhbl on 15-11-5.
//  Copyright (c) 2015年 zykhbl. All rights reserved.
//

#include <stdio.h>
#include <math.h>

void ex_1_1_07_a() {
    double t = 9.0;
    
    while (fabs(t - 9.0/t) > 0.001) {
        t = (9.0/t + t) / 2.0;
    }
    
    printf("%.5f\n", t);
}

void ex_1_1_07_b() {
    int sum = 0;
    
    for (int i = 1; i < 1000; i++) {
        for (int j = 0; j < i; j++) {
            sum++;
        }
    }
    
    printf("%d\n", sum);
}

void ex_1_1_07_c() {
    int sum = 0;
    
    for (int i = 1; i < 1000; i *= 2) {
        for (int j = 0; j < 1000; j++) {
            sum++;
        }
    }
    
    printf("%d\n", sum);
}

int test_ex_1_1_07(int argc, const char * argv[]) {
    ex_1_1_07_a();
    ex_1_1_07_b();
    ex_1_1_07_c();
    
    return 0;
}