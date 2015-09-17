#ifndef IUPS_H
#define IUPS_H

#include <iup/iup.h>        /* IUP functions*/
#include <iup/iupgl.h>      /* IUP functions related to OpenGL (IupGLCanvasOpen,IupGLMakeCurrent and IupGLSwapBuffers) */

#ifdef WIN32
#include <windows.h>    /* includes only in MSWindows not in UNIX */
#endif


namespace iups
{


/* IupSimple open */
    void IupSOpen(int* argc, char** argv[]);

/* File selection dialog */
    const char* IupSelectFile(const char* dialog_title, const char* file_extension, const char* dialog_tip);

/* Create a IUP GL canvas */
    Ihandle* IupSGLCanvas(int width, int height, Icallback repaint_cb, Icallback resize_cb);

/* Canvas resize */
    void IupCanvasResize(Ihandle* canvas, Ihandle* parent_dialog, int new_width, int new_height);

/* Simple button */
    Ihandle* IupSButton(const char* image_file, const char* tip, Icallback callback);

/* Message bar */
    Ihandle* IupSMessageBar(const char* initial_message, int height);

/* Simple dialog */
    Ihandle* IupSDialog(const char* title, Ihandle* content, Icallback exit_cb, const char* resize);

}
#endif