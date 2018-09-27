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

#include "./PointObjectAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace bits;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

PointObjectAppearance::PointObjectAppearance() : m_point_appearance_bits(0)
{
}

//////////////////////////////////////////////////////////////////////////

PointObjectAppearance::PointObjectAppearance( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

PointObjectAppearance::~PointObjectAppearance()
{
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetBreach( Breach2bit B )
{
    setBits<2, 0>(m_point_appearance_bits, B);
}

//////////////////////////////////////////////////////////////////////////

Breach2bit PointObjectAppearance::GetBreach() const
{
    return ( Breach2bit ) getUbits<2, 0>(m_point_appearance_bits);
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetOpacity( KUINT8 Opacity ) throw( KException )
{
    if( Opacity > 100 ) throw KException( __FUNCTION__, INVALID_DATA, "Acceptable values are 0-100." );

    setBits<8, 0>(m_point_appearance_bits, Opacity);
}

//////////////////////////////////////////////////////////////////////////

KUINT8 PointObjectAppearance::GetOpacity() const
{
    return (KUINT8) getUbits<8, 0>(m_point_appearance_bits);
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetBurstSize( KUINT8 S )
{
    setBits<8, 8>(m_point_appearance_bits, S);
}

//////////////////////////////////////////////////////////////////////////

KUINT8 PointObjectAppearance::GetBurstSize() const
{
    return (KUINT8) getUbits<8, 8>(m_point_appearance_bits);
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetHeight( KUINT8 H )
{
    setBits<8, 16>(m_point_appearance_bits, H);
}

//////////////////////////////////////////////////////////////////////////

KUINT8 PointObjectAppearance::GetHeight() const
{
    return (KUINT8) getUbits<8, 16>(m_point_appearance_bits);
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetNumBursts( KUINT8 N )
{
    setBits<6, 24>(m_point_appearance_bits, N);
}

//////////////////////////////////////////////////////////////////////////

KUINT8 PointObjectAppearance::GetNumBursts() const
{
    return (KUINT8) getUbits<6, 24>(m_point_appearance_bits);
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetChemical( Chemical C )
{
    setBits<2, 30>(m_point_appearance_bits, (KBOOL) C);
}

//////////////////////////////////////////////////////////////////////////

Chemical PointObjectAppearance::GetChemical() const
{
    return ( Chemical ) getUbits<2, 30>(m_point_appearance_bits);
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetCraterSize( KUINT8 S )
{
    setBits<8, 0>(m_point_appearance_bits, S);
}

//////////////////////////////////////////////////////////////////////////

KUINT8 PointObjectAppearance::GetCraterSize() const
{
    return (KUINT8) getUbits<8, 0>(m_point_appearance_bits);
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetNumSegments( KUINT8 N )
{
    setBits<8, 0>(m_point_appearance_bits, N);
}

//////////////////////////////////////////////////////////////////////////

KUINT8 PointObjectAppearance::GetNumSegments() const
{
    return (KUINT8) getUbits<8, 0>(m_point_appearance_bits);
}

//////////////////////////////////////////////////////////////////////////

KString PointObjectAppearance::GetAsString() const
{
    KStringStream ss;

    ss << ObjectAppearance::GetAsString()
       << "\tSpecific Appearance: " << m_point_appearance_bits << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < POINT_OBJECT_APPEARANCE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_point_appearance_bits;
    ObjectAppearance::Decode(stream);
}

//////////////////////////////////////////////////////////////////////////

KDataStream PointObjectAppearance::Encode() const
{
    KDataStream stream;

    PointObjectAppearance::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::Encode( KDataStream & stream ) const
{
    // First add the specific bytes and then the general.
    stream << m_point_appearance_bits;
    ObjectAppearance::Encode(stream);
}

//////////////////////////////////////////////////////////////////////////

KBOOL PointObjectAppearance::operator == ( const PointObjectAppearance & Value ) const
{
    return (m_point_appearance_bits == Value.m_point_appearance_bits)
            && (ObjectAppearance::operator==(Value));
}

//////////////////////////////////////////////////////////////////////////

KBOOL PointObjectAppearance::operator != ( const PointObjectAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
