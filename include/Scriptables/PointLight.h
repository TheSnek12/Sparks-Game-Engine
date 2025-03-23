#pragma once
#include "Scriptable.h"
#include "src/Renderer/IRenderEngine.h"
#include <Scriptables/Transform.h>
#include "src/Context.h"
namespace sparks
{
    class PointLight : public Scriptable {
        private:
        s_Renderer::PointLight light;
        public:
        void onStart() override;
        void onTick () override{}
        PointLight();
        ~PointLight();
        float luminance = 1.0f;
        Vec3 color = Vec3(1, 1, 1);
    };
} // namespace sparls
