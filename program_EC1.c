#include <stdio.h>

int main()
{

  // declare two 5x5 integer arrays
  int depts[5][5];
  int progs[5][5];

  // declare one 5-element integer array and one 5x5 integer array
  int marked_dept[5];
  int marked_prog[5][5];

  // declare a 100-character string for storing the input file name
  char str[100];

  // prompt the user to enter a file name
  printf("Enter a file name: ");

  // read the input file name from the user and store it in the 'str' variable
  scanf("%s", str);

  // open the input file in read mode
  FILE *fp;
  fp = fopen(str, "r");

  // read the first 5 integers in each line of the file and store them in the 'depts' array
  for (int i = 0; i < 5; ++i)
  {
    for (int j = 0; j < 5; ++j)
    {
      fscanf(fp, " %d", & depts[j][i]);
    }
  }

  // read the next 5 integers in each line of the file and store them in the 'progs' array
  for (int i = 0; i < 5; ++i)
   for (int i = 0; i < 5; ++i)
  {
    for (int j = 0; j < 5; ++j)
    {
      fscanf(fp, " %d", & depts[j][i]);
    }
  }

  // read the next 5 integers in each line of the file and store them in the 'progs' array
  for (int i = 0; i < 5; ++i)
  {
    for (int j = 0; j < 5; ++j)
    {
      fscanf(fp, " %d", & progs[j][i]);
    }
  }

  // close the input file
  fclose(fp);

  // initialize all elements of the 'marked_dept' array to -1
  for (int i = 0; i < 5; i++)
  {
    marked_dept[i] = -1;
  }

  // set the elements of the 'marked_prog' array to the indices of the corresponding department
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      marked_prog[i][progs[i][j] - 1] = j;
    }
  }

  // loop through each number from 0 to 4
  for (int num = 0; num < 5; num++)
  for (int num = 0; num < 5; num++)
  {
    // loop through each department
    for (int i = 0; i < 5; i++)
    {
      // check if the department is unmarked
      if (marked_dept[i] == -1)
      {
        int j = 0;
        // loop through each programmer of the department until the best possible programmer is found
        while (marked_dept[i] == -1 && j < 5)
        {
          int programmer = depts[i][j] - 1;
          if (marked_prog[programmer][i] == num)
          {
            marked_dept[i] = programmer;
          }
          j++;
        }
      }
    }
  }

  // print the distribution of programmers to departments
  for (int i = 0; i < 5; i++)
  {
    printf("Department #%d will get Programmer #%d\n", i + 1, marked_dept[i] + 1);
  }

  return 0;
}

