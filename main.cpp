#include <iostream>
#include <glad/glad.h>
#include <SDL2/SDL.h>

//Globais

int gScreenHeight = 640;
int gScreenWidth = 480;
SDL_Window*     gGraphicsApplicationWindow = nullptr;
SDL_GLContext   gOpenGLContext = nullptr;

bool gQuit = false;

void GetOpenGLVersionInfo(){
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "Shading Language: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

void inicializar(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL2 falhou em inicializar: " << std::endl;
        exit(1);
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    gGraphicsApplicationWindow = SDL_CreateWindow("Janela",0, 0, gScreenWidth,
                                  gScreenHeight, SDL_WINDOW_OPENGL);

    if(gGraphicsApplicationWindow == nullptr){
        std::cout << "Janela não carregou" << std::endl;
        exit(1);
    }else{
        std::cout << "Janela foi aberta" << std::endl;
    }

    gOpenGLContext = SDL_GL_CreateContext(gGraphicsApplicationWindow);

    if(gOpenGLContext == nullptr){
        std::cout << "Context OpenGL não foi aberto" << std::endl;
        exit(1);
    }

    // Inicializar biblioteca Glad
    if(!gladLoadGLLoader(SDL_GL_GetProcAddress)){
        std::cout << "Glad não foi inicializado" << std::endl;
        exit(1);
    }

    GetOpenGLVersionInfo();
}

void Input(){
    SDL_Event e;

    while(SDL_PollEvent(&e) != 0){
        if(e.type == SDL_QUIT){
            std::cout << "boa noite" << std::endl;
            gQuit = true;
        }
    }

}

void PreDraw(){


}

void Draw(){


}
void loop(){

    while(!gQuit){
        Input();

        PreDraw();

        Draw();

        // Atualizar a tela
        SDL_GL_SwapWindow(gGraphicsApplicationWindow);
    }

}

void limpar(){
    SDL_DestroyWindow(gGraphicsApplicationWindow);
    SDL_Quit();

}

int main(){

    inicializar();

    loop();

    limpar();

    return 0;
}