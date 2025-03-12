#pragma once
#include "Renderer.h"
#include "Vec3.h"
#include "RenderObject.h"
namespace s_Renderer
{
    struct Cam{
        Vec3* up;
        Vec3* right;
        Vec3* dir;
        Vec3* pos;
        float near;
        float far;
        float fov;
    };
    class IRenderEngine {
        public:
        virtual bool initRenderer() = 0;
        virtual bool destroyRenderer() = 0;
        virtual void setCamera(Cam cam) = 0;
        virtual void addObjectToQueue(RenderObject* renderObject) = 0;
        virtual void drawFrame() = 0;
        virtual Renderer rendererType() = 0;


    };
} // namespace s_Renderer
