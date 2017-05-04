http:http.o main.o 
	gcc -o $@ $^ -lpthread
%.o:%.c
	gcc -c $<
.PHONY:clean
clean:
	rm -f *.o http
