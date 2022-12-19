#include <stdio.h>
#include<string.h>
#include<stdlib.h>

// made by me
// char* remove_char(const char* src)
// {
//
// 	int len = strlen(src);
// 	char * ret = malloc(len);
//
// 	for(int i = 0; i < len; i++)
// 	{
//     // when reaching end of
// 		if (i == len - 2)
// 		{
// 			ret[i] = '\0';
// 			break;
// 		}
// 		ret[i] = src[i + 1];
// 	}
//
// 	return ret;
// }


char* remove_char(char* dst, const char* src)
{
    strcpy(dst, src + 1);
    dst[strlen(dst) - 1] = '\0';
    return dst;
}

int main(){
	char * src = "Hello World";
	char * dst = malloc(strlen(src));
	char * str = remove_char(dst, src);

	printf("%s\n", str);
	free(dst);
}
