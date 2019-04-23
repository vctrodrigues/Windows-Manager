#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <string.h>

typedef struct coordinates Coordinates;
struct coordinates
{
  int x;
  int y;
};

typedef struct window Window;
struct window
{
  std::string ID;
  Coordinates p1[2];
  Coordinates p2[2];
  int zIndex;
};

typedef struct wList WindowList;
struct wList
{
  Window list[200];
};

typedef struct cList CoordinatesList;
struct cList
{
  Coordinates list[100];
};

#endif