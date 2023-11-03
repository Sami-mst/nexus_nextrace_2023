#!/bin/sh

EXEC="./babySnipe"
PORT=2033

socat -dd -T300 tcp-l:$PORT,reuseaddr,fork,keepalive exec:"$EXEC",stderr
