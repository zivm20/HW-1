CC=gcc
FLAGS=-lm -Wall -g
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
mains: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a

maindloop: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloops.so

maindrec: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) ./libclassrec.so


#clean
clean:
	rm *.o *.so *.a mains maindloop maindrec

#compile dependencies
%.so: %.o
	$(CC) -shared -o $@ $<

%.a: %.o
	ar -rcs  -o $@ $<

libclassrec.o: advancedClassificationRecursion.c NumClass.h basicClassification.c
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c -o libclassrec.o

libclassloops.o: advancedClassificationLoop.c NumClass.h basicClassification.c
	$(CC) $(FLAGS) -c advancedClassificationLoop.c -o libclassloops.o

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c


#libclassrec.so: $(REC_OBJ)
#	$(CC) -shared -o libclassrec.so $(REC_OBJ)

#libclassloops.so: $(LOOP_OBJ)
#	$(CC) -shared -o libclassloops.so $(REC_OBJ)

#libclassrec.a: $(REC_OBJ)
#	ar -rcs libclassrec.a $(REC_OBJ)

#libclassloops.a: $(LOOP_OBJ)
#	ar -rcs libclassloops.a $(LOOP_OBJ)
