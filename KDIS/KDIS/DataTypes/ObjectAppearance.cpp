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

#include "./ObjectAppearance.h"

using namespace bits;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

ObjectAppearance::ObjectAppearance() :
        m_percentComplete(0),
        m_bits(0)
{
}

//////////////////////////////////////////////////////////////////////////

ObjectAppearance::ObjectAppearance( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

ObjectAppearance::ObjectAppearance( KUINT8 PerCent, ObjectDamage OD, KBOOL Predist, KBOOL State,
                                    KBOOL Smoking, KBOOL Flaming ) throw( KException )
{
    if( PerCent > 100 ) throw KException( __FUNCTION__, INVALID_DATA, "PerCent Acceptable values are 0-100." );

    m_percentComplete = PerCent;
    SetDamage(OD);
    SetPredistributed(Predist);
    SetState(State);
    SetSmoking(Smoking);
    SetFlaming(Flaming);
}

//////////////////////////////////////////////////////////////////////////

ObjectAppearance::~ObjectAppearance()
{
}

//////////////////////////////////////////////////////////////////////////

void ObjectAppearance::SetGeneralAppearance( KUINT16 GA )
{
    m_percentComplete = getUbits<8, 0>(GA);
    m_bits = getUbits<8, 8>(GA);
}

//////////////////////////////////////////////////////////////////////////

KUINT16 ObjectAppearance::GetGeneralAppearance() const
{
    KUINT16 generalAppearance;
    setBits<8, 0>(generalAppearance, m_percentComplete);
    setBits<8, 8>(generalAppearance, m_bits);
    return generalAppearance;
}

//////////////////////////////////////////////////////////////////////////

void ObjectAppearance::SetPercentageComplete( KUINT8 P ) throw( KException )
{
    if( P > 100 ) throw KException( __FUNCTION__, INVALID_DATA, "Acceptable values are 0-100." );

    m_percentComplete = P;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 ObjectAppearance::GetPercentageComplete() const
{
    return m_percentComplete;
}

//////////////////////////////////////////////////////////////////////////

void ObjectAppearance::SetDamage( ObjectDamage OD )
{
    setBits<2, 0>(m_bits, OD);
}

//////////////////////////////////////////////////////////////////////////

ObjectDamage ObjectAppearance::GetDamage() const
{
    return ( ObjectDamage ) getUbits<2, 0>(m_bits);
}

//////////////////////////////////////////////////////////////////////////

void ObjectAppearance::SetPredistributed( KBOOL P )
{
    setBit<2>(m_bits, P);
}

//////////////////////////////////////////////////////////////////////////

KBOOL ObjectAppearance::IsPredistributed() const
{
    return getBit<2>(m_bits);
}

//////////////////////////////////////////////////////////////////////////

void ObjectAppearance::SetState( KBOOL S )
{
    setBit<3>(m_bits, S);
}

//////////////////////////////////////////////////////////////////////////

KBOOL ObjectAppearance::GetState() const
{
    return getBit<3>(m_bits);
}

//////////////////////////////////////////////////////////////////////////

void ObjectAppearance::SetSmoking( KBOOL S )
{
    setBit<4>(m_bits, S);
}

//////////////////////////////////////////////////////////////////////////

KBOOL ObjectAppearance::IsSmoking() const
{
    return getBit<4>(m_bits);
}

//////////////////////////////////////////////////////////////////////////

void ObjectAppearance::SetFlaming( KBOOL F )
{
    setBit<5>(m_bits, F);
}

//////////////////////////////////////////////////////////////////////////

KBOOL ObjectAppearance::IsFlaming() const
{
    return getBit<5>(m_bits);
}

//////////////////////////////////////////////////////////////////////////

KString ObjectAppearance::GetAsString() const
{
    KStringStream ss;

    ss << "Object Appearance:\n"
       << "\tGeneral Appearance:"
       << "\tPercent Complete:  " << m_percentComplete                          << "\n"
       << "\tDamage:            " << GetEnumAsStringObjectDamage( GetDamage() ) << "\n"
       << "\tPredistributed:    " << IsPredistributed()                         << "\n"
       << "\tState:             " << GetState()                                 << "\n"
       << "\tSmoking:           " << IsSmoking()                                << "\n"
       << "\tFlaming:           " << IsFlaming()                                << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ObjectAppearance::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < OBJECT_APPEARANCE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_bits
           >> m_percentComplete;
}

//////////////////////////////////////////////////////////////////////////

KDataStream ObjectAppearance::Encode() const
{
    KDataStream stream;

    ObjectAppearance::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void ObjectAppearance::Encode( KDataStream & stream ) const
{
    stream << m_bits
           << m_percentComplete;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ObjectAppearance::operator == ( const ObjectAppearance & Value ) const
{
    return (this->m_bits == Value.m_bits
            && this->m_percentComplete == Value.m_percentComplete);
}

//////////////////////////////////////////////////////////////////////////

KBOOL ObjectAppearance::operator != ( const ObjectAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
