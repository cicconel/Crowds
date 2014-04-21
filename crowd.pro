#------------------------
# QMake generator file
#------------------------

# General options
TEMPLATE = app
TARGET   = crowd_simulation
CONFIG  += qt glut opengl thread openmp debug release 
LIBS *= -lglut -lpng 
OBJECTS_DIR = build

# Code Files
HEADERS = src/agent.hpp \
		  src/group.hpp \
		  src/scene.hpp \
		  src/map.hpp \
		  src/vector.hpp \
		  src/imageio.hpp \
		  tinyxml/tinyxml.h 

SOURCES = src/main.cpp \
		  src/agent.cpp \
		  src/group.cpp \
		  src/scene.cpp \
		  src/scene_update.cpp \
		  src/scene_display.cpp \
		  src/map.cpp \
		  src/imageio.cpp \
		  tinyxml/tinyxml.cpp \
		  tinyxml/tinyxmlerror.cpp \
		  tinyxml/tinyxmlparser.cpp


# Additionnal command to distclean target
QMAKE_DISTCLEAN += *~
QMAKE_DISTCLEAN += src/*~
QMAKE_DISTCLEAN += scenes/*~
QMAKE_DISTCLEAN += tinyxml/*~
QMAKE_DISTCLEAN += -r build/
QMAKE_DISTCLEAN += -r screenshots/

