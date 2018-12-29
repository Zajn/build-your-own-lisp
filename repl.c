#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef _WIN32
#include <string.h>

static int buffer_size = 2048;
static char buffer[buffer_size];

char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, buffer_size, stdin);
  char* cpy = malloc(strlen(buffer) + 1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

void add_history(char* unused) {}
#else
#include <editline/readline.h>
#endif

int main(int argc, char** argv) {
  puts("Lispy Version 0.0.1");
  puts("Press Ctrl-c to exit.\n");

  while(true) {
    char* input = readline("lispy> ");

    /* Add user input to history, allowing for arrow navigation */
    add_history(input);
    printf("No you're a %s\n", input);

    /* free retrieved input */
    free(input);
  }

  return 0;
}
