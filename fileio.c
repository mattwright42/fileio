#include <stdio.h>
#include <stdlib.h>

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
    unsigned char val = (strtoul(line, NULL, 2));
    printf("%02x\n", val);
  }

  fclose(fp);
}