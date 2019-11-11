#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int randNum(){
  int file = open("/dev/random", O_RDONLY);
  int ans = 0;
  int *buff = &ans;
  if (file == -1){
    printf("error: %s\n", strerror(errno));
  }
  else{
    int readBytes = read(file,buff,sizeof(int));
  }
  close(file);
  return ans;
}

int main(){
  int arr[10];
  int i;
  for (i = 0; i < 10; i++){
    arr[i] = randNum();
  }
  printf("Generating random numbers:\n");
  for (i = 0; i < 10; i++){
    printf("random %d: %d\n", i, arr[i]);
  }
  printf("\n");

  printf("Writing numbers to file...\n");
  int file = open("output.txt", O_WRONLY | O_CREAT);
  if (file == -1){
    printf("error: %s\n", strerror(errno));
    printf("Fix error to contine.\n");
  }
  int writtenBytes = write(file,arr,sizeof(arr));
  if (writtenBytes == -1){
    printf("error: %s\n", strerror(errno));
    printf("Fix error to contine.\n");
  }
  close(file);
  printf("\n");

  printf("Reading numbers from file...\n");
  int arr2[10];
  file = open("output.txt", O_RDONLY);
  if (file == -1){
    printf("error: %s\n", strerror(errno));
    printf("Fix error to contine.\n");
  }
  int readBytes = read(file,arr2,writtenBytes);
  if (readBytes == -1){
    printf("error: %s\n", strerror(errno));
    printf("Fix error to contine.\n");
  }
  printf("\n");

  printf("Verification that written values were the same:\n");
  for (i = 0; i < 10; i++){
    printf("random %d: %d\n", i, arr2[i]);
  }
  close(file);

  return 1;
}
