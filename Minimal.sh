#!/bin/bash
echo "Welcome! This script installs the necessary packages and copies the configuration files to the appropriate directories. To quit this program, press [Ctrl] + C anytime"

echo "Should .asoundrc be deleted? (y or n)"
read a
if [ $a == "y" ]
then
   rm ./.asoundrc
   echo ".asoundrc deleted"
else
   cp ./.asoundrc ~
   echo ".asoundrc is copied to your home directory"
fi

echo "Enter username"
read n

echo "Press 1 for DWM, 2 for QTile, 3 for EXWM and 4 for Gnome"
read option
if [[ $option -lt 4 ]]
then
  echo "Additional packages will be installed"
  sudo pacman -S alsa-utils brightnessctl celluloid dmenu lxappearance gparted neofetch pulseaudio pcmanfm python-psutil qutebrowser ranger scrot ttf-font-awesome ttf-fira-code scrot rxvt-unicode vimiv w3m wget youtube-dl
fi
if [[ $option -eq 1 ]]
then

  sudo git clone git://git.suckless.org/dwm /usr/src
  s=$(pwd)
  sudo cp ./dwm/config.h /usr/src/dwm/
  cd /usr/src/dwm
  sudo make clean install
  cd $s
  mkdir /home/$n/Documents
  mkdir /home/$n/Documents/Sripts/
  cp ./dwm/statusbar.sh /home/$n/Documents/Scripts/
  chmod +x /home/$n/Documents/Scripts/statusbar.sh

elif [[ $option -eq 2 ]]
then
 sudo pacman -S qtile python-psutil
 echo "Copying Qtile config files"
 FILE=/home/$n/.config/qtile/
 if [ -f "$FILE" ]; then
    mkdir /home/$n/.config/qtile/backup/
    mv -r /home/$n/.config/qtile/* /home/$n/.config/qtile/backup/
    cp -r ./qtile/* /home/$n/.config/qtile/
 else  
    mkdir /home/$n/.config/qtile/
    cp -r ./qtile/* /home/$n/.config/qtile/
 fi

elif [[ $option -eq 3 ]]
then
    sudo pacman -S emacs gcc
    mkdir /home/$n/.emacs.d/
    cp ./Emacs/init.el /home/$n/.emacs.d/
    echo "Does an xsession file need to be created?"
    read xse
    if [[ $xse -eq 'y' ]]
    then
      sed -i 's/bharath/$n/' ./Emacs/exwm.desktop
      mv ./Emacs/exwm.desktop /home/$n/.emacs.d/
      mv ./Emacs/start-exwm.sh /home/$n/.emacs.d/
      chmod +x /home/$n/.emacs.d/start-exwm.sh
      sudo ln -f /home/$n/.emacs.d/exwm.desktop /usr/share/xsessions/exwm.desktop
    fi

elif [[ $option -eq 4 ]]
then
    echo "Should gnome be installed?"
    read ginstall
    if [[ $ginstall -eq "y" ]]
    then
      sudo pacman -S gnome
      echo "The gdm service will now be enabled and started"
      sudo systemctl enable gdm.service
      sudo systemctl start gdm.service
    fi
    sudo pacman -S dconf-editor gnome-tweaks gnome-shell-extensions
    echo "The keybinding file will now be loaded"
    dconf load '/org/gnome/desktop/wm/keybindings/' < './Gnome/wm-keybindings.dconf.bak'
fi

echo "Copying .Xresources file"
  FILE=/home/$n/.Xresources
  if [ -f "$FILE" ]; then
      mv /home/$n/.Xresources /home/$n/.Xresources-backup
      cp ./.Xresources /home/$n/
  else   
      cp ./.Xresources /home/$n/
  fi

echo "Do you want to install paru? (y or n)"
read a
if [ $a == "y" ]
then
   cd /opt
   sudo git clone https://aur.archlinux.org/paru.git
   sudo chown -R $n:$n ./paru
   cd paru
   makepkg -si
fi

echo "Do you want to install Flat Remix GTK and Paper Icon Theme from the AUR? (y or n)"
read a
if [ $a == "y" ]
then
   paru -S flat-remix-gtk paper-icon-theme-git
fi
echo "Everything is set to go"
if [[ $option -eq 3 ]]
then
echo "Once you open Emacs, please run M-x all-the-icons-install-fonts during the first run"
fi
