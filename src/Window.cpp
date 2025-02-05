#include "Window.h"
namespace sparks
{
    Window::Window(IContext *context, uint16_t width, uint16_t height, const char* title) : 
    _context(context), width(width), height(height), title(title) {}
} // namespace sparks