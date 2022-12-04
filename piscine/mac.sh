#!/bin/sh
ifconfig
ifconfig en0 ether | sed -e '1,2d' -e s/ether//g -e $'s/\t//g'
