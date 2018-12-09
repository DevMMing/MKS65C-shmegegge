all : shmegegge.o
	gcc -o shmegegge shmegegge.o
run : ./shmegegge
	./shmegegge
shmegegge.o : shmegegge.c
	gcc -c shmegegge.c
clean : 
	rm *.o ./shmegegge ./a.out
