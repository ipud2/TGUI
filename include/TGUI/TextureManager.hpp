/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus's Graphical User Interface
// Copyright (C) 2012-2014 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TGUI_TEXTURE_MANAGER_HPP
#define TGUI_TEXTURE_MANAGER_HPP

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <TGUI/TextureData.hpp>

#include <list>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    class Texture;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class TGUI_API TextureManager
    {
      public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // You cannot copy an instance of TextureManager
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TextureManager(const TextureManager&) = delete;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // You cannot copy an instance of TextureManager
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TextureManager& operator=(const TextureManager&) = delete;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Loads a texture.
        ///
        /// @param filename   Filename of the image to load.
        /// @param texture    The texture object to store the loaded image.
        /// @param partRect   Load only part of the image. Don't pass this parameter if you want to load the full image.
        /// @param middlePart Choose the middle part of the image for 9-slice scaling (relative to the part defined by partRect)
        /// @param repeated   Should the image be repeated or stretched when the size is bigger than the image?
        ///
        /// The second time you call this function with the same filename, the previously loaded image will be reused.
        ///
        /// @throw Exception when image couldn't be loaded.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void getTexture(Texture& texture,
                        const std::string& filename,
                        const sf::IntRect& partRect = sf::IntRect(0, 0, 0, 0),
                        const sf::IntRect& middlePart = sf::IntRect(0, 0, 0, 0),
                        bool repeated = false);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Share the image with another texture.
        ///
        /// @param textureToCopy  The original texture that will now be reused.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void copyTexture(const Texture& textureToCopy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Removes the texture.
        ///
        /// @param textureToRemove  The texture that should be removed.
        ///
        /// When no other texture is using the same image then the image will be removed from memory.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void removeTexture(const Texture& textureToRemove);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        struct ImageMapData
        {
            sf::Image image;
            std::list<TextureData> data;
        };

        std::map<std::string, ImageMapData> m_imageMap;
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_TEXTURE_MANAGER_HPP
