#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int ret, del;
  del = 0;
  if (argc > 1) {
    for(int i=1; i<argc; i++) {
      printf("exist = %d\n", access(argv[i], F_OK));
      if (access(argv[i], F_OK) == 0) {
        ret = remove(argv[i]);
        if (ret == 0)
          del = 1;
        else
          del = 0;
      }
    }
  }
  return del;
}