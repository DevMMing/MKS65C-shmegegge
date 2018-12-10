#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int key;
int shmid;
char *data;
char input[99];
int main(int argc, char *argv[]){
	key=ftok("shmegegge.c",'R');
	if((shmid =shmget(key,200*sizeof(char),0644 | IPC_CREAT))==-1){
	printf("created new key\n");
	}
	data = shmat(shmid, (void *)0, 0);
	if (data == (char *)(-1)) {
        perror("dead data");
		data=(char *)malloc(99*sizeof(char));
    }
	if(!strcmp(data,"")){
	printf("A new memory segment was created!\n");
	}
	else{
	printf("These are the current contents of the shared memory: %s\n", data);
	}
	printf("Do you want to modify this shared memory?[Yes/No]");
	fgets (input , 99 , stdin);
	//printf("%s",input);
	input[strlen(input)-1] = 0;
	//printf("%d\n",strcmp(input,"Yes"));
	if(!strcmp(input,"Yes")){
		printf("Enter a string:");
		fgets (input , 99 , stdin);
		input[strlen(input)-1] = 0;
		strcpy(data,input);
	}
	printf("Delete this shared memory?[Yes/No]");
	fgets (input , 99 , stdin);
	input[strlen(input)-1] = 0;
	if(!strcmp(input,"Yes")){
		shmdt(data);
		shmctl(shmid, IPC_RMID, NULL);
	}
}
