//
//  Ex_1_1_15.c
//  Algorithms4Edition
//
//  Created by zykhbl on 15-11-10.
//  Copyright (c) 2015年 zykhbl. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* histogram(int *a, int n, int m) {
    int *b = malloc(m * sizeof(int));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j] == i) {
                b[i]++;
            }
        }
    }
    
    return b;
}

int test_ex_1_1_15(int argc, const char * argv[]) {
    int n = 40, m = 30;
    int a[n];
    
    srand(time(0) % 100);
    
    printf("a: \n");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % m;
        printf("%5d", a[i]);
    }
    printf("\n");
    
    int *b = histogram(a, n, m);
    int sum = 0;
    printf("b: \n");
    for (int j = 0; j < m; j++) {
        printf("%5d", b[j]);
        sum += b[j];
    }
    printf("\n sum = %d\n", sum);
    
    return 0;
}