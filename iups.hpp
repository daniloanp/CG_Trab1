#ifndef IUPS_H
#define IUPS_H
#include <string>

#include <iup/iup.h>        /* IUP functions*/
#include <iup/iupgl.h>      /* IUP functions related to OpenGL (IupGLCanvasOpen,IupGLMakeCurrent and IupGLSwapBuffers) */

#ifdef WIN32
#include <windows.h>    /* includes only in MSWindows not in UNIX */
#endif

using std::string;

/* IupSimple open */
void IupSOpen(int* argc, char** argv[]);

/* File selection dialog */
string IupSelectFile( string dialog_title, string file_extension, string dialog_tip );

/* Create a IUP GL canvas */
Ihandle* IupSGLCanvas(int width, int height, Icallback repaint_cb, Icallback resize_cb);

/* Canvas resize */
void IupCanvasResize( Ihandle* canvas, Ihandle* parent_dialog, int new_width, int new_height ); 

/* Simple button */
Ihandle* IupSButton(string image_file, string tip, Icallback callback);

/* Message bar */
Ihandle* IupSMessageBar(string initial_message, int height );

/* Simple dialog */
Ihandle* IupSDialog(string title, Ihandle* content,  Icallback exit_cb, string resize);


#endif