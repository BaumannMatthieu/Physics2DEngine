#ifndef __SYSTEM_H
#define __SYSTEM_H

class System {
    public:
        System(const unsigned int screenWidth,
               const unsigned int screenHeight,
               const std::string strNameWindow);
        ~System();
        
        void start();
    
    private:
        void initializeSDLWindow();
        void destroySDLWindow(); 
        
        void initializeOpenGLContext();
        void destroyOpenGLContext();
    
    private:
        SDL_Window* window;
        std::string strNameWindow;
        unsigned int screenWidth;
        unsigned int screenHeight;
        
        SDL_GLContext contextOpenGL;
        
        SDL_Event events; 
};

#endif
