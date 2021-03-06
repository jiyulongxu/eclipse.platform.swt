/*******************************************************************************
 * Copyright (c) 2000, 2017 IBM Corporation and others.
 *
 * This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License 2.0
 * which accompanies this distribution, and is available at
 * https://www.eclipse.org/legal/epl-2.0/
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *    IBM Corporation - initial API and implementation
 *******************************************************************************/
package org.eclipse.swt.internal.cocoa;

public class NSPanel extends NSWindow {

public NSPanel() {
	super();
}

public NSPanel(long /*int*/ id) {
	super(id);
}

public NSPanel(id id) {
	super(id);
}

public void setBecomesKeyOnlyIfNeeded(boolean becomesKeyOnlyIfNeeded) {
	OS.objc_msgSend(this.id, OS.sel_setBecomesKeyOnlyIfNeeded_, becomesKeyOnlyIfNeeded);
}

public void setFloatingPanel(boolean floatingPanel) {
	OS.objc_msgSend(this.id, OS.sel_setFloatingPanel_, floatingPanel);
}

public void setWorksWhenModal(boolean worksWhenModal) {
	OS.objc_msgSend(this.id, OS.sel_setWorksWhenModal_, worksWhenModal);
}

public boolean worksWhenModal() {
	return OS.objc_msgSend_bool(this.id, OS.sel_worksWhenModal);
}

public static double /*float*/ minFrameWidthWithTitle(NSString aTitle, long /*int*/ aStyle) {
	return (double /*float*/)OS.objc_msgSend_fpret(OS.class_NSPanel, OS.sel_minFrameWidthWithTitle_styleMask_, aTitle != null ? aTitle.id : 0, aStyle);
}

public static long /*int*/ windowNumberAtPoint(NSPoint point, long /*int*/ windowNumber) {
	return OS.objc_msgSend(OS.class_NSPanel, OS.sel_windowNumberAtPoint_belowWindowWithWindowNumber_, point, windowNumber);
}

}
