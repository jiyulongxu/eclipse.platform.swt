/*******************************************************************************
* Copyright (c) 2000, 2004 IBM Corporation and others.
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Common Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/cpl-v10.html
* 
* Contributors:
*     IBM Corporation - initial API and implementation
*******************************************************************************/

#include "swt.h"
#include "os_stats.h"

#ifdef NATIVE_STATS

int OS_nativeFunctionCount = 438;
int OS_nativeFunctionCallCount[438];
char * OS_nativeFunctionNames[] = {
	"CODESET", 
	"Call", 
	"ConnectionNumber", 
	"FD_1ISSET", 
	"FD_1SET", 
	"FD_1ZERO", 
	"LC_1CTYPE", 
	"MB_1CUR_1MAX", 
	"MonitorEnter", 
	"MonitorExit", 
	"XAllocColor", 
	"XBell", 
	"XBlackPixel", 
	"XChangeActivePointerGrab", 
	"XChangeProperty", 
	"XChangeWindowAttributes", 
	"XCheckIfEvent", 
	"XCheckMaskEvent", 
	"XCheckWindowEvent", 
	"XClearArea", 
	"XClipBox", 
	"XCloseDisplay", 
	"XCopyArea", 
	"XCopyPlane", 
	"XCreateBitmapFromData", 
	"XCreateFontCursor", 
	"XCreateGC", 
	"XCreateImage", 
	"XCreatePixmap", 
	"XCreatePixmapCursor", 
	"XCreateRegion", 
	"XCreateWindow", 
	"XDefaultColormap", 
	"XDefaultColormapOfScreen", 
	"XDefaultDepthOfScreen", 
	"XDefaultGCOfScreen", 
	"XDefaultRootWindow", 
	"XDefaultScreen", 
	"XDefaultScreenOfDisplay", 
	"XDefaultVisual", 
	"XDefineCursor", 
	"XDestroyImage", 
	"XDestroyRegion", 
	"XDestroyWindow", 
	"XDisplayHeight", 
	"XDisplayHeightMM", 
	"XDisplayWidth", 
	"XDisplayWidthMM", 
	"XDrawArc", 
	"XDrawLine", 
	"XDrawLines", 
	"XDrawPoint", 
	"XDrawRectangle", 
	"XEmptyRegion", 
	"XEventsQueued", 
	"XFillArc", 
	"XFillPolygon", 
	"XFillRectangle", 
	"XFilterEvent", 
	"XFlush", 
	"XFontsOfFontSet", 
	"XFree", 
	"XFreeColors", 
	"XFreeCursor", 
	"XFreeFont", 
	"XFreeFontNames", 
	"XFreeGC", 
	"XFreePixmap", 
	"XFreeStringList", 
	"XGetGCValues", 
	"XGetGeometry", 
	"XGetIconSizes", 
	"XGetImage", 
	"XGetInputFocus", 
	"XGetModifierMapping", 
	"XGetWindowAttributes", 
	"XGetWindowProperty", 
	"XGrabKeyboard", 
	"XGrabPointer", 
	"XInitThreads", 
	"XInternAtom", 
	"XIntersectRegion", 
	"XKeysymToKeycode", 
	"XKeysymToString", 
	"XListFonts", 
	"XListProperties", 
	"XLocaleOfFontSet", 
	"XLookupString", 
	"XLowerWindow", 
	"XMapWindow", 
	"XMoveResizeWindow", 
	"XOpenDisplay", 
	"XPointInRegion", 
	"XPolygonRegion", 
	"XPutImage", 
	"XQueryBestCursor", 
	"XQueryColor", 
	"XQueryPointer", 
	"XQueryTree", 
	"XRaiseWindow", 
	"XReconfigureWMWindow", 
	"XRectInRegion", 
	"XReparentWindow", 
	"XResizeWindow", 
	"XRootWindowOfScreen", 
	"XSelectInput", 
	"XSendEvent", 
	"XSetBackground", 
	"XSetClipMask", 
	"XSetClipRectangles", 
	"XSetDashes", 
	"XSetErrorHandler", 
	"XSetFillStyle", 
	"XSetForeground", 
	"XSetFunction", 
	"XSetGraphicsExposures", 
	"XSetIOErrorHandler", 
	"XSetInputFocus", 
	"XSetLineAttributes", 
	"XSetRegion", 
	"XSetStipple", 
	"XSetSubwindowMode", 
	"XSetWMNormalHints", 
	"XShapeCombineMask", 
	"XShapeCombineRegion", 
	"XSubtractRegion", 
	"XSync", 
	"XSynchronize", 
	"XTestFakeButtonEvent", 
	"XTestFakeKeyEvent", 
	"XTestFakeMotionEvent", 
	"XTranslateCoordinates", 
	"XUndefineCursor", 
	"XUngrabKeyboard", 
	"XUngrabPointer", 
	"XUnionRectWithRegion", 
	"XUnionRegion", 
	"XUnmapWindow", 
	"XWarpPointer", 
	"XWhitePixel", 
	"XWithdrawWindow", 
	"XineramaIsActive", 
	"XineramaQueryScreens", 
	"XmAddWMProtocolCallback", 
	"XmChangeColor", 
	"XmClipboardCopy", 
	"XmClipboardEndCopy", 
	"XmClipboardEndRetrieve", 
	"XmClipboardInquireCount", 
	"XmClipboardInquireFormat", 
	"XmClipboardInquireLength", 
	"XmClipboardRetrieve", 
	"XmClipboardStartCopy", 
	"XmClipboardStartRetrieve", 
	"XmComboBoxAddItem", 
	"XmComboBoxDeletePos", 
	"XmComboBoxSelectItem", 
	"XmCreateArrowButton", 
	"XmCreateCascadeButtonGadget", 
	"XmCreateComboBox", 
	"XmCreateDialogShell", 
	"XmCreateDrawingArea", 
	"XmCreateDrawnButton", 
	"XmCreateErrorDialog", 
	"XmCreateFileSelectionDialog", 
	"XmCreateForm", 
	"XmCreateFrame", 
	"XmCreateInformationDialog", 
	"XmCreateLabel", 
	"XmCreateList", 
	"XmCreateMainWindow", 
	"XmCreateMenuBar", 
	"XmCreateMessageDialog", 
	"XmCreatePopupMenu", 
	"XmCreatePulldownMenu", 
	"XmCreatePushButton", 
	"XmCreatePushButtonGadget", 
	"XmCreateQuestionDialog", 
	"XmCreateScale", 
	"XmCreateScrollBar", 
	"XmCreateScrolledList", 
	"XmCreateScrolledText", 
	"XmCreateSeparator", 
	"XmCreateSeparatorGadget", 
	"XmCreateTextField", 
	"XmCreateToggleButton", 
	"XmCreateToggleButtonGadget", 
	"XmCreateWarningDialog", 
	"XmCreateWorkingDialog", 
	"XmDestroyPixmap", 
	"XmDragCancel", 
	"XmDragStart", 
	"XmDropSiteRegister", 
	"XmDropSiteUnregister", 
	"XmDropSiteUpdate", 
	"XmDropTransferAdd", 
	"XmDropTransferStart", 
	"XmFileSelectionBoxGetChild", 
	"XmFontListAppendEntry", 
	"XmFontListCopy", 
	"XmFontListEntryFree", 
	"XmFontListEntryGetFont", 
	"XmFontListEntryLoad", 
	"XmFontListFree", 
	"XmFontListFreeFontContext", 
	"XmFontListInitFontContext", 
	"XmFontListNextEntry", 
	"XmGetAtomName", 
	"XmGetDragContext", 
	"XmGetFocusWidget", 
	"XmGetPixmap", 
	"XmGetPixmapByDepth", 
	"XmGetXmDisplay", 
	"XmImMbLookupString", 
	"XmImRegister", 
	"XmImSetFocusValues", 
	"XmImSetValues", 
	"XmImUnregister", 
	"XmImUnsetFocus", 
	"XmInternAtom", 
	"XmListAddItemUnselected", 
	"XmListDeleteAllItems", 
	"XmListDeleteItemsPos", 
	"XmListDeletePos", 
	"XmListDeletePositions", 
	"XmListDeselectAllItems", 
	"XmListDeselectPos", 
	"XmListGetKbdItemPos", 
	"XmListGetSelectedPos", 
	"XmListItemPos", 
	"XmListPosSelected", 
	"XmListReplaceItemsPosUnselected", 
	"XmListSelectPos", 
	"XmListSetKbdItemPos", 
	"XmListSetPos", 
	"XmListUpdateSelectedList", 
	"XmMainWindowSetAreas", 
	"XmMessageBoxGetChild", 
	"XmParseMappingCreate", 
	"XmParseMappingFree", 
	"XmProcessTraversal", 
	"XmRenderTableAddRenditions", 
	"XmRenderTableFree", 
	"XmRenditionCreate", 
	"XmRenditionFree", 
	"XmStringBaseline", 
	"XmStringCompare", 
	"XmStringComponentCreate", 
	"XmStringConcat", 
	"XmStringCreate", 
	"XmStringCreateLocalized", 
	"XmStringDraw", 
	"XmStringDrawImage", 
	"XmStringDrawUnderline", 
	"XmStringEmpty", 
	"XmStringExtent", 
	"XmStringFree", 
	"XmStringGenerate", 
	"XmStringHeight", 
	"XmStringParseText", 
	"XmStringUnparse", 
	"XmStringWidth", 
	"XmTabCreate", 
	"XmTabFree", 
	"XmTabListFree", 
	"XmTabListInsertTabs", 
	"XmTextClearSelection", 
	"XmTextCopy", 
	"XmTextCut", 
	"XmTextDisableRedisplay", 
	"XmTextEnableRedisplay", 
	"XmTextFieldPaste", 
	"XmTextGetInsertionPosition", 
	"XmTextGetLastPosition", 
	"XmTextGetMaxLength", 
	"XmTextGetSelection", 
	"XmTextGetSelectionPosition", 
	"XmTextGetString", 
	"XmTextGetSubstring", 
	"XmTextGetSubstringWcs", 
	"XmTextInsert", 
	"XmTextPaste", 
	"XmTextPosToXY", 
	"XmTextReplace", 
	"XmTextScroll", 
	"XmTextSetEditable", 
	"XmTextSetHighlight", 
	"XmTextSetInsertionPosition", 
	"XmTextSetMaxLength", 
	"XmTextSetSelection", 
	"XmTextSetString", 
	"XmTextShowPosition", 
	"XmUpdateDisplay", 
	"XmWidgetGetDisplayRect", 
	"XmbTextListToTextProperty", 
	"XmbTextPropertyToTextList", 
	"XpCancelJob", 
	"XpCreateContext", 
	"XpDestroyContext", 
	"XpEndJob", 
	"XpEndPage", 
	"XpFreePrinterList", 
	"XpGetOneAttribute", 
	"XpGetPageDimensions", 
	"XpGetPrinterList", 
	"XpGetScreenOfContext", 
	"XpSetAttributes", 
	"XpSetContext", 
	"XpStartJob", 
	"XpStartPage", 
	"XtAddCallback", 
	"XtAddEventHandler", 
	"XtAddExposureToRegion", 
	"XtAppAddInput", 
	"XtAppAddTimeOut", 
	"XtAppCreateShell", 
	"XtAppGetSelectionTimeout", 
	"XtAppNextEvent", 
	"XtAppPeekEvent", 
	"XtAppPending", 
	"XtAppProcessEvent", 
	"XtAppSetErrorHandler", 
	"XtAppSetFallbackResources", 
	"XtAppSetSelectionTimeout", 
	"XtAppSetWarningHandler", 
	"XtBuildEventMask", 
	"XtCallActionProc", 
	"XtClass", 
	"XtConfigureWidget", 
	"XtCreateApplicationContext", 
	"XtCreatePopupShell", 
	"XtDestroyApplicationContext", 
	"XtDestroyWidget", 
	"XtDispatchEvent", 
	"XtDisplay", 
	"XtDisplayToApplicationContext", 
	"XtFree", 
	"XtGetMultiClickTime", 
	"XtGetValues", 
	"XtInsertEventHandler", 
	"XtIsManaged", 
	"XtIsRealized", 
	"XtIsSubclass", 
	"XtIsTopLevelShell", 
	"XtLastTimestampProcessed", 
	"XtMalloc", 
	"XtManageChild", 
	"XtMapWidget", 
	"XtMoveWidget", 
	"XtNameToWidget", 
	"XtOpenDisplay", 
	"XtOverrideTranslations", 
	"XtParent", 
	"XtParseTranslationTable", 
	"XtPopdown", 
	"XtPopup", 
	"XtQueryGeometry", 
	"XtRealizeWidget", 
	"XtRegisterDrawable", 
	"XtRemoveEventHandler", 
	"XtRemoveInput", 
	"XtRemoveTimeOut", 
	"XtResizeWidget", 
	"XtResizeWindow", 
	"XtSetLanguageProc", 
	"XtSetMappedWhenManaged", 
	"XtSetValues", 
	"XtToolkitInitialize", 
	"XtToolkitThreadInitialize", 
	"XtTranslateCoords", 
	"XtUnmanageChild", 
	"XtUnmapWidget", 
	"XtUnregisterDrawable", 
	"XtWindow", 
	"XtWindowToWidget", 
	"_1XmSetMenuTraversal", 
	"close", 
	"fd_1set_1sizeof", 
	"getenv", 
	"iconv", 
	"iconv_1close", 
	"iconv_1open", 
	"memmove__ILorg_eclipse_swt_internal_motif_XButtonEvent_2I", 
	"memmove__ILorg_eclipse_swt_internal_motif_XClientMessageEvent_2I", 
	"memmove__ILorg_eclipse_swt_internal_motif_XConfigureEvent_2I", 
	"memmove__ILorg_eclipse_swt_internal_motif_XExposeEvent_2I", 
	"memmove__ILorg_eclipse_swt_internal_motif_XImage_2I", 
	"memmove__ILorg_eclipse_swt_internal_motif_XKeyEvent_2I", 
	"memmove__ILorg_eclipse_swt_internal_motif_XmDragProcCallbackStruct_2I", 
	"memmove__ILorg_eclipse_swt_internal_motif_XmTextBlockRec_2I", 
	"memmove__ILorg_eclipse_swt_internal_motif_XmTextVerifyCallbackStruct_2I", 
	"memmove__I_3BI", 
	"memmove__I_3CI", 
	"memmove__I_3II", 
	"memmove__I_3SI", 
	"memmove__Lorg_eclipse_swt_internal_motif_Visual_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XAnyEvent_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XButtonEvent_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XCharStruct_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XClientMessageEvent_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XConfigureEvent_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XCreateWindowEvent_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XCrossingEvent_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XDestroyWindowEvent_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XEvent_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XExposeEvent_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XFocusChangeEvent_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XFontStruct_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XIconSize_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XImage_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XKeyEvent_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XModifierKeymap_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XMotionEvent_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XPropertyEvent_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XReparentEvent_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XineramaScreenInfo_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XmAnyCallbackStruct_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XmDragProcCallbackStruct_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XmDropFinishCallbackStruct_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XmDropProcCallbackStruct_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XmTextBlockRec_2II", 
	"memmove__Lorg_eclipse_swt_internal_motif_XmTextVerifyCallbackStruct_2II", 
	"memmove___3BII", 
	"memmove___3CII", 
	"memmove___3III", 
	"nl_1langinfo", 
	"overrideShellWidgetClass", 
	"pipe", 
	"read", 
	"select", 
	"setResourceMem", 
	"setlocale", 
	"shellWidgetClass", 
	"strlen", 
	"topLevelShellWidgetClass", 
	"transientShellWidgetClass", 
	"write", 
	"xmMenuShellWidgetClass", 
};

#define STATS_NATIVE(func) Java_org_eclipse_swt_tools_internal_NativeStats_##func

JNIEXPORT jint JNICALL STATS_NATIVE(OS_1GetFunctionCount)
	(JNIEnv *env, jclass that)
{
	return OS_nativeFunctionCount;
}

JNIEXPORT jstring JNICALL STATS_NATIVE(OS_1GetFunctionName)
	(JNIEnv *env, jclass that, jint index)
{
	return (*env)->NewStringUTF(env, OS_nativeFunctionNames[index]);
}

JNIEXPORT jint JNICALL STATS_NATIVE(OS_1GetFunctionCallCount)
	(JNIEnv *env, jclass that, jint index)
{
	return OS_nativeFunctionCallCount[index];
}

#endif
