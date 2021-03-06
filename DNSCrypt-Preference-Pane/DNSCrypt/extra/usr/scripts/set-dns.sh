#! /bin/sh

. ./common.inc

servers="$*"

[ $# -lt 1 ] && exit 1
exec networksetup -listallnetworkservices 2>/dev/null | \
fgrep -v '*' | while read x ; do
  networksetup -setdnsservers "$x" $servers
done
dscacheutil -flushcache 2> /dev/null
killall -HUP mDNSResponder 2> /dev/null
exit 0
