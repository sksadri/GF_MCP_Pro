//
// Created by Ben on 5/05/2016.
//

#ifndef GF_MCP_PRO_XPLGLUE_H
#define GF_MCP_PRO_XPLGLUE_H


#include <XPLMDefs.h>
#include <XPLMUtilities.h>


class XPLGlue {

};





//Standard X-Plane plugin function hooks.
PLUGIN_API int XPluginStart(
        char *		outName,
        char *		outSig,
        char *		outDesc);

PLUGIN_API void XPluginStop(void);

PLUGIN_API int XPluginEnable(void);

PLUGIN_API void XPluginDisable(void);

PLUGIN_API void XPluginReceiveMessage(
        XPLMPluginID   inFromWho,
        intptr_t        inMessage,
        void *      inParam);




// FLCB
extern float GFMCPPro_flcb(
        float                inElapsedSinceLastCall,
        float                inElapsedTimeSinceLastFlightLoop,
        int                  inCounter,
        void *               inRefcon);


extern int GFMCPPro_cmdHandler(    XPLMCommandRef        inCommand,
                            XPLMCommandPhase     inPhase,
                            void *               inRefcon);


extern void GFMCPPro_menuHandler(
		void *               inMenuRef,
		void *               inItemRef);


#endif //GF_MCP_PRO_XPLGLUE_H
