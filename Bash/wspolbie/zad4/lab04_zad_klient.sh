#!/bin/bash

server=serwerfifo
klient="$1""/klientfifo"

trap "rm -f $klient" EXIT

if [[ ! -p $klient ]]; then
    mkfifo $klient
fi

if [[ ! -p $server ]]; then
    echo "Reader(server) not running"
    exit 1
fi

echo $klient $2 > $server
read line < $klient
echo $line
