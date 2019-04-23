#include "../include/window_manager.hpp"

namespace wm
{
WindowList windowsOverPointer(Coordinates p, Window *first, Window *last)
{
  WindowList overPointer = {};
  Window *ptr = &overPointer.list[0];
  while (first != last)
  {
    if (first->p1->x <= p.x && first->p1->y <= p.y && first->p2->x >= p.x && first->p2->y >= p.y)
    {
      *ptr = *first;
      ptr++;
    }
    first++;
  }

  return overPointer;
} // namespace wm
Window windowClicked(Coordinates p, Window *first, Window *last)
{
  WindowList overList = windowsOverPointer(p, first, last);
  first = &overList.list[0];
  last = &overList.list[199];

  Window frontWindow = *first;

  while (first != last)
  {
    if (first->zIndex <= frontWindow.zIndex)
    {
      frontWindow = *first;
    }
  }

  return frontWindow;
}
void bringToFront(Window w, Window *first, Window *last)
{
  int nextLayer = 0;
  w.zIndex = 0;

  Window *slow = first;
  while (slow != last)
  {
    Window *fast = first;
    if (fast != last)
    {
      if (strcmp(fast->ID.c_str(), w.ID.c_str()) && fast->zIndex == nextLayer)
      {
        fast->zIndex = ++nextLayer;
      }
      fast++;
    }
    slow++;
  }
}
} // namespace wm
