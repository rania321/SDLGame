prog:enigme.o mainenigme.o
	gcc enigme.o mainenigme.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
mainenigme.o:mainenigme.c
	gcc -c mainenigme.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
enigme.o:enigme.c
	gcc -c enigme.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
