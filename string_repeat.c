#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *repeat_str(size_t count, const char *src) {
	int length = strlen(src);
	char *repeated_str = calloc(length * count + 1, sizeof(char));

	for (size_t i = 0; i < count; i++) {
		strcat(repeated_str, src);
	}
	return repeated_str;
}

int main() {
	char *src = "hello ";
	char *rep = repeat_str(4, src);

	printf("%s\n", rep);
	if (strcmp(rep, "hello hello hello hello ") == 0)
		printf("pass\n");
}
