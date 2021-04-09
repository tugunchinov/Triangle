#include <iostream>

#include <api.hpp>
#include <config.hpp>
#include <window.hpp>

int main() {
  simple_graphic::CheckCompatibility();
  simple_graphic::SetErrorHandler();

  simple_graphic::Window window;

  window.SetName("Triangle");
  window.SetEventMask(PointerMotionMask);
  window.SetEventMask(ButtonPressMask);

  window.Show();

  glClearColor(0.5f, 0.6f, 0.7f, 1.0f);

  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLES);
  {
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
  }
  glEnd();

  // Present frame
  glXSwapBuffers(simple_graphic::display, window.window_);

  XEvent ev;
  // Enter message loop
  while (true) {
    XNextEvent(simple_graphic::display, &ev);
    // TODO: Extract method "ResizeFit?"
    if (ev.type == Expose) {
      XWindowAttributes attribs;
      XGetWindowAttributes(simple_graphic::display, window.window_, &attribs);
      glViewport(0, 0, attribs.width, attribs.height);
    }

    // OpenGL Rendering
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    {
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(0.0f, -1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(1.0f, 1.0f, 0.0f);
    }
    glEnd();

    // Present frame
    glXSwapBuffers(simple_graphic::display, window.window_);
  }

  simple_graphic::Clear();

  return 0;
}
