// MouseClickLockForGames.cpp
// https://github.com/HerMajestyDrMona/MouseClickLockForGames
// Charity project, created by: Dr.MonaLisa.

#include "MouseClickLockForGames.h"

bool is_number(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

bool is_number_ws(const std::wstring& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

milliseconds GetCurrentMillisecondsTime() {
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch());
}

milliseconds GetZeroMilisecondsTime() {
	return milliseconds(0);
}

bool dirExists(const std::wstring& dirName_in)
{
	DWORD ftyp = GetFileAttributesW(dirName_in.c_str());
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path!

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!

	return false;    // this is not a directory!
}

BOOL FileExistsW(LPCWSTR szPath)
{
	/*if (boost::filesystem::exists(szPath)) {
		return true;
	}
	return false;*/

	DWORD dwAttrib = GetFileAttributesW(szPath);
	return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
		!(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

BOOL FileExists(LPCTSTR szPath)
{
	/*if (boost::filesystem::exists(szPath)) {
		return true;
	}
	return false;*/

	DWORD dwAttrib = GetFileAttributes(szPath);
	return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
		!(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

void find_and_replace(string& source, string const& find, string const& replace)
{
	//boost::replace_all(source, find, replace);
	for (std::string::size_type i = 0; (i = source.find(find, i)) != std::string::npos;)
	{
		source.replace(i, find.length(), replace);
		i += replace.length() - find.length() + 1;
	}
}

void find_and_replace_ws(wstring& source, wstring const& find, wstring const& replace)
{
	//boost::replace_all(source, find, replace);
	for (std::string::size_type i = 0; (i = source.find(find, i)) != std::string::npos;)
	{
		source.replace(i, find.length(), replace);
		i += replace.length() - find.length() + 1;
	}
}

bool NewIsConfigLineEqualTo(string ConfigLine, string SearchFor, string SearchForValue) {
	string SearchForTmp = SearchFor + "=" + SearchForValue;
	std::size_t sssearch1 = ConfigLine.find(SearchForTmp);
	if (sssearch1 != std::string::npos) {
		return true;
	}
	else {
		SearchForTmp = SearchFor + " = " + SearchForValue;
		sssearch1 = ConfigLine.find(SearchForTmp);
		if (sssearch1 != std::string::npos) {
			return true;
		}
		else {
			SearchForTmp = SearchFor + " =" + SearchForValue;
			sssearch1 = ConfigLine.find(SearchForTmp);
			if (sssearch1 != std::string::npos) {
				return true;
			}
			else {
				SearchForTmp = SearchFor + "= " + SearchForValue;
				sssearch1 = ConfigLine.find(SearchForTmp);
				if (sssearch1 != std::string::npos) {
					return true;
				}
			}
		}
	}
	return false;
}

long long int NewConfigGetIntValueAfter(string ConfigLine, string SearchFor) {
	bool GotCorrectString = false;
	string CorrectString = "";
	string SearchForTmp = SearchFor + "=";
	std::size_t sssearch1 = ConfigLine.find(SearchForTmp);
	if (sssearch1 != std::string::npos) {
		CorrectString = ConfigLine.substr(sssearch1 + SearchForTmp.length());
		//MessageBox(Message4, CorrectString.c_str(), "Str Test", MB_OK | MB_ICONERROR);
		GotCorrectString = true;
	}
	else {
		SearchForTmp = SearchFor + " = ";
		sssearch1 = ConfigLine.find(SearchForTmp);
		if (sssearch1 != std::string::npos) {
			CorrectString = ConfigLine.substr(sssearch1 + SearchForTmp.length());
			GotCorrectString = true;
		}
		else {
			SearchForTmp = SearchFor + " =";
			sssearch1 = ConfigLine.find(SearchForTmp);
			if (sssearch1 != std::string::npos) {
				CorrectString = ConfigLine.substr(sssearch1 + SearchForTmp.length());
				GotCorrectString = true;
			}
			else {
				SearchForTmp = SearchFor + "= ";
				sssearch1 = ConfigLine.find(SearchForTmp);
				if (sssearch1 != std::string::npos) {
					CorrectString = ConfigLine.substr(sssearch1 + SearchForTmp.length());
					GotCorrectString = true;
				}
			}
		}
	}

	if (GotCorrectString) {
		find_and_replace(CorrectString, "\r\n", "");
		find_and_replace(CorrectString, "\r", "");
		find_and_replace(CorrectString, "\n", "");
		if (CorrectString.length() > 0) {
			if (is_number(CorrectString)) {
				return atoll(CorrectString.c_str());
			}
		}
	}
	return -696969;//Control value
}

double NewConfigGetDoubleValueAfter(string ConfigLine, string SearchFor) {
	bool GotCorrectString = false;
	string CorrectString = "";
	string SearchForTmp = SearchFor + "=";
	std::size_t sssearch1 = ConfigLine.find(SearchForTmp);
	if (sssearch1 != std::string::npos) {
		CorrectString = ConfigLine.substr(sssearch1 + SearchForTmp.length());
		GotCorrectString = true;
	}
	else {
		SearchForTmp = SearchFor + " = ";
		sssearch1 = ConfigLine.find(SearchForTmp);
		if (sssearch1 != std::string::npos) {
			CorrectString = ConfigLine.substr(sssearch1 + SearchForTmp.length());
			GotCorrectString = true;
		}
		else {
			SearchForTmp = SearchFor + " =";
			sssearch1 = ConfigLine.find(SearchForTmp);
			if (sssearch1 != std::string::npos) {
				CorrectString = ConfigLine.substr(sssearch1 + SearchForTmp.length());
				GotCorrectString = true;
			}
			else {
				SearchForTmp = SearchFor + "= ";
				sssearch1 = ConfigLine.find(SearchForTmp);
				if (sssearch1 != std::string::npos) {
					CorrectString = ConfigLine.substr(sssearch1 + SearchForTmp.length());
					GotCorrectString = true;
				}
			}
		}
	}

	if (GotCorrectString) {
		find_and_replace(CorrectString, "\r\n", "");
		find_and_replace(CorrectString, "\r", "");
		find_and_replace(CorrectString, "\n", "");
		if (CorrectString.length() > 0) {
			//if (is_number(CorrectString)) {
			std::string::size_type sz;     // alias of size_t
			double earth = std::stod(CorrectString, &sz);
			return earth;
			//}
		}
	}
	return -69.69;//Control value
}

void Mona_Load_Configuration() {
	string line = "";
	int rowcnt = 0;
	long long int TmpValueFromNewConfigGetIntFunction = -696969;
	if (FileExists(ConfigFile.c_str())) {
		ifstream settingsfile(ConfigFile, ios::binary);
		if (settingsfile.is_open()) {
			while (!settingsfile.eof()) {
				getline(settingsfile, line);
				++rowcnt;
				if (line.length() > 0) {

					find_and_replace(line, "\r\n", "");
					find_and_replace(line, "\r", "");
					find_and_replace(line, "\n", "");

					if (rowcnt > 1000) {
						//Just in case someone loads a 1000TB file as a config.
						break;
					}


					if (line.length() > 1) {
						string test2 = line.substr(0, 1);
						if (test2 == "/") {
							continue;
						}
						else if (test2 == "#") {
							continue;
						}
						else if (test2 == ";") {
							continue;
						}
						string LastChar = line.substr(line.length() - 1);
						if (LastChar == ";") {
							line = line.substr(0, line.length() - 1);
						}
					}

					if (NewIsConfigLineEqualTo(line, "AutomaticallyRunThisProgramOnStartup", "1") || NewIsConfigLineEqualTo(line, "AutomaticallyRunThisProgramOnStartup", "true")) {
						AutomaticallyRunThisProgramOnStartup = true;
						continue;
					}
					else if (NewIsConfigLineEqualTo(line, "AutomaticallyRunThisProgramOnStartup", "0") || NewIsConfigLineEqualTo(line, "AutomaticallyRunThisProgramOnStartup", "false")) {
						AutomaticallyRunThisProgramOnStartup = false;
						continue;
					}

					if (NewIsConfigLineEqualTo(line, "UseWindowsClickLockAntiDoubleFix", "1") || NewIsConfigLineEqualTo(line, "UseWindowsClickLockAntiDoubleFix", "true")) {
						UseWindowsClickLockAntiDoubleFix = true;
						continue;
					}
					else if (NewIsConfigLineEqualTo(line, "UseWindowsClickLockAntiDoubleFix", "0") || NewIsConfigLineEqualTo(line, "UseWindowsClickLockAntiDoubleFix", "false")) {
						UseWindowsClickLockAntiDoubleFix = false;
						continue;
					}

					if (NewIsConfigLineEqualTo(line, "CreateLogFile", "1") || NewIsConfigLineEqualTo(line, "CreateLogFile", "true")) {
						CreateLogFile = true;
						continue;
					}
					else if (NewIsConfigLineEqualTo(line, "CreateLogFile", "0") || NewIsConfigLineEqualTo(line, "CreateLogFile", "false")) {
						CreateLogFile = false;
						continue;
					}

					if (NewIsConfigLineEqualTo(line, "MoveMouseBackToClickPosition", "1") || NewIsConfigLineEqualTo(line, "MoveMouseBackToClickPosition", "true")) {
						MoveMouseBackToClickPosition = true;
						continue;
					}
					else if (NewIsConfigLineEqualTo(line, "MoveMouseBackToClickPosition", "0") || NewIsConfigLineEqualTo(line, "MoveMouseBackToClickPosition", "false")) {
						MoveMouseBackToClickPosition = false;
						continue;
					}

					TmpValueFromNewConfigGetIntFunction = NewConfigGetIntValueAfter(line, "ClickLockMouseButtonMode");
					if (TmpValueFromNewConfigGetIntFunction != -696969) {
						if (TmpValueFromNewConfigGetIntFunction >= 0) {//For performance purposes disallow 0s for now.
							if (TmpValueFromNewConfigGetIntFunction < 4) {
								ClickLockMouseButtonMode = static_cast<int>(TmpValueFromNewConfigGetIntFunction);
								continue;
							}
						}
					}

					TmpValueFromNewConfigGetIntFunction = NewConfigGetIntValueAfter(line, "ActivationDelay");
					if (TmpValueFromNewConfigGetIntFunction != -696969) {
						if (TmpValueFromNewConfigGetIntFunction >= 0) {//For performance purposes disallow 0s for now.
							ActivationDelay = static_cast<int>(TmpValueFromNewConfigGetIntFunction);
							continue;
						}
					}
				}
			}
		}
	}
}

bool RegistryGetStringValue(std::wstring& valueBuf, HKEY MainKey, const std::wstring& regSubKey, const std::wstring& regValue)
{
	size_t bufferSize = 0xFFF; // If too small, will be resized down below.
	//std::wstring valueBuf; // Contiguous buffer since C++11.
	valueBuf.resize(bufferSize);
	auto cbData = static_cast<DWORD>(bufferSize * sizeof(wchar_t));
	auto rc = RegGetValueW(
		MainKey,
		regSubKey.c_str(),
		regValue.c_str(),
		RRF_RT_REG_SZ,
		nullptr,
		static_cast<void*>(valueBuf.data()),
		&cbData
	);
	while (rc == ERROR_MORE_DATA)
	{
		// Get a buffer that is big enough.
		cbData /= sizeof(wchar_t);
		if (cbData > static_cast<DWORD>(bufferSize))
		{
			bufferSize = static_cast<size_t>(cbData);
		}
		else
		{
			bufferSize *= 2;
			cbData = static_cast<DWORD>(bufferSize * sizeof(wchar_t));
		}
		valueBuf.resize(bufferSize);
		rc = RegGetValueW(
			MainKey,
			regSubKey.c_str(),
			regValue.c_str(),
			RRF_RT_REG_SZ,
			nullptr,
			static_cast<void*>(valueBuf.data()),
			&cbData
		);
	}
	if (rc == ERROR_SUCCESS)
	{
		cbData /= sizeof(wchar_t);
		valueBuf.resize(static_cast<size_t>(cbData - 1)); // remove end null character
		//return valueBuf;
		return true;
	}
	else
	{
		//throw std::runtime_error("Windows system error code: " + std::to_string(rc));
	}
	return false;
}

bool RegistrySetStringValue(HKEY MainKey, const std::wstring& regSubKey, const std::wstring& regValue, const std::wstring& stringToSet)
{
	auto rc = RegSetKeyValueW(
		MainKey,
		regSubKey.c_str(),
		regValue.c_str(),
		//RRF_RT_REG_SZ,
		REG_SZ,
		stringToSet.c_str(),
		stringToSet.length() * 2
	);

	if (rc == ERROR_SUCCESS)
	{
		return true;
	}
	else
	{
		//throw std::runtime_error("Windows system error code: " + std::to_string(rc));
	}

	return false;
}

bool RegistryDeleteKeyValue(HKEY MainKey, const std::wstring& regSubKey, const std::wstring& regValue)
{
	auto rc = RegDeleteKeyValueW(
		MainKey,
		regSubKey.c_str(),
		regValue.c_str()
	);

	if (rc == ERROR_SUCCESS)
	{
		return true;
	}
	else
	{
		//throw std::runtime_error("Windows system error code: " + std::to_string(rc));
	}

	return false;
}


std::wstring MonaGetTimeForLog(bool AddBraces = true) {
	const auto now = std::chrono::system_clock::now();
	const auto nowAsTimeT = std::chrono::system_clock::to_time_t(now);
	const auto nowMs = std::chrono::duration_cast<std::chrono::milliseconds>(
		now.time_since_epoch()) % 1000;
	std::wstringstream nowSs;
	std::time_t t = std::time(nullptr);
	std::tm tm;
	localtime_s(&tm, &t);
	if (AddBraces) {
		nowSs << L"[" << std::put_time(&tm, L"%F %T") << '.' << std::setfill(L'0') << std::setw(3) << nowMs.count() << L"] ";
	}
	else {
		nowSs << std::put_time(&tm, L"%F %T") << '.' << std::setfill(L'0') << std::setw(3) << nowMs.count();
	}
	return nowSs.str();
}

std::wstring MonaGetTimeForLogFilename() {
	const auto now = std::chrono::system_clock::now();
	const auto nowAsTimeT = std::chrono::system_clock::to_time_t(now);
	std::wstringstream nowSs;
	std::time_t t = std::time(nullptr);
	std::tm tm;
	localtime_s(&tm, &t);
	nowSs << std::put_time(&tm, L"%Y-%m-%d_%H-%M-%S");
	return nowSs.str();
}

void Check_And_Set_Auto_Program_Startup() {
	wstring QueryKey = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";
	//wstring QueryValue = L"MouseClickLockForGames";
	wstring QueryValue = ProgramName;

	bool FoundInRegistry = false;
	bool CorrectInRegistry = false;

	wstring CurrentExeWorksForRegistry = L"\"";
	CurrentExeWorksForRegistry = CurrentExeWorksForRegistry + CurrentExeWorks + L"\"";

	wstring InAutostart = L"";
	if (RegistryGetStringValue(InAutostart, HKEY_CURRENT_USER, QueryKey, QueryValue)) {
		if (InAutostart.length() > 0) {
			FoundInRegistry = true;
			if (CurrentExeWorksForRegistry == InAutostart) {
				CorrectInRegistry = true;
				if (CreateLogFile) { LOG << MonaGetTimeForLog() << L"The Auto Startup registry key value is correct. No need to update." << std::endl; }
			}
			else {
				if (CreateLogFile) { LOG << MonaGetTimeForLog() << L"The existing Auto Startup registry key value: " << InAutostart << L" Length: " << InAutostart.length() << L" does not match the current process: " << CurrentExeWorksForRegistry << L" Length: " << CurrentExeWorksForRegistry.length() << std::endl; }
			}
		}
	}
	if (AutomaticallyRunThisProgramOnStartup) {
		if (!FoundInRegistry || !CorrectInRegistry) {
			//Set the key
			if (RegistrySetStringValue(HKEY_CURRENT_USER, QueryKey, QueryValue, CurrentExeWorksForRegistry)) {
				if (CreateLogFile) { LOG << MonaGetTimeForLog() << L"Successfully set the Auto Startup registry key value to: " << CurrentExeWorks << std::endl; }
			}
			else {
				if (CreateLogFile) { LOG << MonaGetTimeForLog() << L"Error setting the Auto Startup registry key value to: " << CurrentExeWorks << std::endl; }
			}
		}

	}
	else {
		if (FoundInRegistry) {
			//Delete key
			if (RegistryDeleteKeyValue(HKEY_CURRENT_USER, QueryKey, QueryValue)) {
				if (CreateLogFile) { LOG << MonaGetTimeForLog() << L"Successfully removed the Auto Startup registry key value for: " << CurrentExeWorks << std::endl; }
			}
			else {
				if (CreateLogFile) { LOG << MonaGetTimeForLog() << L"ERROR: Unable to delete the Auto Startup registry key value for: " << CurrentExeWorks << std::endl; }
			}
		}
	}
}

//Important: This Callback can slow down mouse move of the system!!! Don't put anything unnecessary here, and use the other thread!
static LRESULT CALLBACK LowLevelMousePressProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode == HC_ACTION) {

		if (MonitorLeftMouseClick){
			if (wParam == WM_LBUTTONDOWN)
			{
				if (!WindowsClickLockFixNowLeft) {
					//LeftClickSessionID++;
					LastTimeClickedLeftMouseButton = GetCurrentMillisecondsTime();
				}
				if (CreateLogFile) {
					LOG << MonaGetTimeForLog() << L"[WH_MOUSE_LL Thread] LEFT Mouse Button DOWN event detected on: " << MonaGetTimeForLog(false).c_str() << L"." << std::endl;
				}
				if (!LeftClickLockActiveNow && !WindowsClickLockFixNowLeft) {
					GetCursorPos(&MouseLeftClickStartPoint);
				}
				else {
					if (CreateLogFile) {
						LOG << MonaGetTimeForLog() << L"[WH_MOUSE_LL Thread] LeftClickLockActiveNow is true. Skipping MouseLeftClickStartPoint position update." << std::endl;
					}
				}
				LeftButtonPressedATM = true;
			}

			else if (wParam == WM_LBUTTONUP)
			{
				if (CreateLogFile) {
					LOG << MonaGetTimeForLog() << L"[WH_MOUSE_LL Thread] LEFT Mouse Button UP event detected on: " << MonaGetTimeForLog(false).c_str() << L"." << std::endl;
				}

				LastTimeReleasedLeftMouseButton = GetCurrentMillisecondsTime();

				if (WindowsClickLockFixNowLeft) {

				}
				else if (LeftClickLockActiveNow) {
					if (CreateLogFile) {
						LOG << MonaGetTimeForLog() << L"[WH_MOUSE_LL Thread] LEFT ClikLock was active. Releasing now and setting booleans to false." << std::endl;
					}
					LeftClickLockActiveNow = false;
					AnyClickLockActiveNow = false;
				}
				else {
					if (LastTimeReleasedLeftMouseButton.count() >= (LastTimeClickedLeftMouseButton.count() + ActivationDelay)) {
						ClickLockSessionID++;
						if (CreateLogFile) {
							int diff = LastTimeReleasedLeftMouseButton.count() - LastTimeClickedLeftMouseButton.count();
							LOG << MonaGetTimeForLog() << L"[WH_MOUSE_LL Thread] LEFT ClikLock has been ACTIVATED now. The LEFT Mouse Button was pressed for: " << to_wstring(diff).c_str() << L" milliseconds. ClickLock Session ID: " << to_wstring(ClickLockSessionID).c_str() << L"." << std::endl;
						}
						LeftClickLockActiveNow = true;
						AnyClickLockActiveNow = true;
						return -1;
					}
					else {
						if (CreateLogFile) {
							int diff = LastTimeReleasedLeftMouseButton.count() - LastTimeClickedLeftMouseButton.count();
							LOG << MonaGetTimeForLog() << L"[WH_MOUSE_LL Thread] NOT activating the LEFT ClikLock, because only: " << to_wstring(diff).c_str() << L" milliseconds have passed since the LEFT mouse button was down." << std::endl;
						}
					}
				}

				LeftButtonPressedATM = false;
			}
		}
		if (MonitorRightMouseClick) {
			if (wParam == WM_RBUTTONDOWN)
			{
				if (!WindowsClickLockFixNowRight) {
					//RightClickSessionID++;
					LastTimeClickedRightMouseButton = GetCurrentMillisecondsTime();
				}
				if (CreateLogFile) {
					LOG << MonaGetTimeForLog() << L"[WH_MOUSE_LL Thread] RIGHT Mouse Button DOWN event detected on: " << MonaGetTimeForLog(false).c_str() << L"." << std::endl;
				}
				if (!RightClickLockActiveNow && !WindowsClickLockFixNowRight) {
					GetCursorPos(&MouseRightClickStartPoint);
				}
				else {
					if (CreateLogFile) {
						LOG << MonaGetTimeForLog() << L"[WH_MOUSE_LL Thread] RightClickLockActiveNow is true. Skipping MouseRightClickStartPoint position update." << std::endl;
					}
				}
				RightButtonPressedATM = true;
			}

			else if (wParam == WM_RBUTTONUP)
			{
				if (CreateLogFile) {
					LOG << MonaGetTimeForLog() << L"[WH_MOUSE_LL Thread] RIGHT Mouse Button UP event detected on: " << MonaGetTimeForLog(false).c_str() << L"." << std::endl;
				}

				LastTimeReleasedRightMouseButton = GetCurrentMillisecondsTime();

				if (WindowsClickLockFixNowRight) {

				}
				else if (RightClickLockActiveNow) {
					if (CreateLogFile) {
						LOG << MonaGetTimeForLog() << L"[WH_MOUSE_LL Thread] RIGHT ClikLock was active. Releasing now and setting booleans to false." << std::endl;
					}
					RightClickLockActiveNow = false;
					AnyClickLockActiveNow = false;
				}
				else {
					if (LastTimeReleasedRightMouseButton.count() >= (LastTimeClickedRightMouseButton.count() + ActivationDelay)) {
						ClickLockSessionID++;
						if (CreateLogFile) {
							int diff = LastTimeReleasedRightMouseButton.count() - LastTimeClickedRightMouseButton.count();
							LOG << MonaGetTimeForLog() << L"[WH_MOUSE_LL Thread] RIGHT ClikLock has been ACTIVATED now. The RIGHT Mouse Button was pressed for: " << to_wstring(diff).c_str() << L" milliseconds. ClickLock Session ID: " << to_wstring(ClickLockSessionID).c_str() << L"." << std::endl;
						}
						RightClickLockActiveNow = true;
						AnyClickLockActiveNow = true;
						return -1;
					}
					else {
						if (CreateLogFile) {
							int diff = LastTimeReleasedRightMouseButton.count() - LastTimeClickedRightMouseButton.count();
							LOG << MonaGetTimeForLog() << L"[WH_MOUSE_LL Thread] NOT activating the RIGHT ClikLock, because only: " << to_wstring(diff).c_str() << L" milliseconds have passed since the RIGHT mouse button was down." << std::endl;
						}
					}
				}

				RightButtonPressedATM = false;
			}
		}
	}
	return CallNextHookEx(HandleLowLevelMousePressProc, nCode, wParam, lParam);
}

DWORD WINAPI MouseClickWatchdogThread(void* data) {

	HINSTANCE hInstLowLevelMousePressProc = GetModuleHandle(NULL);
	HandleLowLevelMousePressProc = SetWindowsHookEx(WH_MOUSE_LL, LowLevelMousePressProc, hInstLowLevelMousePressProc, 0);
	if (!HandleLowLevelMousePressProc) {
		std::wcout << L"Failed to install WH_MOUSE_LL Mouse Hook! Please run this program as administrator!" << endl;
		system("pause");
		InterruptTheMainThreadNow = true;
		return 0;
	}
	MSG msgMouseClickWatchdog;
	while (GetMessage(&msgMouseClickWatchdog, 0, 0, 0))
	{
		PeekMessage(&msgMouseClickWatchdog, 0, 0, 0, 0x0001);
	}
	UnhookWindowsHookEx(HandleLowLevelMousePressProc);
	return 0;
}

int main()
{
    HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);

	//Generate strings with .exe path information, and set the working directory to the one where .exe is:
	wchar_t result[MAX_PATH];
	CurrentExeWorks = std::wstring(result, GetModuleFileNameW(NULL, result, MAX_PATH));
	std::filesystem::path CurrentPath(CurrentExeWorks);
	CurrentExeWorksFilenameOnly = CurrentPath.filename().wstring();
	wchar_t CurrentWorkingDirectoryWhereExeIs[MAX_PATH];
	wstring ress = std::wstring(CurrentWorkingDirectoryWhereExeIs, GetModuleFileNameW(NULL, CurrentWorkingDirectoryWhereExeIs, MAX_PATH));
	PathRemoveFileSpecW(CurrentWorkingDirectoryWhereExeIs);
	SetCurrentDirectoryW(CurrentWorkingDirectoryWhereExeIs);
	CurrentExeWorksPath = CurrentWorkingDirectoryWhereExeIs;

	//Get Windows ClickLock status:
	BOOL fResult;
	WindowsClickLockEnabled = false;
	DWORD WindowsClickLockActivationTimeMilliseconds = 0;
	// Get the current mouse speed.         
	fResult = SystemParametersInfo(SPI_GETMOUSECLICKLOCK,
		0,
		&WindowsClickLockEnabled,
		0);

	fResult = SystemParametersInfo(SPI_GETMOUSECLICKLOCKTIME,
		0,
		&WindowsClickLockActivationTimeMilliseconds,
		0);
	WindowsClickLockActivationTimeMillisecondsInt = (int)WindowsClickLockActivationTimeMilliseconds;

	//Load configuration:
	Mona_Load_Configuration();

	bool ChangedActivationDelayToWindowsOne = false;
	if (ActivationDelay == 0) {
		if (WindowsClickLockActivationTimeMillisecondsInt != 0) {
			ActivationDelay = WindowsClickLockActivationTimeMillisecondsInt;
			ChangedActivationDelayToWindowsOne = true;
		}
	}

	if (ClickLockMouseButtonMode == 0) {
		MonitorLeftMouseClick = true;
		MonitorRightMouseClick = false;
		PrimaryMouseButtonWstr = L"Left";
	}
	else if (ClickLockMouseButtonMode == 1) {
		MonitorLeftMouseClick = true;
		MonitorRightMouseClick = false;
		PrimaryMouseButtonWstr = L"Left";
	}
	else if (ClickLockMouseButtonMode == 2) {
		MonitorLeftMouseClick = false;
		MonitorRightMouseClick = true;
		PrimaryMouseButtonWstr = L"Right";
	}
	else if (ClickLockMouseButtonMode == 3) {
		MonitorLeftMouseClick = true;
		MonitorRightMouseClick = true;
		PrimaryMouseButtonWstr = L"Left and Right";
	}

	wstring MutexName = L"Mona" + ProgramName + L"-AlreadyRunning";
	HANDLE handleMutex = CreateMutex(NULL, TRUE, MutexName.c_str());
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		std::wcout << ProgramName << L" is already running. Exiting this instance..." << endl;
		return 1;
	}

	//HANDLE hInput = GetConsoleWindow();
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD prev_mode;
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS |
		(prev_mode & ~ENABLE_QUICK_EDIT_MODE));

	std::chrono::milliseconds ProgrmStartTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	wstring ProgramAndVersionInfo = ProgramName + L", ver. " + ProgramVersion + L", created by Dr.MonaLisa.";
	std::wcout << ProgramAndVersionInfo.c_str() << endl;
	printf("https://github.com/HerMajestyDrMona/MouseClickLockForGames\n\n");
	printf("Please read the GitHub page to learn how to configure this program.\n\n");

	printf("If the program does not work for you, please run it as administrator.\n\n");

	wstring AntiDub = L"";

	if (WindowsClickLockEnabled) {
		std::wcout << L"Windows ClickLock is currently ENABLED. Delay: " << to_wstring(WindowsClickLockActivationTimeMillisecondsInt).c_str() << L" milliseconds." << endl;
		if (UseWindowsClickLockAntiDoubleFix) {
			std::wcout << L"Use Windows Click Lock Anti Double Fix: YES." << endl << endl;
			AntiDub = L"YES";
		}
		else {
			std::wcout << L"Use Windows Click Lock Anti Double Fix: NO." << endl << endl;
			AntiDub = L"NO";
		}
	}
	else {
		std::wcout << L"Windows ClickLock is currently DISABLED. Delay: " << to_wstring(WindowsClickLockActivationTimeMillisecondsInt).c_str() << L" milliseconds." << endl;
	}
	if (ChangedActivationDelayToWindowsOne) {
		std::wcout << L"Activation Delay was 0, so it has been changed to match the Windows ClickLock time: " << to_wstring(WindowsClickLockActivationTimeMillisecondsInt).c_str() << L" milliseconds." << endl;
	}

	std::wcout << L"ClickLock For Games Mouse Button Mode: " << PrimaryMouseButtonWstr.c_str() << L"." << endl;
	std::wcout << L"ClickLock For Games Activation Delay: " << to_wstring(ActivationDelay).c_str() << L" milliseconds." << endl;

	wstring MoveMouseBack = L"";
	wstring RunOnStartup = L"";
	wstring LogFil = L"";
	if (MoveMouseBackToClickPosition) {
		std::wcout << L"Move Mouse Back To Click Position: YES." << endl;
		MoveMouseBack = L"YES";
	}
	else {
		std::wcout << L"Move Mouse Back To Click Position: NO." << endl;
		MoveMouseBack = L"YES";
	}
	if (AutomaticallyRunThisProgramOnStartup) {
		std::wcout << L"Automatically Run This Program On System Startup: YES." << endl;
		RunOnStartup = L"YES";
	}
	else {
		std::wcout << L"Automatically Run This Program On System Startup: NO." << endl;
		RunOnStartup = L"NO";
	}
	
	if (CreateLogFile) {
		std::wcout << L"Create Log File: YES." << endl << endl;
		LogFil = L"YES";
	}
	else {
		std::wcout << L"Create Log File: NO." << endl << endl;
		LogFil = L"NO";
	}

	if (CreateLogFile) {
		wstring LogFileName = ProgramName + L"_" + MonaGetTimeForLogFilename() + L"_LOG.txt";
		if (!LOG.is_open())
		{
			LOG.open(LogFileName.c_str(), std::ios::trunc);
		}

		if (!LOG.is_open())
		{
			std::wcout << L"Failed to open the log file: \"" << LogFileName << L"\". Please try starting this program as administrator." << endl;
			CreateLogFile = false;
		}
		else {
			std::wcout << L"Successfully created the log file: \"" << LogFileName << "." << endl;
			LOG << MonaGetTimeForLog() << ProgramAndVersionInfo << L" Started on: " << MonaGetTimeForLog(false) << std::endl;
			if (WindowsClickLockEnabled) {
				LOG << MonaGetTimeForLog() << L"Windows ClickLock is currently ENABLED. Delay: " << to_wstring(WindowsClickLockActivationTimeMillisecondsInt).c_str() << L" milliseconds" << std::endl;
				LOG << MonaGetTimeForLog() << L"Use Windows Click Lock Anti Double Fix: " << AntiDub.c_str() << L"." << std::endl;
				std::wcout << L"Use Windows Click Lock Anti Double Fix: YES." << endl << endl;
			}
			else {
				LOG << MonaGetTimeForLog() << L"Windows ClickLock is currently DISABLED. Delay: " << to_wstring(WindowsClickLockActivationTimeMillisecondsInt).c_str() << L" milliseconds" << std::endl;
			}
			if (ChangedActivationDelayToWindowsOne) {
				LOG << MonaGetTimeForLog() << L"Activation Delay was 0, so it has been changed to match the Windows ClickLock time: " << to_wstring(WindowsClickLockActivationTimeMillisecondsInt).c_str() << L" milliseconds" << std::endl;
			}
			LOG << MonaGetTimeForLog() << L"ClickLock For Games Mouse Button Mode: " << PrimaryMouseButtonWstr.c_str() << std::endl;
			LOG << MonaGetTimeForLog() << L"ClickLock For Games Activation Delay: " << to_wstring(ActivationDelay).c_str() << L" milliseconds" << std::endl;
			LOG << MonaGetTimeForLog() << L"Move Mouse Back To Click Position: " << MoveMouseBack.c_str() << std::endl;
			LOG << MonaGetTimeForLog() << L"Automatically Run This Program On System Startup: " << RunOnStartup.c_str() << std::endl;
			LOG << MonaGetTimeForLog() << L"Create Log File: " << LogFil.c_str() << std::endl;
		}
	}

	//Check auto start:
	if (CreateLogFile) { LOG << MonaGetTimeForLog() << L"Checking for Autostart keys in the registry..." << std::endl; }
	Check_And_Set_Auto_Program_Startup();

	//Start Mouse Click Watchdog Thread 
	if (CreateLogFile) { LOG << MonaGetTimeForLog() << L"Creating the MouseClickWatchdogThread..." << std::endl; }
	HANDLE ThreadHandleMouseClickWatchdogThread = CreateThread(NULL, 0, MouseClickWatchdogThread, NULL, 0, NULL);

	std::chrono::nanoseconds LoopSleep = chrono::nanoseconds(500000);//0.5 milliseconds

	if (CreateLogFile) { LOG << MonaGetTimeForLog() << L"The main loop sleep time is: " << LoopSleep.count() << L" nanoseconds." << std::endl; }

	while (true) {
		if (InterruptTheMainThreadNow) {
			break;
		}

		if (WindowsClickLockEnabled && UseWindowsClickLockAntiDoubleFix) {
			if(!LeftClickLockActiveNow && !WindowsClickLockFixNowLeft){
				if ((LastTimeReleasedLeftMouseButton.count() < LastTimeClickedLeftMouseButton.count()) && (LastTimeClickedLeftMouseButton.count() != 0) && (LastTimeReleasedLeftMouseButton.count() != 0)) {
					milliseconds TimeNow = GetCurrentMillisecondsTime();
					if (TimeNow.count() >= (LastTimeClickedLeftMouseButton.count() + ActivationDelay)) {
						if (CreateLogFile) {
							int diff = TimeNow.count() - LastTimeClickedLeftMouseButton.count();
							LOG << MonaGetTimeForLog() << L"[MAIN Thread] LEFT Mouse Button was pressed for: " << to_wstring(diff).c_str() << L" milliseconds. Applying a fix to release keys, because Windows ClickLock is enabled." << std::endl;
						}
						int screenX = GetSystemMetrics(SM_CXVIRTUALSCREEN);
						int screenY = GetSystemMetrics(SM_CYVIRTUALSCREEN);
						int ClickX = MouseLeftClickStartPoint.x * (65535 / screenX);
						int ClickY = MouseLeftClickStartPoint.y * (65535 / screenY);
						WindowsClickLockFixNowLeft = true;
						if (MoveMouseBackToClickPosition) {
							mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, ClickX, ClickY, 0, 0);
						}
						mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_ABSOLUTE, ClickX, ClickY, 0, 0);
						mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE, ClickX, ClickY, 0, 0);
						WindowsClickLockFixNowLeft = false;
					}
					
				}
			}
			if (!RightClickLockActiveNow && !WindowsClickLockFixNowRight) {
				if ((LastTimeReleasedRightMouseButton.count() < LastTimeClickedRightMouseButton.count()) && (LastTimeClickedRightMouseButton.count() != 0) && (LastTimeReleasedRightMouseButton.count() != 0)) {
					milliseconds TimeNow = GetCurrentMillisecondsTime();
					if (TimeNow.count() >= (LastTimeClickedRightMouseButton.count() + ActivationDelay)) {
						if (CreateLogFile) {
							int diff = TimeNow.count() - LastTimeClickedRightMouseButton.count();
							LOG << MonaGetTimeForLog() << L"[MAIN Thread] RIGHT Mouse Button was pressed for: " << to_wstring(diff).c_str() << L" milliseconds. Applying a fix to release keys, because Windows ClickLock is enabled." << std::endl;
						}
						int screenX = GetSystemMetrics(SM_CXVIRTUALSCREEN);
						int screenY = GetSystemMetrics(SM_CYVIRTUALSCREEN);
						int ClickX = MouseRightClickStartPoint.x * (65535 / screenX);
						int ClickY = MouseRightClickStartPoint.y * (65535 / screenY);
						WindowsClickLockFixNowRight = true;
						if (MoveMouseBackToClickPosition) {
							mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, ClickX, ClickY, 0, 0);
						}
						mouse_event(MOUSEEVENTF_RIGHTUP | MOUSEEVENTF_ABSOLUTE, ClickX, ClickY, 0, 0);
						mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_ABSOLUTE, ClickX, ClickY, 0, 0);
						WindowsClickLockFixNowRight = false;
					}

				}
			}
		}

		if (AnyClickLockActiveNow && LastClickLockSessionID != ClickLockSessionID) {
			LastClickLockSessionID = ClickLockSessionID;
			if (CreateLogFile) { LOG << MonaGetTimeForLog() << L"[MAIN Thread] Detected a new ClickLock signal for ClickLock SessionID: " << to_wstring(ClickLockSessionID).c_str() << std::endl; }
			if (MoveMouseBackToClickPosition) {
				DWORD flagClick = MOUSEEVENTF_LEFTDOWN;
				POINT LastClickStartPoint = MouseLeftClickStartPoint;
				if (RightClickLockActiveNow) {
					if (LastTimeClickedRightMouseButton.count() == 0 || LastTimeReleasedRightMouseButton.count() == 0) {
						continue;
					}
					flagClick = MOUSEEVENTF_RIGHTDOWN;
					LastClickStartPoint = MouseRightClickStartPoint;
				}
				else {
					if (LastTimeClickedLeftMouseButton.count() == 0 || LastTimeReleasedLeftMouseButton.count() == 0) {
						continue;
					}
				}
				
				//Simulate Left Click again to fix problems in games:
				int screenX = GetSystemMetrics(SM_CXVIRTUALSCREEN);
				int screenY = GetSystemMetrics(SM_CYVIRTUALSCREEN);
				int ClickX = LastClickStartPoint.x * (65535 / screenX);
				int ClickY = LastClickStartPoint.y * (65535 / screenY);

				mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, ClickX, ClickY, 0, 0);
				mouse_event(flagClick | MOUSEEVENTF_ABSOLUTE, ClickX, ClickY, 0, 0);

				if (CreateLogFile) {
					GetCursorPos(&MousePointNow);
					milliseconds CurrentTime = GetCurrentMillisecondsTime();
					int msago = 0;
					if (!RightClickLockActiveNow) {
						msago = CurrentTime.count() - LastTimeClickedLeftMouseButton.count();
						LOG << MonaGetTimeForLog() << L"[MAIN Thread] The recent ClickLock is for the LEFT mouse button. Set: " << to_wstring(msago).c_str() << L" milliseconds ago. Mouse moved back to position X: " << to_wstring(LastClickStartPoint.x).c_str() << L" Y: " << to_wstring(LastClickStartPoint.y).c_str() << L". From position X: " << to_wstring(MousePointNow.x).c_str() << L" Y: " << to_wstring(MousePointNow.y).c_str() << L"." << std::endl;
					}
					else {
						msago = CurrentTime.count() - LastTimeClickedRightMouseButton.count();
						LOG << MonaGetTimeForLog() << L"[MAIN Thread] The recent ClickLock is for the RIGHT mouse button. Set: " << to_wstring(msago).c_str() << L" milliseconds ago. Mouse moved back to absolute position X: " << to_wstring(LastClickStartPoint.x).c_str() << L" Y: " << to_wstring(LastClickStartPoint.y).c_str() << L". From position X: " << to_wstring(MousePointNow.x).c_str() << L" Y: " << to_wstring(MousePointNow.y).c_str() << L"." << std::endl;
					}
				}
			}
			else {
				DWORD flagClick = MOUSEEVENTF_LEFTDOWN;
				if (RightClickLockActiveNow) {
					if (LastTimeClickedRightMouseButton.count() == 0 || LastTimeReleasedRightMouseButton.count() == 0) {
						continue;
					}
					flagClick = MOUSEEVENTF_RIGHTDOWN;
				}
				else {
					if (LastTimeClickedLeftMouseButton.count() == 0 || LastTimeReleasedLeftMouseButton.count() == 0) {
						continue;
					}
				}
				//Simulate Left Click again to fix problems in games:
				int screenX = GetSystemMetrics(SM_CXVIRTUALSCREEN);
				int screenY = GetSystemMetrics(SM_CYVIRTUALSCREEN);

				GetCursorPos(&MousePointNow);
				int ClickX = MousePointNow.x * (65535 / screenX);
				int ClickY = MousePointNow.y * (65535 / screenY);
				mouse_event(flagClick | MOUSEEVENTF_ABSOLUTE, ClickX, ClickY, 0, 0);

				if (CreateLogFile) {
					milliseconds CurrentTime = GetCurrentMillisecondsTime();
					int msago = 0;
					if (!RightClickLockActiveNow) {
						msago = CurrentTime.count() - LastTimeClickedLeftMouseButton.count();
						LOG << MonaGetTimeForLog() << L"[MAIN Thread] The recent ClickLock is for the LEFT mouse button. Set: " << to_wstring(msago).c_str() << L" milliseconds ago. Mouse button pressed at absolute position X: " << to_wstring(MousePointNow.x).c_str() << L" Y: " << to_wstring(MousePointNow.y).c_str() << L"." << std::endl;
					}
					else {
						msago = CurrentTime.count() - LastTimeClickedRightMouseButton.count();
						LOG << MonaGetTimeForLog() << L"[MAIN Thread] The recent ClickLock is for the RIGHT mouse button. Set: " << to_wstring(msago).c_str() << L" milliseconds ago. Mouse button pressed at absolute position X: " << to_wstring(MousePointNow.x).c_str() << L" Y: " << to_wstring(MousePointNow.y).c_str() << L"." << std::endl;
					}
				}
			}
		}
		std::this_thread::sleep_for(LoopSleep);
		continue;
	}

    std::cout << "Bye\n";
}
