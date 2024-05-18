#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


void noArgs() {
	char* inputLine = NULL;
	size_t inputLen = 0;
	
	char** lines = NULL;
	int lineCount = 0;
	
	printf("Give inputs (quit by sending empty line):\n");
	
	// Get lines from user and store each line in the array of lines
	while (getline(&inputLine, &inputLen, stdin) > 1) {
		// Allocate memory
		char* line = malloc(inputLen * sizeof(char));
		char** temp = realloc(lines, (lineCount + 1) * sizeof(char*));
		
		// Check that allocation was successful
		if (temp == NULL) {
			fprintf(stderr, "error: memory allocation failed\n");
			for (int i = 0; i < lineCount; i++) {
				free(lines[i]);
			}
			free(inputLine);
			free(line);
			exit(1);
		} else {
			lines = temp;
		}
		
		// Copy the input line to allocated line and increase line count
		strcpy(line, inputLine);
		lines[lineCount] = line;
		lineCount++;
	}
	
	// Print the lines backwards
	for (int i = lineCount; i > 0; i--) {
		printf("%s", lines[i - 1]);
	}
	
	// Free allocated memory
	for (int i = 0; i < lineCount; i++) {
		free(lines[i]);
	}
	free(inputLine);
	free(lines);
	
	return;
}


void oneArg(char* inputFileName) {
	// Open input file with error checking
	FILE* inputFile = fopen(inputFileName, "r");
	if (inputFile == NULL) {
		fprintf(stderr, "error: opening input file failed\n");
		exit(1);
	}
	
	char* inputLine = NULL;
	size_t inputLen = 0;

	char** lines = NULL;
	int lineCount = 0;
	
	// Read lines from input file
	while (getline(&inputLine, &inputLen, inputFile) > 0) {
		// Allocate memory for new line and resize array of lines
		char* line = malloc(inputLen * sizeof(char));
		char** temp = realloc(lines, (lineCount + 1) * sizeof(char*));
		
		// Check that allocation was successful
		if (temp == NULL) {
			fprintf(stderr, "error: memory allocation failed\n");
			for (int i = 0; i < lineCount; i++) {
				free(lines[i]);
			}
			free(inputLine);
			free(line);
			fclose(inputFile);
			exit(1);
		} else {
			lines = temp;
		}

		// Copy the input line to allocated line and increase line count
		strcpy(line, inputLine);
		lines[lineCount] = line;
		lineCount++;
	}
	fclose(inputFile);
	
	// Print the lines reversed
	for (int i = lineCount; i > 0; i--) {
		printf("%s", lines[i - 1]);
	}
	
	// Free allocated memory
	for (int i = 0; i < lineCount; i++) {
		free(lines[i]);
	}
	free(inputLine);
	free(lines);
	
	return;
}


void twoArgs(char* inputFileName, char* outputFileName) {
	// Check that input and output files are different
	if (strcmp(inputFileName, outputFileName) == 0) {
		fprintf(stderr, "error: input and output file must differ\n");
		exit(1);
	}

	// Open input file with error checking
	FILE* inputFile = fopen(inputFileName, "r");
	if (inputFile == NULL) {
		fprintf(stderr, "error: opening input file failed\n");
		exit(1);
	}
	
	char* inputLine = NULL;
	size_t inputLen = 0;
	
	char** lines = NULL;
	int lineCount = 0;
	
	// Read lines from input file
	while (getline(&inputLine, &inputLen, inputFile) > 0) {
		// Allocate memory for new line and resize array of lines
		char* line = malloc(inputLen * sizeof(char));
		char** temp = realloc(lines, (lineCount + 1) * sizeof(char*));
		
		// Check that allocation was successful
		if (temp == NULL) {
			fprintf(stderr, "error: memory allocation failed\n");
			for (int i = 0; i < lineCount; i++) {
				free(lines[i]);
			}
			free(inputLine);
			free(line);
			fclose(inputFile);
			exit(1);
		} else {
			lines = temp;
		}
		
		// Copy the input line to allocated line and increase line count
		strcpy(line, inputLine);
		lines[lineCount] = line;
		lineCount++;
	}
	fclose(inputFile);
	
	// Open output file with error checking
	FILE* outputFile = fopen(outputFileName, "w");
	if (outputFile == NULL) {
		fprintf(stderr, "error: opening output file failed\n");
		for (int i = 0; i < lineCount; i++) {
			free(lines[i]);
		}
		free(inputLine);
		free(lines);
		exit(1);
	}
	
	// Write reversed lines to file
	for (int i = lineCount; i > 0; i--) {
		fprintf(outputFile, "%s", lines[i - 1]);
	}
	fclose(outputFile);
	
	printf("Reversed file written to %s\n", outputFileName);
	
	// Free allocated memory
	for (int i = 0; i < lineCount; i++) {
		free(lines[i]);
	}
	free(inputLine);
	free(lines);
	
	return;
}
