CC = gcc
CFLAGS = -g
LDFLAGS = -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -no-pie

SRCDIR = src
BUILDDIR = build

SRCS = main.c main2.c main3.c background.c collisionPP.c evan.c mouvment.c \
       scrolling.c minimap.c enigme.c animation.c ennemie.c gestionvie.c \
       mainmenu.c text.c annimation.c fullscreen.c backgroundmenu.c p.c \
       partage.c animationpartage.c collisionPPpartage.c evanpartage.c \
       mouvementpartage.c scrollingpartage.c

OBJS = $(patsubst %.c,$(BUILDDIR)/%.o,$(SRCS))

prog: $(BUILDDIR) $(OBJS)
	$(CC) $(OBJS) -o prog $(LDFLAGS)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(BUILDDIR) prog

.PHONY: clean
