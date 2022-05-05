/*******************************************************************
*
*  DESCRIPTION: ControlEncendido
*
*  AUTHOR: Julio Kriger
*
*  EMAIL: mailto://jkriger@dc.uba.ar
*
*  DATE: 27/04/2002
*
*******************************************************************/

#include "ControlEncendido.h"
#include "message.h"

ControlEncendido::ControlEncendido( const string &name ) :
	Atomic( name )
	, m_inOn ( addInputPort( "TURN_ON" ) )
	, m_inOff( addInputPort( "TURN_OFF" ) )
	, m_outOn( addOutputPort( "CLOCK_ON" ))
	, m_outOff( addOutputPort( "CLOCK_OFF" ))
{
}

ControlEncendido::~ControlEncendido()
{
}

Model &ControlEncendido::initFunction()
{
	m_state = OFF;
	holdIn( Atomic::active, Time::Zero );
	return *this;
}

Model &ControlEncendido::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == m_inOn)
	{
		if( m_state == OFF )
		{
			m_state = ON;
			holdIn( Atomic::active, Time::Zero );
		}
	}
	else if( msg.port() == m_inOff)
	{
		if( m_state == ON )
		{
			m_state = OFF;
			holdIn( Atomic::active, Time::Zero );
		}
	}
	return *this;
}

Model &ControlEncendido::internalFunction( const InternalMessage &msg )
{
	passivate();
	return *this;
}

Model &ControlEncendido::outputFunction( const InternalMessage &msg )
{
	if( m_state == ON )
	{
		sendOutput( msg.time(), m_outOn, 1.0 );
	}
	else
	{
		if( m_state == OFF )
		{
			sendOutput( msg.time(), m_outOff, -1.0 );
		}
	}
	return *this;
}
