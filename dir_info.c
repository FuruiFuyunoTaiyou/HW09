#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(){
  printf("Statistics for directory . \n");

  /*//printing all files
  printf("Files: \n");
  DIR * directory = opendir(".");
  struct dirent * entry = readdir(directory);
  while(entry){ //check for errors
    printf("\t%s \n", entry->d_name);
    entry = readdir(directory);
  }
  closedir(directory);*/

  /*//finding total size of all files
  printf("Total directory size: ");
  int dir_size = 0;
  directory = opendir(".");
  entry = readdir(directory);
  struct stat buff0;
  stat(entry->d_name
  while(entry){
    dir_size += entry->
  }
  closedir(directory);*/

  //printing directories & other files separately
  printf("Directories: \n");
  DIR * directory = opendir(".");
  struct dirent * entry = readdir(directory);
  struct stat buff;
  stat(entry->d_name, &buff);
  while(entry){
    if(S_ISDIR(buff.st_mode)){
      printf("\t%s \n", entry->d_name);
    }
    entry = readdir(directory);
    stat(entry->d_name, &buff);
  }
  closedir(directory);

  printf("Other: \n");
  directory = opendir(".");
  entry = readdir(directory);
  buff;
  stat(entry->d_name, &buff);
  while(entry){
    if(!S_ISDIR(buff.st_mode)){
      printf("\t%s \n", entry->d_name);
    }
    entry = readdir(directory);
    stat(entry->d_name, &buff);
  }
  closedir(directory);

  return 0;
}
