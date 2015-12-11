/*
	ClassSelection.inc
	
    Copyright (C) <2015>  <Adam Walker (FreAkeD) @ SA-MP Forums>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#if defined _included_ClassSelection
	#endinput
#endif

#define _included_ClassSelection

// NATIVES

/*
	native ShowClassTextdraw(playerid, teamcolor, teamname[], teaminfo[]);
	native HideClassTextdraw(playerid);
*/

// TEXTDRAWS

static PlayerText:TeamName[MAX_PLAYERS];
static PlayerText:InfoHead[MAX_PLAYERS];
static PlayerText:ClassInfo[MAX_PLAYERS];

// CALLBACKS

public OnPlayerConnect(playerid)
{
	TeamName[playerid] = CreatePlayerTextDraw(playerid, 321, 125, "_");
	PlayerTextDrawLetterSize(playerid, TeamName[playerid], 0.699998, 2.576888);
	PlayerTextDrawAlignment(playerid, TeamName[playerid], 2);
	PlayerTextDrawColor(playerid, TeamName[playerid], -1);
	PlayerTextDrawSetShadow(playerid, TeamName[playerid], 0);
	PlayerTextDrawSetOutline(playerid, TeamName[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, TeamName[playerid], 255);
	PlayerTextDrawFont(playerid, TeamName[playerid], 3);
	PlayerTextDrawSetProportional(playerid, TeamName[playerid], 1);

	InfoHead[playerid] = CreatePlayerTextDraw(playerid, 320, 298, "Class Information");
	PlayerTextDrawLetterSize(playerid, InfoHead[playerid], 0.376998, 1.699555);
	PlayerTextDrawTextSize(playerid, InfoHead[playerid], 866.000000, 336.622436);
	PlayerTextDrawAlignment(playerid, InfoHead[playerid], 2);
	PlayerTextDrawColor(playerid, InfoHead[playerid], -1);
	PlayerTextDrawUseBox(playerid, InfoHead[playerid], true);
	PlayerTextDrawBoxColor(playerid, InfoHead[playerid], 65535);
	PlayerTextDrawSetShadow(playerid, InfoHead[playerid], 0);
	PlayerTextDrawSetOutline(playerid, InfoHead[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, InfoHead[playerid], 255);
	PlayerTextDrawFont(playerid, InfoHead[playerid], 2);
	PlayerTextDrawSetProportional(playerid, InfoHead[playerid], 1);

	ClassInfo[playerid] = CreatePlayerTextDraw(playerid, 320, 319, "_");
	PlayerTextDrawLetterSize(playerid, ClassInfo[playerid], 0.280499, 1.425778);
	PlayerTextDrawTextSize(playerid, ClassInfo[playerid], 53.500000, 336.622314);
	PlayerTextDrawAlignment(playerid, ClassInfo[playerid], 2);
	PlayerTextDrawColor(playerid, ClassInfo[playerid], -1);
	PlayerTextDrawUseBox(playerid, ClassInfo[playerid], true);
	PlayerTextDrawBoxColor(playerid, ClassInfo[playerid], 80);
	PlayerTextDrawSetShadow(playerid, ClassInfo[playerid], 0);
	PlayerTextDrawSetOutline(playerid, ClassInfo[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, ClassInfo[playerid], 255);
	PlayerTextDrawFont(playerid, ClassInfo[playerid], 1);
	PlayerTextDrawSetProportional(playerid, ClassInfo[playerid], 1);

	#if defined ClassSelection_OnPlayerConnect
		return ClassSelection_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect ClassSelection_OnPlayerConnect

#if defined ClassSelection_OnPlayerConnect
	forward ClassSelection_OnPlayerConnect(playerid);
#endif

// STOCK FUNCTIONS

stock HideClassTextdraw(playerid)
{
	PlayerTextDrawHide(playerid, TeamName[playerid]);
	PlayerTextDrawHide(playerid, InfoHead[playerid]);
	PlayerTextDrawHide(playerid, ClassInfo[playerid]);
}

stock ShowClassTextdraw(playerid, teamcolor, teamname[], teaminfo[])
{
	PlayerTextDrawSetString(playerid, TeamName[playerid], teamname);
	PlayerTextDrawSetString(playerid, ClassInfo[playerid], teaminfo);
	
	PlayerTextDrawColor(playerid, TeamName[playerid], teamcolor);
	
	PlayerTextDrawShow(playerid, TeamName[playerid]);
	PlayerTextDrawShow(playerid, InfoHead[playerid]);
	PlayerTextDrawShow(playerid, ClassInfo[playerid]);
}
