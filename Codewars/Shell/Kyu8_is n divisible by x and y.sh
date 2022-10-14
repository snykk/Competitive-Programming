#!/bin/bash

[[ $(($1 % $2)) == 0 && $(($1 % $3)) == 0 ]] && echo "true" || echo "false"
