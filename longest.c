#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
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

char *longest(const char *s1, const char *s2) {
	int length = strlen(s1) + strlen(s2) + 1;
	char *string = calloc(length, sizeof(char));
	strcat(string, s1);
	strcat(string, s2);

	sort(length, string);
	char *trimmed = trim(length, string);
	printf("%s--ha\n", string);
	fflush(stdout);

	return string;
}

static void dotest(const char *s1, const char *s2, const char *expected) {
	const char *actual = longest(s1, s2);
	cr_assert_str_eq(
		actual, expected,
		"for strings:\n\"%s\"\n\"%s\"\nexpected:\n\"%s\"\nbut got:\n\"%s\"", s1,
		s2, expected, actual);
}

Test(tests_suite, sample_tests) {
	dotest("aretheyhere", "yestheyarehere", "aehrsty");
	dotest("loopingisfunbutdangerous", "lessdangerousthancoding",
		   "abcdefghilnoprstu");
	dotest("inmanylanguages", "theresapairoffunctions", "acefghilmnoprstuy");
	dotest("lordsofthefallen", "gamekult", "adefghklmnorstu");
	dotest("codewars", "codewars", "acdeorsw");
	dotest("agenerationmustconfrontthelooming", "codewarrs",
		   "acdefghilmnorstuw");

	dotest("sssssssllllllooooxxxxxxxqqqpppppppppppx",
		   "vvvvuuuuuuoooooooooooubbbbbbbbvvvqq", "blopqsuvx");
	dotest("mmmmmmmmmhhhhhhhhhnnnmmmmmqxxxxxxxjjjccccccccc",
		   "hhhhhhhhhhvvvvvvvvvppppppppphhhoouuuuuuuummqqq", "chjmnopquvx");
	dotest("ssssssssssgiiiiiiiiiizzzzzzzzfffffffffftttccccccccczzzz",
		   "uuurrrrrrrrrryyyyyyccccqqqqqqqqccccccccwwwwwwwkkkkkkk",
		   "cfgikqrstuwyz");
	dotest("eeeeefffffffffckkkkkwxxxxxxktttt",
		   "dpppppppppyyyyffffffffffdddddddddmmmpmmmmmm", "cdefkmptwxy");
	dotest("wwwwwwoooxxvgggggggggggggggggynnnn",
		   "jjjjjjjjjjjjjjjjksskkkkkkkwwwwwnnniiiiiiiii", "gijknosvwxy");
}
