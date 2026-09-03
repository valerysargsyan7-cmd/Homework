#include <stddef.h>
#include "str_utils.h"

int my_strlen(const char *str)
{

	if(str == NULL){

		return 0;

	}

	int count = 0;

	while(str[count] != '\0'){

		count++;

	}

	return count;

}

char *my_strchr(const char *str, char ch)
{

	if(str == NULL){

		return NULL;

	}

	while(*str != '\0'){

		if(*str == ch){

			return (char *)str;

		}

		str++;

	}

	if(ch == '\0'){

		return (char *)str;

	}

	return NULL;

}
