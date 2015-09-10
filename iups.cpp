#ifndef IUPS_C
#define IUPS_C

#include <cstdio>
#include <string>
#include "iups.hpp"

using std::string;

void IupSOpen(int* argc, char** argv[])
{
    IupOpen(argc, argv);                        /* opens the IUP lib (iup.lib comctl32.lib) */
    IupGLCanvasOpen();                          /* enable the use of OpenGL to draw in canvas (iupgl.lib opengl32.lib) */
}

string IupSelectFile(string title, string ext, string tip)
{
    Ihandle* getfile = IupFileDlg();
    string filename = NULL;

    IupSetAttribute(getfile, IUP_TITLE, title.c_str());
    IupSetAttribute(getfile, IUP_DIALOGTYPE, IUP_OPEN);
    IupSetAttribute(getfile, IUP_FILTER, ext.c_str());
    IupSetAttribute(getfile, IUP_FILTERINFO, tip.c_str());
    IupPopup(getfile, IUP_CENTER, IUP_CENTER);

    filename = IupGetAttribute(getfile, IUP_VALUE);
    return filename;
}

Ihandle* IupSDialog(string title, Ihandle* content, Icallback exit_cb, string resize)
{
    Ihandle* dialog = IupDialog(content);
    IupSetAttribute(dialog, "TITLE", title.c_str());
    IupSetAttribute(dialog, "CLOSE_CB", "exit_cb");
    IupSetAttribute(dialog, "RESIZE", resize.c_str());
    IupSetFunction("exit_cb", (Icallback) exit_cb);
    return dialog;
}


void IupCanvasResize(Ihandle* canvas, Ihandle* parent_dialog, int new_width, int new_height)
{
    char buffer[64];
    sprintf(buffer, "%dx%d", new_width, new_height);
    IupStoreAttribute(canvas, IUP_RASTERSIZE, buffer);
    IupSetAttribute(parent_dialog, IUP_RASTERSIZE, NULL);
    IupShowXY(parent_dialog, IUP_CENTER, IUP_CENTER);
}


Ihandle* IupSButton(string image_file, string tip, Icallback callback)
{
    Ihandle* button = IupButton(NULL, NULL);
    IupSetAttribute(button, "IMAGE", image_file.c_str());
    IupSetAttribute(button, "TIP", tip.c_str());
    IupSetCallback(button, "ACTION", callback);

    return button;
}

/* Create a IUP GL canvas */
Ihandle* IupSGLCanvas(int width, int height, Icallback repaint_cb, Icallback resize_cb)
{
    Ihandle* canvas = IupGLCanvas(NULL);        /* create a canvas  */
    IupSetfAttribute(canvas, IUP_RASTERSIZE, "%dx%d", width, height);  /* define the initial size in pixels */
    IupSetAttribute(canvas, IUP_BUFFER,
                    IUP_DOUBLE);      /* define that this OpenGL _canvas has double buffer (front and back) */
    /* bind callback actions with callback functions */
    IupSetCallback(canvas, "ACTION", repaint_cb);
    IupSetCallback(canvas, "RESIZE_CB", resize_cb);

    return canvas;
}


Ihandle* IupSMessageBar(string initial_message, int height)
{
    Ihandle* msgbar = IupLabel(initial_message.c_str());       /* label as a msg bar */
    IupSetfAttribute(msgbar, IUP_RASTERSIZE, "x%d", height);     /* define height in pixels */
    IupSetAttribute(msgbar, "EXPAND", "HORIZONTAL");

    return msgbar;
}

#endif
