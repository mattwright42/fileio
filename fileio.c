#include <stdio.h>
#include <stdlib.h> // included for strtoul

int main(int argc, char **argv)
{
  FILE *fp;
  char line[1024];

  if (argc != 2)
  {
    printf("usage: fileio filename\n");
    return 1;
  }

  fp = fopen(argv[1], "r");

  if (fp == NULL)
  {
    printf("Error opening file %s\n", argv[1]);
    return 2;
  }

  while (fgets(line, 1024, fp) != NULL)
  {
    // printf("%s", line);
    char *endptr;

    unsigned char val = (strtoul(line, &endptr, 2));

    if (line == endptr)
    {
      printf("SKIPPING: %s\n", line);
      continue;
    }
    printf("%02x\n", val);
    //store in memory
  }

  
  fclose(fp);
}