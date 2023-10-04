CFLAGS 	= -g -Wall -pedantic
CC 	= gcc
OBJECTS = a_is_consonant.o a_create_file_name.o 

all:	task1		\
	fifo_sender   \
	fifo_receiver 


fifo_receiver: fifo_receiver.o $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS)  $@.o  -o $@ 

fifo_sender: fifo_sender.o $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS)  $@.o  -o $@ 

task1: task1.o $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS)  $@.o  -o $@ 


# generic
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f core *.o a.out 
	rm -f DIRECTORY.html
	rm -rf *.dSYM
	rm -f goggamal-solution 
	rm -f task1
	rm -f task2
	rm -f task3_sender
	rm -f task3_receiver
	rm -f fifo_sender
	rm -f fifo_receiver 
