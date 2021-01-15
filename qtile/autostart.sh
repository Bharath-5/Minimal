#! /bin/bash
xset r rate 300 50 &
xinput set-prop 13 274 1
xrdb ~/.Xresources &
brightnessctl s 15% &
nitrogen --random --set-zoom-fill /home/bharath/Pictures/Wallpapers &
