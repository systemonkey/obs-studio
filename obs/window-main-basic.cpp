/******************************************************************************
    Copyright (C) 2013 by Hugh Bailey <obs.jim@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#include "obs-app.hpp"
#include "window-main-basic.hpp"

void OBSBasic::OnClose(wxCloseEvent& event)
{
	wxGetApp().ExitMainLoop();
	event.Skip();
}

void OBSBasic::OnMinimize(wxIconizeEvent& event)
{
	event.Skip();
}

void OBSBasic::OnSize(wxSizeEvent& event)
{
	struct obs_video_info ovi;

	event.Skip();

	if (!obs_get_video_info(&ovi))
		return;

	/* resize preview panel to fix to the top section of the window */
	wxSize targetSize   = GetPreviewContainer()->GetSize();
	double targetAspect = double(targetSize.x) / double(targetSize.y);
	double baseAspect   = double(ovi.base_width) / double(ovi.base_height);

	if (targetAspect > baseAspect)
		GetPreviewPanel()->SetMinSize(wxSize(targetSize.y * baseAspect,
				targetSize.y));
	else
		GetPreviewPanel()->SetMinSize(wxSize(targetSize.x,
				targetSize.x / baseAspect));
}

void OBSBasic::file_newOnMenuSelection(wxCommandEvent& event)
{
}

void OBSBasic::file_openOnMenuSelection(wxCommandEvent& event)
{
}

void OBSBasic::file_saveOnMenuSelection(wxCommandEvent& event)
{
}

void OBSBasic::file_exitOnMenuSelection(wxCommandEvent& event)
{
}

void OBSBasic::scenesOnRightDown(wxMouseEvent& event)
{
}

void OBSBasic::sceneAddOnToolClicked(wxCommandEvent& event)
{
}

void OBSBasic::sceneRemoveOnToolClicked(wxCommandEvent& event)
{
}

void OBSBasic::scenePropertiesOnToolClicked(wxCommandEvent& event)
{
}

void OBSBasic::sceneUpOnToolClicked(wxCommandEvent& event)
{
}

void OBSBasic::sceneDownOnToolClicked(wxCommandEvent& event)
{
}

void OBSBasic::sourcesOnRightDown(wxMouseEvent& event)
{
}

void OBSBasic::sourceAddOnToolClicked(wxCommandEvent& event)
{
}

void OBSBasic::sourceRemoveOnToolClicked(wxCommandEvent& event)
{
}

void OBSBasic::sourcePropertiesOnToolClicked(wxCommandEvent& event)
{
}

void OBSBasic::sourceUpOnToolClicked(wxCommandEvent& event)
{
}

void OBSBasic::sourceDownOnToolClicked(wxCommandEvent& event)
{
}