#include "Editor.h"

Editor::Editor()
: m_itemSelector(m_map), m_order(m_map),
m_threadSelector(&ItemSelector::update, &m_itemSelector),
m_threadOrder(&Order::update, &m_order),
 m_minimap(m_map), m_fullscreen(false), m_threadinit(true), m_showMinimap(true),
 m_itemSelectorIn()
{
    m_threadSelector.launch();
    m_threadOrder.launch();
}

void Editor::update(sf::RenderWindow &window)
{
    m_eventManager.update(window, m_map, m_itemSelector, m_itemSelectorIn, m_fullscreen, m_showMinimap);
    m_map.update();
    m_minimap.update(m_map);
    if (m_fullscreen)
        m_itemSelectorIn.update(window, m_map.getResolution());
}

void Editor::draw(sf::RenderWindow &window)
{
    m_map.draw(window);

    if (m_showMinimap)
        m_minimap.draw(window);

    if (!m_fullscreen)
    {
        if (!m_threadinit)
        {
            m_threadinit = true;
            m_threadSelector.launch();
            m_threadOrder.launch();
        }

        m_itemSelector.draw();
    }
    else
    {
        if (m_threadinit)
        {
            m_threadinit = false;
            m_threadSelector.terminate();
            m_threadOrder.terminate();
        }

        m_itemSelectorIn.draw(window, m_map.getResolution());
    }
}

Editor::~Editor()
{
    m_threadSelector.terminate();
    m_threadOrder.terminate();
}
