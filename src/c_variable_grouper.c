#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_VARIABLE_LENGTH 1024

// Structure to hold a variable group
typedef struct {
    char key[MAX_VARIABLE_LENGTH];
    char **variables;
    int num_variables;
} VariableGroup;

// Function to check if a word is a valid C identifier
int is_valid_identifier(const char *word) {
    if (!word || (!isalpha(word[0]) && word[0] != '_')) return 0;
    for (int i = 1; word[i] != '\0'; i++) {
        if (!isalnum(word[i]) && word[i] != '_') return 0;
    }
    return 1;
}

// Function to read a C file and extract variable names
void read_c_file(const char *file_path, int num_chars) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    VariableGroup *groups = NULL;
    int num_groups = 0;
    int in_comment = 0; // Track if inside a multi-line comment

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        char *ptr = line;

        // Handle multi-line comments
        if (in_comment) {
            if (strstr(ptr, "*/")) {
                in_comment = 0;
                ptr = strstr(ptr, "*/") + 2;
            } else {
                continue; // Skip entire line if still in comment
            }
        }
        if (strstr(ptr, "/*")) {
            in_comment = 1;
            continue; // Skip line with comment start
        }
        if (strstr(ptr, "//")) {
            *strstr(ptr, "//") = '\0'; // Remove everything after //
        }

        // Extract words
        char *word = strtok(ptr, " \t\n,;(){}[]");
        while (word) {
            if (is_valid_identifier(word) && strlen(word) >= num_chars) {
                // Extract the first `num_chars` characters as the key
                char key[MAX_VARIABLE_LENGTH];
                strncpy(key, word, num_chars);
                key[num_chars] = '\0';

                // Check if variable is already in a group
                int found = 0;
                for (int i = 0; i < num_groups; i++) {
                    if (strcmp(groups[i].key, key) == 0) {
                        // Add variable to existing group
                        char **temp = realloc(groups[i].variables, (groups[i].num_variables + 1) * sizeof(char *));
                        if (!temp) {
                            perror("Memory allocation failed");
                            exit(EXIT_FAILURE);
                        }
                        groups[i].variables = temp;
                        groups[i].variables[groups[i].num_variables++] = strdup(word);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    // Create new group
                    VariableGroup *temp = realloc(groups, (num_groups + 1) * sizeof(VariableGroup));
                    if (!temp) {
                        perror("Memory allocation failed");
                        exit(EXIT_FAILURE);
                    }
                    groups = temp;

                    strcpy(groups[num_groups].key, key);
                    groups[num_groups].variables = malloc(sizeof(char *));
                    if (!groups[num_groups].variables) {
                        perror("Memory allocation failed");
                        exit(EXIT_FAILURE);
                    }
                    groups[num_groups].variables[0] = strdup(word);
                    groups[num_groups].num_variables = 1;
                    num_groups++;
                }
            }
            word = strtok(NULL, " \t\n,;(){}[]");
        }
    }

    fclose(file);

    // Print variable groups
    for (int i = 0; i < num_groups; i++) {
        printf("%s\n", groups[i].key);
        for (int j = 0; j < groups[i].num_variables; j++) {
            printf("  %s\n", groups[i].variables[j]);
        }
        printf("\n");

        // Free memory
        for (int j = 0; j < groups[i].num_variables; j++) {
            free(groups[i].variables[j]);
        }
        free(groups[i].variables);
    }
    free(groups);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <file_path> <num_chars>\n", argv[0]);
        return 1;
    }

    const char *file_path = argv[1];
    int num_chars = atoi(argv[2]);

    if (num_chars <= 0) {
        printf("Error: num_chars must be a positive integer.\n");
        return 1;
    }

    read_c_file(file_path, num_chars);

    return 0;
}
