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


#ifndef TGUI_MENU_BAR_HPP
#define TGUI_MENU_BAR_HPP


#include <TGUI/Label.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    class MenuBarRenderer;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class TGUI_API MenuBar : public Widget
    {
    public:

        typedef std::shared_ptr<MenuBar> Ptr; ///< Shared widget pointer
        typedef std::shared_ptr<const MenuBar> ConstPtr; ///< Shared constant widget pointer


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Default constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        MenuBar();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Virtual destructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ~MenuBar() {};


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Create the menu bar
        ///
        /// @param themeFileFilename  Filename of the theme file.
        /// @param section            The section in the theme file to read.
        ///
        /// @throw Exception when the theme file could not be opened.
        /// @throw Exception when the theme file did not contain the requested section with the needed information.
        /// @throw Exception when one of the images, described in the theme file, could not be loaded.
        ///
        /// When an empty string is passed as filename, the built-in white theme will be used.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static MenuBar::Ptr create(const std::string& themeFileFilename = "", const std::string& section = "MenuBar");


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Makes a copy of another menu bar
        ///
        /// @param menuBar  The other menu bar
        ///
        /// @return The new menu bar
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static MenuBar::Ptr copy(MenuBar::ConstPtr menuBar);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer, which gives access to functions that determine how the widget is displayed
        ///
        /// @return Reference to the renderer
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::shared_ptr<MenuBarRenderer> getRenderer() const
        {
            return std::static_pointer_cast<MenuBarRenderer>(m_renderer);
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Set the position of the widget
        ///
        /// This function completely overwrites the previous position.
        /// See the move function to apply an offset based on the previous position instead.
        /// The default position of a transformable widget is (0, 0).
        ///
        /// @param position  New position
        ///
        /// @see move, getPosition
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setPosition(const Layout& position) override;
        using Transformable::setPosition;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the size of the menu bar.
        ///
        /// @param size  The new size of the menu bar.
        ///
        /// By default, the menu bar has the same width as the window and the height is 20 pixels.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setSize(const Layout& size) override;
        using Transformable::setSize;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Adds a new menu.
        ///
        /// @param text  The text written on the menu
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void addMenu(const sf::String& text);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Adds a new menu item.
        ///
        /// @param menu  The name of the menu to which the menu item will be added
        /// @param text  The text written on this menu item
        ///
        /// @return True when the item was added, false when menu was not found.
        ///
        /// @code
        /// menuBar->addMenu("File");
        /// menuBar->addMenuItem("File", "Load");
        /// menuBar->addMenuItem("File", "Save");
        /// @endcode
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool addMenuItem(const sf::String& menu, const sf::String& text);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Removes a menu.
        ///
        /// Any menu items that belong to this menu will be removed as well.
        ///
        /// @param menu  The name of the menu to remove
        ///
        /// @return True when the menu was removed, false when menu was not found.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool removeMenu(const sf::String& menu);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Removes all menus.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void removeAllMenus();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Removes a menu item.
        ///
        /// @param menu      The name of the menu in which the menu item is located
        /// @param menuItem  The name of the menu item to remove
        ///
        /// @return True when the item was removed, false when menu or menuItem was not found.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool removeMenuItem(const sf::String& menu, const sf::String& menuItem);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the character size of the text.
        ///
        /// @param size  The new size of the text.
        ///              If the size is 0 (default) then the text will be scaled to fit in the menu bar.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextSize(unsigned int size);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the character size of the text.
        ///
        /// @return The text size.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getTextSize() const
        {
            return m_textSize;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the minimum width of the submenus.
        ///
        /// When a submenu is displayed, the width will be either this or the width of the longest text in the submenu.
        /// The default minimum width is 125 pixels.
        ///
        /// @param minimumWidth  minimum width of the submenus
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setMinimumSubMenuWidth(float minimumWidth)
        {
            m_minimumSubMenuWidth = minimumWidth;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the distance between the text and the side of the menu item.
        ///
        /// @return minimum width of the submenus
        ///
        /// @see setMinimumSubMenuWidth
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        float getMinimumSubMenuWidth() const
        {
            return m_minimumSubMenuWidth;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool mouseOnWidget(float x, float y) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void leftMousePressed(float x, float y) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void leftMouseReleased(float x, float y) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void mouseMoved(float x, float y) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void mouseNoLongerDown() override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // This function is called when the mouse leaves the widget. If requested, a callback will be send.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void mouseLeftWidget() override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Closes any menu that might be open
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void closeVisibleMenu();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // This function is called when the widget is added to a container.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void initialize(Container *const container) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the widget
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Widget::Ptr clone() override
        {
            return std::make_shared<MenuBar>(*this);
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Draws the widget on the render target.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Defines specific triggers to MenuBar.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        enum MenuBarCallbacks
        {
            MenuItemClicked = WidgetCallbacksCount * 1,  ///< A menu item was clicked
            MenuBarCallbacksCount = WidgetCallbacksCount * 2
        };


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        struct Menu
        {
            Label text;
            std::vector<Label> menuItems;
            int selectedMenuItem = -1;
        };

        std::vector<Menu> m_menus;

        int m_visibleMenu = -1;

        unsigned int m_textSize = 0;

        float m_minimumSubMenuWidth = 125;

        friend class MenuBarRenderer;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class MenuBarRenderer : public WidgetRenderer
    {
    public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Constructor
        ///
        /// @param menuBar  The menu bar that is connected to the renderer
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        MenuBarRenderer(MenuBar* menuBar) : m_menuBar{menuBar} {}


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Dynamically change a property of the renderer, without even knowing the type of the widget.
        ///
        /// This function should only be used when you don't know the type of the widget.
        /// Otherwise you can make a direct function call to make the wanted change.
        ///
        /// @param property  The property that you would like to change
        /// @param value     The new value that you like to assign to the property
        /// @param rootPath  Path that should be placed in front of any resource filename
        ///
        /// @throw Exception when the property doesn't exist for this widget.
        /// @throw Exception when the value is invalid for this property.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setProperty(std::string property, const std::string& value, const std::string& rootPath = getResourcePath()) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Set the background color that will be used inside the menu bar.
        ///
        /// @param backgroundColor  The color of the background of the menu bar
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBackgroundColor(const sf::Color& backgroundColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Set the text color that will be used inside the menu bar.
        ///
        /// @param textColor  The color of the text
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextColor(const sf::Color& textColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Set the background color of the selected text that will be used inside the menu bar.
        ///
        /// @param selectedBackgroundColor  The color of the background of the selected item
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSelectedBackgroundColor(const sf::Color& selectedBackgroundColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Set the text color of the selected text that will be used inside the menu bar.
        ///
        /// @param selectedTextColor  The color of the text when it is selected
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSelectedTextColor(const sf::Color& selectedTextColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the font used in the menu bar.
        ///
        /// When you don't call this function then the global font will be use.
        /// This global font can be changed with the setGlobalFont function from the parent.
        ///
        /// @param font  The new font.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextFont(std::shared_ptr<sf::Font> font);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the distance between the text and the side of the menu item.
        ///
        /// @param distanceToSide  distance between the text and the side of the menu item
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setDistanceToSide(unsigned int distanceToSide);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the borders that are optionally drawn around the menu items.
        ///
        /// @param color  New border color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBorderColor(const sf::Color& color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Change the image that is used to fill the entire menu bar
        ///
        /// Pass an empty string to unset the image.
        ///
        /// @param filename   Filename of the image to load.
        /// @param partRect   Load only part of the image. Don't pass this parameter if you want to load the full image.
        /// @param middlePart Choose the middle part of the image for 9-slice scaling (relative to the part defined by partRect)
        /// @param repeated   Should the image be repeated or stretched when the size is bigger than the image?
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBackgroundImage(const std::string& filename,
                                const sf::IntRect& partRect = sf::IntRect(0, 0, 0, 0),
                                const sf::IntRect& middlePart = sf::IntRect(0, 0, 0, 0),
                                bool repeated = false);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Change the image that is used as background for every menu item
        ///
        /// Pass an empty string to unset the image.
        ///
        /// @param filename   Filename of the image to load.
        /// @param partRect   Load only part of the image. Don't pass this parameter if you want to load the full image.
        /// @param middlePart Choose the middle part of the image for 9-slice scaling (relative to the part defined by partRect)
        /// @param repeated   Should the image be repeated or stretched when the size is bigger than the image?
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setItemBackgroundImage(const std::string& filename,
                                    const sf::IntRect& partRect = sf::IntRect(0, 0, 0, 0),
                                    const sf::IntRect& middlePart = sf::IntRect(0, 0, 0, 0),
                                    bool repeated = false);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Change the image that is used as background of the selected menu item
        ///
        /// Pass an empty string to unset the image.
        ///
        /// @param filename   Filename of the image to load.
        /// @param partRect   Load only part of the image. Don't pass this parameter if you want to load the full image.
        /// @param middlePart Choose the middle part of the image for 9-slice scaling (relative to the part defined by partRect)
        /// @param repeated   Should the image be repeated or stretched when the size is bigger than the image?
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSelectedItemBackgroundImage(const std::string& filename,
                                            const sf::IntRect& partRect = sf::IntRect(0, 0, 0, 0),
                                            const sf::IntRect& middlePart = sf::IntRect(0, 0, 0, 0),
                                            bool repeated = false);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Draws the widget on the render target.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the renderer
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual std::shared_ptr<WidgetRenderer> clone(Widget* widget) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        MenuBarRenderer(const MenuBarRenderer&) = default;
        MenuBarRenderer& operator=(const MenuBarRenderer&) = delete;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        MenuBar*  m_menuBar;

        float     m_distanceToSide = 4;

        sf::Color m_textColor               = {  0,   0,   0};
        sf::Color m_selectedTextColor       = {255, 255, 255};

        sf::Color m_backgroundColor         = {255, 255, 255};
        sf::Color m_selectedBackgroundColor = {  0, 110, 255};

        Texture   m_backgroundTexture;
        Texture   m_itemBackgroundTexture;
        Texture   m_selectedItemBackgroundTexture;

        friend class MenuBar;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_MENU_BAR_HPP
