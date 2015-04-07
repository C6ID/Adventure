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

#include "engineutils.h"
#include <iostream>
#include <framework/ostreamlogoutput.h>

ADVENTURE_NAMESPACE_START

static OstreamLogOutput defaultLogOutput(std::cerr);
static std::unique_ptr<LogOutput> currentLogOutput = nullptr;

void EngineUtils::setLogOutput(TAKES_OWNERSHIP LogOutput * logOutput)
{
    currentLogOutput.reset(logOutput);
}

void EngineUtils::log(LogLevel level, const std::string & message)
{
    LogOutput * output = currentLogOutput.get();
    if (!output) {
        output = &defaultLogOutput;
    }

    output->log(level, message);
}

ADVENTURE_NAMESPACE_END
