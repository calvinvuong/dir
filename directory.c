// Calvin Vuong
// MKS65 pd10
// Work 5
// 11-02-2016

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
  closedir(folder);

  folder = opendir(".");
  entry = readdir(folder);
  // print regular files
  printf("\nRegular Files: \n");
  while ( entry != NULL ) {
    stat(entry->d_name, &buf);
    if ( entry->d_type != 0 && entry->d_type != 4 ) {
      printf("%s\n", entry->d_name);
      size += buf.st_size;
    }
    entry = readdir(folder);
  }

  closedir(folder);
  printf("\nTotal Directory Size: %d Bytes\n\n", size);

  return 0;
}
