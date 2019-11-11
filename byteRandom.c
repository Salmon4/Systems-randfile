#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int randNum(){
  int file = open("/dev/random", O_RDONLY);
  int ans = 0;
  int *buff = &ans;
  if (file == -1){
    printf("Something's wronnnggggg :(((((");
  }
  else{
    int readBytes = read(file,buff,sizeof(int));
  }
  close(file);
  return ans;
}

int main(){
  return 1;
}
