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

/********************************************************************
    class:      AirPlatformAppearance
    created:    22/09/2008 - Updated March 2012    
    author:     Karl Jones

    purpose:    Represents the appearance of a air platform.
                Implemented as struct so as to prevent the size from
                changing due to RTTI etc. This struct will be part of a
                union with all specific appearance values so it is implemented
                slightly different.
                No constructors to prevent C2620 error caused by union of
                classes/structs.
    size:       32 Bits / 4 Octet
*********************************************************************/

#pragma once

#include "./../KDefines.h"
#include "./Enums/KDISEnums.h"
#include "./external/bits/bits.hpp"

namespace KDIS {
namespace DATA_TYPE {

struct KDIS_EXPORT AirPlatformAppearance
{
protected:

    KUINT32 m_bits;

public:

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityPaintScheme
    //              KDIS::DATA_TYPE::AirPlatformAppearance::GetEntityPaintScheme
    // Description: Describes the paint scheme of an entity.
    // Parameter:   EntityPaintScheme EPS
    //************************************
    void SetEntityPaintScheme( KDIS::DATA_TYPE::ENUMS::EntityPaintScheme EPS ) {
        bits::setBit<0>(m_bits, EPS);
    }

    KDIS::DATA_TYPE::ENUMS::EntityPaintScheme GetEntityPaintScheme() const {
        return static_cast<KDIS::DATA_TYPE::ENUMS::EntityPaintScheme>(
                bits::getBit<1>(m_bits));
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityMobilityKill
    //              KDIS::DATA_TYPE::AirPlatformAppearance::DoesEntityMobilityKill
    // Description: Mobility/Propulsion Kill True/False?
    // Parameter:   KBOOL MK
    //************************************
    void SetEntityMobilityKill( KBOOL MK ) {
        bits::setBit<1>(m_bits, MK);
    }

    KBOOL DoesEntityMobilityKill() const {
        return bits::getBit<1>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetNVGMode
    //              KDIS::DATA_TYPE::AirPlatformAppearance::GetNVGMode
    // Description: NVG Lighting Mode.
    // Parameter:   NVGMode NM
    //************************************
    void SetNVGMode( KDIS::DATA_TYPE::ENUMS::NVGMode NM ) {
        bits::setBit<2>(m_bits, NM);
    }

    KDIS::DATA_TYPE::ENUMS::NVGMode GetNVGMode() const {
        return static_cast<KDIS::DATA_TYPE::ENUMS::NVGMode>(
                bits::getBit<2>(m_bits));
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityDamage
    //              KDIS::DATA_TYPE::AirPlatformAppearance::GetEntityDamage
    // Description: Entity Damage State
    // Parameter:   EntityDamage ED
    //************************************
    void SetEntityDamage( KDIS::DATA_TYPE::ENUMS::EntityDamage ED ) {
        bits::setBits<2, 3>(m_bits, ED);
    }

    KDIS::DATA_TYPE::ENUMS::EntityDamage GetEntityDamage() const {
        return static_cast<KDIS::DATA_TYPE::ENUMS::EntityDamage>(
                bits::getUbits<2, 3>(m_bits));
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntitySmoke,
    //              KDIS::DATA_TYPE::AirPlatformAppearance::GetEntitySmoke
    // Description: Entity Smoke State
    // Parameter:   EntitySmoke ES
    //************************************
    void SetEntitySmoke( KDIS::DATA_TYPE::ENUMS::EntitySmoke ES ) {
        bits::setBits<2, 5>(m_bits, ES);
    }

    KDIS::DATA_TYPE::ENUMS::EntitySmoke GetEntitySmoke() const {
        return static_cast<KDIS::DATA_TYPE::ENUMS::EntitySmoke>(
                bits::getUbits<2, 5>(m_bits));
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityTrailingEffect
    //              KDIS::DATA_TYPE::AirPlatformAppearance::GetEntityTrailingEffect
    // Description: Describes the size of the dust cloud/trailing effect.
    // Parameter:   EntityTrailingEffect ETE
    //************************************
    void SetEntityTrailingEffect( KDIS::DATA_TYPE::ENUMS::EntityTrailingEffect ETE ) {
        bits::setBits<2, 7>(m_bits, ETE);
    }

    KDIS::DATA_TYPE::ENUMS::EntityTrailingEffect GetEntityTrailingEffect() const {
        return static_cast<KDIS::DATA_TYPE::ENUMS::EntityTrailingEffect>(
                bits::getUbits<2, 7>(m_bits));
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityCanopyState
    //              KDIS::DATA_TYPE::AirPlatformAppearance::GetEntityCanopyState
    // Description: Is the canopy open or closed? Note: Only PrimaryHatchIsClosed
	//              or PrimaryHatchIsOpen are acceptable values when using aircraft.
    // Parameter:   EntityHatchState ECS
    //************************************
    void SetEntityCanopyState( KDIS::DATA_TYPE::ENUMS::EntityHatchState ECS ) {
        bits::setBits<3, 9>(m_bits, ECS);
    }

    KDIS::DATA_TYPE::ENUMS::EntityHatchState GetEntityCanopyState() const {
        return static_cast<KDIS::DATA_TYPE::ENUMS::EntityHatchState>(
                bits::getUbits<3, 9>(m_bits));
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityLandingLights
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityLandingLightsOn
    // Description: Are the vehicles landing lights turned on? True = On, False = Off.
    // Parameter:   KBOOL LL
    //************************************
    void SetEntityLandingLights( KBOOL LL ) {
        bits::setBit<12>(m_bits, LL);
    }

    KBOOL IsEntityLandingLightsOn() const {
        return bits::getBit<12>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityNavigationLights
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityNavigationLightsOn
    // Description: Are the vehicles Navigation lights turned on? True = On, False = Off.
    // Parameter:   KBOOL NL
    //************************************
    void SetEntityNavigationLights( KBOOL NL ) {
        bits::setBit<13>(m_bits, NL);
    }

    KBOOL IsEntityNavigationLightsOn() const {
        return bits::getBit<13>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityAntiCollisionLights
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityAntiCollisionLightsOn
    // Description: Are the vehicles Anti-Collision lights turned on? True = On, False = Off.
    // Parameter:   KBOOL ACL
    //************************************
    void SetEntityAntiCollisionLights( KBOOL ACL ) {
        bits::setBit<14>(m_bits, ACL);
    }

    KBOOL IsEntityAntiCollisionLightsOn() const {
        return bits::getBit<14>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityFlamingEffect
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityFlaming
    // Description: Are flames rising from the entity?
    // Parameter:   KBOOL EFE
    //************************************
    void SetEntityFlamingEffect( KBOOL EFE ) {
        bits::setBit<15>(m_bits, EFE);
    }

    KBOOL IsEntityFlaming() const {
        return bits::getBit<15>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityAfterburner
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsAfterburnerOn
    // Description: Is the entity afterburner on?
    // Parameter:   KBOOL AB, void
    //************************************
    void SetEntityAfterburner( KBOOL AB ) {
        bits::setBit<16>(m_bits, AB);
    }

    KBOOL IsAfterburnerOn() const {
        return bits::getBit<16>(m_bits);
    }
	
    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityLowerAntiCollisionLight
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityLowerAntiCollisionLightOn
    // Description: Is the vehicles lower anti-collision light turned on? True = On, False = Off.
    // Parameter:   KBOOL LACL
    //************************************
    void SetEntityLowerAntiCollisionLight( KBOOL LACL ) {
        bits::setBit<17>(m_bits, LACL);
    }

    KBOOL IsEntityLowerAntiCollisionLightOn() const {
        return bits::getBit<17>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityUpperAntiCollisionLight
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityUpperAntiCollisionLightOn
    // Description: Is the vehicles lower anti-collision light turned on? True = On, False = Off.
    // Parameter:   KBOOL UACL
    //************************************
    void SetEntityUpperAntiCollisionLight( KBOOL UACL ) {
        bits::setBit<18>(m_bits, UACL);
    }

    KBOOL IsEntityUpperAntiCollisionLightOn() const {
        return bits::getBit<18>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetAntiCollisionLightDayNight
    //              KDIS::DATA_TYPE::AirPlatformAppearance::GetAntiCollisionLightDayNight
    // Description: Anti-Collision Light Day/Night.
    // Parameter:   AntiCollisionDayNight ACDN
    //************************************
    void SetAntiCollisionLightDayNight( KDIS::DATA_TYPE::ENUMS::AntiCollisionDayNight ACDN ) {
        bits::setBit<19>(m_bits, ACDN);
    }

    KDIS::DATA_TYPE::ENUMS::AntiCollisionDayNight GetAntiCollisionLightDayNight() const {
        return static_cast<KDIS::DATA_TYPE::ENUMS::AntiCollisionDayNight>(
                bits::getBit<19>(m_bits));
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetBlinking
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsBlinking
    // Description: Are any lights blinking?
    // Parameter:   KBOOL EFS
    //***********************************?
    void SetBlinking( KBOOL B ) {
        bits::setBit<20>(m_bits, B);
    }

    KBOOL IsBlinking() const {
        return bits::getBit<20>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityFrozenStatus
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityFrozen
    // Description: Is the entity frozen?
    //              Note: Frozen entities should not be dead-reckoned, they should remain
    //              frozen in place. You would likely freeze entites when your application is
    //              in a paused state.
    // Parameter:   KBOOL EFS
    //************************************
    void SetEntityFrozenStatus( KBOOL EFS ) {
        bits::setBit<21>(m_bits, EFS);
    }

    KBOOL IsEntityFrozen() const {
        return bits::getBit<21>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityPowerPlantOn
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityPowerPlantOn
    // Description: Power Plant On/Off. True = On, False = Off.
    // Parameter:   KBOOL EPPS
    //************************************
    void SetEntityPowerPlantOn( KBOOL EPPS ) {
        bits::setBit<22>(m_bits, EPPS);
    }

    KBOOL IsEntityPowerPlantOn() const {
        return bits::getBit<22>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityStateActive
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityStateActive
    // Description: True = Active, False = Deactivated.
    // Parameter:   KBOOL ES
    //************************************
    void SetEntityStateActive( KBOOL ES ) {
        bits::setBit<23>(m_bits, !ES);
    }

    KBOOL IsEntityStateActive() const {
        return !bits::getBit<23>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityFormationLights
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityFormationLightsOn
    // Description: Are the vehicles Formation lights turned on? True = On, False = Off.
    // Parameter:   KBOOL FL
    //************************************
    void SetEntityFormationLights( KBOOL FL ) {
        bits::setBit<24>(m_bits, FL);
    }

    KBOOL IsEntityFormationLightsOn() const {
        return bits::getBit<24>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetLandingGearExtended
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsLandingGearExtended
    // Description: Is the landing gear extended or wholly retracted?
    // Parameter:   KBOOL LGE
    //***********************************?
    void SetLandingGearExtended( KBOOL LGE ) {
        bits::setBit<25>(m_bits, LGE);
    }

    KBOOL IsLandingGearExtended() const {
        return bits::getBit<25>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetCargoDoorsOpened
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsCargoDoorsOpened
    // Description: Is the cargo door (main door) open?
    // Parameter:   KBOOL LGE
    //***********************************?
    void SetCargoDoorsOpened( KBOOL CDO ) {
        bits::setBit<26>(m_bits, CDO);
    }

    KBOOL IsCargoDoorsOpened() const {
        return bits::getBit<26>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetNavigationPositionBrightness
    //              KDIS::DATA_TYPE::AirPlatformAppearance::GetNavigationPositionBrightness
    // Description: Brightness of the navigation/position lights
    // Parameter:   KDIS::DATA_TYPE::ENUMS::NavigationnPositionBrightness NPB
    //***********************************?
    void SetNavigationPositionBrightness( KDIS::DATA_TYPE::ENUMS::NavigationPositionBrightness NPB ) {
        bits::setBit<27>(m_bits, NPB);
    }

    KDIS::DATA_TYPE::ENUMS::NavigationPositionBrightness GetNavigationPositionBrightness() const {
        return static_cast<KDIS::DATA_TYPE::ENUMS::NavigationPositionBrightness>(
                bits::getBit<27>(m_bits));
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityBlackoutBrakeLights
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityBlackoutBrakeLightsOn
    // Description: Are the vehicles spot lights turned on? True = On, False = Off.
    // Parameter:   KBOOL SL
    //************************************
    void SetEntitySpotLights( KBOOL SL ) {
        bits::setBit<28>(m_bits, SL);
    }

    KBOOL IsEntitySpotLightsOn() const {
        return bits::getBit<28>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetEntityInteriorLights
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsEntityInteriorLightsOn
    // Description: Are the vehicles interior lights turned on? True = On, False = Off.
    // Parameter:   KBOOL IL
    //************************************
    void SetEntityInteriorLights( KBOOL IL ) {
        bits::setBit<29>(m_bits, IL);
    }

    KBOOL IsEntityInteriorLightsOn() const {
        return bits::getBit<29>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetReverseThrustEngaged
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsReverseThrustEngaged
    // Description: Is reverse thrust engaged?
    // Parameter:   KBOOL RTE
    //************************************
    void SetReverseThrustEngaged( KBOOL RTE ) {
        bits::setBit<30>(m_bits, RTE);
    }

    KBOOL IsReverseThrustEngaged() const {
        return bits::getBit<30>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::SetWeightOnWheels
    //              KDIS::DATA_TYPE::AirPlatformAppearance::IsWeightOnWheels
    // Description: Is weight on the main landing gear?
    // Parameter:   KBOOL RTE
    //************************************
    void SetWeightOnWheels( KBOOL WOW ) {
        bits::setBit<31>(m_bits, WOW);
    }

    KBOOL IsWeightOnWheels() const {
        return bits::getBit<31>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::AirPlatformAppearance::GetAsString
    // Description: Returns a string representation
    //************************************
    KString GetAsString() const;

    KBOOL operator == ( const AirPlatformAppearance & Value ) const;
    KBOOL operator != ( const AirPlatformAppearance & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

