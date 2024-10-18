CC=cc
FILE= main.c
OUTPUT = todo

install:
	$(CC) $(FILE) -o $(OUTPUT) 

remove-data:
	rm data.txt
