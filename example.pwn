#include <a_samp>
#include <ClassSelection>

main()
{
	print("\n----------------------------------");
	print(" Blank Gamemode by your name here");
	print("----------------------------------\n");
}

public OnGameModeInit()
{
	AddPlayerClass(287, 2775.2332, -2392.3889, 18.9217, 102.8251, 0, 0, 0, 0, 0, 0);
	AddPlayerClass(287, 2775.2332, -2392.3889, 18.9217, 102.8251, 0, 0, 0, 0, 0, 0);
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	SetPlayerPos(playerid, 364.252258, 2029.698608, 22.640625);
	SetPlayerFacingAngle(playerid, 145.840316);
	SetPlayerCameraLookAt(playerid, 364.252258, 2029.698608, 22.640625);
	SetPlayerCameraPos(playerid, 364.252258 + (5 * floatsin(-145.840316, degrees)), 2029.698608 + (5 * floatcos(-145.840316, degrees)), 22.640625);
	
	switch(classid)
    {
    	case 0:
     	{
			ShowClassTextdraw(playerid, 0x0198E1FF, "Engineer", "Can repair vehicles and disarm any bomb. Can also hack into the enemy's secruity systems and gain information for attacking.");
		}
		case 1:
     	{
			ShowClassTextdraw(playerid, 0x33AA33FF, "Support", "Can supply ammo to anyone. Can also plant and detonate explosives.");
		}
	}
	return 1;
}

public OnPlayerSpawn(playerid)
{
    HideClassTextdraw(playerid);
	return 1;
}
