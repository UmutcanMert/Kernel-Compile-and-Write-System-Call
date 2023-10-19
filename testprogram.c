/**
 * Test the stephen syscall (#3..)
 */
#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <errno.h>

/*
 * Put your syscall number here.
 */
#define SYS_umutcan 335 /*syscall table daki no ile ayni olmali*/

int main(int argc, char **argv)
{
  if (argc <= 1) {
    printf("Must provide a string to give to system call.\n");
    return -1;
  }
  char *arg = argv[1];
  printf("Making system call with \"%.50s\".\n", arg);
  long res = syscall(SYS_umutcan, arg); /*yani syscall(335,arg)*/

  if (res == -1)
    fprintf(stderr, "umutcan failed, errno = %d\n", errno);
  else
    printf("System call umutcan returned %ld.\n", res);
  return res;
}
