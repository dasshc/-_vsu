#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	printf("Hello from parent.c\n");
	printf("PID of old process is: %d\n", getpid());

	char *args[] = {"Hello", NULL};
	execv("./child", args);
	return 0;
}