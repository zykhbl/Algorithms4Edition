//
//  Ex_1_1_16.c
//  Algorithms4Edition
//
//  Created by zykhbl on 15-11-5.
//  Copyright (c) 2015年 zykhbl. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ex_1_1_16(int n) {
    if (n <= 0) return NULL;
    
    char *s1 = ex_1_1_16(n - 3);
    char *s2 = ex_1_1_16(n - 2);
    
    int size = 2 * sizeof(char) + 1;
    
    if (s1 != NULL) {
        size += strlen(s1);
    }
    
    if (s2 != NULL) {
        size += strlen(s2);
    }
    
    char *s = malloc(size);
    
    int offset = 0;
    if (s1 != NULL) {
        strcpy(s + offset, s1);
        offset += strlen(s1);
    }
    
    *(s + offset) = '0' + n;
    offset++;
    
    if (s2 != NULL) {
        strcpy(s + offset, s2);
        offset += strlen(s2);
    }
    
    *(s + offset) = '0' + n;
    
    *(s + (size - 1)) = '\0';
    
    if (s1 != NULL) {
        free(s1);
    }
    
    if (s2 != NULL) {
        free(s2);
    }
    
    return s;
}

int test_ex_1_1_16(int argc, const char * argv[]) {
    char *s = ex_1_1_16(6);
    printf("%s\n", s);
    free(s);
    
    return 0;
}