#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

static void sighandler(int signo){

  if(signo == SIGINT){
    umask(000);
    char buffer[] = "Ended due to SIGINT\n";
    int fd = open("file.boop",O_CREAT | O_WRONLY | O_APPEND ,0666);
    write(fd,buffer,sizeof(buffer));
    close(fd);
    exit(0);
  }
  if(signo == SIGUSR1){
    printf("Salve, I'm %d\n",getppid());
  }
}

void main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while(1){
    printf("Bonjour, I'm %d!\n", getpid());
    sleep(1);
  }
}
