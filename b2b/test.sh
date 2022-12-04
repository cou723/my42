#!/bin/bash
if [ -z $(sudo lvdisplay) ]; then
    echo test
else
    echo ok
fi
