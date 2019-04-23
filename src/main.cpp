#include <iostream>
#include "../include/window_manager.hpp"
#include "../include/definitions.hpp"

#include <iostream>

int main()
{
  WindowList windows = {};

  int W, H;
  int n, m;

  std::cin >> W >> H;
  std::cin >> n >> m;

  CoordinatesList mouseClicks = {};

  for (int i = 0; i < n; i++)
  {
    std::string ID;
    int x1, y1, x2, y2, zIndex;
    std::cin >> ID >> x1 >> y1 >> x2 >> y2 >> zIndex;

    Coordinates p1 = {x1, y1};
    Coordinates p2 = {x2, y2};
    Window w = {ID, p1, p2, zIndex};

    windows.list[i] = w;
  }

  for (int j = 0; j < m; j++)
  {
    int x, y;
    std::cin >> x >> y; //travou na sexta leitura do std::cin
    Coordinates p = {x, y};

    mouseClicks.list[j] = p;
  }

  for (int i = 0; i < m; i++)
  {
    Window *first = &windows.list[0];
    Window *last = &windows.list[n];
    WindowList windowsOverPointer = wm::windowsOverPointer(mouseClicks.list[i], first, last);

    for (int j = 0; j < n; j++)
    {
      if (windowsOverPointer.list[j].ID != "")
      {
        Window w = windowsOverPointer.list[j];
        Coordinates *p1 = w.p1;
        Coordinates *p2 = w.p2;

        std::cout << w.ID << " " << p1->x << " " << p1->y << " " << p2->x << " " << p2->y << " " << w.zIndex << std::endl;
      }
      else
      {
        break;
      }
    }

    Window clicked = wm::windowClicked(mouseClicks.list[i], first, last);
    if (clicked.ID != "")
    {
      std::cout << clicked.ID << std::endl;
    }
    else
    {
      std::cout << "no window clicked" << std::endl;
    }
  }

  return 0;
}