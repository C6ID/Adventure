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

#include "sdlsystem.h"

#include <SDL.h>
#include <vector>
#include <core/events/event.h>

ADVENTURE_NAMESPACE_START

SDLSystem::SDLSystem() : m_window(nullptr)
{
}

void SDLSystem::init()
{
    int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    WARN_ASSERT(result == 0);

    // TODO: Put these somewhere else.
    static const char * const WINDOW_TITLE = u8"Adventure";
    static const int WINDOW_WIDTH = 800;
    static const int WINDOW_HEIGHT = 600;

    m_window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
}

void SDLSystem::deinit()
{
    if (m_window) {
        SDL_DestroyWindow(m_window);
    }
}

void SDLSystem::pollEvents(SharedPtrs<Event> & events)
{
    SDL_Event sdlEvent;

    while (SDL_PollEvent(&sdlEvent)) {
        switch (sdlEvent.type) {
            case SDL_QUIT:
                events.emplace_back(new QuitEvent);
                break;

            case SDL_KEYUP:
                break;
        }
    }
}

ADVENTURE_NAMESPACE_END
