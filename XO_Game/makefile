built_Functions.obj : built_Functions.c built_Functions.h
	gcc -c built_Functions.c -o built_Functions.obj
Main.obj : built_Functions.h Main.c 
	gcc -c Main.c -o Main.obj
All : Main.obj built_Functions.obj
	gcc Main.obj built_Functions.obj -o game.exe
	