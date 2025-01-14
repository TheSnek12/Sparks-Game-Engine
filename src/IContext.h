#ifndef HICONTEXT
#define HICONTEXT

namespace sparks

{
    enum Renderer
    {
        OpenGL
    };
    class IContext
    {
    public:
        virtual bool init() = 0;
        virtual bool cleanup() = 0;
        virtual void selectEngine(Renderer renderer) = 0;
        virtual void close() = 0;
        virtual void abort() = 0;
    };
} // namespace sparks
#endif