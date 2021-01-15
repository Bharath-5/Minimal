# Minimal

- This repo contains the config files of some programs that I use. The script places those files in appropriate locations and installs the necessary software to make it work, and also a few extra programs that I often use.
- The commands given below assumes that you are using Arch Linux or a distro based on Arch.
- The .asoundrc file is to set the default audio card. 
- The path to "Pictures" folder in the qtile config under custom keybindings needs to be modified according to use case.
## Screenshot 

![alt text](https://github.com/Bharath-5/Minimal/blob/master/Screenshot.jpg?raw=true)

## Installation
1. Clone this repository, go to the cloned directory and delete the .asoundrc file

```
        git clone https://github.com/Bharath-5/Minimal; cd Minimal;
```

2. Change the file permissions of the script and run the script 


```
      chmod 755 ./Minimal.sh; ./Minimal.sh 
```

## Usage

- Most of my frequently used programs are mapped to the [Super] + Function keys. The applications open up in their respective workspaces [in XMonad]. The workspaces are categorized as follows:

| Workspace number | Description | Keymappings |
|:----------------:|:-----------:|:-----------:|
| 1 | Browser | [Super] + F1 opens Qutebrowser | 
| 2 | File Manager | [Super] + F2 opens PcManFm |
| 3 | Terminal / Terminal based applications | [Super] + [Shift] + [Enter] opens URxvt |
| 4 | Office Programs	| [Super] + F4 opens LibreOffice |
| 5 | General	| [Super] + p opens dmenu |	
| 6 | Notes / Email | [Super] + F6 opens Thunderbird |
| 7 | Social | [Super] + F7 opens Telegram |
| 8 | Other |[Super] + F3 opens lynx browser |

- Most other keybindings are as close to their defaults



