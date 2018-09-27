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

#include "./ArealObjectAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace std;
using namespace bits;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

ArealObjectAppearance::ArealObjectAppearance() :
        m_bits(0),
        m_mines(0)
{
}

//////////////////////////////////////////////////////////////////////////

ArealObjectAppearance::ArealObjectAppearance( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

ArealObjectAppearance::~ArealObjectAppearance()
{
}

//////////////////////////////////////////////////////////////////////////

void ArealObjectAppearance::SetBreach( Breach2bit B )
{
    setBits<2, 0>(m_bits, B);
}

//////////////////////////////////////////////////////////////////////////

Breach2bit ArealObjectAppearance::GetBreach() const
{
    return ( Breach2bit ) getUbits<2, 0>(m_bits);
}

//////////////////////////////////////////////////////////////////////////////

void ArealObjectAppearance::SetMineCount( KUINT16 M )
{
    m_mines = M;
}

//////////////////////////////////////////////////////////////////////////////

KUINT16 ArealObjectAppearance::GetMineCount() const
{
    return m_mines;
}

//////////////////////////////////////////////////////////////////////////

KString ArealObjectAppearance::GetAsString() const
{
    KStringStream ss;

    ss << ObjectAppearance::GetAsString()
       << "\tBreach: " << GetEnumAsStringBreach2bit( GetBreach() ) << "\n"
       << "\tMine Count: " << m_mines << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ArealObjectAppearance::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ArealObjectAppearance::AREAL_OBJECT_APPEARANCE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_mines >> m_bits;
    ObjectAppearance::Decode(stream);
}

//////////////////////////////////////////////////////////////////////////

KDataStream ArealObjectAppearance::Encode() const
{
    KDataStream stream;

    ArealObjectAppearance::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void ArealObjectAppearance::Encode( KDataStream & stream ) const
{
    // TODO need a unit test to make sure I did this right.
    // First add the specific bytes and then the general.
    stream << m_mines << m_bits;
    ObjectAppearance::Encode(stream);
}

//////////////////////////////////////////////////////////////////////////

KBOOL ArealObjectAppearance::operator == ( const ArealObjectAppearance & Value ) const
{
    return ((m_bits == Value.m_bits) && (m_mines == Value.m_mines)
            && ObjectAppearance::operator==(Value));
}

//////////////////////////////////////////////////////////////////////////

KBOOL ArealObjectAppearance::operator != ( const ArealObjectAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
