/*******************************************************************
*
*  DESCRIPTION: AgujaHour
*
*  AUTHOR: Julio Kriger
*
*  EMAIL: mailto://jkriger@dc.uba.ar
*
*  DATE: 27/04/2002
*
*******************************************************************/

#include "AgujaHour.h"
#include "message.h"

AgujaHour::AgujaHour( const string &name ) :
	Atomic( name )
	, m_maxHours( 12 )
	, m_maxMins( 60 )
	, m_inInc( addInputPort( "INCREMENT" ) )
	, m_inDec( addInputPort( "DECREMENT" ) )
	, m_outValue( addOutputPort( "VALUE" ) )
{
}

AgujaHour::~AgujaHour()
{
}

Model &AgujaHour::initFunction()
{
	m_minCounter = 0;
	m_hourCounter = 1;
	holdIn( Atomic::active, Time::Zero );
	return *this;
}

Model &AgujaHour::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == m_inInc )
	{
		m_minCounter ++;
		if( m_minCounter >= m_maxMins )
		{
			m_minCounter = 0;
			m_hourCounter ++;
			if( m_hourCounter > m_maxHours )
			{
				m_hourCounter = 1;
			}
			holdIn( Atomic::active, Time::Zero );
		}
	}
	else if( msg.port() == m_inDec )
	{
		m_minCounter --;
		if( m_minCounter < 0 )
		{
			m_minCounter = m_maxMins - 1;
			m_hourCounter --;
			if( m_hourCounter <= 0 )
			{
				m_hourCounter = m_maxHours;
			}
			holdIn( Atomic::active, Time::Zero );
		}
	}
	return *this;
}

Model &AgujaHour::internalFunction( const InternalMessage &msg )
{
	passivate();
	return *this;
}

Model &AgujaHour::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), m_outValue, double( m_hourCounter ) );
	return *this;
}

