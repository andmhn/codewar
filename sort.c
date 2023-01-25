#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int length, char *string) {
    char temp;
    int i, j;
    for (i = 0; i < length - 1; i++) {
        for (j = i + 1; j < length; j++) {
            if (string[i] > string[j]) {
                temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }
}

// TODO Make this work.
char *trim(int length, const char *string) {
    char *trimmed = malloc(length);
    int index = 0;

    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (string[i] != string[j]) {
                trimmed[index] = string[i];
                index++;
            }
        }
    }
    trimmed[index + 1] = '\0';
    return trimmed;
}

int main(void) {
    char string[] = "AnandMohan";
    sort(strlen(string), string);
    printf("String after sorting  - %s \n", string);
    return 0;
}
