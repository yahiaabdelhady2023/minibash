LIBS = -lreadline

minibash : minibash.c
	gcc minibash.c $(LIBS) -o minibash
