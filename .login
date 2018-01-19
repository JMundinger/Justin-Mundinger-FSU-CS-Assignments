# As strange as it sounds, this script is executed AFTER .tcshrc, but
# only from a "login" shell.

if (! $?TERM) then
   set noglob; eval `tset -Q -s`; unset noglob
endif

if ($TERM == "network" || $TERM == "unknown" || $TERM == "dialup"  ) then
   setenv TERM vt100; unsetenv TERMCAP; unsetenv DISPLAY
else if ($TERM == "console" || $TERM == "sun" || $TERM == "nsun") then
   click -n
endif

stty -tabs        # expand tabs to spaces (helpful on some terminals)

# do not notify user about new mail in shell
if ( -x /usr/ucb/biff ) then
  /usr/ucb/biff n
else if ( -x /usr/bin/biff ) then
  /usr/bin/biff n
endif

# all setup information common to all logins
source ~/.setup

alias ow "(set path=(/usr/openwin/bin $path);openwin)"
alias mit "(set path=(/bin/X11 $path);startx)"
set TTY=`tty`
if ($TTY == "/dev/console" ) then
   echo ""; echo ""; echo ""
   echo "starting X-windows (^C to stop)"
   sleep 10
   mit # can replace mit with ow if you prefer openwindows
   logout
endif

set tempmanpath = ( /usr/man /usr/*/man /usr/local/*/man/ /opt/*/man )
set manpath=`echo $tempmanpath | sed 's/ /:/g'`
setenv MANPATH $manpath

