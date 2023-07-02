#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <SDL.h>
class TextureManager
{
    public:
        static Engine * GetInstance(){
            return s_Instance = (s_Instance!= nullptr)? s_Instance : new TextureManager();
        }
        bool Load(std::string id, std::string filename);
        void Drop(std::string id);
        void Clean();

        void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip=FLIP_NONE);



    private:
        TextureManager(){};
        std::map<std::string,SDL_Texture*> m_TextureMap;
        static Engine * s_Instance;
};

#endif // TEXTUREMANAGER_H
