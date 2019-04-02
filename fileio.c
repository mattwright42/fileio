#include <stdio.h>

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

  while (fgets(line, 1024, fp) != NULL)
  {
    printf("%s", line);
  }

  fclose(fp);
}