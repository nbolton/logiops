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
#ifndef LOGID_ACTION_RELEASEGESTURE_H
#define LOGID_ACTION_RELEASEGESTURE_H

#include "Gesture.h"

namespace logid {
namespace actions
{
    class ReleaseGesture : public Gesture
    {
    public:
        ReleaseGesture(Device* device, config::ReleaseGesture& config,
                       const std::shared_ptr<ipcgull::node>& parent,
                       const std::string& direction);

        virtual void press(bool init_threshold=false);
        virtual void release(bool primary=false);
        virtual void move(int16_t axis);

        virtual bool wheelCompatibility() const;
        virtual bool metThreshold() const;

    protected:
        int16_t _axis;
        std::shared_ptr<Action> _action;
        config::ReleaseGesture& _config;
    };
}}

#endif //LOGID_ACTION_RELEASEGESTURE_H
