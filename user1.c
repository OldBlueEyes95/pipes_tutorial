#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char* argv[]){
    int arr[5];
    srand(time(NULL)); 
    int i;
    for(int i = 0 ; i < 5; i++){
        arr[i] = rand() % 100;
    }

    int fd = open("sum", O_WRONLY); // Get the file descriptor
    if(fd == -1){
        return 1; // Error occurred
    }

    for(int i = 0; i < 5; i++){
        if(write(fd, &arr[i], sizeof(int)) == -1){
            return 2; // Error occurred while writing
        }
        printf("Written %d\n", arr[i]);
    }

    close(fd);

    return 0;
}