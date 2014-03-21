#------------------------
# QMake generator file
#------------------------

# General options
TEMPLATE = app
TARGET   = crowd_simulation
CONFIG  += qt glut opengl thread openmp debug release 
LIBS *= -lglut
OBJECTS_DIR = build

#Todo : option that might be useful?
#opengl glut warn_on release thread openmp debug
#QT *= xml opengl 
#Todo : using absolute path might be a great idea

# Code Files
HEADERS = src/agent.hpp \
          src/group.hpp \
          src/scene.hpp \
          src/map.hpp \
          src/vector.hpp

SOURCES = src/main.cpp \
          src/agent.cpp \
          src/group.cpp \
          src/scene.cpp \
          src/scene_update.cpp \
          src/scene_display.cpp \
          src/map.cpp


# Additionnal command to distclean target
QMAKE_DISTCLEAN += rm -f *~; \
    rm -r build/;            \
    rm -f /src/*~;           \
    rm -f /scenes/*~;        \
