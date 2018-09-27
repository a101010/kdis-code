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

#include "./APA.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

APA::APA() :
    m_ui16ParamIndex( 0 ),
    m_i16Value( 0 )
{}

//////////////////////////////////////////////////////////////////////////

APA::APA( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

APA::APA( AdditionalPassiveParameterIndex APPI, KBOOL Val1, KBOOL Val2, KINT16 Value ) :
    m_ui16ParamIndex( 0 ),
    m_i16Value( Value )
{
	SetAPPI(APPI);
	SetStatus(Val1, Val2);
}

//////////////////////////////////////////////////////////////////////////

KString APA::GetAsString() const
{
    KStringStream ss;

    ss << "APA:"
       << "\n\tParam Index:  " << GetEnumAsStringAdditionalPassiveParameterIndex( GetAPPI() )
       << "\n\tStatus:       ( " << GetStatusVal1() << " , " << GetStatusVal2() << " )"
       << "\n\tValue:        " << m_i16Value
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void APA::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < APA_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16ParamIndex
           >> m_i16Value;
}

//////////////////////////////////////////////////////////////////////////

KDataStream APA::Encode() const
{
    KDataStream stream;

    APA::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void APA::Encode( KDataStream & stream ) const
{
    stream << m_ui16ParamIndex
           << m_i16Value;
}

//////////////////////////////////////////////////////////////////////////

KBOOL APA::operator == ( const APA & Value ) const
{
    if( m_ui16ParamIndex != Value.m_ui16ParamIndex ) return false;
    if( m_i16Value       != Value.m_i16Value )       return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL APA::operator != ( const APA & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

