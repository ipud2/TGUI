/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus's Graphical User Interface
// Copyright (C) 2012 Bruno Van de Velde (VDV_B@hotmail.com)
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


#ifndef _TGUI_EVENT_MANAGER_INCLUDED_
#define _TGUI_EVENT_MANAGER_INCLUDED_

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \internal
    //  Keeps track of all objects and passes the events to them.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct TGUI_API EventManager : public sf::NonCopyable
    {
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // The default constructor.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        EventManager();


    private:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // When this function is called then all the objects receive the event (if there are objects).
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void handleEvent(sf::Event& event);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // You can use this function to change the focus to another object.
        // You cannot manually call this function. You should call the focus function from the object's parent instead.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void focusObject(OBJECT* object);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Unfocuses the given object.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void unfocusObject(OBJECT* object);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Unfocuses all the objects.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void unfocusAllObjects();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Places an object before all other objects.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void updateTime(const sf::Time& elapsedTime);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // When the tab key is pressed then this function is called. The focus will move to the next object (if there is one).
        // This function will only work when tabKeyUsageEnabled is true.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void tabKeyPressed();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Checks above which object the mouse is standing.
        // The object can be signaled through Objects[ObjectNr] on condition that this function returned true.
        //
        // return:  true when the mouse is standing on an object
        //          false if the mouse isn't on any object
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool mouseOnObject(unsigned int& objectNr, float x, float y);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Tells all the objects that the mouse is not on top of them.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void mouseNotOnObject();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Tells all the objects that the mouse is no longer down.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void mouseNoLongerDown();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // This function is similar to the tabKeyPressed function.
        // The difference is that this function will return false and unfocus all objects when the last object was focused.
        // The tabKeyPressed function on the other hand would just focus the first object.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool focusNextObject();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private:

        // This vector will hold all objects
        std::vector<OBJECT*> m_Objects;

        // The id of the focused object
        unsigned int m_FocusedObject;

        // When one of the elements of the array becomes true then the key is held down.
        // When nothing happend (e.g. focus another object) and it goes up again then the focused object receives a signal.
        // When something happens then this key will also becomes false again (while the key is still down).
        // Not all elements are used, only a few elements of the array are changed.
        bool m_KeyPress[sf::Keyboard::KeyCount];

        // A pointer to the struct that owns the event manager (NULL when it is the window)
        OBJECT* m_Parent;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        // The event handler can only be used by objects and by the window
        friend struct Group;
        friend struct Panel;
        friend struct ChildWindow;
        friend struct Window;
        friend struct Form;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif //_TGUI_EVENT_MANAGER_INCLUDED_

