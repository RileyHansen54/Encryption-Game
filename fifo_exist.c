
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    struct stat file_info;
    const char *fifo_name = "/tmp/my_fifo";

    if (stat(fifo_name, &file_info) == 0) {
        if (S_ISFIFO(file_info.st_mode)) {
            printf("The file '%s' exists and is a FIFO.\n", fifo_name);
        } else {
            printf("The file '%s' exists, but it is not a FIFO.\n", fifo_name);
        }
    } else {
        printf("The file '%s' does not exist.\n", fifo_name);
    }

    return 0;
}

