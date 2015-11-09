//
//  Ex_1_1_13.c
//  Algorithms4Edition
//
//  Created by zykhbl on 15-11-9.
//  Copyright (c) 2015年 zykhbl. All rights reserved.
//

#include <stdio.h>

void ex_1_1_13(int *a, int *b, int m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *(b + i * m + j) = *(a + i + j * n);
        }
    }
}

int test_ex_1_1_13(int argc, const char * argv[]) {
    int m = 4, n = 3;
    
    int a[m][n];
    int b[n][m];
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = i * 10 + j;
        }
    }
    
    printf("a: \n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
    
    ex_1_1_13((int*)a, (int*)b, m, n);
    
    printf("b: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d", b[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}