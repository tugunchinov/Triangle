#include <iostream>

#include <api.hpp>
#include <config.hpp>
#include <window.hpp>

void HandleClick(simple_graphic::Window& window, const XEvent& event) {
  // Left mouse
  if (event.xbutton.button == 1) {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    int x = event.xmotion.x;
    int y = event.xmotion.y;

    glBegin(GL_TRIANGLES);
    {
      glVertex2i(x, y);
      glVertex2i(window.GetWidth() - x, 0);
      glVertex2i(0, window.GetHeight() - y);
    }
    glEnd();
  }
}

int main() {
  simple_graphic::Configure();

  simple_graphic::Window window;
  window.SetName("Triangle");

  window.SetEventsHandlers({
    {ButtonPressMask, ButtonPress, HandleClick}
  });

  window.Show();

  window.SetBackgroundColor(0.145f, 0.521f, 0.294f, 1.0f);

  window.RunEventLoop();

  simple_graphic::Clear();

  return 0;
}
