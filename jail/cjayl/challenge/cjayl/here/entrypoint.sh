#!/bin/sh

USER="ctf"
EXEC="./cj"
PORT=2038

socat -dd -T300 tcp-l:$PORT,reuseaddr,fork,keepalive exec:"$EXEC",stderr,su="$USER"

