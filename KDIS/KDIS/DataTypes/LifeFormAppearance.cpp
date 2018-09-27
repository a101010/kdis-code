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

#include "./LifeFormAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

LifeFormAppearance::LifeFormAppearance() :
    m_bits(0)
{}


//////////////////////////////////////////////////////////////////////////

KString LifeFormAppearance::GetAsString() const
{
    KStringStream ss;

    ss << "Lifeform Appearance:"
       << "\n\tPaint Scheme:         " << GetEnumAsStringEntityPaintScheme( GetEntityPaintScheme() )
       << "\n\tDamage:               " << GetEnumAsStringEntityDamage( GetEntityDamage() )
       << "\n\tCompliance:           " << GetEnumAsStringEntityCompliance( GetEntityEntityCompliance() )
       << "\n\tSignal Smoke In Use:  " << IsEntitySignalSmokeInUse()
       << "\n\tFlash Lights:         " << IsEntityFlashLightsOn()
       << "\n\tSignal Mirror In Use: " << IsEntitySignalMirrorInUse()
       << "\n\tIR Strobe On:         " << IsEntityIRStrobeOn()
       << "\n\tIR Illuminator On:    " << IsEntityIRIlluminatorOn()
       << "\n\tLifeform State:       " << GetEnumAsStringEntityLifeformAppearance( GetEntityLifeformState() )
       << "\n\tFrozen Status:        " << IsEntityFrozen()
       << "\n\tMounted/Hoisted:      " << IsEntityMountedHoisted()
       << "\n\tState:                " << IsEntityStateActive()
       << "\n\tWeapon 1:             " << GetEnumAsStringEntityLifeformWeapon( GetEntityLifeformWeapon1() )
       << "\n\tWeapon 2:             " << GetEnumAsStringEntityLifeformWeapon(GetEntityLifeformWeapon2())
       << "\n\tCamouflage:           " << GetEnumAsStringEntityCamouflage( GetEntityCamouflage() )
       << "\n\tConcealed Stationary: " << IsConcealedStationary()
       << "\n\tConcealed Movement:   " << IsConcealedMovement()
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL LifeFormAppearance::operator == ( const LifeFormAppearance & Value ) const
{
    // Lets do a single comparison instead of checking every field. 
    // This struct is basically a KUINT32 so lets cast it to one and compare.

    KUINT32 a = *( KUINT32 * )this;
    KUINT32 b = *( KUINT32 * )&Value;

    if( a != b )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LifeFormAppearance::operator != ( const LifeFormAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
