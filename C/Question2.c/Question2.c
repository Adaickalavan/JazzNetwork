// Question2.c

#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *f(int m) {
	char buf[7];
    int x = 4;
    if (m == 1 && x--) {
		strcpy(buf, "AAAAAA");
		return buf;
	}
	else if (m == 2) {
		char *msg = (char *)malloc(3);
	    strcpy(msg, "ABCD");
        return msg;
	}
	return "CCCCCC";
}

int main(int argc, char **argv) {
	char *m;
	argc = 4;
	m = f(argc);
	putchar(m[0]);
	putchar(m[1]);
	putchar(m[2]);
	putchar(m[3]);
	putchar(m[4]);
	putchar(m[5]);
	putchar(m[6]);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
