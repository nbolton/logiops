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
#ifndef LOGID_FEATURE_DEVICESTATUS_H
#define LOGID_FEATURE_DEVICESTATUS_H


#include <features/DeviceFeature.h>
#include <Device.h>
#include <backend/hidpp20/features/WirelessDeviceStatus.h>

namespace logid::features {
    class DeviceStatus : public DeviceFeature {
    public:
        explicit DeviceStatus(Device* dev);

        ~DeviceStatus() noexcept override;

        void configure() final;

        void listen() final;

    private:
        std::optional<backend::hidpp::Device::EvHandlerId> _ev_handler;
        std::shared_ptr<backend::hidpp20::WirelessDeviceStatus>
                _wireless_device_status;
    };
}

#endif //LOGID_FEATURE_DEVICESTATUS_H
