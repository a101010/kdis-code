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

#include "./LinearObjectAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace std;
using namespace bits;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

LinearObjectAppearance::LinearObjectAppearance() :
        m_linear_appearance_bits (0)
{
}

//////////////////////////////////////////////////////////////////////////

LinearObjectAppearance::LinearObjectAppearance( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

LinearObjectAppearance::~LinearObjectAppearance()
{
}

//////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetBreach( Breach2bit B )
{
    setBits<2, 0>(m_linear_appearance_bits, B);
}

//////////////////////////////////////////////////////////////////////////

Breach2bit LinearObjectAppearance::GetBreach() const
{
    return static_cast<Breach2bit>(
            getUbits<2, 0>(m_linear_appearance_bits));
}

////////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetBreachLength( KUINT8 L )
{
    setBits<8, 16>(m_linear_appearance_bits, L);
}

////////////////////////////////////////////////////////////////////////////

KUINT8 LinearObjectAppearance::GetBreachLength() const
{
    return getUbits<8, 16>(m_linear_appearance_bits);
}

////////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetBreachLocation( const bitset<8> & L )
{
    KUINT32 i = L.to_ulong();
    setBits<8, 24>(m_linear_appearance_bits, i);
}

////////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetBreachLocation( KUINT8 L )
{
    setBits<8, 24>(m_linear_appearance_bits, L);
}

////////////////////////////////////////////////////////////////////////////

KUINT8 LinearObjectAppearance::GetBreachLocation() const
{
    return (KUINT8) getUbits<8, 24>(m_linear_appearance_bits);
}

////////////////////////////////////////////////////////////////////////////

bitset<8> LinearObjectAppearance::GetBreachLocationAsBitset()
{
    return bitset<8>( ( KINT32 )getUbits<8, 24>(m_linear_appearance_bits) ); // We need to cast to a signed int, this is a visual studio 2010 fix
}

////////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetOpacity( KUINT8 Opacity ) throw( KException )
{
    if( Opacity > 100 ) throw KException( __FUNCTION__, INVALID_DATA, "Acceptable values are 0-100." );

   setBits<8, 0>(m_linear_appearance_bits, Opacity);
}

//////////////////////////////////////////////////////////////////////////

KUINT8 LinearObjectAppearance::GetOpacity() const
{
    return (KUINT8) getUbits<8, 0>(m_linear_appearance_bits);
}

//////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetAttached( KBOOL A )
{
    setBit<8>(m_linear_appearance_bits, A);
}

//////////////////////////////////////////////////////////////////////////

KBOOL LinearObjectAppearance::IsAttached() const
{
    return getBit<8>(m_linear_appearance_bits);
}

//////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetChemical( Chemical C )
{
    setBits<2, 9>(m_linear_appearance_bits, (KBOOL) C);
}

//////////////////////////////////////////////////////////////////////////

Chemical LinearObjectAppearance::GetChemical() const
{
    return ( Chemical ) getUbits<2, 9>(m_linear_appearance_bits);
}

//////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::SetVisibleSide( VisibleSide V )
{
    setBits<2, 0>(m_linear_appearance_bits, V);
}

//////////////////////////////////////////////////////////////////////////

VisibleSide LinearObjectAppearance::GetVisibleSide() const
{
    return  ( VisibleSide ) getUbits<2, 0>(m_linear_appearance_bits);
}

//////////////////////////////////////////////////////////////////////////

KString LinearObjectAppearance::GetAsString() const
{
    KStringStream ss;

    ss << ObjectAppearance::GetAsString()
       << "\tSpecific Appearance: " << m_linear_appearance_bits << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < LINEAR_OBJECT_APPEARANCE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    // Note: The order of the bytes is switched in the linear appearance to fix an alignment issue in the 1998 standard.
    ObjectAppearance::Decode(stream);
    stream >> m_linear_appearance_bits;
}

//////////////////////////////////////////////////////////////////////////

KDataStream LinearObjectAppearance::Encode() const
{
    KDataStream stream;

    LinearObjectAppearance::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void LinearObjectAppearance::Encode( KDataStream & stream ) const
{
    // First add the specific bytes and then the general.
    ObjectAppearance::Encode(stream);
    stream << m_linear_appearance_bits;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LinearObjectAppearance::operator == ( const LinearObjectAppearance & Value ) const
{
    return (m_linear_appearance_bits == Value.m_linear_appearance_bits)
            && ObjectAppearance::operator==(Value);
}

//////////////////////////////////////////////////////////////////////////

KBOOL LinearObjectAppearance::operator != ( const LinearObjectAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
