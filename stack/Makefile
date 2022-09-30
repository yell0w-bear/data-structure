stack_list : single_linked_list.o stack_list.o
	g++ -o stack_list single_linked_list.o stack_list.o

single_linked_list.o : single_linked_list.cpp
	g++ -c -o single_linked_list.o single_linked_list.cpp

stack_list.o : stack_list.cpp
	g++ -c -o stack_list.o stack_list.cpp
    
clean:
	rm *.o stack_list