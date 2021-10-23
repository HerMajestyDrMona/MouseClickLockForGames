# Mouse ClickLock For Games

This small utility works in a similar way as ClickLock available on Windows, but also supports old games where the normal ClickLock fails to work. This is a charity project, designed for people with disabilities.

## What is ClickLock?
ClickLock allows a user to lock down the primary mouse button with a single click. It's then possible to highlight or drag without holding down the primary mouse button.

## What is this program: "Mouse ClickLock For Games" needed for?

I'm developing an [Unofficial Patch](https://ee2.eu/patch/) for an old RTS game - Empire Earth II. An user on the Support Chat asked me for help getting the ClickLock to work in this game. He can only use a trackball because he can't move the mouse around. He uses a stick in his mouth with a piece of rubber tubing on the end to roll the ball.

Unfortunately, some games (especially old ones) don't support the default ClickLock available on Windows. It's because they intercept mouse clicks on hardware level. This is what this software helps with. I primarily wanted to include it as an option to the game Launcher. I then realized that there are other people with disabilities looking for a tool like this, in order to use in the other programs / games, where Windows ClickLock fails to work. As a result I released `Mouse ClickLock For Games` available for free, for everyone.

`Mouse ClickLock For Games` works a little bit differently. After the mouse button is released, the program simulates the hardware-level mouse operations. At first it returns to the position where the mouse button was primarily pressed. Then it simulates the mouse button down event. This way games only receive a signal that the mouse is down, and you are able to drag-select units. When you click the mouse button again - it completes.

## [Download Binary (MouseClickLockForGames.exe)](https://github.com/HerMajestyDrMona/MouseClickLockForGames/releases/)
(MouseClickLockForGames_x86.exe is a 32bit version. Most likely you don't need it.)

## [View the source code](https://github.com/HerMajestyDrMona/MouseClickLockForGames/blob/main/MouseClickLockForGames)

## What if it doesn't work?
If the program does not work for you, please try to run it as administrator. This way Hooking the `WH_MOUSE_LL` should success.

## What options are available in Mouse ClickLock For Games?

The program reads a configuration file `MouseClickLockForGamesConfig.txt` which should be present in the same folder as `MouseClickLockForGames.exe`.
It's possible to configure the program by creating a configuration file at the same location as `MouseClickLockForGames.exe`. The configuration file should be named: `MouseClickLockForGamesConfig.txt`.

You can include the following variables to your `MouseClickLockForGamesConfig.txt` file:

- Which Mouse Button should the program intercept?
  - 0 = Auto Detection (currently just selects the Left Mouse Button only).
  - 1 = Left Mouse Button only.
  - 2 = Right Mouse Button only.
  - 3 = Left and Right Mouse Buttons.
```
ClickLockMouseButtonMode=0
```

- After how many milliseconds the program should hold the selected mouse button pressed for you?
  - If the value is set to 0, the program will use the same time as set in Windows ClickLock settings.
```
ActivationDelay=0
```

- Should the mouse cursor be automatically moved back to the position where you pressed the mouse button?
  - 0 = No, the new mouse button down event will be simulated at the position where you released the press.
  - 1 = Yes, the mouse button will return to the position where you firstly pressed it.
```
MoveMouseBackToClickPosition=1
```

- When Windows ClickLock is enabled, should the program use a fix not to miss clicks?
  - 0 = No, the program won't emulate extra mouse up / down clicks.
  - 1 = Yes, the program will emulate extra mouse up / down clicks.
```
UseWindowsClickLockAntiDoubleFix=1
```

- Should the program run automatically on system startup? 
  - 0 = No
  - 1 = Yes
```
AutomaticallyRunThisProgramOnStartup=0
```

- Should the program create a log file with debugging information (MouseClickLockForGames_{DateTime}_LOG.txt)? 
  - 0 = No
  - 1 = Yes
```
CreateLogFile=0
```

After modifying the configuration file you need to restart the program by closing it and opening again.



