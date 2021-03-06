CC=gcc
FLAGS=-Wall -g
OBJECTS_MAIN=main.o
REC_OBJ = libclassrec.o
LOOP_OBJ = libclassloops.o

all:libclassloops.a libclassrec.a libclassrec.so libclassloops.so maindrec maindloop mains


#no commands
loops: libclassloops.a

recursives: libclassrec.a

recursived: libclassrec.so

loopd: libclassloops.so


#create main programs
mains: $(OBJECTS_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a -lm

maindloop: $(OBJECTS_MAIN) libclassloops.so
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloops.so -lm

maindrec: $(OBJECTS_MAIN) libclassrec.so
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) ./libclassrec.so -lm


#clean
clean:
	rm *.o *.so *.a mains maindloop maindrec

.PHONY: clean all loops recursives recursived loopd


#compile dependencies
%.so: %.o
	$(CC) -shared -o $@ $<

%.a: %.o
	ar -rcs -o $@ $<

libclassrec.o: advancedClassificationRecursion.c NumClass.h basicClassification.c
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c -o libclassrec.o

libclassloops.o: advancedClassificationLoop.c NumClass.h basicClassification.c
	$(CC) $(FLAGS) -c advancedClassificationLoop.c -o libclassloops.o

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c
