#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <readline/readline.h>
#define DELIM " \t"
#define PREFICS 'J'
int main() {
    char sogl[] = {"bBcCdDfFgGhHjJkKlLmMnNpPqQrRsStTvVwWxXyYzZ"};
    char *str = readline("\n>");
    char *str2 = strdup(str);
    char *out = calloc(strlen(str2) + 1, sizeof(char));
    char *lema = strtok(str2, DELIM);
    char *d_lema;
    int col_dlema;
    int flag = 0;
    clock_t start = clock();
    while (lema != NULL) {
        for (int j = 0; j < strlen(sogl); j++) {
            if (lema[0] == sogl[j]) {
                flag++;
                break;
            }
        }
        if (flag == 1) {
            d_lema = strdup(lema);
            col_dlema = strlen(d_lema) + 1;
            d_lema = realloc(d_lema, col_dlema);
            for (int i = col_dlema; i > 0; i--) {
                d_lema[i] = d_lema[i - 1];
            }
            d_lema[0] = PREFICS;
            out = strcat(out, d_lema);
            flag = 0;
        } else {
            out = strcat(out, lema);
        }
        lema = strtok(NULL, DELIM);
        if (lema != NULL) {
            out = strcat(out, " ");
        }
    }
    printf("Initial:\"%s\"\n", str);
    printf("Result:\"%s\"\n", out);
    if (str != NULL) {
        free(str);
    }
    if (str2 != NULL) {
        free(str2);
    }
    if (out != NULL) {
        free(out);
    }
    if (lema != NULL) {
        free(lema);
    }
    if (d_lema != NULL) {
        free(d_lema);
    }
    clock_t end = clock();
    printf("First program worked: %lfs\n", (double)(end - start) / CLOCKS_PER_SEC);
}