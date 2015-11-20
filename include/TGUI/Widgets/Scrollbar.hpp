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


#ifndef TGUI_SCROLLBAR_HPP
#define TGUI_SCROLLBAR_HPP


#include <TGUI/Widget.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    class ScrollbarRenderer;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Scrollbar widget
    ///
    /// Signals:
    ///     - ValueChanged (The value of the scrollbar has changed)
    ///         * Optional parameter int: New value
    ///         * Uses Callback member 'value'
    ///
    ///     - Inherited signals from Widget
    ///
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API Scrollbar : public Widget
    {
    public:

        typedef std::shared_ptr<Scrollbar> Ptr; ///< Shared widget pointer
        typedef std::shared_ptr<const Scrollbar> ConstPtr; ///< Shared constant widget pointer


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Default constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Scrollbar();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Makes a copy of another scrollbar
        ///
        /// @param scrollbar  The other scrollbar
        ///
        /// @return The new scrollbar
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static Scrollbar::Ptr copy(Scrollbar::ConstPtr scrollbar);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer, which gives access to functions that determine how the widget is displayed
        ///
        /// @return Reference to the renderer
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::shared_ptr<ScrollbarRenderer> getRenderer() const
        {
            return std::static_pointer_cast<ScrollbarRenderer>(m_renderer);
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
        /// @brief Changes the size of the scrollbar.
        ///
        /// @param size  The new size of the scrollbar
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSize(const Layout2d& size) override;
        using Transformable::setSize;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets a maximum value.
        ///
        /// @param maximum  The new maximum value
        ///
        /// When the value is bigger than (maximum - low value), the value is set to maximum - low value.
        /// The default maximum value is 10.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setMaximum(unsigned int maximum);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the current value.
        ///
        /// @param value  The new value
        ///
        /// The value has to be smaller than maximum - low value.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setValue(unsigned int value);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the 'low value'.
        ///
        /// @param lowValue  The new low value.
        ///                  In e.g. a list box, this value is the amount of items that fit inside the list box.
        ///
        /// Until the maximum is bigger than this value, no scrollbar will be drawn.
        /// You can however choose to always draw the scrollbar by calling setAutoHide(false).
        /// The default low value is 6.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setLowValue(unsigned int lowValue);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the maximum value.
        ///
        /// @return The current maximum value
        ///
        /// The default maximum value is 10.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getMaximum() const
        {
            return m_maximum;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the current value.
        ///
        /// @return The current value
        ///
        /// The default value is 0.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getValue() const
        {
            return m_value;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the low value.
        ///
        /// @see setLowValue
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getLowValue() const
        {
            return m_lowValue;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes how much the value changes when pressing one of the arrows of the scrollbar
        ///
        /// @param scrollAmount  How far should the scrollbar scroll when an arrow is clicked?
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setArrowScrollAmount(unsigned int scrollAmount)
        {
            m_scrollAmount = scrollAmount;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns how much the value changes when pressing one of the arrows of the scrollbar
        ///
        /// @return How far should the scrollbar scroll when an arrow is clicked?
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getArrowScrollAmount()
        {
            return m_scrollAmount;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes whether the scrollbar should hide automatically or not.
        ///
        /// When true (default), the scrollbar will not be drawn when the maximum is smaller than the low value.
        ///
        /// @param autoHide  Should the scrollbar be invisible when you can't scroll?
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setAutoHide(bool autoHide)
        {
            m_autoHide = autoHide;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns whether the scrollbar is hiding automatically or not.
        ///
        /// When true (default), the scrollbar will not be drawn when the maximum is smaller than the low value.
        /// So when you can't scroll, the scrollbar won't be drawn.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool getAutoHide() const
        {
            return m_autoHide;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the opacity of the widget.
        ///
        /// @param opacity  The opacity of the widget. 0 means completely transparent, while 1 (default) means fully opaque.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setOpacity(float opacity) override;


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
        virtual void widgetFocused() override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void mouseNoLongerDown();


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
            return std::make_shared<Scrollbar>(*this);
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Draws the widget on the render target.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        enum class Part
        {
            Track,
            Thumb,
            ArrowUp,
            ArrowDown
        };

        // Keep track on which part of the scrollbar the mouse is standing
        Part m_mouseHoverOverPart = Part::Thumb;

        // When the mouse went down, did it go down on top of the thumb? If so, where?
        bool m_mouseDownOnThumb = false;
        sf::Vector2f m_mouseDownOnThumbPos;

        unsigned int m_maximum = 10;
        unsigned int m_value = 0;

        // Maximum should be above this value before the scrollbar is needed
        unsigned int m_lowValue = 6;

        // Is the scrollbar draw vertically?
        bool m_verticalScroll = true;

        // Does the image lie vertically?
        bool m_verticalImage = true;

        // How far should the value change when pressing one of the arrows?
        unsigned int m_scrollAmount = 1;

        // When no scrollbar is needed, should the scrollbar be drawn or stay hidden?
        bool m_autoHide = true;

        // Did the mouse went down on one of the arrows?
        bool m_mouseDownOnArrow = false;

        sf::FloatRect m_track;
        sf::FloatRect m_thumb;
        sf::FloatRect m_arrowUp;
        sf::FloatRect m_arrowDown;

        // ListBox, ComboBox and TextBox can access the scrollbar directly
        friend class ListBox;
        friend class ComboBox;
        friend class TextBox;
        friend class ChatBox;

        friend class ScrollbarRenderer;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    };


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class TGUI_API ScrollbarRenderer : public WidgetRenderer
    {
    public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Constructor
        ///
        /// @param scrollbar  The scrollbar that is connected to the renderer
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ScrollbarRenderer(Scrollbar* scrollbar) : m_scrollbar{scrollbar} {}


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Change a property of the renderer
        ///
        /// @param property  The property that you would like to change
        /// @param value     The new serialized value that you like to assign to the property
        ///
        /// @throw Exception when deserialization fails or when the widget does not have this property.
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
        /// @brief Changes the color of the track.
        ///
        /// @param color  New track color
        ///
        /// This color will overwrite the color for both the normal and hover state.
        ///
        /// Note that this color is ignored when a track and thumb image have been set.
        ///
        /// @see setTrackColorNormal
        /// @see setTrackColorHover
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTrackColor(const sf::Color& color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the track in the normal state (mouse not on the track).
        ///
        /// @param color  New track color
        ///
        /// Note that this color is ignored when a track and thumb image have been set.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTrackColorNormal(const sf::Color& color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the track in hover state (mouse on top of the track).
        ///
        /// @param color  New track color
        ///
        /// Note that this color is ignored when a track and thumb image have been set.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTrackColorHover(const sf::Color& color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the thumb.
        ///
        /// @param color  New thumb color
        ///
        /// This color will overwrite the color for both the normal and hover state.
        ///
        /// Note that this color is ignored when a track and thumb image have been set.
        ///
        /// @see setTrackColorNormal
        /// @see setTrackColorHover
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setThumbColor(const sf::Color& color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the thumb in the normal state (mouse not on the thumb).
        ///
        /// @param color  New thumb color
        ///
        /// Note that this color is ignored when a track and thumb image have been set.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setThumbColorNormal(const sf::Color& color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the thumb in hover state (mouse on top of the thumb).
        ///
        /// @param color  New thumb color
        ///
        /// Note that this color is ignored when a track and thumb image have been set.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setThumbColorHover(const sf::Color& color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background color of the arrows.
        ///
        /// @param color  New arrow background color
        ///
        /// This color will overwrite the color for both normal and hover states.
        ///
        /// Note that this color is ignored when all normal images have been set.
        ///
        /// @see setArrowBackgroundColorNormal
        /// @see setArrowBackgroundColorHover
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setArrowBackgroundColor(const sf::Color& color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background color of the arrows in the normal state (mouse not on arrow).
        ///
        /// @param color  New background color
        ///
        /// Note that this color is ignored when all normal images have been set.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setArrowBackgroundColorNormal(const sf::Color& color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background color of the arrows in the hover state (mouse standing on top of the arrow).
        ///
        /// @param color  New arrow background color
        ///
        /// Note that this color is ignored when all normal images have been set.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setArrowBackgroundColorHover(const sf::Color& color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the arrows.
        ///
        /// @param color  New arrow color
        ///
        /// This color will overwrite the color for both normal and hover states.
        ///
        /// Note that this color is ignored when all normal images have been set.
        ///
        /// @see setArrowColorNormal
        /// @see setArrowColorHover
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setArrowColor(const sf::Color& color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the arrows in the normal state (mouse not on arrow).
        ///
        /// @param color  New arrow color
        ///
        /// Note that this color is ignored when all normal images have been set.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setArrowColorNormal(const sf::Color& color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the arrows in the hover state (mouse standing on top of the arrow).
        ///
        /// @param color  New arrow color
        ///
        /// Note that this color is ignored when all normal images have been set.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setArrowColorHover(const sf::Color& color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Change the image of the track that is displayed when the mouse is not on top of the scrollbar
        ///
        /// @param texture  The new track texture
        ///
        /// When all normal are set, then the alternative color properties will be ignored.
        /// Pass an empty string to unset the image.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTrackTexture(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Change the image of the track that is displayed when the mouse is on top of the slider
        ///
        /// @param texture  The new hover track texture
        ///
        /// The hover texture is ignored if no normal texture was set.
        /// Pass an empty texture to unset the image.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTrackHoverTexture(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Change the image of the thumb that is displayed when the mouse is not on top of the slider
        ///
        /// @param texture  The new thumb texture
        ///
        /// When all normal are set, then the alternative color properties will be ignored.
        /// Pass an empty string to unset the image.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setThumbTexture(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Change the image of the thumb that is displayed when the mouse is on top of the slider
        ///
        /// @param texture  The new hover thumb texture
        ///
        /// The hover texture is ignored if no normal texture was set.
        /// Pass an empty texture to unset the image.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setThumbHoverTexture(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Change the image that is used as the up arrow
        ///
        /// @param texture  The new arrow texture
        ///
        /// When all normal are set, then the alternative color properties will be ignored.
        /// Pass an empty texture to unset the image, in this case the color properties will be used again.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setArrowUpTexture(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Change the image that is used as the down arrow
        ///
        /// @param texture  The new arrow texture
        ///
        /// When all normal are set, then the alternative color properties will be ignored.
        /// Pass an empty texture to unset the image, in this case the color properties will be used again.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setArrowDownTexture(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Change the image that is used as the up arrow when the mouse is on top of this arrow
        ///
        /// @param texture  The new hover arrow texture
        ///
        /// The hover texture is ignored if no normal texture was set.
        /// Pass an empty texture to unset the image.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setArrowUpHoverTexture(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Change the image that is used as the up arrow when the mouse is on top of this arrow
        ///
        /// @param texture  The new hover arrow texture
        ///
        /// The hover texture is ignored if no normal texture was set.
        /// Pass an empty texture to unset the image.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setArrowDownHoverTexture(const Texture& texture);


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

        ScrollbarRenderer(const ScrollbarRenderer&) = default;
        ScrollbarRenderer& operator=(const ScrollbarRenderer&) = delete;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        Scrollbar* m_scrollbar;

        Texture    m_textureTrackNormal;
        Texture    m_textureTrackHover;
        Texture    m_textureThumbNormal;
        Texture    m_textureThumbHover;
        Texture    m_textureArrowUpNormal;
        Texture    m_textureArrowUpHover;
        Texture    m_textureArrowDownNormal;
        Texture    m_textureArrowDownHover;

        sf::Color  m_trackColorNormal           = {255, 255, 255};
        sf::Color  m_trackColorHover            = {255, 255, 255};
        sf::Color  m_thumbColorNormal           = {220, 220, 220};
        sf::Color  m_thumbColorHover            = {210, 210, 210};
        sf::Color  m_arrowBackgroundColorNormal = {245, 245, 245};
        sf::Color  m_arrowBackgroundColorHover  = {255, 255, 255};
        sf::Color  m_arrowColorNormal           = { 60,  60,  60};
        sf::Color  m_arrowColorHover            = {  0,   0,   0};

        friend class Scrollbar;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_SCROLLBAR_HPP
