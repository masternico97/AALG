#-----------------------
# IMPORTANTE: Los valores de los parametros de los ejercicio?_test deben ajustarse.
# Se asume que los ficheros fuente se llaman ejercicio1.c, ejercicio2.c,...,ordenar.h
#-----------------------

CC = gcc -ansi -pedantic
CFLAGS = -Wall
EXE = ejercicio1 ejercicio2 ejercicio3 ejercicio4 ejercicio5 ejercicio6

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

aleatoriedad.o: aleatoriedad.c
	$(CC) $(CFLAGS) -c aleatoriedad.c

aleatoriedad: aleatoriedad.o permutaciones.o
	$(CC) $(CFLAGS) -o aleatoriedad aleatoriedad.o permutaciones.o

ejercicio1_test:
	@echo Ejecutando ejercicio1
	@./ejercicio1 -limInf 1 -limSup 5 -numN 10

ejercicio1_valgrind:
	@echo Ejecutando ejercicio1 con valgrind
	valgrind --leak-check=full ./ejercicio1 -limInf 1 -limSup 5 -numN 10

ejercicio2_test:
	@echo Ejecutando ejercicio2
	@./ejercicio2 -tamanio 10 -numP 5

ejercicio2_valgrind:
	@echo Ejecutando ejercicio2 con valgrind
	valgrind --leak-check=full ./ejercicio2 -tamanio 10 -numP 5

ejercicio3_test:
	@echo Ejecutando ejercicio3
	@./ejercicio3 -tamanio 10 -numP 5


ejercicio3_valgrind:
	@echo Ejecutando ejercicio3 con valgrind
	valgrind --leak-check=full ./ejercicio3 -tamanio 10 -numP 5

ejercicio4_test:
	@echo Ejecutando ejercicio4
	@./ejercicio4 -tamanio 10


ejercicio4_valgrind:
	@echo Ejecutando ejercicio4 con valgrind
	valgrind --leak-check=full ./ejercicio4 -tamanio 10

ejercicio5_test:
	@echo Ejecutando ejercicio5
	@./ejercicio5 -num_min 500 -num_max 10000 -incr 500 -numP 10 -fichSalida ejercicio5.log

ejercicio5_valgrind:
	@echo Ejecutando ejercicio5 con valgrind
	valgrind --track-origins=yes --leak-check=full ./ejercicio5 -num_min 1000 -num_max 10000 -incr 100 -numP 2 -fichSalida ejercicio5.log

ejercicio6_test:
	@echo Ejecutando ejercicio6
	@./ejercicio6 -num_min 500 -num_max 10000 -incr 500 -numP 10 -fichSalida ejercicio6.log

ejercicio6_valgrind:
	@echo Ejecutando ejercicio6 con valgrind
	valgrind --track-origins=yes --leak-check=full ./ejercicio6 -num_min 1000 -num_max 10000 -incr 100 -numP 2 -fichSalida ejercicio6.log
