//
//  Ex_1_1_09.c
//  Algorithms4Edition
//
//  Created by zykhbl on 15-11-6.
//  Copyright (c) 2015年 zykhbl. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

char* itoa_2(int n) {
    char *s = malloc(10 * sizeof(char));
    
    int i = 0;
    if (n == 0) {
        *(s + i) = '0';
        i++;
    } else {
        for (; n > 0; i++, n /= 2) {
            *(s + i) = '0' + n % 2;
        }
    }
    
    *(s + i) = '\0';
    
    for (int j = 0; j < i / 2; j++) {
        char t = *(s + j);
        *(s + j) = *(s + i - 1 - j);
        *(s + i - 1 - j) = t;
    }
    
    return s;
}

int test_ex_1_1_09(int argc, const char * argv[]) {
    char *s = itoa_2(10);
    printf("%s\n", s);
    free(s);
    
    return 0;
}