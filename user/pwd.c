#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fs.h"
#include "user/user.h"
#include "kernel/fcntl.h"

#define MAXPATH 512

char path[MAXPATH];









void
build_path()
{
    int fd;
    struct stat st_cur, st_parent;
    struct dirent de;

    fd = open(".", O_RDONLY);
    fstat(fd, &st_cur);
    close(fd);

    fd = open("..", O_RDONLY);
    fstat(fd, &st_parent);

    if(st_cur.ino == st_parent.ino){
        close(fd);
        return;
    }

    while(read(fd, &de, sizeof(de)) == sizeof(de)){
        if(de.inum == st_cur.ino){
           char temp[MAXPATH];
       strcpy(temp, path);
        char temp2[MAXPATH];
   strcpy(temp2, path);

            path[0] = '/';
            strcpy(path + 1, de.name);
            strcpy(path + strlen(path), temp2);
            break;
        }
    }

    close(fd);

    chdir("..");
    build_path();
}







int
main(int argc, char *argv[])
{
    path[0] = '\0';

   build_path();

  if(strlen(path) == 0)
        printf("/\n");
  else
        printf("%s\n", path);

    exit(0);
}
