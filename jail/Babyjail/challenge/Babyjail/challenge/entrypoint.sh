#!/bin/sh

USER="ctf"
EXEC="python3 main.py"
PORT=2037

socat -dd -T300 tcp-l:$PORT,reuseaddr,fork,keepalive exec:"$EXEC",stderr,su="$USER"



