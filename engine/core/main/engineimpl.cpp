/*
 * Copyright (C) 2015 C6ID
 *
 * This file is part of {ADVENTURE_NAME}.
 *
 * {ADVENTURE_NAME} is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * {ADVENTURE_NAME} is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with {ADVENTURE_NAME}.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>

#include "engineimpl.h"
#include <system/sdlsystem.h>
#include <events/event.h>

ADVENTURE_NAMESPACE_START

EngineImpl::EngineImpl() :
    m_system(new SDLSystem)
{
}

EngineImpl::~EngineImpl()
{
    m_system->deinit();
}

void EngineImpl::fireUp()
{
    m_system->init();
    m_running = true;
}

void EngineImpl::step()
{
    if (!m_running) {
        return;
    }

    SharedPtrs<Event> events;
    m_system->pollEvents(events);
    for (auto & event : events) {
        if (event->getType() == Event::Type::Quit) {
            WARN_ASSERT(false);
            ERR_ASSERT(false);
            m_running = false;
            break;
        }
    }
}

bool EngineImpl::isRunning() const
{
    return m_running;
}

ADVENTURE_NAMESPACE_END
