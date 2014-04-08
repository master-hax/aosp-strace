#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

const char *tmp_file="/data/local/tmp/strace_stat_test";
#define    BLK_SIZE 4096

int main(int argc, char *argv[])
{
    int ret = 0, size = 0, bk_size = 0;
    struct stat test_stat;
    int fd = open(tmp_file, O_ASYNC | O_CREAT | O_RDWR, 0766);
    char buf[BLK_SIZE];

    if (fd < 0)
        return -1;

    bk_size = size = random() % 1000789;
    while (size >4096) {
        write(fd, buf, BLK_SIZE);
        size -= 4096;
    }
    if (size !=0)
        write(fd, buf, size);

    ret = fstat(fd, &test_stat);
    if (ret < 0) {
        close(fd);
        unlink(tmp_file);
        return ret;
    }

    printf("st_dev=makedev(%lu, %lu), st_ino=%lu, st_mode=S_IFREG|%#o, ",
        (unsigned long) major(test_stat.st_dev),
        (unsigned long) minor(test_stat.st_dev),
        (unsigned long) test_stat.st_ino,
        test_stat.st_mode & ~S_IFMT);
    printf("st_nlink=%lu, st_uid=%lu, st_gid=%lu,",
        (unsigned long) test_stat.st_nlink,
        (unsigned long) test_stat.st_uid,
        (unsigned long) test_stat.st_gid);

    close(fd);

    unlink(tmp_file);
    return 0;
}
