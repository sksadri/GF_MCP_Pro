//
// Created by Ben on 5/05/2016.
//

#include "GFCommand.h"

#include "XPLGlue.h"

#include "GFUtils.h"

#include "Windows_snprintf.h"


GFCommand::GFCommand( const std::string cmd_name, const std::string cmd_description, void* button_router ) {

	char caTmp[1024];
	snprintf( caTmp, 1024, " cmd:(%s)\n", cmd_name.c_str() );
	GFUtils::Log( caTmp );

	_button_router = button_router;

	_is_multi_phase = 0;

    _name = cmd_name;
    //_description = cmd_description;

    _xpcmd = XPLMCreateCommand( cmd_name.c_str(), cmd_description.c_str() );


    XPLMRegisterCommandHandler( _xpcmd,              // in Command name
                                GFMCPPro_cmdHandler,       // in Handler
                                1,                      // Receive input before plugin windows.
                                (void *)this
								);

}


void GFCommand::Begin() {
    XPLMCommandBegin( _xpcmd );
    _cmd_active = 1;
}


void GFCommand::Stop() {
    if( _cmd_active ) {
        XPLMCommandEnd( _xpcmd );
        _cmd_active = 0;
    }
}









GFCommand_Switch::GFCommand_Switch( const std::string cmd_name, const std::string cmd_description, void* _button_router )
		: GFCommand( cmd_name, cmd_description, _button_router ){

	GFUtils::Log("\t\tGFCommand_Switch: Requesting multi phase..\n");

	_last_switch_state = 0;

	_is_multi_phase = 1;

};


void GFCommand_Switch::Begin(){

	//check to see if the switch state was already HIGH
	if( 1 == _last_switch_state ){
		//do nothing

	}else{
		//trigger... switch state has changed, edge detected..
		XPLMCommandBegin( _xpcmd );
		_cmd_active = 1;
		_last_switch_state = 1;

	}

}


void GFCommand_Switch::Stop(){

	if( 1 == _last_switch_state ){
		//trigger... switch state has changed, edge detected.
		//do stuff to end task.

		if( _cmd_active ) {
			XPLMCommandEnd( _xpcmd );
			_cmd_active = 0;
			_last_switch_state = 0;
		}

	}else{
		//do nothing
	}

}




// eof
