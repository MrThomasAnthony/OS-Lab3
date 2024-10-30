#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    const char *fifo = "/tmp/myfifo";
    mkfifo(fifo, 0666);

    while (1) {
        int fd = open(fifo, O_RDONLY);
        if (fd == -1) {
            perror("Error opening FIFO");
            return 1;
        }

        char request[256];
        read(fd, request, sizeof(request));
        close(fd);

        // Print client's request to CLI
        printf("%s", request);

        int lower_bound, upper_bound;
        if (sscanf(request, "RANGE %d %d", &lower_bound, &upper_bound) != 2) {
            fd = open(fifo, O_WRONLY);
            write(fd, "malformed request\n", 18);
            close(fd);
            continue;
        }

        char response[2048] = "Primes: ";
        char buffer[64];
        for (int i = lower_bound; i <= upper_bound; i++) {
            if (i <= 1) continue;
            int is_prime = 1;
            for (int j = 2; j <= sqrt(i); j++) {
                if (i % j == 0) {
                    is_prime = 0;
                    break;
                }
            }
            if (is_prime) {
                sprintf(buffer, "%d ", i);
                strcat(response, buffer);
            }
        }
        strcat(response, "\n");

        fd = open(fifo, O_WRONLY);
        write(fd, response, strlen(response) + 1);
        close(fd);
    }

    unlink(fifo);
    return 0;
}
