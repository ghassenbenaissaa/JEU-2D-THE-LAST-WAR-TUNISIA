prog:main.o main2.o main3.o background.o collisionPP.o evan.o mouvment.o scrolling.o minimap.o enigme.o animation.o ennemie.o gestionvie.o mainmenu.o text.o annimation.o fullscreen.o backgroundmenu.o p.o partage.o animationpartage.o collisionPPpartage.o evanpartage.o mouvementpartage.o scrollingpartage.o 
	gcc -no-pie  main.o main2.o main3.o background.o collisionPP.o evan.o mouvment.o scrolling.o minimap.o enigme.o animation.o ennemie.o gestionvie.o mainmenu.o text.o annimation.o fullscreen.o backgroundmenu.o p.o partage.o animationpartage.o collisionPPpartage.o evanpartage.o mouvementpartage.o scrollingpartage.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
main.o:main.c 
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -g
main2.o:main2.c 
	gcc -c main2.c -lSDL -lSDL_image -lSDL_mixer -g
main3.o:main3.c 
	gcc -c main3.c -lSDL -lSDL_image -lSDL_mixer -g
background.o:background.c 
	gcc -c background.c -lSDL -lSDL_image -lSDL_mixer -g
collisionPP.o:collisionPP.c 
	gcc -c collisionPP.c -lSDL -lSDL_image -lSDL_mixer -g
evan.o:evan.c 
	gcc -c evan.c -lSDL -lSDL_image -lSDL_mixer -g
mouvment.o:mouvment.c 
	gcc -c mouvment.c -lSDL -lSDL_image -lSDL_mixer -g
scrolling.o:scrolling.c 
	gcc -c scrolling.c -lSDL -lSDL_image -lSDL_mixer -g
minimap.o:minimap.c 
	gcc -c minimap.c -lSDL -lSDL_image -lSDL_mixer -g
enigme.o:enigme.c
	gcc -c enigme.c -lSDL -lSDL_image -lSDL_mixer -g
animation.o:animation.c 
	gcc -c animation.c -lSDL -lSDL_image -lSDL_mixer -g
ennemie.o:ennemie.c
	gcc -c ennemie.c -g
gestionvie.o:gestionvie.c 
	gcc -c gestionvie.c -lSDL -lSDL_image -g 
mainmenu.o:mainmenu.c 
	gcc -c mainmenu.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
text.o:text.c 
	gcc -c text.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
annimation.o:annimation.c 
	gcc -c annimation.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
fullscreen.o:fullscreen.c 
	gcc -c fullscreen.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
backgroundmenu.o:backgroundmenu.c 
	gcc -c backgroundmenu.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
partage.o:partage.c
	gcc -c partage.c -g
chedi.o:p.c
	gcc -c p.c -g
animationpartage.o:animationpartage.c 
	gcc -c animationpartage.c  -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
collisionPPpartage.o:collisionPPpartage.c 
	gcc -c collisionPPpartage.c -lSDL -lSDL_image -lSDL_mixer -g
evanpartage.o:evanpartage.c 
	gcc -c evanpartage.c -lSDL -lSDL_image -lSDL_mixer -g
mouvementpartage.o:mouvementpartage.c 
	gcc -c mouvementpartage.c -lSDL -lSDL_image -lSDL_mixer -g
scrollingpartage.o:scrollingpartage.c 
	gcc -c scrollingpartage.c -lSDL -lSDL_image -lSDL_mixer -g

