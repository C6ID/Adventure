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

#define TAKES_OWNERSHIP

#ifdef _C6ID_IN_LIB_BUILD
#define LIBRARY_VISIBLE [[gnu::visibility("default")]]
#else
#define LIBRARY_VISIBLE
#endif

#include <memory>
#include <vector>

template<typename T>
using SharedPtr = std::shared_ptr<T>;

template<typename T>
using SharedPtrs = std::vector<SharedPtr<T>>;

#define ADVENTURE_NAMESPACE_START namespace Adventure {
#define ADVENTURE_NAMESPACE_END }
