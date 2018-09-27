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
    class:      LifeFormAppearance
    created:    22/09/2008 - Updated May 2012
    author:     Karl Jones

    purpose:    Represents the appearance of a life form.
                Implemented as struct so as to prevent the size from
                changing due to RTTI etc. No virtual methods, so
                no VTABLE.
    size:       32 Bits / 4 Octet
*********************************************************************/

#pragma once

#include "./../KDefines.h"
#include "./Enums/KDISEnums.h"
#include "./external/bits/bits.hpp"

namespace KDIS {
namespace DATA_TYPE {

struct KDIS_EXPORT LifeFormAppearance
{
protected:
    KUINT32 m_bits;
    
public:

    LifeFormAppearance();

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityPaintScheme
    //              KDIS::DATA_TYPE::LifeFormAppearance::GetEntityPaintScheme
    // Description: Describes the paint scheme of an entity.
    // Parameter:   EntityPaintScheme EPS
    //************************************
    void SetEntityPaintScheme(KDIS::DATA_TYPE::ENUMS::EntityPaintScheme EPS) {
        bits::setBit<0>(m_bits, EPS);
    }
    KDIS::DATA_TYPE::ENUMS::EntityPaintScheme GetEntityPaintScheme() const {
        return static_cast<KDIS::DATA_TYPE::ENUMS::EntityPaintScheme>(
            bits::getBit<0>(m_bits));
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityDamage
    //              KDIS::DATA_TYPE::LifeFormAppearance::GetEntityDamage
    // Description: Entity Damage/Health State.
    // Parameter:   EntityDamage ED
    //************************************
    void SetEntityDamage(KDIS::DATA_TYPE::ENUMS::EntityDamage ED) {
        bits::setBits<2, 3>(m_bits, ED);
    }
    KDIS::DATA_TYPE::ENUMS::EntityDamage GetEntityDamage() const {
        return static_cast<KDIS::DATA_TYPE::ENUMS::EntityDamage>(
                bits::getUbits<2, 3>(m_bits));
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityEntityCompliance
    //              KDIS::DATA_TYPE::LifeFormAppearance::GetEntityEntityCompliance
    // Description: Describes compliance of life form.
    // Parameter:   EntityCompliance EC
    //************************************
    void SetEntityEntityCompliance(KDIS::DATA_TYPE::ENUMS::EntityCompliance EC) {
        bits::setBits<4, 5>(m_bits, EC);
    }
    KDIS::DATA_TYPE::ENUMS::EntityCompliance GetEntityEntityCompliance() const {
        return static_cast< KDIS::DATA_TYPE::ENUMS::EntityCompliance>(
                bits::getUbits<4, 5>(m_bits));
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntitySignalSmokeInUse
    //              KDIS::DATA_TYPE::LifeFormAppearance::IsEntitySignalSmokeInUse
    // Description: Describes whether signal smoke is being used or not. True - In Use. False - Not In Use.
    // Parameter:   KBOOL FL
    //************************************
    void SetEntitySignalSmokeInUse(KBOOL SS) {
        bits::setBit<11>(m_bits, SS);
    }
    KBOOL IsEntitySignalSmokeInUse() const {
        return bits::getBit<11>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityFlashLights
    //              KDIS::DATA_TYPE::LifeFormAppearance::IsEntityFlashLightsOn
    // Description: Describes whether Flash Lights are on or off. True - On. False - Off.
    // Parameter:   KBOOL FL
    //************************************
    void SetEntityFlashLights(KBOOL FL) {
        bits::setBit<12>(m_bits, FL);
    }
    KBOOL IsEntityFlashLightsOn() const {
        return bits::getBit<12>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntitySignalMirrorInUse
    //              KDIS::DATA_TYPE::LifeFormAppearance::IsEntitySignalMirrorInUse
    // Description: Describes whether a signal mirror is being used or not. True - In Use. False - Not In Use.
    // Parameter:   KBOOL FL
    //************************************
    void SetEntitySignalMirrorInUse(KBOOL SM) {
        bits::setBit<13>(m_bits,SM);
    }
    KBOOL IsEntitySignalMirrorInUse() const {
        return bits::getBit<13>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityIRStrobe
    //              KDIS::DATA_TYPE::LifeFormAppearance::IsEntityIRStrobeOn
    // Description: Describes whether an IR strobe is on or off. True - On. False - Off.
    // Parameter:   KBOOL FL
    //************************************
    void SetEntityIRStrobe(KBOOL IRS) {
        bits::setBit<14>(m_bits, IRS);
    }
    KBOOL IsEntityIRStrobeOn() const {
        return bits::getBit<14>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityIRIlluminator
    //              KDIS::DATA_TYPE::LifeFormAppearance::IsEntityIRIlluminatorOn
    // Description: Describes whether an IR strobe is on or off. True - On. False - Off.
    // Parameter:   KBOOL FL
    //************************************
    void SetEntityIRIlluminator(KBOOL IRI) {
        bits::setBit<15>(m_bits, IRI);
    }
    KBOOL IsEntityIRIlluminatorOn() const {
        return bits::getBit<15>(m_bits);
    }

   //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityLifeformState
    //              KDIS::DATA_TYPE::LifeFormAppearance::GetEntityLifeformState
    // Description: Entities state/appearance. I.E Posture.
    // Parameter:   EntityLifeformAppearance EA
    //************************************
    void SetEntityLifeformState(KDIS::DATA_TYPE::ENUMS::EntityLifeformAppearance EA) {
        bits::setBits<4, 16>(m_bits, EA);
    }
    KDIS::DATA_TYPE::ENUMS::EntityLifeformAppearance GetEntityLifeformState() const {
        return static_cast<KDIS::DATA_TYPE::ENUMS::EntityLifeformAppearance>(
                bits::getUbits<4, 16>(m_bits));
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityFrozenStatus
    //              KDIS::DATA_TYPE::LifeFormAppearance::IsEntityFrozen
    // Description: Is the entity frozen?
    //              Note: Frozen entities should not be dead-reckoned.
    // Parameter:   KBOOL EFS
    //************************************
    void SetEntityFrozenStatus(KBOOL EFS) {
        bits::setBit<21>(m_bits, EFS);
    }
    KBOOL IsEntityFrozen() const {
        return bits::getBit<21>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityMountedHoisted
    //              KDIS::DATA_TYPE::LifeFormAppearance::IsEntityMountedHoisted
    // Description: Describes whether the lifeform is mounted/hoisted on another platform. True - Yes. False - No.
    // Parameter:   KBOOL FL
    //************************************
    void SetEntityMountedHoisted(KBOOL MH) {
        bits::setBit<22>(m_bits, MH);
    }
    KBOOL IsEntityMountedHoisted() const {
        return bits::getBit<22>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityStateActive
    //              KDIS::DATA_TYPE::LifeFormAppearance::IsEntityStateActive
    // Description: Active(true) / De active(false)
    // Parameter:   KBOOL ES
    //************************************
    void SetEntityStateActive(KBOOL ES) {
        bits::setBit<23>(m_bits, !ES);
    }
    KBOOL IsEntityStateActive() const {
        return !bits::getBit<23>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityLifeformWeapon
    //              KDIS::DATA_TYPE::LifeFormAppearance::GetEntityLifeformWeapon
    // Description: Weapon Status. E.G Stowed.
    // Parameter:   EntityLifeformWeapon ELW
    //************************************
    void SetEntityLifeformWeapon1(KDIS::DATA_TYPE::ENUMS::EntityLifeformWeapon ELW) {
        bits::setBits<2, 24>(m_bits, ELW);
    }
    KDIS::DATA_TYPE::ENUMS::EntityLifeformWeapon GetEntityLifeformWeapon1() const {
        return static_cast<KDIS::DATA_TYPE::ENUMS::EntityLifeformWeapon>(
                bits::getUbits<2, 24>(m_bits));
    }

    void SetEntityLifeformWeapon2(KDIS::DATA_TYPE::ENUMS::EntityLifeformWeapon ELW) {
        bits::setBits<2, 26>(m_bits, ELW);
    }
    KDIS::DATA_TYPE::ENUMS::EntityLifeformWeapon GetEntityLifeformWeapon2() const {
        return static_cast<KDIS::DATA_TYPE::ENUMS::EntityLifeformWeapon>(
                bits::getUbits<2, 26>(m_bits));
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetEntityCamouflage
    //              KDIS::DATA_TYPE::LifeFormAppearance::GetEntityCamouflage
    // Description: camouflage type worn.
    // Parameter:   EntityCamouflage EC
    //************************************
    void SetEntityCamouflage(KDIS::DATA_TYPE::ENUMS::EntityCamouflage EC) {
        bits::setBits<2, 28>(m_bits, EC);
    }
    KDIS::DATA_TYPE::ENUMS::EntityCamouflage GetEntityCamouflage() const {
        return static_cast<KDIS::DATA_TYPE::ENUMS::EntityCamouflage>(
                bits::getUbits<2, 28>(m_bits));
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetConcealedStationary
    //              KDIS::DATA_TYPE::LifeFormAppearance::IsConcealedStationary
    // Description: Describes the type of stationary concealment. 
    //              False - Not concealed. True - Entity in a prepared concealed position.
    // Parameter:   KBOOL CS
    //************************************
    void SetConcealedStationary(KBOOL CS) {
        bits::setBit<30>(m_bits, CS);
    }
    KBOOL IsConcealedStationary() const {
        return bits::getBit<30>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::SetConcealedStationary
    //              KDIS::DATA_TYPE::LifeFormAppearance::IsConcealedStationary
    // Description: Describes the type of movement concealment. 
    //              False - Open movement. True - Rushes between covered positions.
    // Parameter:   KBOOL CM
    //************************************
    void SetConcealedMovement(KBOOL CM) {
        bits::setBit<31>(m_bits, CM);
    }
    KBOOL IsConcealedMovement() const {
        return bits::getBit<31>(m_bits);
    }

    //************************************
    // FullName:    KDIS::DATA_TYPE::LifeFormAppearance::GetAsString
    // Description: Returns a string representation
    //************************************
    KString GetAsString() const;

    void SetData(KUINT32& data) { m_bits = data; }

    KBOOL operator == ( const LifeFormAppearance & Value ) const;
    KBOOL operator != ( const LifeFormAppearance & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

