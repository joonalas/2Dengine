#ifndef LOADER_PARAMS_H
#define LOADER_PARAMS_H

class LoaderParams {
    public:
        LoaderParams(int x, int y, int width, int height, std::string textureID, int initFrame = 1, int initRow = 1) :
        m_x(x), m_y(y), m_width(width), m_height(height), m_textureID(textureID), m_initFrame(initFrame), m_initRow(initRow) {}
        int getX() const { return m_x; }
        int getY() const { return m_y; }
        int getWidth() const { return m_width; }
        int getHeight() const { return m_height; }
        std::string getTextureID() const { return m_textureID; }
        int getInitFrame() const {return m_initFrame;}
        int getInitRow() const {return m_initRow;}
    private:
        int m_x;
        int m_y;
        int m_width;
        int m_height;
        std::string m_textureID;
        int m_initFrame;
        int m_initRow;
};

#endif