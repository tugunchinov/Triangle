#include <iostream>

#include <api.hpp>
#include <config.hpp>
#include <window.hpp>

// TODO: Extract method: "DrawTriangle"
void HandleClick(simple_graphic::Window& /* window */, const XEvent& event) {
  // Left mouse
  if (event.xbutton.button == Button1) {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    int x = event.xbutton.x;
    int y = event.xbutton.y;

    glBegin(GL_TRIANGLES);
    {
      glVertex2i(x, y);
      glVertex2i(x + 100, y);
      glVertex2i(x, y + 100);
    }
    glEnd();
  }
}

// TODO: save triangle
void HandleExposure(simple_graphic::Window& window, const XEvent& /* event */) {
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glViewport(0, 0, window.GetWidth(), window.GetHeight());
  glLoadIdentity();
  glOrtho(0.f, window.GetWidth(), window.GetHeight(), 0.f, 0.f, 1.f);
}

// TODO: optimizations
void HandleMove(simple_graphic::Window& /* window */, const XEvent& event) {
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  int x = event.xmotion.x;
  int y = event.xmotion.y;

  glBegin(GL_TRIANGLES);
  {
    glVertex2i(x, y);
    glVertex2i(x + 100, y);
    glVertex2i(x, y + 100);
  }
  glEnd();

  usleep(1000);
}

int main() {
  simple_graphic::Configure();

  simple_graphic::Window window;
  window.SetName("Triangle");

  window.SetEventsHandlers({
                               {ButtonPressMask, ButtonPress, HandleClick},
                               {ExposureMask, Expose, HandleExposure},
                               {Button1MotionMask, MotionNotify, HandleMove}
                           });

  window.Show();

  window.SetBackgroundColor(0.145f, 0.521f, 0.294f, 1.0f);

  window.RunEventLoop();

  simple_graphic::Clear();

  return 0;
}
