CC:=gcc
TARGET:=gtkTest
# ----------- includes --------
INC:=-I/usr/include/gtk-3.0
INC+=-I/usr/include/atk-1.0
INC+=-I/usr/include/at-spi2-atk/2.0
INC+=-I/usr/include/pango-1.0
INC+=-I/usr/include/gio-unix-2.0/
INC+=-I/usr/include/cairo
INC+=-I/usr/include/gdk-pixbuf-2.0
INC+=-I/usr/include/glib-2.0
INC+=-I/usr/lib/x86_64-linux-gnu/glib-2.0/include
INC+=-I/usr/include/harfbuzz
INC+=-I/usr/include/freetype2
INC+=-I/usr/include/pixman-1
INC+=-I/usr/include/libpng12
#------------- libraries ------------------
LIB:=-lgtk-3
LIB+=-lgdk-3
LIB+=-latk-1.0
LIB+=-lgio-2.0
LIB+=-lpangocairo-1.0
LIB+=-lgdk_pixbuf-2.0
LIB+=-lcairo-gobject
LIB+=-lpango-1.0
LIB+=-lcairo
LIB+=-lgobject-2.0
LIB+=-lglib-2.0

CFLAGS:=-pthread -export-dynamic -rdynamic

all:
	gcc -o $(TARGET) gtkTest.c $(CFLAGS) $(INC) $(LIB) 
	
clean:
	rm $(TARGET)