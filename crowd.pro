TEMPLATE = app
TARGET   = crowd_simulation
CONFIG  += qt glut opengl thread openmp debug release 
OBJECTS_DIR = build

#Todo : option that might be useful?
#opengl glut warn_on release thread openmp debug
#QT *= xml opengl 
#Todo : using absolute path might be a great idea

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

LIBS *= -lglut
