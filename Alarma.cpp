/*******************************************************************
*
*  DESCRIPTION: Alarma
*
*  AUTHOR: Julio Kriger
*
*  EMAIL: mailto://jkriger@dc.uba.ar
*
*  DATE: 27/04/2002
*
*******************************************************************/

#include "Alarma.h"
#include "message.h"

Alarma::Alarma( const string &name ) :
	Atomic( name )
	, m_inHour( addInputPort( "CLOCK_HOUR" ) )
	, m_inMin( addInputPort( "CLOCK_MIN" ) )
	, m_inAlarmHour( addInputPort( "ALARM_HOUR" ) )
	, m_inAlarmaMin( addInputPort( "ALARM_MIN" ) )
	, m_inActivate( addInputPort( "ACTIVATE" ) )
	, m_inDeactivate( addInputPort( "DEACTIVATE" ) )
	, m_outSound( addOutputPort( "SOUND_ALARM" ))
	, m_outAlarnOn( addOutputPort( "ALARM_ON" ))
	, m_outAlarmOff( addOutputPort( "ALARM_OFF" ))
{
}

Alarma::~Alarma()
{
}

Model &Alarma::initFunction()
{
	m_state = INACTIVE;
	m_hour = m_min = m_alarmHour = m_alarmMin = 0;
	m_bOutputState = 1;
	holdIn( Atomic::active, Time::Zero );
	return *this;
}

Model &Alarma::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == m_inHour )
	{
		m_hour = int(msg.value());
	}
	else if( msg.port() == m_inMin )
	{
		m_min = int(msg.value());
	}
	else if( msg.port() == m_inAlarmHour )
	{
		m_alarmHour = int(msg.value());
	}
	else if( msg.port() == m_inAlarmaMin )
	{
		m_alarmMin = int(msg.value());
	}

	if( msg.port() == m_inActivate )
	{
		if( m_state == INACTIVE )
		{
			m_bOutputState = 1;
			m_state = ACTIVE;
			holdIn( Atomic::active, Time::Zero );
		}
	}
	else if( msg.port() == m_inDeactivate )
	{
		if( m_state == ACTIVE )
		{
			m_bOutputState = 1;
			m_state = INACTIVE;
			holdIn( Atomic::active, Time::Zero );
		}
	}
	else
	{
		if( ( m_state == ACTIVE ) && ( m_hour == m_alarmHour ) && ( m_min == m_alarmMin ) )
		{
			holdIn( Atomic::active, Time::Zero );
		}
	}
	return *this;
}

Model &Alarma::internalFunction( const InternalMessage &msg )
{
	passivate();
	return *this;
}

Model &Alarma::outputFunction( const InternalMessage &msg )
{
	if( m_bOutputState )
	{
		m_bOutputState = 0;
		if( m_state == ACTIVE )
		{
			sendOutput( msg.time(), m_outAlarnOn, 0.0 );
		}
		else
		{
			if( m_state == INACTIVE )
			{
				sendOutput( msg.time(), m_outAlarmOff, 0.0 );
			}
		}
	}
	else
	{
		if( m_state == ACTIVE )
		{
			sendOutput( msg.time(), m_outSound, 0.0 );
		}
	}
	return *this;
}
