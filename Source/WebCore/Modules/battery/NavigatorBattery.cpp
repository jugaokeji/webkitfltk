/*
 *  Copyright (C) 2012 Samsung Electronics
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with this library; see the file COPYING.LIB.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301, USA.
 */

#include "config.h"
#include "NavigatorBattery.h"

#if ENABLE(BATTERY_STATUS)

#include "BatteryController.h"
#include "BatteryManager.h"
#include "Navigator.h"

namespace WebCore {

NavigatorBattery::NavigatorBattery()
{
}

NavigatorBattery::~NavigatorBattery()
{
}

BatteryManager* NavigatorBattery::webkitBattery(Navigator* navigator)
{
    if (!navigator->frame())
        return nullptr;

    NavigatorBattery* navigatorBattery = NavigatorBattery::from(navigator);
    if (!navigatorBattery->m_batteryManager)
        navigatorBattery->m_batteryManager = BatteryManager::create(navigator);
    return navigatorBattery->m_batteryManager.get();
}

const char* NavigatorBattery::supplementName()
{
    return "NavigatorBattery";
}

NavigatorBattery* NavigatorBattery::from(Navigator* navigator)
{
    NavigatorBattery* supplement = static_cast<NavigatorBattery*>(Supplement<Navigator>::from(navigator, supplementName()));
    if (!supplement) {
        auto newSupplement = std::make_unique<NavigatorBattery>();
        supplement = newSupplement.get();
        provideTo(navigator, supplementName(), std::move(newSupplement));
    }
    return supplement;
}

} // namespace WebCore

#endif // ENABLE(BATTERY_STATUS)
