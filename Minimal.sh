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
echo "Installing packages"
sudo pacman -S alsa-utils brightnessctl celluloid dmenu lxappearance gparted neofetch pulseaudio pcmanfm python-psutil qutebrowser ranger scrot ttf-font-awesome ttf-fira-code qtile scrot rxvt-unicode vimiv w3m wget youtube-dl

echo "Enter username"
read n

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

echo "Copying .Xresources file"
FILE=/home/$n/.Xresources
if [ -f "$FILE" ]; then
    mv /home/$n/.Xresources /home/$n/.Xresources-backup
    cp ./.Xresources /home/$n/
else   
    cp ./.Xresources /home/$n/
fi

echo "Do you want to install yay? (y or n)"
read a
if [ $a == "y" ]
then
   cd /opt
   sudo git clone https://aur.archlinux.org/yay-git.git
   sudo chown -R $n:$n ./yay-git
   cd yay-git
   makepkg -si
fi 

echo "Do you want to install Flat Remix GTK and Paper Icon Theme from the AUR? (y or n)"
read a
if [ $a == "y" ]
then
   yay -S flat-remix-gtk paper-icon-theme-git
fi
echo "Everything is set to go"
