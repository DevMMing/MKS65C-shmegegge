#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int key;
int size;
int shmflag;
int shmid;
char *data;
char line[99];
int main(int argc, char *argv[]){
	key=ftok("shmegegge.c",'R');
	if(shmget(key,200,0644)==-1){
	printf("created new key");
	}
	shmid=shmget(key,200,0644 |IPC_CREAT);
	data = shmat(shmid, (void *)0, 0);
	printf("Enter a string: ");
	gets(data);
	if(!strcmp(data,"Yes")){
		printf("Enter a string: ");
		gets(line);
		strcpy(data,line);
	}
	else{
		printf("shared contents: %s\n", data);
	}
	printf("Delete?");
	gets(data);
	if(!strcmp(data,"Yes")){
		shmdt(data);
		shmctl(shmid, IPC_RMID, NULL);
	}
}