#!/bin/bash
echo "Welcome!1 This script installs the necessary packages and copies the configuration files to the appropriate directories. To quit this program, press [Ctrl] + C anytime"

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

echo "Installing packages"
sudo pacman -S alsa-utils brightnessctl celluloid dmenu lxappearance gparted neofetch pulseaudio pcmanfm python-psutil qutebrowser ranger scrot ttf-font-awesome ttf-fira-code qtile scrot rxvt-unicode vimiv w3m wget youtube-dl

echo "Press 1 for DWM and 2 for QTile"
read option
if [[$option -eq 1]]
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

elif [[$option -eq 2]]
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
