#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"


int main(int argc, char *argv[]) {
  int pidOne = 0;
  int pidTwo = 0;

  pidOne = fork();
  int stat;
  wait(&stat);
  printf(1, "waitchild %d", stat);
  if (pidOne != 0) {
    printf(1, "one\n");
    pidTwo = fork();
    //int stat;
    //wait(&stat);
    //printf(1,"wait child %d",stat);
    if (pidTwo != 0) {
      int status;
      waitpid(pidOne, &status, 0);
      printf(1, "two %d\n",status);
      waitpid(pidTwo, 0, 0);
      printf(1,"three\n");
      exit(0);
    }
    printf(1,"four\n");
  }
  printf(1,"five\n");
  exit(0);
}
