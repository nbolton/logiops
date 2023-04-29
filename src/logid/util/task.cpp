/*
 * Copyright 2019-2023 PixlOne
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include <util/task.h>

using namespace logid;

void logid::spawn_task(const std::function<void()>& function) {
    auto future = std::make_shared<std::future<void>>();
    *future = std::async(std::launch::async, [function, future]() {
        try {
            function();
        } catch (std::exception& e) {
            ExceptionHandler::Default(e);
        }
    });
}