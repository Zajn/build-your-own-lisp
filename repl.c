#include <stdio.h>
#include <stdbool.h>

const int BUFFER_SIZE = 2048;
static char input_buffer[BUFFER_SIZE];

int main(int argc, char** argv) {
  puts("Lispy Version 0.0.1");
  puts("Press Ctrl-c to exit.\n");

  while(true) {
    fputs("lispy> ", stdout);

    fgets(input_buffer, BUFFER_SIZE, stdin);

    printf("No you're a %s", input_buffer);
  }

  return 0;
}
