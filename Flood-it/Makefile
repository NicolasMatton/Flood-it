GCC_FLAGS = -Wall -g

SDLFLAGS = -lSDL

all : Flood-It temps

API_Gene_instance.o : API_Gene_instance.c API_Gene_instance.h 
	gcc ${GCC_FLAGS} -c API_Gene_instance.c

API_Grille.o : API_Grille.c API_Grille.h
	gcc ${GCC_FLAGS} -c API_Grille.c $(SDLFLAGS)

Liste_case.o : Liste_case.c Liste_case.h
	gcc ${GCC_FLAGS} -c Liste_case.c
	
zones.o : zones.c zones.h
	gcc ${GCC_FLAGS} -c zones.c
	
exo1.o : exo1.c exo1.h
	gcc ${GCC_FLAGS} -c exo1.c

Flood-It.o : Flood-It.c Flood-It.h
	gcc ${GCC_FLAGS} -c Flood-It.c

Flood-It : Flood-It.c API_Gene_instance.o API_Gene_instance.h API_Grille.o API_Grille.h Liste_case.o Liste_case.h zones.o zones.h exo1.o exo1.h
	gcc ${GCC_FLAGS} Flood-It.c API_Gene_instance.o API_Grille.o Liste_case.o zones.o exo1.o $(SDLFLAGS) -o Flood-It

temps.o : temps.c temps.h
	gcc ${GCC_FLAGS} -c temps.c

temps : temps.c API_Gene_instance.o API_Gene_instance.h API_Grille.o API_Grille.h Liste_case.o Liste_case.h zones.o zones.h exo1.o exo1.h
	gcc ${GCC_FLAGS} temps.c API_Gene_instance.o API_Grille.o Liste_case.o zones.o exo1.o $(SDLFLAGS) -o temps
	
clean :
	rm -f Flood-It Flood-It.o Liste_case.o API_Grille.o API_Gene_instance.o essai.o
	reset
	clear
