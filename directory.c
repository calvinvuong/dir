#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
  int size = 0;
  DIR *folder = opendir(".");
  struct dirent *entry = readdir(folder);
  struct stat buf;
  // print directories first
  printf("Directories: \n");
  while ( entry != NULL ) {
    stat(entry->d_name, &buf);
    if ( entry->d_type == 0 || entry->d_type == 4 ) 
      printf("%s\n", entry->d_name);
    entry = readdir(folder);
  }

  // print regular files
  while ( entry != NULL ) {
    stat(entry->d_name, &buf);
    if ( entry->d_type != 0 && entry->d_type != 4 ) {
      printf("%s\n", entry->d_name);
      size += buf.st_size;
    }
  }

  printf("Total Directory Size: %d\n", size);

  return 0;
}
