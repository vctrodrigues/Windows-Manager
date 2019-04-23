#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <iostream>
#include <vector>
#include "definitions.hpp"

namespace wm
{
WindowList windowsOverPointer(Coordinates p, Window *first, Window *last);
Window windowClicked(Coordinates p, Window *first, Window *last);
void bringToFront(Window w, Window *first, Window *last);
} // namespace wm

#endif