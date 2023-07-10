make:
	@gcc client.c -o client
	@gcc server.c -o server
	@gcc computetime.c -o computetime
	@gcc finaltimestamp.c -o finaltimestamp
	@gcc initialtimestamp.c -o initialtimestamp
	@./initialtimestamp
	@./server & ./client
	

make2: 
	@./finaltimestamp
	@./computetime
