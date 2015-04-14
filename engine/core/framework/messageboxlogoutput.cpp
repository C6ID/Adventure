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

#include "messageboxlogoutput.h"

#include <SDL.h>

ADVENTURE_NAMESPACE_START

void MessageBoxLogOutput::log(LogLevel level, const std::string & message)
{
    SDL_MessageBoxFlags flags = SDL_MESSAGEBOX_INFORMATION;
    if (level == LogLevel::Warning) {
        flags = SDL_MESSAGEBOX_WARNING;
    } else if (level > LogLevel::Warning) {
        flags = SDL_MESSAGEBOX_ERROR;
    }

    SDL_ShowSimpleMessageBox(flags, "Log Output", message.c_str(), nullptr);
}

ADVENTURE_NAMESPACE_END
