/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus's Graphical User Interface
// Copyright (C) 2012-2015 Bruno Van de Velde (vdv_b@tgui.eu)
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


#ifndef TGUI_CHAT_BOX_HPP
#define TGUI_CHAT_BOX_HPP


#include <TGUI/Widget.hpp>
#include <TGUI/Widgets/Panel.hpp>
#include <TGUI/Widgets/Scrollbar.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    class Scrollbar;
    class ChatBoxRenderer;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class TGUI_API ChatBox : public Widget
    {
    public:

        typedef std::shared_ptr<ChatBox> Ptr; ///< Shared widget pointer
        typedef std::shared_ptr<const ChatBox> ConstPtr; ///< Shared constant widget pointer


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Default constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ChatBox();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Copy constructor
        ///
        /// @param copy  Instance to copy
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ChatBox(const ChatBox& copy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Overload of assignment operator
        ///
        /// @param right  Instance to assign
        ///
        /// @return Reference to itself
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ChatBox& operator= (const ChatBox& right);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Makes a copy of another chat box
        ///
        /// @param chatBox  The other chat box
        ///
        /// @return The new chat box
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static ChatBox::Ptr copy(ChatBox::ConstPtr chatBox);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer, which gives access to functions that determine how the widget is displayed
        ///
        /// @return Reference to the renderer
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::shared_ptr<ChatBoxRenderer> getRenderer() const
        {
            return std::static_pointer_cast<ChatBoxRenderer>(m_renderer);
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
        virtual void setPosition(const Layout2d& position) override;
        using Transformable::setPosition;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the size of the chat box.
        ///
        /// This size does not include the borders.
        ///
        /// @param size   The new size of the chat box
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSize(const Layout2d& size) override;
        using Transformable::setSize;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the full size of the chat box.
        ///
        /// This is the size including the borders.
        ///
        /// @return Full size of the chat box
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual sf::Vector2f getFullSize() const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Add a new line of text to the chat box.
        ///
        /// The whole text passed to this function will be considered as one line for the getLine and removeLine functions,
        /// even if it is too long and gets split over multiple lines.
        ///
        /// The default text color and character size will be used.
        ///
        /// @param text  Text that will be added to the chat box
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void addLine(const sf::String& text);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Add a new line of text to the chat box.
        ///
        /// The whole text passed to this function will be considered as one line for the getLine and removeLine functions,
        /// even if it is too long and gets split over multiple lines.
        ///
        /// The default text color will be used.
        ///
        /// @param text      Text that will be added to the chat box
        /// @param textSize  Size of the text
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void addLine(const sf::String& text, unsigned int textSize);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Add a new line of text to the chat box.
        ///
        /// The whole text passed to this function will be considered as one line for the getLine and removeLine functions,
        /// even if it is too long and gets split over multiple lines.
        ///
        /// The default character size will be used.
        ///
        /// @param text   Text that will be added to the chat box
        /// @param color  Color of the text
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void addLine(const sf::String& text, const sf::Color& color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Add a new line of text to the chat box.
        ///
        /// The whole text passed to this function will be considered as one line for the getLine and removeLine functions,
        /// even if it is too long and gets split over multiple lines.
        ///
        /// @param text      Text that will be added to the chat box
        /// @param color     Color of the text
        /// @param textSize  Size of the text
        /// @param font      Font of the text (nullptr to use default font)
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void addLine(const sf::String& text, const sf::Color& color, unsigned int textSize, const Font& font = nullptr);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the contents of the requested line.
        ///
        /// @param lineIndex  The index of the line of which you request the contents.
        ///                   The first line has index 0.
        ///
        /// @return The contents of the requested line.
        ///         An empty string will be returned when the index is too high.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        sf::String getLine(std::size_t lineIndex);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Removes the requested line.
        ///
        /// @param lineIndex  The index of the line that should be removed.
        ///                   The first line has index 0.
        ///
        /// @return True if the line was removed, false if no such line existed (index too high).
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool removeLine(std::size_t lineIndex);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Removes all lines from the chat box.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void removeAllLines();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the amount of lines in the chat box.
        ///
        /// @return Number of lines in the chat box
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::size_t getLineAmount()
        {
            return m_panel->getWidgets().size();
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Set a maximum amount of lines in the chat box.
        ///
        /// Only the last maxLines lines will be kept. Lines above those will be removed.
        /// Set to 0 to disable the line limit (default).
        ///
        /// @param maxLines  The maximum amount of lines that the chat box can contain.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setLineLimit(std::size_t maxLines);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the default font of the text.
        ///
        /// @param font  The new font.
        ///
        /// When you don't call this function then the font from the parent widget will be used.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setFont(const Font& font);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the default font of the text.
        ///
        /// @return The currently used default font
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::shared_ptr<sf::Font> getTextFont()
        {
            return m_panel->getFont();
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the default character size of the text.
        ///
        /// @param size  The new default text size.
        ///              The minimum text size is 8.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextSize(unsigned int size);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the default character size of the text.
        ///
        /// @return The currently used default text size.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getTextSize() const
        {
            return m_textSize;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the default color of the text.
        ///
        /// @param color  The new default text color.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextColor(const sf::Color& color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the default color of the text.
        ///
        /// @return The currently used default text color.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        const sf::Color& getTextColor() const
        {
            return m_textColor;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the line spacing of all lines.
        ///
        /// By default, line spacing is chosen based on the font and character size. This also means that when mixing different
        /// text styles in ChatBox, lines can have different line spacings.
        /// By calling this function, all line spacings will be set to the value passed to this function.
        ///
        /// The line spacing should be equal or greater than the text size to avoid overlapping lines.
        ///
        /// @param lineSpacing  New line spacing for all lines
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setLineSpacing(unsigned int lineSpacing);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the scrollbar of the chat box.
        ///
        /// @param scrollbar The new scrollbar to use in the chat box
        ///
        /// Pass a nullptr to remove the scrollbar. Note that when removing the scrollbar while there are too many lines
        /// to fit in the chat box then the oldest lines will be removed.
        ///
        /// The scrollbar should have no parent and you should not change it yourself.
        /// The function is meant to be used like this:
        /// @code
        /// chatBox->setScrollbar(theme->load("scrollbar"));
        /// @endcode
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setScrollbar(Scrollbar::Ptr scrollbar);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Access the scrollbar of the chat box
        ///
        /// @return scrollbar in the chat box
        ///
        /// You should not change the scrollbar yourself
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Scrollbar::Ptr getScrollbar() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Let the first lines start from the top or from the bottom of the chat box.
        ///
        /// Note that this only makes a difference when the lines don't fill the entire chat box.
        /// This does not change the order of the lines, new lines will always be below older lines.
        ///
        /// @param startFromTop  Let the first lines be placed at the top of the chat box, or remain at the bottom?
        ///
        /// By default the first lines will be placed at the bottom of the chat box.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setLinesStartFromTop(bool startFromTop = true);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the opacity of the widget.
        ///
        /// @param opacity  The opacity of the widget. 0 means completely transparent, while 1 (default) means fully opaque.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setOpacity(float opacity) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the distance between the position where the widget is drawn and where the widget is placed
        ///
        /// This is basically the width and height of the optional borders drawn around widgets.
        ///
        /// @return Offset of the widget
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual sf::Vector2f getWidgetOffset() const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /// This function is called when the widget is added to a container.
        /// You should not call this function yourself.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setParent(Container* parent) override;


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
        virtual void mouseWheelMoved(int delta, int x, int y) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void mouseNotOnWidget() override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void mouseNoLongerDown() override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Retrieve the height of one of the lines, including the space below it that separates it from the next line.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        float getLineSpacing(const Label::Ptr& line);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Recalculate the space used by all the labels.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void recalculateFullTextHeight();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Update the position of the labels.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void updateDisplayedText();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Update the position and size of the panel and scrollbar.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void updateRendering();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Reload the widget
        ///
        /// @param primary    Primary parameter for the loader
        /// @param secondary  Secondary parameter for the loader
        /// @param force      Try to only change the looks of the widget and not alter the widget itself when false
        ///
        /// @throw Exception when the connected theme could not create the widget
        ///
        /// When primary is an empty string the built-in white theme will be used.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void reload(const std::string& primary = "", const std::string& secondary = "", bool force = false) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the widget
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Widget::Ptr clone() const override
        {
            return std::make_shared<ChatBox>(*this);
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Draws the widget on the render target.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        unsigned int m_lineSpacing = 0;
        unsigned int m_textSize = 18;
        sf::Color m_textColor = sf::Color::Black;

        std::size_t m_maxLines = 0;

        float m_fullTextHeight = 0;

        bool m_linesStartFromTop = false;

        // The panel containing the labels
        Panel::Ptr m_panel = std::make_shared<Panel>();

        // The scrollbar
        Scrollbar::Ptr m_scroll = std::make_shared<Scrollbar>();

        friend class ChatBoxRenderer;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class TGUI_API ChatBoxRenderer : public WidgetRenderer, public WidgetBorders, public WidgetPadding
    {
    public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Constructor
        ///
        /// @param chatBox  The chat box that is connected to the renderer
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ChatBoxRenderer(ChatBox* chatBox) : m_chatBox{chatBox} {}


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Change a property of the renderer
        ///
        /// @param property  The property that you would like to change
        /// @param value     The new serialized value that you like to assign to the property
        ///
        /// @throw Exception when deserialization fails or when the widget does not have this property.
        /// @throw Exception when loading scrollbar fails with the theme connected to the list box
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setProperty(std::string property, const std::string& value) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Change a property of the renderer
        ///
        /// @param property  The property that you would like to change
        /// @param value     The new value that you like to assign to the property.
        ///                  The ObjectConverter is implicitly constructed from the possible value types.
        ///
        /// @throw Exception for unknown properties or when value was of a wrong type.
        /// @throw Exception when loading scrollbar fails with the theme connected to the list box
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setProperty(std::string property, ObjectConverter&& value) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Retrieve the value of a certain property
        ///
        /// @param property  The property that you would like to retrieve
        ///
        /// @return The value inside a ObjectConverter object which you can extract with the correct get function or
        ///         an ObjectConverter object with type ObjectConverter::Type::None when the property did not exist.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ObjectConverter getProperty(std::string property) const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Get a map with all properties and their values
        ///
        /// @return Property-value pairs of the renderer
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual std::map<std::string, ObjectConverter> getPropertyValuePairs() const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Set the border color that will be used inside the chat box.
        ///
        /// @param borderColor  The color of the borders
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBorderColor(const sf::Color& borderColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Set the background color that will be used inside the chat box.
        ///
        /// @param backgroundColor  The new background color.
        ///
        /// Note that this color is ignored when you set a background image.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBackgroundColor(const sf::Color& backgroundColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background image
        ///
        /// @param texture  New background texture
        ///
        /// When this image is set, the background color property will be ignored.
        /// Pass an empty string to unset the image, in this case the background color property will be used again.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBackgroundTexture(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the size of the padding.
        ///
        /// @param padding  Size of the padding
        ///
        /// This padding will be scaled together with the background image.
        /// If there is no background image, or when 9-slice scaling is used, the padding will be exactly what you pass here.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setPadding(const Padding& padding) override;
        using WidgetPadding::setPadding;


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

        ChatBoxRenderer(const ChatBoxRenderer&) = default;
        ChatBoxRenderer& operator=(const ChatBoxRenderer&) = delete;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        ChatBox* m_chatBox;

        sf::Color m_borderColor;
        sf::Color m_backgroundColor;

        Texture m_backgroundTexture;

        friend class ChatBox;
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_TEXT_BOX_HPP
