#include "Renderer.h"
#include "RenderObject.h"
namespace s_Renderer
{
    class IRenderEngine {
        public:
        virtual bool initRenderer() = 0;
        virtual bool destroyRenderer() = 0;
        virtual void addObjectToQueue(RenderObject renderObject) = 0;
        virtual void drawFrame() = 0;
        virtual Renderer rendererType() = 0;


    };
} // namespace s_Renderer
