#include <iostream>

#include <api.hpp>
#include <window.hpp>

// TODO: Здесь нет обработки ошибок :(

int main() {
  simple_graphic::CheckCompatibility();

  simple_graphic::Window window;

  window.SetName("Hello, X server!");
  window.Show();

  simple_graphic::RunXLoop();

  return 0;
}
