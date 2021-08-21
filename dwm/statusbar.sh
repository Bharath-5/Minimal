#!/bin/sh


	echo "$(cat /sys/class/net/wlan0/operstate)"
	echo "$(cat /sys/class/power_supply/BAT0/capacity)"
	echo "$(date +"%a|%x|%R")"


