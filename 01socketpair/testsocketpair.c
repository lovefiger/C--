#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>

int main(int argc,char* argv[]){
	int sv[2];
	if(socketpair(AF_UNIX,SOCK_STREAM,0,sv[] < 0)){
		perror("socketpair:");
		return -1;
	}

	pid_t id = fork();
	if(id == 0){//subprocess
		char *msg = "I'm children!\n";
		char buffer[1024]={0, };
		close(sv[1]);

		while(1){
			write(sv[0],msg, strlen(msg));
			sleep(1);

			ssize_t len = read(sv[0], buffer,sizeof(buffer));
			if(len > 0){
				buffer[len] = '\0';
				printf("children: receive form parent: %s \n",buffer);
			}
		}
	}else if(id > 0){//parent process
		char *msg = "I'm father!\n";
		char buffer[1024] = {0, };
		close(sv[0]);

		while(1){
			ssize_t len = read(sv[1], buffer,sizeof(buffer));
			if(len > 0){
				buffer[len] = '\n';
				printf("father: receive form children:%s \n",buffer);
				sleep(1);

			}

			write(sv[1],msg,strlen(msg));
		}
		
	}else{
		perror("Failed to create process! \n");
	}

	return 0;
}
