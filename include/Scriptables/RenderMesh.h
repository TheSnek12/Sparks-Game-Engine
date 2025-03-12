#pragma once
#include <vector>
#include "src/Context.h"
#include <Scriptables/Scriptable.h>
#include "src/Renderer/Mesh.h"
#include "src/Renderer/RenderObject.h"

namespace sparks
{
    class RenderMesh : public Scriptable
    {
        s_Renderer::RenderObject renderObj;
        //FIX THISSS
        Mesh* mesh;
        Shader* shader;
        public:
        ~RenderMesh() override;
        void onStart() override;
        void onTick() override;
    };
} // namespace sparks
