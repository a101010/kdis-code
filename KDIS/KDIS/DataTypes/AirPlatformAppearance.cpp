/*********************************************************************
Copyright 2013 Karl Jones
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

For Further Information Please Contact me at
Karljj1@yahoo.com
http://p.sf.net/kdis/UserGuide
*********************************************************************/

#include "./AirPlatformAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

KString AirPlatformAppearance::GetAsString() const
{
    KStringStream ss;

    ss << "Air Platform Appearance:"
       << "\n\tPaint Scheme:           " << GetEnumAsStringPaintScheme( GetEntityPaintScheme() )
       << "\n\tMobility Kill:          " << DoesEntityMobilityKill()
       << "\n\tNVG Mode:               " << GetEnumAsStringNVGMode( GetNVGMode() )
       << "\n\tDamage:                 " << GetEnumAsStringEntityDamage( GetEntityDamage() )
       << "\n\tSmoke:                  " << GetEnumAsStringEntitySmoke( GetEntitySmoke() )
       << "\n\tTrailing Effect:        " << GetEnumAsStringEntityTrailingEffect( GetEntityTrailingEffect() )
       << "\n\tCanopy State:           " << GetEnumAsStringEntityHatchState( GetEntityCanopyState() )
       << "\n\tLanding Lights:         " << IsEntityLandingLightsOn()
       << "\n\tNavigation Lights:      " << IsEntityNavigationLightsOn()
       << "\n\tAnti-Collision Lights:  " << IsEntityAntiCollisionLightsOn()
       << "\n\tFlaming Effect:         " << IsEntityFlaming()
       << "\n\tAfterburner:            " << IsAfterburnerOn()
       << "\n\tLower Anti-Collision Light: " << IsEntityLowerAntiCollisionLightOn()
       << "\n\tUpper Anti-Collision Light: " << IsEntityUpperAntiCollisionLightOn()
       << "\n\tAnti-Collision Light:   " << GetEnumAsStringAntiCollisionDayNight( GetAntiCollisionLightDayNight() )
       << "\n\tIs Blinking:            " << IsBlinking()
       << "\n\tFrozen Status:          " << IsEntityFrozen()
       << "\n\tPower Plant:            " << IsEntityPowerPlantOn()
       << "\n\tState:                  " << IsEntityStateActive()
       << "\n\tFormation Lights:       " << IsEntityFormationLightsOn()
       << "\n\tLanding Gear Extended:  " << IsLandingGearExtended()
       << "\n\tCargo Doors Opened:     " << IsCargoDoorsOpened()
       << "\n\tNavigation/Position Brightness: " << GetEnumAsStringNavigationPositionBrightness( GetNavigationPositionBrightness() )
       << "\n\tSpot Lights:            " << IsEntitySpotLightsOn()
       << "\n\tInterior Lights:        " << IsEntityInteriorLightsOn()
       << "\n\tReverse Thrust Engaged: " << IsReverseThrustEngaged()
       << "\n\tWeight-on-Wheels:       " << IsWeightOnWheels()
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL AirPlatformAppearance::operator == ( const AirPlatformAppearance & Value ) const
{
    return (this->m_bits == Value.m_bits);
}

//////////////////////////////////////////////////////////////////////////

KBOOL AirPlatformAppearance::operator != ( const AirPlatformAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

