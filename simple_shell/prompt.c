#include <stdio.h>
#include <unistd.h>
/**
 * main - Entry point
 *
 * Return: i
*/
int getStringLength(char *string)
{
int i = 0;
while (string[i])
{
i++;
}
return i;
}
int main()
{
char *prompt = "$ ";
char *line;
size_t lineSize = 0;
int read = 0;
int errno = 0; 
while (1)
{
  if (lineSize <= 0) {
    if (errno) {
      perror("Something Isn't ok!");
    }
  }
write(STDOUT_FILENO, prompt, getStringLength(prompt));
read = getline(&line, &lineSize, stdin);
write(STDOUT_FILENO, line, read);
}
}
