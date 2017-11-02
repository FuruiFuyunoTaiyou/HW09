#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>

int main(){
  printf("Statistics for directory: \nFiles: \n");
  DIR * directory = opendir(".");
  struct dirent * entry = readdir(directory);
  //char filename[256] = entry->d_name;
  while(entry){ //check for errors
    
    printf("\t%s \n", entry->d_name);
    entry = readdir(directory);
    //filename = entry->d_name;
  }
  
  closedir(directory);

  return 0;
}
