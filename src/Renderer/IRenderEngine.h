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


    struct PointLight{
        
        Vec3* pos;
        Vec3* color;
        float* luminance;
        
        bool operator==(const PointLight& rhs){
            return pos==rhs.pos&&color==rhs.color&&luminance==rhs.luminance;
        }
    };
    struct DirLight{
        Vec3* rot;
        Vec3* color;
        float* luminance;

        bool operator==(const DirLight& rhs){
            return rot==rhs.rot&&color==rhs.color&&luminance==rhs.luminance;
        }
    };
    struct SpotLight{
        Vec3* pos;
        Vec3* dir;
        Vec3* color;
        float* innerRadius;
        float* radius;
        float* luminance;

        bool operator==(const SpotLight& rhs){
            return pos==rhs.pos&&dir==rhs.dir&&color==rhs.color&&innerRadius==rhs.innerRadius&&radius==rhs.radius&&luminance==rhs.luminance;
        }
    };

    class IRenderEngine {
        public:
        virtual bool initRenderer() = 0;
        virtual bool destroyRenderer() = 0;
        virtual void setCamera(Cam cam) = 0;
        virtual void addObjectToQueue(RenderObject* renderObject) = 0;
        virtual void drawFrame() = 0;
        virtual void addPointLight(PointLight light) = 0;
        virtual void removePointLight(PointLight light) = 0;
        virtual void addDirLight(DirLight light) = 0;
        virtual void removeDirLight(DirLight light) = 0;
        virtual void addSpotLight(SpotLight light) = 0;
        virtual void removeSpotLight(SpotLight light) = 0;
        virtual Renderer rendererType() = 0;


    };
} // namespace s_Renderer
