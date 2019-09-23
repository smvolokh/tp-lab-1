#include <string.h>
#include <algorithm>
#include "task4.h"


char * sum(char *x, char *y){
	int len = std::max(strlen(x), strlen(y));

	char *s1 = new char[len + 2];
	char *s2 = new char[len + 2];
	memset(s1, 0, len + 2);
	memset(s2, 0, len + 2);

	strcpy(s1 + len - strlen(x) + 1, x);
	strcpy(s2 + len - strlen(y) + 1, y);

	for (int i = 0; i <= len; i++){
		if (s1[i]){
			s1[i] = s1[i] - '0';
		}
		if (s2[i]){
			s2[i] = s2[i] - '0';
		}
	}

	for (int count = 0, i = len; i >= 0; i--, count = count / 10){
		count = count + s1[i] + s2[i];
		s1[i] = count % 10 + '0';
	}
	char *sum;
	if (s1[0] == '0') {
		sum = s1 + 1;
	}
	else sum = s1;
	return sum;
}