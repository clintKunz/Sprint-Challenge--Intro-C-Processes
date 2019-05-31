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
  printf("There are %d command line argument(s):\n", argc);

  for (int i = 0; i < argc; i++) {
    printf("   %s\n", argv[i]);
  }

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
    printf(" file size is %d,", size);
    // print file name
    printf(" %s\n", dp->d_name);
  } 
  // Close directory
  closedir(dir);

  return 0;
}