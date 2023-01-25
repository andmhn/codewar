#include <stdio.h>

char get_grade(int a, int b, int c) {
    float total = 300; // marks
    float obtained = a + b + c;
    float score = (float)(obtained / total) * 100;

    printf("obtained: %f\n score: %f\n", obtained, score);
    if (90 <= score)
        return 'A';
    if (80 <= score)
        return 'B';
    if (70 <= score)
        return 'C';
    if (60 <= score)
        return 'D';
    if (0 <= score)
        return 'F';
    return 'A';
}

int main() {
  char g = get_grade(95, 90, 93);
  printf("%c\n", g);
}
