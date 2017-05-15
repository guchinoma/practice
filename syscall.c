#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv){

    char buf[4096];
    char *error_write = "Open Error\n";
    char *error_read = "Read Error\n";
    char *line = "\n";

    int fd = open(argv[1], O_RDONLY);
        if(fd == -1){
        int fd_fault = write(1, error_write, 13);
        return 0;
    }
    else{
        int fd_read = read(fd, buf, 4096);
        if(fd_read == -1){
            int fd_read_fault = write(1, error_read, 13);
            close(fd);
            return 0;
        }
        else{

            int fd_write = write(1, buf, fd_read);
            //int fd_write_1 = write(1, line, 10);
            close(fd);
        }
    }
    return 0;
}