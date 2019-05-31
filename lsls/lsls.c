#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <libgen.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  
  // Open directory
  DIR *dir;
  struct dirent *dp;

  if ((dir = opendir (".")) == NULL) {
    perror ("Cannot open .");
    exit (1);
  }
  // Repeatly read and print entries
  while ((dp = readdir (dir)) != NULL) {
    // print file size

    // print file name
    printf("%s\n", dp->d_name);
  }
  // Close directory
  closedir(dir);

  return 0;
}