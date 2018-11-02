#-----------------------
# IMPORTANTE: Los valores de los parametros de los ejercicio?_test deben ajustarse.
# Se asume que los ficheros fuente se llaman ejercicio4.c, ejercicio5.c,...,ordenar.h
#-----------------------

CC = gcc -ansi -pedantic
CFLAGS = -Wall
EXE = ejercicio4 ejercicio5

all : $(EXE)

.PHONY : clean
clean :
	rm -f *.o core $(EXE)

$(EXE) : % : %.o ordenacion.o tiempos.o permutaciones.o
	@echo "#---------------------------"
	@echo "# Generando $@ "
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -o $@ $@.o ordenacion.o tiempos.o permutaciones.o

permutaciones.o : permutaciones.c permutaciones.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<

 ordenacion.o : ordenacion.c ordenacion.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<

 tiempos.o : tiempos.c tiempos.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<

ejercicio4_test:
	@echo Ejecutando ejercicio4
	@./ejercicio4 -tamanio 10


ejercicio4_valgrind:
	@echo Ejecutando ejercicio4 con valgrind
	valgrind --leak-check=full ./ejercicio4 -tamanio 10

ejercicio5_test:
	@echo Ejecutando ejercicio5
	@./ejercicio5 -num_min 500 -num_max 10000 -incr 500 -numP 50 -fichSalida ejercicio5.log

ejercicio5_valgrind:
	@echo Ejecutando ejercicio5 con valgrind
	valgrind --track-origins=yes --leak-check=full ./ejercicio5 -num_min 1000 -num_max 10000 -incr 50 -numP 100 -fichSalida ejercicio5.log
