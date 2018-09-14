
#include <stddef.h>
#include <string.h>

int strcmp(const char *s1, const char *s2) {
	const char *p1 = s1;
	const char *p2 = s2;

	char c1, c2;

	while ((c1 = *p1++) == (c2 = *p2++) && c1);

	return c1 - c2;
}

size_t strlen(const char *s) {
	const char *p = s;

	while (*p++);

	return (size_t)(p - s - 1);
}

char *strchr(const char *s, int c) {
	char ch = (char)c;

	while (*s)
	{
		if (*s == ch)
		{
			return (char*)s;
		}

		s++;
	}

	return NULL;
}

size_t strspn(const char *str, const char *accept) {
	size_t length = 0;

	while (*str && strchr(accept, *str))
	{
		str++;
		length++;
	}
	
	return length;
}

size_t strcspn(const char *str, const char *reject) {
	size_t length = 0;

	while (*str)
	{
		if (strchr(reject, *str))
		{
			return length;
		}
		else
		{
			str++;
			length++;
		}
	}

	return length;
}

char *strtok_r(char *str, const char *delim, char **saveptr) {
	
	if (str == NULL)
	{
		str = *saveptr;
	}

	if (*str == '\0')
	{
		*saveptr = str;
		return NULL;
	}

	str += strspn(str, delim);
	if (*str == '\0')
	{
		*saveptr = str;
		return NULL;
	}

	// end of token
	char *end = str + strcspn(str, delim);
	if (*end == '\0')
	{
		*saveptr = end;
		return str;
	}

	*end = '\0';
	*saveptr = end + 1;

	return str;
}