/*******************************************************************
*
*  DESCRIPTION: Pendulo
*
*  AUTHOR: Julio Kriger
*
*  EMAIL: mailto://jkriger@dc.uba.ar
*
*  DATE: 27/04/2002
*
*******************************************************************/

#include "Pendulo.h"
#include "message.h"

Pendulo::Pendulo( const string &name ) :
	Atomic( name )
	, m_inTurnOn( addInputPort( "TURN_ON" ) )
	, m_inTurnOff( addInputPort( "TURN_OFF" ) )
	, m_outTic( addOutputPort( "TIC" ) )
{
}

Pendulo::~Pendulo()
{
}

Model &Pendulo::initFunction()
{
	m_aSecond.seconds( 1 );
	m_state = OFF;
	return *this;
}

Model &Pendulo::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == m_inTurnOn )
	{
		if( m_state == OFF )
		{
			m_state = RIGHT;
			holdIn( Atomic::active, m_aSecond );
		}
	}
	else if( msg.port() == m_inTurnOff )
	{
		if( m_state != OFF )
		{
			m_state = OFF;
			passivate();
		}
	}
	return *this;
}

Model &Pendulo::internalFunction( const InternalMessage &msg )
{
	if( m_state == RIGHT )
	{
		m_state = LEFT;
		holdIn( Atomic::active, m_aSecond );
	}
	else
	{
		if( m_state == LEFT )
		{
			m_state = RIGHT;
			holdIn( Atomic::active, m_aSecond );
		}
	}
	return *this;
}

Model &Pendulo::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), m_outTic, 0.0 );
	return *this;
}
