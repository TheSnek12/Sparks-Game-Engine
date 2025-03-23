#pragma once
#include "Scriptable.h"
#include "src/Renderer/IRenderEngine.h"
#include <Scriptables/Transform.h>
#include "src/Context.h"
namespace sparks
{
    class SpotLight : public Scriptable {
        private:
        s_Renderer::SpotLight light;
        public:
        void onStart() override;
        void onTick () override{}
        SpotLight();
        ~SpotLight();
        float luminance = 1.0f;
        float innerRadius = 1.0f;
        float radius = 1.0f;
        Vec3 color = Vec3(1, 1, 1);
    };
} // namespace sparls
