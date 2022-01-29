/*
 * Copyright 2019-2020 PixlOne
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
#ifndef LOGID_ACTION_GESTURE_H
#define LOGID_ACTION_GESTURE_H

#include "../Action.h"

#define LOGID_GESTURE_DEFAULT_THRESHOLD 50

namespace logid {
namespace actions
{
    class InvalidGesture : public std::exception
    {
    public:
        explicit InvalidGesture(std::string what="") : _what (what)
        {
        }
        virtual const char* what() const noexcept
        {
            return _what.c_str();
        }
    private:
        std::string _what;
    };

    class Gesture
    {
    public:
        virtual void press(bool init_threshold=false) = 0;
        virtual void release(bool primary=false) = 0;
        virtual void move(int16_t axis) = 0;

        virtual bool wheelCompatibility() const = 0;
        virtual bool metThreshold() const = 0;

        virtual ~Gesture() = default;

        static std::shared_ptr<Gesture> makeGesture(Device* device,
                config::Gesture& gesture,
                const std::shared_ptr<ipcgull::node>& parent,
                const std::string& direction);

    protected:
        explicit Gesture(Device* device,
                         const std::shared_ptr<ipcgull::node>& parent,
                         const std::string& direction);
        Device* _device;
        std::shared_ptr<ipcgull::node> _node;
    };
}}

#endif //LOGID_ACTION_GESTURE_H
