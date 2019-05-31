#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <libgen.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  //printf("%s\n", argv[0]);
  //printf("%s\n", argv[1]);

  // Open directory
  DIR *dir;
  struct dirent *dp;

  if ((dir = opendir (argv[1])) == NULL) {
    perror ("Cannot open");
    exit (1);
  }
  // Repeatly read and print entries
  while ((dp = readdir (dir)) != NULL) {
    // print file size
    struct stat st;
    stat(dp->d_name, &st);
    int size = st.st_size;
    printf("%d ", size);
    // print file name
    printf(" %s\n", dp->d_name);
  } 
  // Close directory
  closedir(dir);

  return 0;
}