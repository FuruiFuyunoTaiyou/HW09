#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>

int main(){
  printf("Statistics for directory: \nFiles: \n");
  DIR * directory = opendir(".");

  //printing all files
  struct dirent * entry = readdir(directory);
  while(entry){ //check for errors
    
    printf("\t%s \n", entry->d_name);
    entry = readdir(directory);
  }

  closedir(directory);

  //printing directories & other files separately
  directory = opendir(".");
  printf("Directories: \n");
  entry = readdir(directory);
  while(entry && entry->d_type == DT_DIR){
    printf("\t%s \n", entry->d_name);
    entry = readdir(directory);
  }

  closedir(directory);
  directory = opendir(".");

  printf("Other Files: \n");
  entry = readdir(directory);
  while(entry && entry->d_type != DT_DIR){
    printf("\t%s \n", entry->d_name);
    entry = readdir(directory);
  }
  
  closedir(directory);

  return 0;
}
