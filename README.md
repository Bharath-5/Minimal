# Minimal

- This repo contains the config files of various programs that I use.
- The commands given below assumes that you are using Arch Linux or a distro based on Arch.
- These files are to be modified according to your needs and use cases.
- The .asoundrc file is to set the default audio card. Please do not use that file unless absolutely required.

## Screenshot 

![alt text](https://github.com/Bharath-5/Minimal/blob/master/XMonadScreenshot.png?raw=true)

## Installation
1. Clone this repository

```
        git clone https://github.com/Bharath-5/Minimal
```

- Go to the directory

```
        cd Minimal
```

- Delete the .asoundrc file

```
        rm ./.asoundrc
```	

2. Install the contrib package and xmobar to go along with XMonad. My config file defaults to URxvt as the default terminal.


```
        sudo pacman -S rxvt-unicode xmonad xmonad-contrib xmobar

        cp ~/.xmonad/xmonad.hs ~/.xmonad/xmonad-backup.hs	#Make a backup of any existing configs 

        cp ~/xmobar/xmobar.config ~/xmobar/xmobar-backup.config   

        cp ./.xmonad/xmonad.hs ~/.xmonad/			#Copy the cloned configs

        cp ./xmobar/xmobar.config ~/xmobar/
```


3. Install Additional Software required:

```
        sudo pacman -S dmenu picom qutebrowser telegram-desktop ttf-font-awesome ttf-fira-code volumeicon
```

4. Install an AUR helper [preferably Yay] to install Joplin and a theme

```
        yay -S joplin flat-remix 
```

5. Make a backup copy of your existing .Xresources and .picom.conf [if any] from your Home directory

```
        cp ~/.Xresources ~/.Xresources-backup

        cp ~/.picom.conf ~/.picom-backup.conf
```

6. Place the files .Xresources and .picom.conf in Home directory

```
        mv ./Xresources ~

        mv ./picom.conf ~
```

## Usage

- Most of my frequently used programs are mapped to the [Super] + Function keys. The applications open up in their respective workspaces. The workspaces are categorized as follows:

| Workspace number | Description | Keymappings |
|:----------------:|:-----------:|:-----------:|
| 1 | Browser | [Super] + F1 opens Qutebrowser | 
| 2 | File Manager | [Super] + F2 opens PcManFm |
| 3 | Terminal / Terminal based applications | [Super] + [Shift] + [Enter] opens URxvt |
| 4 | Office Programs	| [Super] + F4 opens LibreOffice |
| 5 | General	| [Super] + p opens dmenu |	
| 6 | Notes | [Super] + F6 opens Joplin |
| 7 | Social | [Super] + F7 opens Telegram |
| 8 | Other |  |
| 9 | Misc | |

- Most other keybindings are as close to their defaults



