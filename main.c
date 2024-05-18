#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char** argv)
{
	if (argc == 1) {
		noArgs();
	}
	else if (argc == 2) {
		oneArg(argv[1]);
	}
	else if (argc == 3) {
		twoArgs(argv[1], argv[2]);
	} 
	else {
		fprintf(stderr, "Invalid amount of arguments\n");
		exit(1);
	}

	return 0;
}

