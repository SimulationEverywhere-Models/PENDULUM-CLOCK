/*******************************************************************
*
*  DESCRIPTION: AgujaMin
*
*  AUTHOR: Julio Kriger
*
*  EMAIL: mailto://jkriger@dc.uba.ar
*
*  DATE: 27/04/2002
*
*******************************************************************/

#include "AgujaMin.h"
#include "message.h"

AgujaMin::AgujaMin( const string &name ) :
	Atomic( name )
	, m_maxMins( 60 )
	, m_maxTics( 60 )
	, m_inInc( addInputPort( "IN_INCREMENT" ) )
	, m_inDec( addInputPort( "IN_DECREMENT" ) )
	, m_inTic( addInputPort( "TIC" ) )
	, m_outInc( addOutputPort( "OUT_INCREMENT" ) )
	, m_outDec( addOutputPort( "OUT_DECREMENT" ) )
	, m_outValue( addOutputPort( "VALUE" ) )
{
}

AgujaMin::~AgujaMin()
{
}

Model &AgujaMin::initFunction()
{
	m_minCounter = 0;
	m_ticCounter = 0;
	holdIn( Atomic::active, Time::Zero );
	return *this;
}

Model &AgujaMin::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == m_inTic )
	{
		m_ticCounter ++;
		if( m_ticCounter >= m_maxTics )
		{
			m_ticCounter = 0;
			m_minCounter ++;
			m_outEvent = INC;
			if( m_minCounter >= m_maxMins )
			{
				m_minCounter = 0;
			}
			holdIn( Atomic::active, Time::Zero );
		}
	}
	else
	{
		if( msg.port() == m_inInc )
		{
			m_minCounter ++;
			m_outEvent = INC;
			if( m_minCounter >= m_maxMins )
			{
				m_minCounter = 0;
			}
			holdIn( Atomic::active, Time::Zero );
		}
		else
		{
			if( msg.port() == m_inDec )
			{
				m_minCounter --;
				m_outEvent = DEC;
				if( m_minCounter < 0 )
				{
					m_minCounter = m_maxMins - 1;
				}
				holdIn( Atomic::active, Time::Zero );
			}
		}
	}
	return *this;
}

Model &AgujaMin::internalFunction( const InternalMessage &msg )
{
	passivate();
	return *this;
}

Model &AgujaMin::outputFunction( const InternalMessage &msg )
{
	if( m_outEvent == INC )
	{
		sendOutput( msg.time(), m_outInc, 1.0 );
	}
	else if( m_outEvent == DEC )
	{
		sendOutput( msg.time(), m_outDec, -1.0 );
	}
	sendOutput( msg.time(), m_outValue, double( m_minCounter ) );
	return *this;
}

