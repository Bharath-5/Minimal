# Minimal

- This repo contains the config files of various programs that I use.
- The i3 config is to be used with Manjaro i3 community edition.
- The commands given below assumes that you are using Arch Linux or a distro based on Arch.
- These files are to be modified according to your needs and use cases.
- The .asoundrc file is to set the default audio card. Please do not use that file unless absolutely required.

## Screenshot [XMonad]

  ![alt tag] (https://github.com/Bharath-5/Minimal/blob/master/XMonadScreenshot.png)

## Installation
- Clone this repository

	git clone https://github.com/Bharath-5/Minimal

- Go to the directory

	cd Minimal

- Delete the .acoundrc file

	rm ./.asoundrc
	
- If you are using the i3/i3-gaps Window Manager and if you are on Manjaro i3 Community Edition.
	* Replace the line "/home/bharath/Documents/HDD Backup/Wallpapers/Wallpapers" to the path of your Wallpapers directory
	* Delete config files of xmonad, xmobar and .asoundrc

	rm .asoundrc

	rm -rf .xmonad xmobar

	* Make a backup of Manjaro i3 config 

	cp ~/.i3/config ~/.i3/config-backup

	* Copy the downloaded config file 

	cp ./.i3/config ~/.i3/

	* Copy the Conky config file to /usr/share/conky [requires root]

	cp ./Conky/* /usr/share/conky

	* Skip the next step involving XMonad Window Manager

- If you are using XMonad Window Manager, also install the contrib package and xmobar to go along with it. My config file defaults to URxvt as the default terminal.

	sudo pacman -S rxvt-unicode xmonad xmonad-contrib xmobar

	* Make a backup of xmonad and xmobar configs [if any]

	cp ~/.xmonad/xmonad.hs ~/.xmonad/xmonad-backup.hs

	cp ~/xmobar/xmobar.config ~/xmobar/xmobar-backup.config

	* Copy xmonad and xmobar config files to appropriate directories

	cp ./.xmonad/xmonad.hs ~/.xmonad/

	cp ./xmobar/xmobar.config ~/xmobar/
 

- Install Additional Software required:

	sudo pacman -S dmenu firefox picom qutebrowser telegram-desktop ttf-font-awesome ttf-fira-code 

- Install an AUR helper [preferably Yay] to install Joplin

	yay -S joplin

- Make a backup copy of your existing .Xresources and .picom.conf [if any] from your Home directory

	cp ~/.Xresources ~/.Xresources-backup


	cp ~/.picom.conf ~/.picom-backup.conf

- Place the files .Xresources and .picom.conf in Home directory

	mv ./Xresources ~

	mv ./picom.conf ~

# Usage

- Most of my frequently used programs are mapped to the [Super] + Function keys. The applications open up in their respective workspaces. The workspaces are categorized as follows:
	* Workspace 1 : Browser						[Super] + F1 opens Firefox/Qutebrowser 
	* Workspace 2 : File Manager					[Super] + F2 opens PcManFm
	* Workspace 3 : Terminal / Terminal based applications		[Super] + [Enter] opens URxvt
	* Workspace 4 : Office Programs					[Super] + F4 opens LibreOffice
	* Workspace 5 : General						[Super] + d (in i3) and [Super] + p (in XMonad) opens dmenu	
	* Workspace 6 : Notes						[Super] + F6 opens Joplin
	* Workspace 7 : Social						[Super] + F7 opens Telegram
	* Workspace 8 : Other						[Super] + F9 opens vim to edit i3 config [In i3 Window Manager]
- The "[Super] + H" key combination in i3 Window Manager has been remapped to "[Super] + ;" to get vim-like keybindings for movement [Super] + h/j/k/l
- Most other keybindings are as close to their defaults



