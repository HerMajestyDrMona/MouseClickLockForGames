// MouseClickLockForGames.h
// https://github.com/HerMajestyDrMona/MouseClickLockForGames
// Charity project, created by: Dr.MonaLisa.

#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include <string.h>
#include <filesystem>
#include <shlwapi.h>
#include <chrono>
#include <thread>

#pragma comment(lib, "Shlwapi.lib")

using namespace std;
using namespace chrono;

//Basic Configuration:
int ClickLockMouseButtonMode = 0;
int ActivationDelay = 750;
bool MoveMouseBackToClickPosition = true;
bool AutomaticallyRunThisProgramOnStartup = false;
bool UseWindowsClickLockAntiDoubleFix = true;
bool CreateLogFile = false;
bool PrintDebugInfo = false;
const wstring ProgramVersion = L"1.0.0.0";

//Dynamic Variables:
wstring ProgramName = L"MouseClickLockForGames";
wstring ConfigFile = L"MouseClickLockForGamesConfig.txt";
wstring CurrentExeWorks = L"";
wstring CurrentExeWorksFilenameOnly = L"";
wstring CurrentExeWorksPath = L"";
bool MonitorLeftMouseClick = false;
bool MonitorRightMouseClick = false;
wstring PrimaryMouseButtonWstr = L"";
milliseconds ProgrmStartTime = milliseconds(0);
HHOOK HandleLowLevelMousePressProc;
bool LeftButtonPressedATM = false;
bool RightButtonPressedATM = false;
std::chrono::milliseconds LastTimeClickedLeftMouseButton = std::chrono::milliseconds(0);
std::chrono::milliseconds LastTimeClickedRightMouseButton = std::chrono::milliseconds(0);
POINT MouseLeftClickStartPoint;
POINT MouseRightClickStartPoint;
POINT MousePointNow;
std::chrono::milliseconds LastTimeReleasedLeftMouseButton = std::chrono::milliseconds(0);
std::chrono::milliseconds LastTimeReleasedRightMouseButton = std::chrono::milliseconds(0);
bool LeftClickLockActiveNow = false;
bool RightClickLockActiveNow = false;
bool WindowsClickLockFixNowLeft = false;
bool WindowsClickLockFixNowRight = false;
bool AnyClickLockActiveNow = false;
long long int LeftClickSessionID = 0;
long long int RightClickSessionID = 0;
long long int ClickLockSessionID = 0;
long long int LastClickLockSessionID = 0;
long long int LastClickLockSessionIDHotfix = 0;
std::wofstream LOG;
int WindowsClickLockActivationTimeMillisecondsInt = 0;
bool InterruptTheMainThreadNow = false;
BOOL WindowsClickLockEnabled = false;

