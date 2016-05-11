//
// Created by Ben on 6/05/2016.
//

#include "GFMCPPro_7Seg.h"

#include <string.h>

#include "Windows_snprintf.h"


GFMCPPro_7Seg::GFMCPPro_7Seg( GFMCPPro_State* state ){

	_handle = 0;

	_mcp_state = state;

}



void GFMCPPro_7Seg::write(){

	if( 1 == _mcp_state->_dref_mcp_light_test->_int_value ){
		_write_light_test();
	}else{
		if( 1 == _mcp_state->_dref_mcp_override->_int_value ){
			_write_override_state();
		}else{
			_write_auto_state();
		}
	}

}



//write dataref state to 7 seg LED's
void GFMCPPro_7Seg::_write_override_state(){

	// Override Mode.
	// Reads back bytes from dataref contents and pushes them to the 7seg displays.

	//CRS Left
	GFUtils::set3f(
			_handle,
			GFMCPPro_7Seg::_usb_report_crs_left,
			_mcp_state->_dref_crs_left->_blob
	);


	//IAS Mach
	GFUtils::set5f(
			_handle,
			GFMCPPro_7Seg::_usb_report_ias,
			_mcp_state->_dref_ias_mach->_blob
	);


	//Heading
	GFUtils::set3f(
			_handle,
			GFMCPPro_7Seg::_usb_report_hdg,
			_mcp_state->_dref_heading->_blob
	);


	//Altitude
	GFUtils::set5f(
			_handle,
			GFMCPPro_7Seg::_usb_report_alt,
			_mcp_state->_dref_altitude->_blob
	);


	//Vert Speed
	GFUtils::set5f(
			_handle,
			GFMCPPro_7Seg::_usb_report_vs,
			_mcp_state->_dref_vert_speed->_blob
	);


	//CRS Right
	GFUtils::set3f(
			_handle,
			GFMCPPro_7Seg::_usb_report_crs_right,
			_mcp_state->_dref_crs_right->_blob
	);

}


//write managed state to 7 seg LED's
void GFMCPPro_7Seg::_write_auto_state(){

	unsigned char caTmp[16];

	//CRS Left
	snprintf( (char*)caTmp, 16, "%03i", _mcp_state->_dref_crs_left->_int_value );
	GFUtils::set3f(
			_handle,
			GFMCPPro_7Seg::_usb_report_crs_left,
			caTmp
	);


	//IAS Mach
	snprintf( (char*)caTmp, 16, "%05i", _mcp_state->_dref_ias_mach->_int_value );
	GFUtils::set5f(
			_handle,
			GFMCPPro_7Seg::_usb_report_ias,
			caTmp
	);


	//Heading
	snprintf( (char*)caTmp, 16, "%03i", _mcp_state->_dref_heading->_int_value );
	GFUtils::set3f(
			_handle,
			GFMCPPro_7Seg::_usb_report_hdg,
			caTmp
	);


	//Altitude
	snprintf( (char*)caTmp, 16, "%05i", _mcp_state->_dref_altitude->_int_value );
	GFUtils::set5f(
			_handle,
			GFMCPPro_7Seg::_usb_report_alt,
			caTmp
	);


	//Vert Speed
	snprintf( (char*)caTmp, 16, "%05i", _mcp_state->_dref_vert_speed->_int_value );
	GFUtils::set5f(
			_handle,
			GFMCPPro_7Seg::_usb_report_vs,
			caTmp
	);


	//CRS Right
	snprintf( (char*)caTmp, 16, "%03i", _mcp_state->_dref_crs_right->_int_value );
	GFUtils::set3f(
			_handle,
			GFMCPPro_7Seg::_usb_report_crs_right,
			caTmp
	);

}


//write light test data to 7 seg LED's
void GFMCPPro_7Seg::_write_light_test(){

	unsigned char caTmp[16];

	//write a full set of 8's to the display buffer.
	snprintf( (char*)caTmp, 16, "88888" );

	//CRS Left
	GFUtils::set3f(
			_handle,
			GFMCPPro_7Seg::_usb_report_crs_left,
			caTmp
	);


	//IAS Mach
	GFUtils::set5f(
			_handle,
			GFMCPPro_7Seg::_usb_report_ias,
			caTmp
	);


	//Heading
	GFUtils::set3f(
			_handle,
			GFMCPPro_7Seg::_usb_report_hdg,
			caTmp
	);


	//Altitude
	GFUtils::set5f(
			_handle,
			GFMCPPro_7Seg::_usb_report_alt,
			caTmp
	);


	//Vert Speed
	GFUtils::set5f(
			_handle,
			GFMCPPro_7Seg::_usb_report_vs,
			caTmp
	);


	//CRS Right
	GFUtils::set3f(
			_handle,
			GFMCPPro_7Seg::_usb_report_crs_right,
			caTmp
	);

}