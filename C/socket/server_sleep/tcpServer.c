#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <memory.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 9999
#define BACKLOG 5
#define BUFLEN 1024
int listenfd, connfd;
int main(int argc, char *argv[])
{
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	pid_t pid;
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(PORT);
	bind(listenfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	listen(listenfd, BACKLOG);
	while (1)
	{
		socklen_t addrlen = sizeof(client_addr);
		connfd = accept(listenfd, (struct sockaddr *)&client_addr, &addrlen);
		if (connfd < 0)
			perror("accept error");
		printf("receive connection\n");
		if ((pid = fork()) == 0)
		{
			close(listenfd);
			sleep(10);
			exit(0);
		}
		else
		{
			close(connfd);
		}
	}
}

