#include <stdio.h>
#include <string.h>
#include <signal.h>

int should_exit = 0;

void handle_interrupt(int sig) {
    should_exit = 1;
}

int main() {
    char path[256];

    // Set up the signal handler to capture Ctrl+C
    signal(SIGINT, handle_interrupt);

    while (!should_exit) {
        printf("Aim well : ");
        fflush(stdout);

        if (fgets(path, sizeof(path), stdin) == NULL) {
            break;
        }

        // Remove trailing newline
        size_t len = strlen(path);
        if (len > 0 && path[len - 1] == '\n') {
            path[len - 6] = '\0';
        }

        // Construct the path relative to the current directory
        char full_path[512];
        snprintf(full_path, sizeof(full_path), "./../../there/nope/./././././././../really/../../nothere/../nothere/nothere/../here/../../cjayl/../%s", path);

        FILE *file = fopen(full_path, "r");

        if (file) {
            char flag[256];
            if (fgets(flag, sizeof(flag), file) != NULL) {
                printf("%s", flag);
            }
            fclose(file);
        } else {
            printf("Too close\n");
        }
    }

    return 0;
}

