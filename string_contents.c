#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vowels = 0, consonants = 0, special_chars = 0, digits = 0; // counters

bool is_vowel(char c) {
    char vowel_chars[] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 5; i++)
        if (c == vowel_chars[i])
            return true;
    return false;
}

// checks every chars in s and updates counters
void check_contents(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (isdigit(c))
            digits++;
        else if (isalpha(c)) {
            if (is_vowel(c))
                vowels++;
            else
                consonants++;
        } else
            special_chars++; // includes spaces
    }
}

int main() {
    char *str = calloc(BUFSIZ, 1); // I do't know why I do this

    // This is why I don't like c
    // Building string @str with spaces
    printf("Enter the string:\n");
    char ch;
    char word[2];
    while ((ch = getchar()) != EOF) {
        sprintf(word, "%c", ch); // TODO find a better way to do this
        strcat(str, word);
    }

    check_contents(str);
    free(str);
    printf("\nVowels: %d\nconsonants: %d \ndigits: %d \nspecial_chars: %d\n",
           vowels, consonants, digits,
           special_chars ? special_chars - 1 : 0); // don't treat EOF as character
}
