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

char* itoa_10(int n) {
    char *s = malloc(10 * sizeof(char));
    
    int i = 0;
    if (n == 0) {
        *(s + i) = '0';
        i++;
    } else {
        for (; n > 0; i++, n /= 10) {
            *(s + i) = '0' + n % 10;
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

char* ex_1_1_16(int n) {
    static char **itoa = NULL;
    static char **ff = NULL;
    if (itoa == NULL) {
        itoa = malloc((n + 1) * sizeof(char*));
    }
    if (ff == NULL) {
        ff = malloc((n + 1) * sizeof(char*));
    }
    
    if (n <= 0) return NULL;
    
    if (*(ff + n - 3) == NULL) {
        *(ff + n - 3) = ex_1_1_16(n - 3);
    }
    char *s1 = *(ff + n - 3);
    
    if (*(ff + n - 2) == NULL) {
        *(ff + n - 2) = ex_1_1_16(n - 2);
    }
    char *s2 = *(ff + n - 2);
    
    if (*(itoa + n) == NULL) {
        *(itoa + n) = itoa_10(n);
    }
    char *s3 = *(itoa + n);
    
    size_t size = 2 * strlen(s3) + 1;
    
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
    
    strcpy(s + offset, s3);
    offset += strlen(s3);
    
    if (s2 != NULL) {
        strcpy(s + offset, s2);
        offset += strlen(s2);
    }
    
    strcpy(s + offset, s3);
    
    *(s + (size - 1)) = '\0';
    
    if (*(ff + n) == NULL) {
        *(ff + n) = s;
    }
    
    return s;
}

char* ex_1_1_16_slow(int n) {
    if (n <= 0) return NULL;
    
    char *s1 = ex_1_1_16_slow(n - 3);
    char *s2 = ex_1_1_16_slow(n - 2);
    char *s3 = itoa_10(n);
    
    size_t size = 2 * strlen(s3) + 1;
    
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
    
    strcpy(s + offset, s3);
    offset += strlen(s3);
    
    if (s2 != NULL) {
        strcpy(s + offset, s2);
        offset += strlen(s2);
    }
    
    strcpy(s + offset, s3);
    
    *(s + (size - 1)) = '\0';
    
    if (s1 != NULL) {
        free(s1);
    }
    
    if (s2 != NULL) {
        free(s2);
    }
    
    free(s3);
    
    return s;
}

int test_ex_1_1_16(int argc, const char * argv[]) {
    char *s = ex_1_1_16(36);
    printf("%s\n", s);
    free(s);
    
    return 0;
}