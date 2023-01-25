#include <stdlib.h>
#include <string.h>

char *dna_to_rna(const char *dna) {
    size_t len = strlen(dna);
    char *rna = calloc(len, sizeof(char));
    strcpy(rna, dna);

    if (len == 0) {
        return rna;
    }
    for (size_t i = 0; i < len; i++) {
        if (rna[i] == 'T')
            rna[i] = 'U';
    }
    return rna;
}
