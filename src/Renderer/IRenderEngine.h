namespace s_Renderer
{
    class IRenderEngine {
        public:
        virtual bool initRenderer() = 0;
        virtual bool destroyRenderer() = 0;
        virtual void addObjectToQueue() = 0;
        virtual void drawFrame() = 0;


    };
} // namespace s_Renderer
