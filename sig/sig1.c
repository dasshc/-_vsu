#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

char str[40] = "Wait your signal...\n"; // a string to send to the console

// signal handler
void signalHandler(int signalCode)
{
  switch (signalCode)
  {
  case SIGUSR1:
    printf("SIGUSR1 Recieved\n");
    strcpy(str, "Last received signal is: SIGUSR1\n"); 
    break;
  case SIGUSR2:
    printf("SIGUSR2 Recieved\n");
    strcpy(str, "Last received signal is: SIGUSR2\n");
    break;
  }
}

int main()
{
  // signal registration
  signal(SIGUSR1, signalHandler);
  signal(SIGUSR2, signalHandler);
  printf("[ PID: %d ]: Started...\n", getpid());
  while (1)
  {
    printf("%s", str); // string output
    sleep(2);
  }
  return 0;
}