#include <iup.h>        /* IUP functions*/
#include <iupgl.h>      /* IUP functions related to OpenGL (IupGLCanvasOpen,IupGLMakeCurrent and IupGLSwapBuffers) */


#ifdef WIN32
#include <windows.h>    /* includes only in MSWindows not in UNIX */
#endif


/* IupSimple open */
void IupSOpen(int* argc, char** argv[]);

/* File selection dialog */
char* IupSelectFile( char* dialog_title, char* file_extension, char* dialog_tip );

/* Create a IUP GL canvas */
Ihandle* IupSGLCanvas(int width, int height, Icallback repaint_cb, Icallback resize_cb);

/* Canvas resize */
void IupCanvasResize( Ihandle* canvas, Ihandle* parent_dialog, int new_width, int new_height ); 

/* Simple button */
Ihandle* IupSButton(char* image_file, char* tip, Icallback callback);

/* Message bar */
Ihandle* IupSMessageBar(char* initial_message, int height );

/* Simple dialog */
Ihandle* IupSDialog(char* title, Ihandle* content,  Icallback exit_cb, char* resize);