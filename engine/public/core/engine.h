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

/********************************************
 *                                          *
 *  Warning: This is a public header file.  *
 *                                          *
 ********************************************/

#pragma once

#include <c6id_common.h>

class Engine
{
    public:
        virtual void fireUp() = 0;
        virtual void step() = 0;
        virtual bool isRunning() const = 0;
};

#include <c6id_uncommon.h>
