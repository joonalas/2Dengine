#include "TextureManager.h"
#include <iostream>

TextureManager* TextureManager::s_pInstance = 0;

TextureManager* TextureManager::Instance() {
    if(s_pInstance == 0) {
        s_pInstance = new TextureManager();
        return s_pInstance;
    }

    return s_pInstance;
}

TextureManager::TextureManager() {}

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer) {
    std::cout << "Loading texture " << fileName << "..." << std::endl;

    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
    if(pTempSurface == 0) {
        std::cerr << "Image loading failure!" << std::endl;
        return false;
    }

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);

    if(pTexture != 0) {
        m_textureMap[id] = pTexture;
        return true;
    }
    std::cerr << "Texture creation failure" << std::endl;
    return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, 
int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, 
int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::clean() {
    std::cout << "Destroying textures..." << std::endl;
    std::map<std::string, SDL_Texture*>::iterator itr;
    for(itr = m_textureMap.begin(); itr != m_textureMap.end();) {
        SDL_DestroyTexture(itr->second);
        std::cout << "Texture '" << itr->first << "' destroyed!" << std::endl;
        m_textureMap.erase(itr++);
    }
    delete s_pInstance;
}

void TextureManager::clearFromTextureMap(std::string id) {
    SDL_DestroyTexture(m_textureMap[id]);
    m_textureMap.erase(id);
}